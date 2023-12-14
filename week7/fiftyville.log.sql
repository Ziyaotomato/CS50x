-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check the format that year/month/day stored.
SELECT * FROM crime_scene_reports LIMIT 5;

-- Locate the crime data & location
-- Result: took place at 10:15 am --> bakery, interviewed with three people at the scene, also littering but should be fine
SELECT *
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- Two crimes were reported that day and only one is related to the duck case.
-- Crime time: 10:15am; 3 witnesses

-- Check the interview transcript
SELECT *
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;
-- Ruth: 10:25am the theft went to the bakery parking lot and drove their car away --> parking lot footage
-- Eugene:  theft withdrawing some money before 10:15am --> atm transaction record
-- Raymond: called someone for less than a minute, earlist flight tmr, ask the other to purchase the flight ticket --> fligt info

-- Check the parking lot
SELECT *
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND activity = 'exit'
AND hour = 10
AND minute > 15;
-- 9 cars fits the requirement.

-- Check the ATM transaction record
SELECT *
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- 8 accounts fit the requirement.

-- Check the phone calls record
SELECT *
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND DURATION <= 60;
-- 10 phone calls fit the requirement.

-- Check Fiftyville's airport id
SELECT *
FROM airports
WHERE full_name LIKE '%Fiftyville%';
-- Airport id is 8 and abbreviation is CSF.

-- Check flights out of Fiftyville on the second day
SELECT *
FROM flights
WHERE year = 2021
AND month = 7
AND day = 29
AND origin_airport_id = 8;
-- Earlist flight id is 36 (depature at 8:20am). The id of the destination airport is 1.

-- Check passenger lists
SELECT *
FROM passengers
WHERE flight_id = 36;

-- Put everything together:
-- Passenger list join people on passport number
-- Phone call list join people on caller number
-- Security camera join people on plate
-- Bank account join people on id
SELECT DISTINCT(people.name)
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN phone_calls
ON people.phone_number = phone_calls.caller
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON atm_transactions.account_number = bank_accounts.account_number
WHERE phone_calls.duration < 60
AND bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.activity = 'exit'
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
AND passengers.flight_id = 36
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';
-- It is Bruce!!!!!

-- Check flight destination
SELECT destination_airport_id
FROM flights
WHERE id = 36;
-- Destination id is 4
SELECT city
FROM airports
WHERE id = 4;
-- LaGuardia Airport

-- Check call receiver
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60
AND phone_calls.caller = '(367) 555-5533';
-- The accomplice is Robin!
