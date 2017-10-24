/********************************************************************** 
 * Program name : truth-table
 * Program : To get a logical expression and construct truth table for it
 * Date : 13 August 2010
 * Successful!!!
 * Things to learn :
 *** Approach the problem from a high-level
 *** Abstract away all the different procedures for easier testing and bug removal
 * Works with command line arguments!!

************************************************************************/



#include <stdio.h>
#include <string.h>
#include "postfix.h"

char ipstr[100] = "";
int fnvalues1[1000], fnvalues2[1000], numvar;

int get_expression(char ipstr[])
{
     printf("Operators : \n& AND\n~ Not\n| OR\n> IMPLIES\n= IMPLIES AND IS IMPLIED BY\n");
     printf("Use any alphabets to denote your variables\n");
     printf("Please enter your logical expression : \n");
//     scanf("%s", ipstr);
     gets(ipstr);
}

/* void print_fnvalues(int fnvalues[], int numvar) */
/* { */
/*      int i; */
/*      for(i=0; i<(1<<numvar); i++){ */
/* 	  printf("%d ", fnvalues[i]); */
/*      } */
/*      printf("\n"); */
/* } */

int equivalent(int arr1[], int arr2[], int numvar)
{
     int i, flag = 0;
     for(i=0; i<(1<<numvar); i++){
	  if(arr1[i] != arr2[i]){
	       flag = 1;
	       return 0;
	  }
     }
     return 1;
}

	       
	  

int main(int argc, char *argv[]){
     int i, j, output;

     if(argc == 1){
	  printf("Logical Expression 1 :\n");
	  get_expression(ipstr);
	  truth_table(ipstr, fnvalues1, &numvar);
	  /* print_fnvalues(fnvalues1, numvar); */
	  printf("Logical Expression 2 :\n");
	  get_expression(ipstr);
	  truth_table(ipstr, fnvalues2, &numvar);
	  /* print_fnvalues(fnvalues2, numvar); */
	  if(equivalent(fnvalues1, fnvalues2, numvar))
	       printf("\nThe given functions are equivalent!\n");
	  else
	       printf("\nThe given functions are NOT equivalent!\n");
     }
     else if(argc != 3){
	  printf("Please enter exactly two logical expressions!");
	  return 0;
     }
     else{
	  strcpy(ipstr, argv[1]);
	  printf("Logical Expression 1 :\n");
	  truth_table(ipstr, fnvalues1, &numvar);
	  /* print_fnvalues(fnvalues1, numvar); */
	  printf("Logical Expression 2 :\n");
	  strcpy(ipstr, argv[2]);	  
	  truth_table(ipstr, fnvalues2, &numvar);
	  /* print_fnvalues(fnvalues2, numvar); */
	  if(equivalent(fnvalues1, fnvalues2, numvar))
	       printf("\nThe given functions are equivalent!\n");
	  else
	       printf("\nThe given functions are NOT equivalent!\n");

     }
     
     return 0;
}

