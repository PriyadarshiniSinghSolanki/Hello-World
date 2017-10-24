/*
 * strstr_with_pointer.c
 *
 *  Created on: 25-Jul-2017
 *      Author: Sys-5304
 */
#include <stdio.h>
#include <string.h>
int main() {
	char *str1 = "Priyadarshini Singh Solanki";
	char *str2 = "Sin";
	char *temp;
	temp = str2;
	int len = strlen(str2);

	for (; *str1 != '\0'; str1++) {
		int cnt = 0;
		while ((*str1 == *temp) && (*str1 != '\0')) {
			temp++;
			str1++;
			cnt++;

			if (cnt == len) {
				printf("%s", str1);
				return 0;
			}
		}
		if (*str1 == '\0')
			break;
		temp = str2;
	}
	printf("String not found");
	return 0;
}

#if 0
/*Number of string in string*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str1 = "HelloHeHi";
	char *str2 = "Hel";
	int len2 = strlen(str2);
	char *tempstr1 = str1;
	char *tempstr2 = str2;
	static int cnt, cnt1;
	int flag = 1;

	while (*tempstr1 != '\0') {
		while ((*tempstr1 == *tempstr2) && (*tempstr2 != '\0')) {
			tempstr1++;
			tempstr2++;
			cnt++;
			flag = 0;
		}
		if ((cnt == len2) && (flag == 0)) {
			cnt1++;
		}
		flag = 1;
		cnt = 0;

		tempstr1 = ++str1;
		tempstr2 = str2;
	}
	printf("%d",cnt1);

	return 0;
}

#endif
