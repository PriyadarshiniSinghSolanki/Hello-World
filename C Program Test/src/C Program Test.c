/*
 ============================================================================
 Name        : C.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description :  3

				 6 4
				 11 1 13 21 3 7
				 11 3 7 1

				 6 3
				 1 2 3 4 5 6
				 1 2 4

				 5 3
				 10 5 2 23 19
				 19 5 3

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
 int num =5;
 static int result = 1;
 while(num){
	 result = result*num--;
 }
 printf("%d",result);
	return 0;
}


