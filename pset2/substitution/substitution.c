#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int notAlpha(string a);
int repeatAlpha(string b);

int main(int argc, string argv[])
{
    //error messages
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");//result for no key or more than 1 key
        return 1;
    }
    if (strlen(argv [1]) != 26)
    {
        printf("Key must contain 26 characters.\n");//result for more than 26 alphabets
        return 1;
    }
    if (notAlpha(argv[1]))
    {
        printf("Key must only contain aphabetic characters.\n");//result for conatin a not alphabet char
        return 1;
    }
    if (repeatAlpha(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");//result for repeating alpha
        return 1;
    }
    
    //main code
    string s = get_string("plaintext: ");//prompt for string
    printf("ciphertext: ");
    
    for (int i = 0; s[i] != '\0'; i++)//main substituting loop
    {
        if (isupper(s[i]))
        {
            printf("%c", toupper(argv[1][(int) s[i] - 65]));//cipher uppercase chars
        }
        else if (islower(s[i]))
        {
            printf("%c", tolower(argv[1][(int) s[i] - 97]));//ciphers lowercase chars
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");//leaving a line for good looks
}

int notAlpha(string a)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (!(isalpha(a[i])))
        {
            return 1;//returns 1 if string contains even 1 non alpha char
        }
    }
    return 0;
}

int repeatAlpha(string b)
{
    for (int i = 0; b[i] != '\0'; i++)
    {
        for (int j = 0; b[j] != '\0'; j++)
        {
            if (b[i] == b[j] && i != j)
            {
                return 1;//returns one if any char in the string is repeated
            }
        }
    }
    return 0;
}