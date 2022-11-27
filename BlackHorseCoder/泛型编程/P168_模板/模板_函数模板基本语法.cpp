#include<iostream>
using namespace std;



//交换两个整形函数
void SwapInt(int &a, int &b){
    int temp =a;
    a=b;
    b = temp;
}

//交换两个浮点型函数
void SwapDouble(double &a, double &b){
    int temp =a;
    a=b;
    b = temp;
}


template<typename T>
//TODO 声明一个模板，告诉编译器后面代码几根的T不要不错，T是个通用类型，也是个虚拟类型，开始时是不确定的数据类型。
//紧跟后面的就是函数声明和定义,行程模板
void mySwap(T &x,T &y){
    T temp =x,
    x = y;
    y = temp;
}


int main(){
    int a =10;
    int b =20;
    // SwapInt(a,b);
    //利用函数模板交换；
    //两种方式进行交换；
    //1.自动类型推导
    mySwap(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    // double c=10.1;
    // double d=20.1;
    // SwapDouble(c,d);
    // cout<<"c = "<<c<<endl;
    // cout<<"d = "<<d<<endl;

    system("pause");

    return 0;
}
