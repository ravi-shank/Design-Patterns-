#include<iostream>
using namespace std;


class IParser
{
    public:
        virtual void parser()=0;
        virtual void dispdata()=0;
};

class CParser: public IParser
{

public:
    void parser()
    {
        cout<<"Legacy Parser"<< endl;
    }
    void  dispdata()
    {
        cout<<"Legacy display data"<< endl;
    }
};

class INewParser
{
    public:
       virtual void newParser()=0;
       virtual void newDispdata()=0;
};

class CNewParser: public INewParser
{

public:
    void newParser()
    {
        cout<<"New Parser"<< endl;
    }
    void  newDispdata()
    {
        cout<<"New display data"<< endl;
    }
};

class CAdapter: public IParser
{

  private:
       INewParser * newParseObj;

    public:
        CAdapter()
        {
            newParseObj= new CNewParser();
        }

        void parser()
        {
            cout<< "Adapter Parser" << endl;
            newParseObj->newParser();
        }
        void dispdata()
        {
            newParseObj->newDispdata();
        }
};

int main()
{
    IParser * parser = new CAdapter();
    parser->parser();
    parser->dispdata();
}



