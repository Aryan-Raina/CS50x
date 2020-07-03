#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string in = get_string("IN: ");
    string out = "";
    out += in[2];
    
    printf("OUT: %s",out);
}