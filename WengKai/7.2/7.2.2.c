#include<stdio.h> 


void swap(int *x, int *y); 

int main()
{
	int a=7;
	int b=6;
	
	swap(&a,&b);//取地址 
	
	printf("a=%d b=%d",a,b);
	
	return 0;
}

void swap(int *x,int *y)// these veriables are only usable in its own erae. 
{
	int t; 
	t=*x;//解应用 
	*x=*y;
	*y=t;
}
