//Do while ������һ�Σ�while ����һ�ζ�����

#include<stdio.h> 
int main(){
	int n;
	int x;
	scanf("%d/n",&x) ;
	do{
		x /= 10;
		n++;
	}while(x>0);
	printf("%d",n);
}
