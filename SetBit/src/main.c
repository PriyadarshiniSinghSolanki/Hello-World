
#include <stdio.h>
#define Set_Bit(Num,Bit,nos) (Num|=(nos<<Bit))
#define Mul(Num) Num*Num

int main() {
	int j = 0,i;
	Set_Bit(j, 5, 0x3F);
	i = Mul(4+1);
	printf("%x , %d", j,i);
	return 0;
}
