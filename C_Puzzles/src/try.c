/* Write your own memcpy()*/
#include <stdio.h>
#include <string.h>
void Mem_Copy(void *des, void* src, int Size) {
	char *csrc = (char *) src;
	int var;
	char *cdest = (char *) des;
	for (var = 0; var < Size; var++) {
		cdest[var] = csrc[var];
	}
	cdest[var] = '\0';
}
int main() {
	char ch[100] = "PriyadarshiniSinghSolanki";
	char des[100];
	int Size = strlen(ch);
	printf("%d", Size);
	Mem_Copy(&des, &ch, Size);
	printf("\n%s", des);

	int isrc[] = { 10, 20, 30, 40, 50 };
	int n = sizeof(isrc) / sizeof(isrc[0]);
	int idest[n], i;
	Mem_Copy(idest, isrc, sizeof(isrc));
	printf("\nCopied array is ");
	for (i = 0; i < n; i++)
		printf("%d ", idest[i]);
	return 0;
}

