/*
 * tautology.h
 *
 *  Created on: 09-Dec-2016
 *      Author: Sys-5304
 */

#ifndef TAUTOLOGYH_
#define TAUTOLOGYH_

char eval_negation(char ch);
char eval_or(char a, char b);
char eval_and(char a, char b);
int is_token(char ch);
int conv_to_postfix(char ipstr[], char opstr[], int precedence[]);
int compute_val_var_from_perm(int perm, int valvar[], int numvar);
int eval_postfix(char opstr[], int valvar[], int numvar, char listvar[]);


int get_var(char listvar[], int * numvar, int precedence[]);
int get_expression(char ipstr[]);
int check_for_valid_characters(char ipstr[]);
int remove_spaces(char ipstr[]);
void set_precedence(int precedence[], char ipstr[]);

int truth_table(char ipstr[], int fnvalues[], int *no_of_variables);
int test_for_tautology(int arr[], int numvar) ;


#endif /* TAUTOLOGYH_ */
