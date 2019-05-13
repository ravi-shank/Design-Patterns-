#include<iostream>
using namespace std;

class Singleton
{

    public:
        static Singleton* instance;
        static Singleton* getInstance();
        void disp();
    private:
        Singleton(){}
};

Singleton*  Singleton :: instance = NULL;

Singleton* Singleton::getInstance()
{
    if(instance==NULL)
        instance = new Singleton();
    return instance;
}

void Singleton::disp()
{
    cout<<"Inside disp"<<endl;
}


int main()
{
    Singleton *inst = Singleton::getInstance();
    Singleton *inst2 = Singleton::getInstance();
    inst->disp();
    inst2->disp();
    if(inst==inst2)
        cout<<"SAME INSTANCE RECEIVED"<< endl;
    else
        cout<<"DIFFERENT INSTANCE RECEIVED"<< endl;

}

