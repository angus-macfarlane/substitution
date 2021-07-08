#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//accept single command line argument
int main(int argc, string argv[])
{
    //printf("argc: %d\n", argc);
    //reject input of 0 or more than 1
    if (argc != 2) //this might need to be two
    {
        printf("Error(too many args): Please enter a valid key.\n");
        return(1);

    }

    //reject key that doesn't have 26 unique letters
    int num_char = strlen(argv[1]);
    if (num_char != 26)
    {
        printf("Error(not 26 chars): Please enter a valid key.\n");
        return(1);
    }
    //check to see if all characters are letters

    for (int i = 0; i < 26; i++)
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Error(not letters): Please enter a valid key.\n");
            return(1);
        }

    //check for no duplicates
    //nested loops????
    for (int i = 0; i < 27; i++) //26 or 25? Or 27?
        {
            for (int j = 1; j < 27; j++)
            {
                if (i != j)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Duplicate Character(s) Detected: %c and %c\n", argv[1][i], argv[1][j]);
                        printf("Error (duplicates): Please enter a valid key.\n");
                        return(1);
                    }
                }
            }

        }

    //ask for plaintext input
    string plaintext = get_string("Enter plain text: ");
    int length = strlen(plaintext);

    char key[26];
    for (int i = 0; i < 27; i++)
    {
        key[i] = argv[1][i];
        //printf("Key i: %c\n", key[i]);
    }

    //create uppercase key
    char key_upper[26];
    for (int i = 0; i < 27; i++)
    {
        if ( isupper(key[i]) != 0 )
        {
            key_upper[i] = key[i];
            //printf("Key i: %c\n", key_upper[i]);
        }

        if ( islower(key[i]) != 0 )
        {
            key_upper[i] = (key[i] - 32);
        }
    }




    //create lowercase key
    char key_lower[26];
    for (int i = 0; i < 27; i++)
    {
        if ( isupper(key[i]) != 0 )
        {
        key_lower[i] = (key[i] + 32);
        //printf("Key i: %c\n", key_lower[i]);
        }

        if ( islower(key[i]) != 0 )
        {
            key_lower[i] = key[i];
        }
    }


    //convert plaintext to ciphertext, maintaining case and leaving all non-letter chars in place
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char ALPHABET[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    //WORK IN PROGRESS:
    char ciphertext[length];
    int index [length];
    printf("ciphertext: ");

    //take the plaintext, compare it to the alphabet, for each match, get the alphabet index and put it into index.
    for (int i = 0; i <= length; i++)
    {

            if ( isalpha(plaintext[i]) != 0) //Keep your i and j straight!!
            {
                if ( isupper(plaintext[i]) != 0)
                {
                    //printf("ASCII UPPER: %d :: ", plaintext[i]);
                    for (int j = 0; j < 27; j++)
                    {
                        if ( plaintext[i] == ALPHABET[j])
                        {
                            //printf("%c :: ", ALPHABET[j]);
                            ciphertext[i] = key_upper[j];
                            //printf("%c", key_upper[j]);
                        }
                    }
                    continue;
                }
                if ( islower(plaintext[i]) != 0)
                {
                    //printf("ASCII Lower: %d", plaintext[i]);
                    for (int j = 0; j < 27; j++)
                    {
                        if ( plaintext[i] == alphabet[j])
                        {

                            ciphertext[i] = key_lower[j];

                        }
                    }
                    continue;
                }
                continue;
            }
            if ( isalpha(plaintext[i]) == 0)
            {
                ciphertext[i] = plaintext[i];
                //printf("%c", plaintext[i]);
                continue;
            }
            // if ( plaintext[i] == ALPHABET[j])
            // {
            //     //index[i] = j;
            //     //printf("%c", key_upper[j]);
            //     continue;
            // }
            // if ( (plaintext[i] != alphabet[j]) && (plaintext[i] != ALPHABET[j]))
            // {
            //     //index[i] = argv[1];
            //     //printf("%c", argv[1][i]);
            //     continue;
            // }



    }
    //printf("\n");
    printf("ciphertext: %s\n", ciphertext);

    return(0);
}










//output ciphertext to screen

