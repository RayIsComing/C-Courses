#include<iostream>
using namespace std;

class CRectangle{
    public:
    int h,w;
    //���������˳�Ա����������
    int Area();
    int Perameter();
    int Init(int w_,int h_);
};

//������Ա�����Ķ���
CRectangle::Area(){
    return h*w;
}
CRectangle::Perameter(){
    return 2*(h+w);
}
CRectangle::(int w_, int h_){
    w = w_;
    h = h_;
}

int main(){
    

}