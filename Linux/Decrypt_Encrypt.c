/*
 * Decrypte_Encrypte.c
 *
 *  Created on: 13 Eki 2019
 *      Author: Erten
 */

#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Decrypt_Encrypt.h"

void Func_Encryption()
{
    /* Declaration of variables */
    unsigned int i,j;
    unsigned int Msg_Length = 20;
    unsigned int Kwd_Length = 20;
    unsigned int Current_Size_Msg = 0;
    unsigned int Current_Size_Kwd = 0;
    int c,ch_msg,ch_kwd;
	
	/* Initial allocation for input strings */ 
    char * Message = malloc(Msg_Length);
    Current_Size_Msg = Msg_Length;
    char * Key = malloc(Kwd_Length);
    Current_Size_Kwd = Kwd_Length;
	
    /* fflush(stdin) does not work properly for input buffer, in order to get rid of \n characters below dummy statement used */ 
    while((c= getchar()) != '\n' && c != EOF)
        /* discard */ ;
	
    /* Requesting message to be encrypted */
    printf("Enter Text to be Encrypted: \n");
    if(Message != NULL)
    {
        unsigned int k = 0;
        /* Take input until user hit the "ENTER" */ 
        while (( ch_msg = getchar() ) != '\n' && ch_msg != EOF)
        {
            Message[k++]=(char)ch_msg;

            /* If predetermined message size reached, reallocate. */
            if(k == Current_Size_Msg)
            {	
                Current_Size_Msg = k+Msg_Length; /* Increase current size. */
                Message = realloc(Message, Current_Size_Msg); /* Reallocate. */
            }
        }
        Message[k] = '\0'; /* End string. */
    }
     
    /* Requesting keyword for encryption */
    printf("Enter Encryption Key: \n");
    if(Key != NULL)
    {
        unsigned int l = 0;
        /* Take input until user hit the "ENTER" */ 
        while (( ch_kwd = getchar() ) != '\n' && ch_kwd != EOF)
        {
            Key[l++]=(char)ch_kwd;

            /* If predetermined key size reached, reallocate. */
            if(l == Current_Size_Kwd)
            {
                Current_Size_Kwd = l+Kwd_Length; /* Increase current size. */
                Key = realloc(Key, Current_Size_Kwd); /* Reallocate. */
            }
        }
        Key[l] = '\0'; /* End string. */
    }

    for( i=0, j=0; i < strlen(Message); i++, j++ )
    {
        /* Repeat until reach to the end of Message length. */
        if( j >= strlen(Key) )
        {
            j=0;
        }
		if(!isalpha(Message[i]))
		{
			j = (j - 1);
		}
		
        if(isalpha(Message[i])) /* Encrypte only alphabet characters */
        {
            /* Algortihm -> ( Input character + Key character )%(26) is equal to encrypted character. */
            printf("%c",65+(((toupper(Message[i])-65)+(toupper(Key[j])-65))%26));
        }
		
        /* If it is not a alphabet character write it as it is, do not encrypt it */
        else
            printf("%c", Message[i]);
    }
    
    /* Free Message Buffer */ 
    free(Message);
    Message = NULL;

    /* Free Key Buffer */ 
    free(Key);
    Key = NULL;
}

void Func_Decryption(void)
{
    /* Declaration of variables */
    unsigned int i,j;
    unsigned int Chip_Length = 20;
    unsigned int Kwd_Length = 20;
    unsigned int Current_Size_Chip = 0;
    unsigned int Current_Size_Kwd = 0;
    int c,ch_cphr,ch_kwd, Value;

	/* Initial allocation for input strings */
    char * Chiper = malloc(Chip_Length);
    Current_Size_Chip = Chip_Length;
    char * Key = malloc(Kwd_Length);
    Current_Size_Kwd = Kwd_Length;
	
    /* fflush(stdin) Does not work, in order to flush the buffer below dummy statement used, it reads the \n character in input buffer */ 
    while((c= getchar()) != '\n' && c != EOF)
        /* discard */ ;
	
    /* Requesting message to be encrypted ( gets function used in order to not discard whitespace ) */
    printf("Enter Text to be Decrypted: \n");
    if(Chiper != NULL)
    {
        unsigned int k = 0;
        /* Take input until user hit the "ENTER" */ 
        while (( ch_cphr = getchar() ) != '\n' && ch_cphr != EOF)
        {
            Chiper[k++]=(char)ch_cphr;

            /* If predetermined message size reached, reallocate. */
            if(k == Current_Size_Chip)
            {
                Current_Size_Chip = k+Chip_Length; /* Increase current size. */
                Chiper = realloc(Chiper, Current_Size_Chip); /* Reallocate */
            }
        }
        Chiper[k] = '\0'; /* End string. */
    }
     
    /* Requesting keyword for encryption */
    printf("Enter Decryption Key: \n");
    if(Key != NULL)
    {
        unsigned int l = 0;
        /* Take input until user hit the "ENTER" */ 
        while (( ch_kwd = getchar() ) != '\n' && ch_kwd != EOF)
        {
            Key[l++]=(char)ch_kwd; 

            /* If predetermined key size reached, reallocate. */
            if(l == Current_Size_Kwd)
            {
                Current_Size_Kwd = l+Kwd_Length; /* Increase current size. */
                Key = realloc(Key, Current_Size_Kwd); /* Reallocate */
            }
        }
        Key[l] = '\0'; /* End string. */
    }

    for( i=0, j=0; i < strlen(Chiper); i++, j++ )
    {
        /* Repeat until reach to the end of Chiper length */
        if( j >= strlen(Key) )
        {
            j=0;
        }
		
		if(!isalpha(Chiper[i]))
		{
			j = (j - 1);
		}
        /* Algortihm -> ( Input character - Key character ) is equal to decrypted character.
        If final result of operation is negative, need to considered going backwards like z to a
        so because of that adding it 26. */
        Value = (toupper(Chiper[i])-64)-(toupper(Key[j])-64);
        if( Value < 0)
        {
            Value = 26 + Value;
        }
        printf("%c",65 + (Value % 26));
    }
	 
    /* Free Cipher Buffer */ 
    free(Chiper);
    Chiper = NULL;
		
    /* Free Key Buffer */ 
    free(Key);
    Key = NULL;
}
