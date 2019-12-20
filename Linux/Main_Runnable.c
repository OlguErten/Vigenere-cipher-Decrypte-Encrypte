/*
 * Runnable.c
 *
 *  Created on: 13 Eki 2019
 *      Author: Erten
 */


#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Decrypt_Encrypt.h"

int main()

{
	int Operation;
	/* Until exiting loop without erros this loop will not come to an end */
	while(1)
	{	
		/* Request input from user for operation */
		printf("Please choose operation: \n");
		printf("1. Text Encryption\n");
		printf("2. Text Decryption\n");
		scanf("%d",&Operation);
		
		switch(Operation)
		{
			case 1: /* Do Encryption */
			{
				Func_Encryption();
				exit(0);
			}
			case 2: /* Do Decryption */
			{
				Func_Decryption();
				exit(0);
			}
        default: /* Request a valid input */
        	printf("Please Enter Valid Option!\n\n");
		}
     }
     return 0;
}
