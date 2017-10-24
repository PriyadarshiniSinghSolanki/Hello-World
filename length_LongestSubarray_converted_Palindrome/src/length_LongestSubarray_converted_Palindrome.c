/*
 ============================================================================
 Name        : length_LongestSubarray_converted_Palindrome.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Find the length of the Longest Subarray which can be converted into a Palindrome.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// A utility function to print a substring str[low..high]
void printSubStr( char* str, int low, int high ){
	for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}


int longestPalSubstr( char *str ){
    int n = strlen( str ); // get length of input string
    bool table[n][n];
    memset(table, 0, sizeof(table));

    // All substrings of length 1 are palindromes
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i){
        if (str[i] == str[i+1]){
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k){
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i){
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i+1][j-1] && str[i] == str[j]){
                table[i][j] = true;

                if (k > maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    printf("Longest palindrome substring is: ");
    printSubStr( str, start, start + maxLength - 1 );
    return maxLength; // return length of LPS
}

int main(void) {
	char *str=  (char*)malloc(sizeof(char*));//[] = "forgeeksskeegfor";
	gets(str);

#if 0
	int i;
	int count[265] = { 0 };
	for (i = 0; i < strlen(str); ++i) {
		count[string[i]]++;
	}

	for (i = 0; i < strlen(str); ++i) {
		if (count[str[i]] == 1) {
			printf("%c", str[i]);
			break;
		}
	}
#endif

	printf("\nLength is: %d\n", longestPalSubstr(str));
	return 0;
}
