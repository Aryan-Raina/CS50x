#include <stdio.h>
#include <cs50.h>

int  main(void)
{
    string name = get_string("What's your name?\n"); //takes name
    printf("hello, %s\n", name); //says hello and then name
}