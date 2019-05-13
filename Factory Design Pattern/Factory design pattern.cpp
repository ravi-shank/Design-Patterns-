#include<iostream>
using namespace std;

// Abstract class: Vehicle
class Vehicle
{
public:
        virtual void PrintVehicle()=0;
        static Vehicle* CreateVehicle(int type);
        virtual ~ Vehicle()
        {
            cout<<"Vehicle destructed"<< endl;
        }
};


class TwoWheeler: public Vehicle
{
    public:
        void PrintVehicle()
        {
            cout<<"From TwoWheeler"<< endl;
        }
    ~TwoWheeler()
    {
        cout<<"TwoWheeler destructed"<< endl;
    }
};

class ThreeWheeler: public Vehicle
{
    public:
        void PrintVehicle()
        {
            cout<<"From ThreeWheeler"<< endl;
        }
     ~ThreeWheeler()
    {
        cout<<"ThreeWheeler destructed"<< endl;
    }
};


class FourWheeler: public Vehicle
{
    public:
        void PrintVehicle()
        {
            cout<<"From FourWheeler"<< endl;
        }
     ~FourWheeler()
    {
        cout<<"FourWheeler destructed"<< endl;
    }
};

Vehicle* Vehicle:: CreateVehicle(int type)
{
    if(type==2)
        return new TwoWheeler();
    else if(type==3)
        return new ThreeWheeler();
    else if(type==4)
        return new FourWheeler();
    else
        return NULL;
}

class Client
{
    private:
        Vehicle *pVehicle;
    public:
        Client()
        {
            int type;
            cout<<"Enter vehicle type: ";
            cin>>type;
            while(type!= 2 && type!= 3 && type!=4)
            {
                cout<<"Enter vehicle type: ";
                cin>>type;
            }

            pVehicle= Vehicle::CreateVehicle(type);
        }

        ~Client()
        {
            cout<<"Client destructed"<< endl;
            if(pVehicle)
                delete pVehicle;

            pVehicle= NULL; // to take care of dangling pointer issue
        }
        Vehicle* GetVehicle()
            {
                return pVehicle;
            }
};


int main()
{
    // creating new client object
    Client *pClient = new Client();

    // getting Vehicle object based on type selected by user
    Vehicle* pVehicle = pClient->GetVehicle();

    // doing some work with that object
    pVehicle->PrintVehicle();

    delete pClient;
    cout<<"Prog Finished" << endl;
}
