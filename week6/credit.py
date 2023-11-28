import sys

def main():
    credit_card = get_card_num()
    validate_card(credit_card)

def get_card_num():
    while True:
        card_num = input("Number: ")
        try:
            if len(card_num) > 0 and int(card_num):
                break
        except ValueError:
            continue
    return card_num

def calculation(ini_digits):
    sec_digits = []
    for i in range(len(ini_digits)):
        sec_digits.append(2 * int(ini_digits[i]))
    sum = 0
    for i in sec_digits:
        if i <= 9:
            sum += i
        else:
            sum += i%10 + 1
    return sum

def validate_card(credit_card):
    card_len = len(credit_card)
    if card_len not in [13, 15, 16]:
        print("INVALID")
        sys.exit(1)

    temp = []
    if card_len % 2 == 0:
        for i in range(card_len):
            if i % 2 == 0:
                temp.append(credit_card[i])
        sum = calculation(temp)
        for i in range(card_len):
            if i % 2 != 0:
                sum += int(credit_card[i])

    else:
        for i in range(card_len):
            if i % 2 != 0:
                temp.append(credit_card[i])
        sum = calculation(temp)
        for i in range(card_len):
            if i % 2 == 0:
                sum += int(credit_card[i])

    if sum % 10 == 0:
        if card_len == 15 and int(credit_card[0]) == 3 and int(credit_card[1]) in [4,7]:
            print("AMEX")
        elif card_len == 16 and int(credit_card[0]) == 5 and int(credit_card[1]) in [1,2,3,4,5]:
            print("MASTERCARD")
        elif card_len in [13, 16] and int(credit_card[0]) == 4:
            print("VISA")
            sys.exit(0)
        else:
            print("INVALID")
            sys.exit(2)
    else:
        print("INVALID")
        sys.exit(3)

main()
