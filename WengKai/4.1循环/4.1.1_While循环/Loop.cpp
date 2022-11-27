// 通过循环进行数字位数的判定。

#include<stdio.h>
/*********************
*起码是1位数，进行第一次判定，n++一次；
* 当x计算一次还是大于0，则持续进入while循环。 
**********************/ 
int main(){
	const int fenmu=10;
	int x;
	int n=0;
	scanf("%d",&x);
	n++;
	x/=fenmu; 
	while(x>0){
		n++;
		x/=fenmu;
	}
	printf("%d\n",n);	
	return 0;	
}

