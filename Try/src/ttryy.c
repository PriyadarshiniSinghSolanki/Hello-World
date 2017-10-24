


/*
Input : 5, 55
Output: 55,47,94,86,172
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
static void series (int n, int v);
static void series (int n, int v){
	v= v<<1;

	printf("%d",v);
}
int main() {

    int i, n,v;
    scanf("%d", &n);//5
    printf("\nEnter the start number: ");//55
    scanf("%d", &v);

    series(n,v);

    return 0;

}
