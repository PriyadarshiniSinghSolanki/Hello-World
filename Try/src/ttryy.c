#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str1 = "helloheolhihelolhi";
	char *str2 = "hel";
	char *temp;
	temp = str2;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	static int cnt, b;

	while (len1) {
		while ((*temp != '\0') && (*str1 == *temp)) {
			str1++;
			len1--;
			temp++;
			cnt++;
		}
		if ((cnt == len2) && (*temp == '\0')) {
			b++;
		} else {
			str1++;
			len1--;
			cnt = 0;
		}

		cnt = 0;
		temp = str2;

	}
	printf("%d", b);
	return 0;
}
