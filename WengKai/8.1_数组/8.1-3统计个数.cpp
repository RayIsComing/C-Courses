#include<stdio.h>
int main(void)
{
    const int NUMBER = 10;
    int x;
    int count[NUMBER];
    int i;
    for (i=0;i<NUMBER;i++)
    {
        count[i] = 0;
    }
    scanf("%d",&x);
    while (x!= -1)
    {
        if (x>=0 && x<=9) {
            count[x]++;
            }
        scanf("%d",&x);    
    }
    for(i=0;i<NUMBER;i++)
    {
        printf("%d:%d\n",i,count[i]);
    }
 return 0; 
}
