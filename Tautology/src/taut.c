/*
 * taut.c
 *
 *  Created on: 09-Dec-2016
 *      Author: Sys-5304
 */
/*
 ============================================================================
 Name        : Tautology.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : A Tautology is a "propositional statement" which is true no matter what valuation is applied for each of the variables in the “vocabulary” of the statement.
 A propositional statement is formed by combining "propositional variables" with arbitrary logical operators.
 Vocabulary of the propositional statement is the set of all the variables in the statement.

 A propositional variable is one that can take truth values(true/false).
 Logical operators that we consider for this exercise are "AND" represented by "&", "OR" represented by "|" and "NOT" by "!".
 ============================================================================

 Examples of valid propositional statements:
 1. a
 2. a & b
 3. a & (b | c)
 4. !a & !b
 5. a | !a
 6. (a & (!b | b)) | (!a & (!b | b))

 Out of the above set of valid propositional statements, only 5 and 6 are tautologies. We'll leave it to you to actually work it out and internalize why they are tautologies.

 Given this context, we want you to parse a given set of statements and for each statement return whether its a tautology or not.

 Assumptions:
 1. All statements that are given as input will be syntactically valid. (You dont need to handle invalid sentences).
 2. All propositional variables will be single letter alphabets and no more than 10 variables will be there in any statement.
 (ie., cardinality of the vocabulary <= 10).
 3. The propositional statement can be arbitrarily nested.
 4. You can expected sentences to be well bracketed in case of binary operations.
 for ex: a | b will always be (a | b) even if it is the only operation in the statement.
 (You dont need to worry about associativity)
 5. Whitespace can appear anywhere in the statement.
 6. Only &, |, ! will be used as logical operators.
 7. ! operator will always associate with the immediate right proposition.

 Input:
 (!a | (a & a))
 (!a | (b & !a))
 (!a | a)
 ((a & (!b | b)) | (!a & (!b | b)))

 Output:
 True False True True
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tautology.h"

int main(int argc, char *argv[]) {
	char ipstr[100] = "a";
	int fnvalues[1000], numvar;
	int test;
	     if(argc == 1){
		  //get_expression(ipstr);
		  if(truth_table(ipstr, fnvalues, &numvar))
		       return 1;
		test = test_for_tautology(fnvalues, numvar);
		if (test == 1)
			printf("\nYAY!! Given expression is a Tautology!!\n");
		else if (test == 2)
			printf("\nThe given expression is a Contradiction!\n");
		else
			printf("\nThe given expression is neither a Tautology nor"
					" a Contradiction!\n");
	} else if (argc != 2) {
		printf("Please enter exactly one logical expressions!");
		return 0;
	} else {
		strcpy(ipstr, argv[1]);
		if (truth_table(ipstr, fnvalues, &numvar))
			//return 1;
		test = test_for_tautology(fnvalues, numvar);
		if (test == 1)
			printf("\nYAY!! Given expression is a Tautology!!\n");
		else if (test == 2)
			printf("\nThe given expression is a Contradiction!\n");
		else
			printf("\nThe given expression is neither a Tautology nor "
					"a Contradiction!\n");
	}
	return 0;
}

int get_expression(char ipstr[]) {
	printf(
			"Operators : \n& AND\n~ Not\n| OR\n> IMPLIES\n= IMPLIES AND IS IMPLIED BY\n");
	printf("Use any alphabets to denote your variables\n");
	printf("Please enter your logical expression : \n");
//     scanf("%s", ipstr);
	gets(ipstr);
	puts(ipstr);
	return *ipstr;
}

int test_for_tautology(int arr[], int numvar) {
	int i, flag = 0;
	for (i = 0; i < (1 << numvar); i++) {
		if (!arr[i]) {
			flag = 1;
		}
	}
	if (!flag)
		return 1; /* Tautology */

	flag = 0;
	for (i = 0; i < (1 << numvar); i++) {
		if (arr[i]) {
			flag = 1;
		}
	}
	if (!flag)
		return 2; /* Contradiction */

	return 0; /* General function */
}

/**********************************************************************
 * Program : To get an expression as argument and construct truth table
 * Date : 13 August 2010
 * Successful!!!
 * Things to learn :
 *** Approach the problem from a high-level
 *** Abstract away all the different procedures for easier testing and bug removal
 * Works with command line arguments!!
 * NOTE : Passing a string will allow the function to change it!!!
 * BE CAREFUL!!

 ************************************************************************/

int truth_table(char ipstr[], int fnvalues[], int *no_of_variables) {
	char opstr[100] = ""; /* Postfix expression */
	char listvar[100]; /* List of variable names (char) */
	int numvar, valvar[100];
	int precedence[256]; /* Precedence for tokens and variables */
	int i, j, output;

	remove_spaces(ipstr);

	if (check_for_valid_characters(ipstr)) {
		printf("ERROR! Use only valid characters - ~&|() a-z A-Z\n");
		return 1;
	}

	set_precedence(precedence, ipstr);
	get_var(listvar, &numvar, precedence);

	if (conv_to_postfix(ipstr, opstr, precedence) == 1) {
		/* printf ("\nSuccess in converting to postfix"); */
		/*  else{ */
		printf("\nError in input\n");
		return 1;
	}

	/* printf("\nPostfix expression : %s", opstr); */

	/* Truth-table Printing */
	printf("\n");
	for (i = 0; i < numvar; i++) {
		printf("%c ", listvar[i]);
	}
	printf("%s ", ipstr);

	for (i = 0; i < (1 << numvar); i++) {
		/* For each permutation of bits */
		printf("\n");
		compute_val_var_from_perm(i, valvar, numvar);
		for (j = 0; j < numvar; j++)
			printf("%d ", valvar[j]);
		output = eval_postfix(opstr, valvar, numvar, listvar);
		if (output == 1) {
			printf("Error : eval - not enuff operands\n");
			return 1;
		}
		fnvalues[i] = output - '0';
		printf("%c ", output);
	}

	*no_of_variables = numvar;
	printf("\n");
	return 0;
}

/*
 * General functions used for converting to and evaluating postfix, etc.
 *
 */

//extern char ipstr[100], opstr[100];
//extern char listvar[100];
//extern int numvar, valvar[100],  precedence[256];
char token_list[] = "~&|>=";

int is_variable(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;
	else
		return 0;
}

int is_token(char ch) {
	int i;
	for (i = 0; i < strlen(token_list); i++)
		if (ch == token_list[i])
			return 1;
	return 0;
}

int get_var(char listvar[], int * numvar, int precedence[]) {
	/* Note : numvar has to be a pointer since we change its value here */
	int k, i;
	k = 0;
	for (i = 'A'; i <= 'z'; i++) {
		if (precedence[i])
			listvar[k++] = i;
	}
	listvar[k] = '\0';
	*numvar = k;
	printf("%d - %s",numvar,*numvar);
//     printf("listvar : %s numvar : %d", listvar, *numvar);
	return *numvar;
}

/*int get_expression(char ipstr[]){
 printf("Use any alphabets to denote your variables\n");
 printf("Operators : \n& AND\n~ Not\n| OR\n> IMPLIES\n= IMPLIES AND IS IMPLIED BY\n");
 printf("\nPlease enter your logical expression : \n");
 //     scanf("%s", ipstr);
 gets(ipstr);
 printf("You input : %s", ipstr);
 }*/

int check_for_valid_characters(char ipstr[]) {
	int i, j, flag;
	char ch;

	/* Check for valid characters */
	for (i = 0; i < strlen(ipstr); i++) {
		ch = ipstr[i];
		switch (ch) {
		case '(':
		case ')':
			break;
		default:
			flag = 0;
			for (j = 0; j < strlen(token_list); j++)
				if (ch == token_list[j])
					flag = 1;
			if (flag)
				continue;
			else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				continue;
			else
				return 1;
		}
	}
	return 0;
}

int remove_spaces(char ipstr[]) {
	/* Remove spaces */
	int i, j;

	char curr[100];
	strcpy(curr, ipstr);
	for (i = 0, j = 0; i < strlen(curr); i++)
		if (curr[i] != ' ')
			ipstr[j++] = curr[i];

	ipstr[j] = '\0';
//     printf("\nw/o spaces - ipstr : %s %d\n", ipstr, strlen(ipstr));
	return 0;
}

void set_precedence(int precedence[], char ipstr[]) {
	/* Precedence for tokens */
	precedence['~'] = 5;
	precedence['&'] = 4;
	precedence['|'] = 3;
	precedence['>'] = 2;
	precedence['='] = 1;

	/* Precedence */
	char temp[100];
	unsigned int i;
	strcpy(temp, ipstr);

	for (i = 'A'; i <= 'z'; i++) {
		precedence[i] = 0;
	}
	/* Precedence for characters */
	for (i = 0; i < strlen(ipstr); i++) {
		if (!precedence[ipstr[i]])
			precedence[ipstr[i]] = 100;
	}

}

char eval_negation(char ch) {
	return (ch == '0') ? '1' : '0';
}

char eval_or(char a, char b) {
	if (a == '0' && b == '0')
		return '0';
	else
		return '1';
}
char eval_and(char a, char b) {
	if (a == '1' && b == '1')
		return '1';
	else
		return '0';
}
char eval_imply(char a, char b) {
	if (a == '1' && b == '0')
		return '0';
	else
		return '1';
}
char eval_bicond(char a, char b) {
	if ((a == '1' && b == '0') || (a == '0' && b == '1'))
		return '0';
	else
		return '1';
}

int conv_to_postfix(char ipstr[], char opstr[], int precedence[]) {
	/* Convert ipstr to opstr in postfix notation  */
	int i, octr = 0, stctr = 0;
	char ch, operstack[100];

	/* Check if the given expression doesn't have variables next to each other */
	int flag = 0;
	int tildeflag = 0;

//     printf("\nVariables next to each other? :");

	for (i = 0; i < strlen(ipstr); i++) {
		if (is_variable(ipstr[i])) {
			if (flag) {
				printf("\nNot a valid Infix Expression!\n");
				return 1;
			} else
				flag = 1;
		} else
			flag = 0;

		if (tildeflag) {
			if (!is_variable(ipstr[i])) {
				printf("\nNot a valid Infix Expression!\n");
				return 1;
			} else
				tildeflag = 0;
		}
		if (ipstr[i] == '~')
			tildeflag = 1;
	}
	if (tildeflag) {
		printf("\nNot a valid Infix Expression!\n");
		return 1;
	}

	for (i = 0; i < 100; i++)
		operstack[i] = opstr[i] = '\0';
//     printf("operstack : %s ipstr : %s", operstack, ipstr);

	int len = strlen(ipstr);

	for (i = 0; i < len; i++) {
		ch = ipstr[i];
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			opstr[octr++] = ch;
		else {
			switch (ch) {
			case '(':
				operstack[stctr++] = ch;
				break;
			case ')':
				while (stctr > 0 && operstack[stctr - 1] != '(')
					opstr[octr++] = operstack[--stctr];
				if (stctr == 0) {
					printf("\nERROR : no (");
					return 1;
				}
				if (operstack[stctr - 1] == '(')
					stctr--;
				break;
			default:
				while (stctr > 0 && is_token(operstack[stctr - 1])
						&& precedence[operstack[stctr - 1]] >= precedence[ch]) {

					/* Pop off operstack onto opstr */
//			 printf("%c %d %c %d ", operstack[stctr-1], precedence[operstack[stctr-1]], ch, precedence[ch]);
					opstr[octr++] = operstack[--stctr];
				}

				operstack[stctr++] = ch;
				break;
			}
		}

//	  printf("\n %s %s octr-%d stctr-%d", opstr, operstack, octr, stctr);
	}
	while (stctr > 0) {
		if (operstack[stctr - 1] == '(' || operstack[stctr - 1] == ')') {
			printf("\nERROR : Extra parens");
			return 1;
		} else
			opstr[octr++] = operstack[--stctr];
	}
	opstr[octr] = '\0';
	return 0;

}

int compute_val_var_from_perm(int perm, int valvar[], int numvar) {
	/*
	 * Get individual bit and put it in the respective valvar
	 */
	int j;
	for (j = numvar - 1; j >= 0; j--) {
		valvar[numvar - j - 1] = (perm & 1 << j) ? 1 : 0;
	}
	return valvar[numvar - j - 1];
}

int eval_postfix(char opstr[], int valvar[], int numvar, char listvar[]) {
	/* Arguments :
	 * char opstr[] - the postfix expression to be evaluated
	 * char valvar[] - the values to be substituted for each variable
	 * int numvar
	 Return the value of the postfix expr. for given inputs
	 */
	char stack[100], temp[100], ch;
	int i, j, ctr = 0;

	for (i = 0; i < 100; i++)
		stack[i] = temp[i] = '\0';
	strcpy(temp, opstr);
	for (i = 0; i < numvar; i++) {
		for (j = 0; j < strlen(temp); j++) {
			if (temp[j] == listvar[i])
				temp[j] = (valvar[i]) ? '1' : '0';
		}
	}
//     printf(" temp - %s\n", temp);

	for (i = 0; i < strlen(temp); i++) {
		ch = temp[i];
		if (ch == '0' || ch == '1')
			stack[ctr++] = ch;
		else {
			switch (ch) {
			case '~':
				if (ctr <= 0) {
//			 printf("Error : eval - not enuff operands");
					return 1;
				} else
					stack[ctr - 1] = eval_negation(stack[ctr - 1]);
				break;
			case '|':
				if (ctr <= 1) {
//			 printf("Error : eval - not enuff operands");
					return 1;
				} else {
					stack[ctr - 2] = eval_or(stack[ctr - 2], stack[ctr - 1]);
					ctr--;
				}
				break;
			case '&':
				if (ctr <= 1) {
//			 printf("Error : eval - not enuff operands");
					return 1;
				} else {
					stack[ctr - 2] = eval_and(stack[ctr - 2], stack[ctr - 1]);
//			 printf("stack-and %c ", stack[ctr-2]);
					ctr--;
				}
				break;
			case '>':
				if (ctr <= 1) {
//			 printf("Error : eval - not enuff operands");
					return 1;
				} else {
					stack[ctr - 2] = eval_imply(stack[ctr - 2], stack[ctr - 1]);
//			 printf("stack-and %c ", stack[ctr-2]);
					ctr--;
				}
				break;
			case '=':
				if (ctr <= 1) {
//			 printf("Error : eval - not enuff operands");
					return 1;
				} else {
					stack[ctr - 2] = eval_bicond(stack[ctr - 2],
							stack[ctr - 1]);
//			 printf("stack-and %c ", stack[ctr-2]);
					ctr--;
				}
				break;
			}
		}
//	  printf(" stack - %s ctr - %d ", stack, ctr);

	}

	if (ctr == 1) {
//	  printf("Return value : %d ", stack[ctr]);
		return stack[ctr - 1];
	} else {
//	  printf("Error : in Evaluation\n");
		return 1;
	}
}

