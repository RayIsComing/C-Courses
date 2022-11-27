#include<iostream>
using namespace std;

//澶氭€侊紱

//鍔ㄧ墿绫�
class Animal
{
public:
    //铏氬嚱鏁帮細virtual鍏抽敭瀛椼€�
    virtual void Speak(){
        cout <<"鍔ㄧ墿鍦ㄨ璇�" <<endl;
    }
};

//鐚被
class Cat :public Animal
{
private:
    /* data */
public:

    void Speak(){
        cout <<"灏忕尗鍦ㄨ璇�" <<endl;
    }
};

//鎵ц璇磋瘽鍑芥暟
//鍦板潃鏃╃粦瀹氾紝缂栬瘧闃舵灏辩‘瀹氫簡缂栬瘧鍦板潃銆�
//濡傛灉鎯虫墽琛岃鐚璇濓紝閭ｄ箞
void doSpeak(Animal &animal){
    animal.Speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);
}


int main(){

    test01();
    system("pause");

    return 0;
}