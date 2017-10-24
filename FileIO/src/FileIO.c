/*
 ============================================================================
 Name        : FileIO.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 1. C program to copy the contents of one file into another using fputc
 2. C Program to read last n characters from the file !
 3. C program to convert the file contents in Upper-case & Write Contents in a output file
 4. C Program to Compare two text/data files in C Programming
 5. C Program to Write on Data File and Read From Data File
 6. C Program to Copy Text From One File to Other File
 7. How to display same source code as output in c programming?*
 ============================================================================
 */


/*1. C program to copy the contents of one file into another using fputc*/

#include <stdio.h>
#include <stdlib.h>
int main(void) {
	FILE *fp1, *fp2;
	fp1 = fopen("file.txt", "r");
	if (fp1 == NULL) {
		printf("unable to open file");
		exit(1);
	}
	fp2 = fopen("file1.txt", "a");
	if (fp1 == NULL) {
		printf("unable to open file1");
		exit(1);
	}
	char c;

	while ((c = fgetc(fp1)) != EOF) {
		fputc(c, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
#if 0
/*2. C Program to read last n characters from the file !*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp1;
	int n = 10;
	char ch;
	fp1 = fopen("file.txt", "r");
	if (fp1 == NULL) {
		puts("cannot open this file");
		exit(1);
	}
	fseek(fp1, 0, SEEK_END);
	int pos = ftell(fp1);
	int place = pos - n;
	fseek(fp1, place, SEEK_SET);
	fseek(fp1, 0, SEEK_CUR);
	while ((ch = getc(fp1)) != EOF) {
		printf("%c", ch);
	}
	fclose(fp1);
	return 0;
}

/*3. C program to convert the file contents in Upper-case & Write Contents in a output file*/

#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *fp1, *fp2;
	char ch;
	fp1 = fopen("file.txt", "r");
	if (fp1 == NULL) {
		printf("unable to open file");
		exit(1);
	}
	fp2 = fopen("file1.txt", "w");
	if (fp2 == NULL) {
		printf("unable to open file");
		exit(1);
	}
	while ((ch = fgetc(fp1)) != EOF) {
		if ((ch >= 'a') && (ch <= 'z')) {
			ch = ch - 32;
		}
		printf("%c",ch);
		putc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

/*4. C Program to Compare two text/data files in C Programming*/

#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *fp1, *fp2;
	fp1 = fopen("file.txt", "r");

	if (fp1 == NULL) {
		printf("unable to open file");
		exit(1);
	}

	fp2 = fopen("file1.txt", "r");
	if (fp2 == NULL) {
		printf("unable to open file1");
		exit(1);
	}
	char ch, ch1;
	while (((ch = fgetc(fp1)) != EOF) && ((ch1 = fgetc(fp2)) != EOF)) {
		if (ch != ch1) {
			printf("both files are not similar");
			return 0;
		}
	}
	printf("both files are similar");
	fclose(fp1);
	fclose(fp2);
	return 0;
}

/*5. C Program to Write on Data File and Read From Data File*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
	FILE *fp1, *fp2;
	char ch;
	char ch1[50];

	/*Read From Data File*/
	fp1 = fopen("file.txt", "r");
	if (fp1 == NULL) {
		printf("unable to open file2");
		exit(1);
	}
	while ((ch = fgetc(fp1)) != EOF) {
		//printf("%c",ch);
		putchar(ch);
	}
	fclose(fp1);

	/*Write on Data File*/
	fp2 = fopen("file1.txt", "w");
	fgets(ch1, 50, stdin);
	printf("%s", ch1);
	fputs(ch1, fp2);
	fclose(fp2);

	return EXIT_SUCCESS;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main() {
	FILE *fp1;
	char ch;
	char ch1[50];

	Write on Data File
	fp1 = fopen("file1.txt", "a");
	fgets(ch1, 50, stdin);
	fputs(ch1, fp1);

	Read From Data File
	fp1 = fopen("file1.txt", "r");
	if (fp1 == NULL) {
		printf("unable to open file2");
		exit(1);
	}
	while ((ch = fgetc(fp1)) != EOF) {
		putchar(ch);
	}
	fclose(fp1);
	return EXIT_SUCCESS;
}*/

/*7. How to display same source code as output in c programming?*/
#include<stdio.h>
int main(){
   printf("%s",__FILE__);
   return 0;
}


int main() {
   FILE *fp;
   char ch;

   fp = fopen(__FILE__, "r");

   do {
      ch = getc(fp);
      putchar(ch);
   } while (ch != EOF);

   fclose(fp);
   return 0;
}
#endif
