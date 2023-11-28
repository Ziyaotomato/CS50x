from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

change = change * 100

quarters = int(change/25)
change = change - 25 * quarters


dimes = int(change/10)
change = change - 10 * dimes


nickels = int(change/5)
change = change - 5 * nickels

pennies = change

sum = quarters + dimes + nickels + pennies

print(int(sum))
