from cs50 import get_string


def main():
    card = get_string("Card Number: ")
    checkSum = 0
    d = int(card[0] + card[1])
    l = len(card)

    for i in range(l):
        j = l - 1 - i
        if i % 2 == 1:
            checkSum += digitSum(str(2 * int(card[j])))
        else:
            checkSum += int(card[j])
            
    if not checkSum % 10 == 0:
        print("INVALID")
    elif l == 15 and d in [35, 37]:
        print("AMEX")
    elif l == 16 and d in [51, 52, 53, 54, 55]:
        print("MASTERCARD")
    elif l in [13, 16] and card[0] == '4':
        print("VISA")
    else:
        print("INVALID")
    
    
def digitSum(num):
    dSum = 0
    for i in num:
        dSum += int(i)
    return dSum
    

main()
    