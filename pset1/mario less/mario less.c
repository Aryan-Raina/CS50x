#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n ;
    do 
    {
        n = get_int("Height: ");//ask for height
    }
    while (n < 1 || n > 8);//control values for height
    
    for (int i = 1; i <= n; i++)//loop for 1 line
    {
        for (int r = 0; r < n - i; r++)//spaces in a line
        {
            printf(" ");
        }
        
        for (int j = 0; j < i; j++) //# in a line
        {
            printf("#");
        }
    
        printf("\n") ;   
    }
}