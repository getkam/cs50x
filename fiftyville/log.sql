-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Kick off query - 3 witness , bakery, 10:15
SELECT *
FROM
  crime_scene_reports
WHERE
  year = 2023
  AND month = 7
  AND day = 28
  AND street = "Humphrey Street";


  --Interviews - valid informations are from
    --> Ruth: car left parking up to 10 min after theft)
    --> Eugene: she saw thief before 10:15 by ATM on Leggett Street withdrawing money
    --> Raymond: thief call to someone right after 10:15, call lasted less than 1 min,
        --other person suppose to buy a ticket on the erliers flight 29th July
  SELECT
    name,
    transcript
  FROM
    interviews
  WHERE
   year = 2023
   AND month = 7
   AND day = 28;

---ATM records - might be usefull later account_number, amount
SELECT
  *
FROM
  atm_transactions
WHERE
   year = 2023
   AND month = 7
   AND day = 28
   AND atm_location = "Leggett Street"
   AND transaction_type = "withdraw";

-- PHONE CALLS -- posiible caller and reciever numbers
SELECT
  *
FROM
  phone_calls
WHERE
 year = 2023
 AND month = 7
 AND day = 28
 and duration < 60;



WHERE year = 2023 AND month = 7 AND day = 28
