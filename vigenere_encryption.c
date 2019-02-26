#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool islowercase(char c);
bool isuppercase(char c); 
bool checkinput(string second); // Declaring all functions that I'm gonna use
int shift( char c, string key, int pos);


int main(int argc, string argv[])
{
    if (argc != 2 || checkinput(argv[1]) == false)
        // Checks whether there were more than two arguments given, or a single argument, or whether it is true that the second argument is not a number
    {
        printf("Usage: %s key \n", argv[0]);    
    }
    
    else
    {
        
        string key = argv[1]; //assign the 2nd argument to a variable as string
        
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        
        for (int i=0, x = 0 ; i < strlen(plaintext); i++)
        {
            if (!islowercase(plaintext[i]) && !isuppercase(plaintext[i]))
            {
                x += 1;
            }
            
            int position = i - x;
            char ciph_c = shift(plaintext[i], key, position);
            
            printf ("%c", ciph_c);
        
        }
        printf ("\n");
    }
}

bool checkinput(string second)
{
    for (int i = 0; i < strlen(second); i++)
    {
        if ( !islowercase(second[i]) && !isuppercase(second[i]) ) //If the second argument is not in the lower or upper case alphabet, return false
        {
            return false;
        }
        else
        {
            continue;
        }
        
    }
    return true;
}


bool islowercase(char c) 
{
    return ( c >= 'a' && c <= 'z');
}

bool isuppercase (char c) 
{
    return (c >= 'A' && c <= 'Z');
}

int shift (char c, string key, int pos) // takes a character as input and returns the number associated with the encrypted ASCII character 
{
    int length = strlen(key);
    int diff = pos % length; // the residual makes sure that we dont exceed the key's length

    if (isuppercase(c))
    {
        if (key[diff] >= 'A' && key[diff] <= 'Z')
        {
            int num_c = (((c - 'A') + (key[diff] - 'A'))%26)+'A';
            return num_c;
        }
        else
        {
            int num_c = (((c - 'A') + (key[diff] - 'a'))%26)+'A';
            return num_c;
        }
    }
    if (islowercase(c))
    {
        if (key[diff] >= 'a' && key[diff] <= 'z')
        {
            int num_c = (((c - 'a') + (key[diff] - 'a'))%26)+'a';
            return num_c;
        }
        else
        {
            int num_c = (((c - 'a') + (key[diff] - 'A'))%26)+'a';
            return num_c;
        }
    }
    else
    {
        return c;
    }
}