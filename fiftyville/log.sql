-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Kick off query
SELECT *
FROM
  crime_scene_reports
WHERE
  year = 2023
  AND month = 7
  AND day = 28
  AND street = "Humphrey Street";
