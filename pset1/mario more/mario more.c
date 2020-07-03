#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n ;
    do 
    {
        n = get_int("Height: ");//prompt user for height
    }
    while (n < 1 || n > 8);//control values for height
    
    for (int i = 1; i <= n; i++)//loop for printing 1 line
    {
        for (int r = 0; r < n - i; r++)//left spaces in a line
        {
            printf(" ");
        }
        
        for (int j = 0; j < i; j++) //left # in a line
        {
            printf("#");
        }
        
        printf("  ");//midle spaces in a line
        
        for (int k = 0; k < i; k++) //right # in a line
        {
            printf("#");
        }
    
        printf("\n") ;   
    }
}