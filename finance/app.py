import os
import re

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    rows = db.execute("SELECT symbol, SUM(CASE WHEN type='buy' THEN amount ELSE 0 END) - SUM(CASE WHEN type='sell' THEN amount ELSE 0 END) as amount, quote FROM transactions WHERE user_id = ? GROUP BY symbol, quote", session.get("user_id"))
    if len(rows) < 1:
        return render_template("index.html")
    portfolio = []
    sum = 0
    for row in rows:
        if row['amount']:
            portfolioEntry = dict(row)
            portfolioEntry['quote']=usd(row['quote'])
            currentPrice = lookup(row['symbol'])
            if not currentPrice:
                portfolioEntry['current_quote'] = "Unavailable"
            portfolioEntry['current_quote']=usd(currentPrice['price'])
            portfolio.append(portfolioEntry)
            sum = sum + row['amount'] * row['quote']

    userEntry = db.execute("SELECT cash FROM users WHERE id = ?", session.get("user_id"))
    if len(userEntry) != 1:
        return apology("Internal Server Error", 500)

    return render_template("index.html", portfolio=portfolio, sum=usd(sum), cash=usd(userEntry[0]['cash']))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        quote = lookup(request.form.get("symbol"))
        if not quote:
            return apology("Invalid symbol", 400)

        amount = request.form.get("amount")
        try:
            amount = int(amount)
        except ValueError:
            return apology("Amount must be a number", 400)
        if amount < 0:
            return apology("Amount cannot be less than 0", 400)

        userId = session.get("user_id")
        userEntry = db.execute("SELECT * FROM users WHERE id = ?", userId)
        if len(userEntry) != 1:
            return apology("DB Issue", 500)

        if amount * quote['price'] > userEntry[0]['cash']:
            return apology("Not enough money", 400)

        db.execute(
            "INSERT INTO transactions (user_id, symbol, amount, quote, type)VALUES (?, ?, ?, ?, 'buy')", userId, quote['symbol'], amount, quote['price']
            )
        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?", userEntry[0]['cash'] - (amount * quote['price']), userId
            )
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    records = db.execute('SELECT * FROM transactions WHERE user_id =?', session.get("user_id"))
    return render_template('history.html', records=records)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quotes = lookup(symbol)
        print(quotes)
        if quotes == None:
            return apology("Invalid Symbol", 400)
        if not isinstance(quotes, list):
            quotes = [quotes]
        return render_template("quoted.html", quotes=quotes)
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        if not username:
            return apology("must provide username", 400)

        password = request.form.get("password")
        if len(password) < 5 or not re.search(r"[a-z]",password) or not re.search(r"[\d]",password):
            return apology("password must contain 5 characters including a letter and a digit", 400)

        confirmpassword = request.form.get("confirmpassword")
        if password !=confirmpassword :
            return apology("passwords are not the same", 400)

        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", username, generate_password_hash(password))

        return redirect("/")
    if request.method == "GET":
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    rows = db.execute("SELECT symbol, (SUM(CASE WHEN type='buy' THEN amount ELSE 0 END) - SUM(CASE WHEN type='sell' THEN amount ELSE 0 END)) as amount FROM transactions WHERE user_id = ? GROUP BY symbol HAVING (SUM(CASE WHEN type='buy' THEN amount ELSE 0 END) - SUM(CASE WHEN type='sell' THEN amount ELSE 0 END)) > 0;", session.get("user_id"))
    if len(rows) < 1:
        return apology("Nothing to sell", 400)
    if request.method == "POST":
        selected = request.form.get('shares')
        quote = lookup(selected)
        if not quote:
            return apology("Something went wrong", 500)
        user_cash = db.execute("SELECT cash FROM users WHERE id= ?",session.get("user_id"))
        if len(user_cash) != 1:
            return apology("Something went wrong", 500)
        amount_possesion = db.execute("SELECT SUM(amount) as amount FROM transactions WHERE user_id =? AND symbol = ?", session.get("user_id"), selected)
        new_saldo = float(user_cash[0]['cash']) + int(amount_possesion[0]['amount']) * quote['price']
        db.execute("UPDATE users SET cash = ? WHERE id = ?",new_saldo,session.get("user_id"))
        db.execute("INSERT INTO transactions (user_id, symbol, amount, quote, type)VALUES (?, ?, ?, ?, 'sell')", session.get("user_id"), selected, amount_possesion[0]['amount'], quote['price'])
        return redirect("/")
    else:
        return render_template("sell.html", rows=rows)
