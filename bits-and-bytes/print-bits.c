#include <stdio.h>
int main(){
unsigned char a = 181;
char b = -75;

int i;
for(i=7;i>=0;i--){
	printf("%d", (a>>i)&0x01);
}
printf("\n");
int j;
for(j=7;j>=0;j--){
	printf("%d", (b>>j)&0x01);
}
printf("\n");
}