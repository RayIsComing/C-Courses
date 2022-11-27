#include <iostream>
using namespace std;
class Location
{
    private:
        int x, y;
    public:
        void init(int x=0, int y=0);
        void ValueX(int val){
            x = val;
        }
        int ValueX(){
            return x;
        }
};

void Location::init(int X,int Y){
    x = X;
    y = Y;

}

int main(){
    Location A, B;
    A.init(3);
    //生成了两个局部变量，x=3;y=0
    cout << A.ValueX() << endl;//返回局部变量x的值。
    A.ValueX(5);
    //局部变量x=5; 
    cout << A.ValueX();//返回局部变量x的值 
    return 0;
}
