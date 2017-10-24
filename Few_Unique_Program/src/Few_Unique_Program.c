/*
 ============================================================================
 Name        : Few_Unique_Program.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	if (sizeof(int) > -1)
		printf("True");
	else
		printf("False");
	return 0;
}
Result : False

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *p = "Sanfoundry C-Test";
	p[0] = 'a';
	p[1] = 'b';
	printf("%s", p);
	return 0;
}
Result : segmemntation fault



#include <stdio.h>
int main(void) {
	double f = 0.1;
	if (f == 0.1)
		printf("True");
	else
		printf("False");
	return 0;
}
Reult: true


#include <stdio.h>
int main(void) {
	float f = 0.1;
	if (f == 0.1)
		printf("True");
	else
		printf("False");
	return 0;
}
Reult: False


#include <stdio.h>
int main(void) {
	double f = 0.1;
	if (f == (float) 0.1)
		printf("True");
	else
		printf("False");
	return 0;
}
Reult: True


#include <stdio.h>
int main() {
	int n = 0, m = 0;
	if (n > 0)
		if (m > 0)
			printf("True");
		else
			printf("False");
	return 0;
}
Reult: Nothing will display
#endif

#include<stdio.h>
int main(){
int a=5,b=10,c=15;
int *arr[]={&a,&b,&c};
printf("%d",*arr[1]);
return 0;


}
