#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int change;
    int coins = 0;
    
    do
    {
        change = round(get_float("Change owed: ") * 100);//get the user input in dollar and convert to cents
    }
    while (change < 0);
    
    if (change >= 25)//count the 25 cent coins
    {
        coins += change / 25;
        change = change % 25;
    }
    if (change >= 10)//count the 10 cent coins
    {
        coins += change / 10;
        change = change % 10;
    }
    if (change >= 5)//count the 5 cent coins
    {
        coins += change / 5;
        change = change % 5;
    }
    if (change >= 1)//count the 1 cent coins
    {
        coins += change / 1;
    }
    
    printf("%i \n", coins);
}