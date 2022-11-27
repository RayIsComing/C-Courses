#include<iostream>
using namespace std;

//function declare.
void SwapFunc(int *Input_a, int *Input_b);

int main(){

    int a = 10;
    int b = 20;
    SwapFunc(&a,&b);

    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;

    // cout << "Input_a = "<<*Input_a << endl;
    // cout << "Input_b = "<<*Input_b << endl;
    //这个地方不能用的原因：作用域的问题。
}

//function define;

void SwapFunc(int *Input_a, int *Input_b)
{
    int temp;

    temp = *Input_a;
    *Input_a = *Input_b;
    *Input_b = temp;

    cout << "Input_a = "<<*Input_a << endl;
    cout << "Input_b = "<<*Input_b << endl;

};
