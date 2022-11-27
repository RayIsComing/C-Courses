#include<iostream>
using namespace std;

void func(int& ref)
{
    ref = 100;//ref是引用，转换为*ref=100
}

int main()
{
    int a = 10;

    //自动转换为 int* const ref = &a;
    //指针变量是指针指向不可改，也说明为什么引用不可以改
    int& ref = a;//自动转换为 int* const ref = &a;
    ref = 20;//自动转换为：*ref = 20；
    cout << "a = "<< a << endl;
    cout << "ref = "<< ref << endl;
    
    func(a);
    cout << "a = "<< a << endl;
    cout << "ref = "<< ref << endl;

    return 0;
}
