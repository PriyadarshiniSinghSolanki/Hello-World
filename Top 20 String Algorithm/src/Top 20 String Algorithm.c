/* ============================================================================
 Name        : Top.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description :
 1) How to Print duplicate characters from String?
 You need to write a program in C, C++, Java or Python to print duplicate characters from a given String.
 i.e. if String is "Java" then program should print "a".
 Bonus points if your program is robust and handle different kinds of input
 e.g. String without duplicate, null or empty String etc.

 2) How to check if two Strings are anagrams of each other?
 You need to write a Java program to check if two given strings are anagrams of Each other.
 Two strings are anagrams if they are written using the same exact letters, ignoring space, punctuation and capitalization.
 Each letter should have the same count in both strings. For example, Army and Mary are anagram of each other.

 3) How to program to print first non repeated character from String?
 Find the first non-repeated (unique) character in a given string.
 for Example if given String is "Morning" then it should print "M".
 This question demonstrates efficient use of Hashtable.
 We scan the string from left to right counting the number occurrences of each character in a Hashtable.
 Then we perform a second pass and check the counts of every character.
 Whenever we hit a count of 1 we return that character, that’s the first unique letter.
 Be prepared for follow-up question for improving memory efficiency, solving it without hash table as well.


 4) How to reverse String in Java using Iteration and Recursion?
 Your task is to write a program to reverse String in Java without using StringBuffer class.
 You also need to provide both iterative and recursive algorithm for String reversal.
 You can use other String utility methods e.g. charAt(), toCharArray() or substring() from java.lang.String class.


 5) How to check if a String contains only digits?
 You need to write a program to check a String contains only numbers by using Regular expression in Java.
 You can use Java API but a  without using Java API will be better because that is what interviewer can always ask.


 6) How to find duplicate characters in a String?
 You need to write a program to print all duplicate character and their count in Java.
 For example if given String is "Programming" then your program should print
 g : 2
 r : 2
 m : 2


 7) How to count number of vowels and consonants in a String?
 You have to write a Java program which will take a String input and print out number of vowels and consonants on that String.
 For example the if input is "Java" then your program should print "2 vowels and 2 consonants".
 If you get this question on Interview, you should clarify that whether String can contain numbers, special characters or not
 e.g. anything other than vowels and consonants.


 8) How to count occurrence of a given character in String?
 If interviewer ask you to count occurrence of more than one character than you can either use an array, hash table or any additional data structure.
 In order to solve this problem, you are not allowed to do so.
 Your method must return count of given character,
 for example if input String is "Java" and given character is 'a' then it should return 2.
 Bonus point if you handle case, null and empty String and come up with unit tests.


 9) How to convert numeric String to an int?
 A classical coding interview question based upon String.
 You need to write a method like atoi() from C/C++, which takes a numeric String and return its int equivalent.
 For example, if you pass "67263" to the program then it should return 67263. Make sure your  is robust
 i.e. it should be able to handle + and - character, null and empty String, integer overflow and other corner cases.
 Bonus points if you come up with good unit test cases.
 By the way, if your interviewer doesn't mention to you about atoi() then you can also use Java API's parseInt() or valueOf() method to solve this problem.


 10) How to replace each given character to other e.g. blank with %20?
 Write a Java program to replace a given character in a String to other provided character,
 for example if you are asked to replace each blank in a String with %20, similar to URL encoding done by the browser,
 so that Server can read all request parameters. For example if the input is "Java is Great" and asked to replace space with %20 then it should be "Java%20is%20Great".


 11) How to find all permutations of String?
 It has a easy recursive  but thinks get really tricky when Interviewer ask you to solve this question without using recursion.
 You can use Stack though. Write a program to print all permutations of a String in Java,
 for example, the if input is "xyz" then it should print "xyz", "yzx", "zxy", "xzy", "yxz", "zyx".


 12) How to reverse words in a sentence without using library method?
 Write a function, which takes a String word and returns sentence on which words are reversed in order
 e.g. if an input is "Java is best programming language", the output should be "language programming best is Java".


 13) How to check if String is Palindrome?
 Another easy coding question based upon String, I am sure you must have done this numerous time.
 Your program should return true if String is Palindrome, otherwise false.
 For example, if the input is "radar", the output should be true, if input is "madam" output will be true, and if input is "Java" output should be false.


 14) How to remove duplicate characters from String?
 You need to remove duplicate characters from a given string keeping only the first occurrences.
 For example, if the input is ‘bananas’ the output will be ‘bans’.
 Pay attention to what output could be, because if you look closely original order of characters are retained the in output.
 This is where many developer make the a mistake of shorting character array of String and removing duplicates, similar to how you remove duplicates from array.
 That destroys original order of characters and will not be correct  in this case.



 15) How to check if a String is valid shuffle of two String?
 One more difficult String algorithm based coding question for senior developers.
 You are given 3 strings: first,  second, and  third.
 third String is said to be a shuffle of first and second if it can be formed by interleaving the characters of first and second String in a way that maintains the left to right ordering of the characters from each string. For example, given first = "abc" and second = "def",  third = "dabecf"  is a valid shuffle since it preserves the character ordering of the two strings.
 So, given these 3 strings write a function that detects whether third String is a valid shuffle of first and second String.


 16) Write a program to check if a String contains another String e.g. indexOf()?
 You need to write a function to search for the existence of a string (target) in another string (source).
 The function takes two strings as the input and returns the index where the second string is found. If the target string cannot be found, then return -1.
 If you are a Java developer, then you can related its behavior to indexOf() method from java.lang.String class.
 This question is also asked as Code and algorithm to check if a given short string is a substring of a main string. Can you get a linear  (O(n)) if possible?


 17) How  to return highest occurred character in a String?
 You need to write a function to implement an algorithm which will accept a string of characters and should find the highest occurrence of the character and display it.
 For example if input is "aaaaaaaaaaaaaaaaabbbbcddddeeeeee" it should return "a".


 18) Write a program to remove a given characters from String?
 One of my favorite coding question, when I interview Java developers.
 You need to write a Java method which will accept a String and a character to be removed and return a String, which doesn't has that character
 e.g remove(String word, char ch).
 You need to provide both iterative and recursive  of this method and also has to write JUnit tests to cover cases like null and empty String,
 input which only contains letter to be removed, String which doesn't contain given character etc.


 19) Write a program to find longest palindrome in a string?
 This is one of the tough coding question based upon String.
 It's hard to think about an algorithm to solve this problem until you have practiced good.
 What makes it more difficult is the constraint that your  has O(n) time complexity and O(1) space complexity.


 20) How to sort String on their length in Java?
 Write a Program to sort String on their length in Java?
 Your method should accept  an array of String and return a sorted array based upon the length of String. Don't forget to write unit tests for your .
 ============================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1. Print duplicate characters from String*/
#if 0
int static cnt;
char* duplicate(char *str, int n) {
	int var, i = 0;
	static char arr[100];
	while (*str != '\0') {
		for (var = 1; var < n; var++) {
			if (*str == *(str + var)) {
				arr[i] = *str;
				i++;
				cnt++;
				break;
			}
		}
		str++;
	}
	return arr;
}

int main(void) {
	char *str = "combination";
	char *p;
	int len, var;
	len = strlen(str);
	printf("%d\r\n", len);

	p = duplicate(str, len);
	printf("%d\r\n",cnt);
	if (cnt != 0) {
		for (var = 0; var < cnt; var++) {
			printf("%c ", p[var]);
		}
	} else
	printf("no duplicate word in string");
	return EXIT_SUCCESS;
}
#endif

/*2. Anargram string : same count,same exact letters, ignoring space, punctuation and capitalization*/
#if 0
int main() {
	char *str1 = "stop";
	char *str2 = "tops";
	static int j = 0, k = 0, cnt;
	char arr[strlen(str1)];

	if (strlen(str1) == strlen(str2)) {
		while (*str1 != '\0' && *str2 != '\0') {
			if (*str1 == *(str2)) {
				str1++;
				str2++;
			} else {
				arr[j] = *str2;
				str2++;
				j++;
			}
		}
		while (*str1 != '\0' && *str2 == '\0') {
			for (k = 0; k < j; k++) {
				if (*str1 == arr[k])
				str1++;
			}
		}
		if (*str1 != '\0' && *str2 == '\0' && k == j) {
			cnt = 0;
		} else
		cnt = 1;
	} else
	cnt = 0;
	if (cnt == 0)
	printf("string - 1 is not anargram");
	else
	printf("string - 1 is anargram");

	return 0;
}
#endif

/*3. C program to find first non-repeating character*/
#if 0
int *count_of_char(char *str) {
	int i;
	int *count = (int*) calloc(256, sizeof(int));
	for (i = 0; *(str + i); i++)
	count[*(str + i)]++;
	return count;
}

int main() {
	int i;
	char *str = "PPriyadarshini";
	int *count = count_of_char(str);
	for (i = 0; *(str + i); i++) {
		if (count[*(str + i)] == 1) {
			printf("%c", *(str + i));
			break;
		}
	}
	free(count);
	return 0;
}
#endif

#if 0
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char *FirstUnrepeatedCharacter(char* input1) {
	int i;
	int *count = (int*) calloc(256, sizeof(int));
	for (i = 0; *(input1 + i); i++)
		count[*(input1 + i)]++;
	for (i = 0; *(input1 + i); i++) {
		if (count[*(input1 + i)] == 1) {

			*(input1 + i + 1) = '\0';
			return (input1 + i);
		}
	}
}
int main() {
	char* output = NULL;
	char* ip1;
	ip1 = (char *) malloc(512000 * sizeof(char));
	scanf("\n%[^\n]", ip1);
	output = FirstUnrepeatedCharacter(ip1);
	printf("%s\n", output);
	return 0;
}
#endif

/*4) How to reverse String in C using Iteration and Recursion?
 Your task is to write a program to reverse String in C without using header function.
 You also need to provide both iterative and recursive algorithm for String reversal.*/
#if 0
void reverse_string(char *str) {
	char ch;
	if (*str != '\0') {
		ch = *str;
		str++;
		reverse_string(str);
		printf("%c", ch);
	}
	return;
}

int main() {
	char *str = "PPriyadarshini";
	char *str1 = malloc(sizeof(str));

#if 1	looping
	int len = strlen(str);
	while (*str != '\0') {
		*(str1 + len - 1) = *str;
		str++;
		len--;
	}
#endif

#if 0	Iterative
	int i;
	(str1+strlen(str))='\0';
	for(i=strlen(str);i>= 0; i--) {
		*(str1+i-1) = *str;
		str++;
	}
#endif

	printf("%s", str1);

#if 0	recursive
	reverse_string(str);
#endif
	return 0;
}
#endif

/*5) How to check if a String contains only digits?
 You need to write a program to check a String contains only numbers by using Regular expression in C.*/
#if 0
int main() {
	char *str = "12345";
	static int cnt;
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9') {
			cnt = 0;
			str++;
		} else {
			cnt = 1;
			break;
		}
	}
	if (cnt == 1)
	printf("string contain other than numbers too");
	else
	printf("string only contains number");
	return 0;
}
#endif

 /*6) How to find duplicate characters in a String?
 You need to write a program to print all duplicate character and their count in C.
 For example if given String is "Programming" then your program should print
 g : 2
 r : 2
 m : 2*/
#if 0
void get_repeat_char(char *str) {
	int *count = (int*) calloc(256, sizeof(int));
	int i;
	for (i = 0; *(str + i); i++) {
		count[*(str + i)]++;
	}
	for (i = 0; i < 256; i++)
	if (count[i] > 1)
	printf("%c - %d \r\n", i, count[i]);

	free(count);
}
int main() {
	char *str = "Programming";
	get_repeat_char(str);

	return 0;
}
#endif

/*7) How to count number of vowels and consonants in a String?
 For example the if input is "Java" then your program should print "2 vowels and 2 consonants".
 If you get this question on Interview, you should clarify that whether String can contain numbers, special characters or not*/

#if 0
int main() {
	char *str = "Programming";
	static int vowels,consonants;
	while(*str != '\0') {
		if((*str == 'a') ||(*str == 'e')||(*str == 'i')||(*str == 'o')||(*str == 'u')||(*str == 'A') ||(*str == 'E')||(*str == 'I')||(*str == 'O')||(*str == 'U')) {
			vowels++;
		} else if (((*str >= 'a') && (*str <= 'z'))|| ((*str >= 'A') && (*str <= 'Z'))) {
			consonants++;
		}
		str++;
	}
	printf("String contains %d vowels and %d consonants",vowels,consonants);

	return 0;
}
#endif

/*8) How to count occurrence of a given character in String?
 If interviewer ask you to count occurrence of more than one character than you can either use an array, hash table or any additional data structure.
 In order to solve this problem, you are not allowed to do so.
 Your method must return count of given character,
 for example if input String is "Java" and given character is 'a' then it should return 2.
 Bonus point if you handle case, null and empty String and come up with unit tests.*/

#if 0
void get_count(char *str, char ch) {
	int *count = (int *) calloc(256, sizeof(int));
	int i;
	for (i = 0; *(str + i); i++) {
		count[*(str + i)]++;
	}
	for (i = 0; i < 256; i++) {
		if (*(str + i) == ch) {
			printf("%d", count[*(str + i)]);
			break;
		}
	}
	free(count);
}
int main() {
	char *str = "asdfffffthgbk";
	int ch = 'f';
	get_count(str, ch);
	return 0;
}
#endif

/*9) How to convert numeric String to an int?
 You need to write a method like atoi() from C/C++, which takes a numeric String and return its int equivalent.
 i.e. it should be able to handle + and - character, null and empty String, integer overflow and other corner cases.*/

#if 1
#define ROW 10
#define COLOUM 10
int main() {
	int *str = "123456789";

	return 0;
}
#endif
