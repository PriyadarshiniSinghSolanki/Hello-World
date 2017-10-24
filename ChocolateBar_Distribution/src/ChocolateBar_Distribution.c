/*
 ============================================================================
 Name        : ChocolateBar_Distribution.c
 Author      : Priyadarshini Singh Solanki
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<string.h>

int cadbury(int input1, int input2, int input3, int input4) {
	static int cnt;
	int i, j, k, l, temp;

	if (input1 == input3)
		cnt++;
	else if (input1 > input3) {
		cnt++;
		i = input1 - input3;
		if (i == input3)
			cnt++;
		else {
			if (i == 1)
				cnt += input3;
			else {
				if (input3 % i == 0)
					cnt = cnt + (input3 / i);
				else {
					if (input3 > i) {
						cnt++;
						temp = input3 - i;
						if (temp == 1)
							cnt += i;
					}
				}
			}
		}
	}
	if (input1 == input4)
		cnt++;
	else if (input1 > input4) {
		cnt++;
		j = input1 - input4;
		if (j == input4)
			cnt++;
		else {
			if (j == 1)
				cnt += input4;
			else {
				if (input4 % j == 0)
					cnt = cnt + (input4 / j);
				else {
					if (input4 > j) {
						cnt++;
						temp = input4 - j;
						if (temp == 1)
							cnt += j;
					}
				}
			}
		}

	}
	if (input2 == input3)
		cnt++;
	else if (input2 > input3) {
		cnt++;
		k = input2 - input3;
		if (k == input3)
			cnt++;
		else {
			if (k == 1)
				cnt += input3;
			else {
				if (input3 % k == 0)
					cnt = cnt + (input3 / k);
				else {
					if (input3 > k) {
						cnt++;
						temp = input3 - k;
						if (temp == 1)
							cnt += k;
					}
				}
			}
		}

	}
	if (input2 == input4)
		cnt++;
	else if (input2 > input4) {
		cnt++;
		l = input2 - input4;
		if (l == input4)
			cnt++;
		else {
			if (l == 1)
				cnt += input4;
			else {
				if (input4 % l == 0)
					cnt = cnt + (input4 / l);
				else {
					if (input4 > l) {
						cnt++;
						temp = input4 - l;
						if (temp == 1)
							cnt += l;
					}
				}
			}
		}
	}

	return cnt;
}

int main() {
	int c;
	c = cadbury(5, 6, 3, 4);
	printf("%d", c);
	return 0;

}

/*while (input1) {
	if ((input1 % input3) == 0)
	cnt += input1 / input3;
	else {
		while (input1 > input3) {
			input1 -= input3;
			cnt++;
		}
		if (input1 == 1)
		cnt += input3;
	}
}*/

