#include <cs50.h>
#include <stdio.h>


int digitSum(int s)//digit sum function + length function
{
    int sum = 0;
    while(s)
    {
        sum += s % 10;
        s /= 10;
    }
    return sum;
}

int length(long l)
{
    int counter = 0;
    while(l)
    {
        l /= 10;
        counter++;
    }
    return counter;
}

int nthDigit(int j,long k)
{
    do 
    {
        k /= 10;
    }
    while (length(k) != j);
    return k;
}

int main(void)
{
    long i = get_long("i= ");
    int m = get_int("m= ");
    printf("%i\n",nthDigit(m,i));
}