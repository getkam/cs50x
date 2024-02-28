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

-- backery security logs ------------> licence plates
SELECT
  *
FROM
  bakery_security_logs
WHERE
  activity = "exit"
  AND year = 2023
  AND month = 7
  AND day = 28
  AND hour = 10
  AND minute BETWEEN 15 AND 26;

---ATM records ----------------------> account_number, amount
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

   -----------------------------------------------list of people having this bank account
SELECT
  person_id
FROM
  bank_accounts
WHERE
  account_number IN (
    SELECT
      account_number
        FROM
          atm_transactions
        WHERE
          year = 2023
          AND month = 7
          AND day = 28
          AND atm_location = "Leggett Street"
          AND transaction_type = "withdraw"
    );

-- PHONE CALLS ------------------> caller and reciever numbers
SELECT
  *
FROM
  phone_calls
WHERE
 year = 2023
 AND month = 7
 AND day = 28
 and duration < 60;

 ---> Earliest flight from Fiftyville on 29th of JULY
 SELECT
   *
 FROM
   flights
 WHERE
   year = 2023
   AND month = 7
   AND day = 29
   AND origin_airport_id IN (
     SELECT id
     FROM airports
     WHERE city = "Fiftyville"
   )
   ORDER BY
     hour,
     minute
   LIMIT
     1;

--- DESTINATION CITY of out thiefs.  --------------- New York City
SELECT
  city
FROM
  airports
WHERE
 id IN (
  SELECT
   destination_airport_id
 FROM
   flights
 WHERE
   year = 2023
   AND month = 7
   AND day = 29
   AND origin_airport_id IN (
     SELECT id
     FROM airports
     WHERE city = "Fiftyville"
   )
   ORDER BY
     hour,
     minute
   LIMIT
     1
);

------------------------------- list of passport numbers

SELECT
  *
FROM
  passengers
WHERE
  flight_id IN (
    SELECT
      id
    FROM
      flights
    WHERE
    year = 2023
    AND month = 7
    AND day = 29
    AND origin_airport_id IN (
        SELECT id
        FROM airports
        WHERE city = "Fiftyville"
    )
    ORDER BY
        hour,
        minute
    LIMIT
        1
  )
--------------------------------------- Thief
SELECT
  *
FROM
  people 
WHERE



WHERE year = 2023 AND month = 7 AND day = 28
