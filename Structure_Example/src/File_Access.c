/*
 * File_Access.c
 *
 *  Created on: 13-Sep-2017
 *      Author: Sys-5304
 */

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
FILE *fp1;
fp1 = fopen("file.txt","a+");
if(fp1 == NULL){
	printf("unable to open file - error\r\n");
	exit(1);
}
char *ptr = "Hello File";
fprintf(fp1,"%s",ptr);
fseek(fp1,0L,SEEK_SET);
fseek(fp1,0L,SEEK_END);
fseek(fp1,-10L,SEEK_CUR);
int n = ftell(fp1);
printf("%d\r\n",n);
	return 0;
}
#endif
#if 0
int main(){
	FILE *fp;
	char ch;
	int n;
    fp=fopen("file.txt", "r");
    if(fp==NULL)
		printf("file cannot be opened");
	else{
		printf("Enter value of n  to read last ‘n’ characters");
		fflush(stdout);
		scanf("%d",&n);
		fflush(stdin);
		fseek(fp,-n,2);
		while((ch=fgetc(fp))!=EOF){
			printf("%c\t",ch);
			fflush(stdout);
			}
		}
    fclose(fp);
return 0;
}
#endif
