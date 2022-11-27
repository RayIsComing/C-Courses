#include <iostream>

using namespace std;

const double PI = 3.14;

//define a constant PI.


class circle{

public:


    int m_r;
    //行为
    //计算圆的周长

    double CalculateZC(){

        double zc;
        zc = 2 * PI * m_r;
        return zc;
    }
};

int main(){
    //定义一个圆类的对象
    circle c1;
    //计算一个圆
    c1.m_r = 10;

    cout<<"The ZC of the C1 is :"<<c1.CalculateZC()<<endl;

    system("pause");
    

}
