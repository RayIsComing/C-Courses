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
    //�����������ֲ�������x=3;y=0
    cout << A.ValueX() << endl;//���ؾֲ�����x��ֵ��
    A.ValueX(5);
    //�ֲ�����x=5; 
    cout << A.ValueX();//���ؾֲ�����x��ֵ 
    return 0;
}
