// ͨ��ѭ����������λ�����ж���

#include<stdio.h>
/*********************
*������1λ�������е�һ���ж���n++һ�Σ�
* ��x����һ�λ��Ǵ���0�����������whileѭ���� 
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

