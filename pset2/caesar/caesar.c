#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int isnum(string a);

int main(int argc, string argv[])
{
    if (argc == 2 && isnum(argv[1]))//condition to run the main code
    {
        int key = atoi(argv[1]);
        
        string in = get_string("plaintext: ");
        string out = "";
        printf("ciphertext: ");
        
        for (int i = 0; in[i] != '\0'; i++)//checks each char of input one by one
        {
            if (isupper(in[i]))
            {
                printf("%c", (((int)in[i] - 65 + key) % 26 + 65));//add key to char uppercase
            }
            else if (islower(in[i]))
            {
                printf("%c", (((int)in[i] - 97 + key) % 26 + 97));//add key to char lowercase
            }
            else 
            {
                printf("%c", in[i]);//do nothing if not alphabet
            }
        }
        printf("\n");//leave a line
    }
    else//what to do if user doesnt co operate
    {
        printf("Usage: ./caesar key\n");
        return 1;//error declaration
    }
}


int isnum(string a)//check if a string is a number
{
    int num = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (!(isdigit(a[i])))//adds k to num if a has k non ints
        {
            num += 1;
        }
    }
    
    return (bool) !(num);//returns true if num == 0 and false if num != 0
}