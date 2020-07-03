#include <stdio.h>
#include <cs50.h>
int length(long l);
int digitSum(int s);//extra functions 
int nthDigit(int j, long k);


int main(void)
{
    long card = get_long("Card Number: ");//prompt user for card no
    int sum1 = 0;
    int sum2 = 0;
    long card1 = card / 10;
    long card2 = card;
    int d = nthDigit(2, card);
    
    //part 1 digit sum
    while (card1)
    {
        sum1 += digitSum(2 * (card1 % 10));
        card1 /= 100;
    }
    
    //part 2 digit sum
    while (card2)
    {
        sum2 += card2 % 10;
        card2 /= 100;
    }
    
    //conditions
    if ((sum1 + sum2) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (length(card) == 15 && (d == 35 || d == 37))
    {
        printf("AMEX\n");
    }
    else if (length(card) == 16 && (d == 51 || d == 52 || d == 53 || d == 54 || d == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length(card) == 13 || length(card) == 16) && nthDigit(1, card) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");//if card no satisfies nothing 
    }
}

int digitSum(int s)//adds digits of a no
{
    int sum = 0;
    while (s)
    {
        sum += s % 10;
        s /= 10;
    }
    return sum;
}

int length(long l)//gets length
{
    int counter = 0;
    while (l)
    {
        l /= 10;
        counter++;
    }
    return counter;
}

int nthDigit(int j, long k)//gets the nth digit from left of number
{
    do 
    {
        k /= 10;
    }
    while (length(k) != j);
    return k;
}