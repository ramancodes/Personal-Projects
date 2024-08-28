// classes and objects
// constructors and destructors
// this operator

#include<iostream>
#include<iomanip>

using namespace std;

class details   //class
{
    string product;
    int quantity = 1;
    float rate;

    public:
        details(){} //default constructor

        details(string product, int quantity, float rate) // parameterised constructor
        {
            this->product = product;
            this->quantity = quantity;
            this->rate = rate;
        }

        details(details &obj) // copy constructor
        {
            product = obj.product;
            quantity = obj.quantity;
            rate = obj.rate;
        }

        void showDetails();
        void showFinalData();

        ~details(){}    // destructor
};

void details :: showDetails()
{
    cout<<"The entered details : "<<endl;
    cout<<setw(20)<<"Product"<<setw(10)<<"Quantity"<<setw(10)<<"Rate"<<endl;
    cout<<setw(20)<<product<<setw(10)<<quantity<<setw(10)<<rate<<endl;
}

void details :: showFinalData()
{
    cout<<"The Final Receipt : "<<endl;
    cout<<setw(20)<<"Product"<<setw(10)<<"Quantity"<<setw(10)<<"Total"<<endl;
    cout<<setw(20)<<product<<setw(10)<<quantity<<setw(10)<<(rate*quantity)<<endl;
}

int main()
{
    details obj, obj1;  // objects
    string product;
    int qty;
    float rate;

    cout<<"Enter the Produnct Name"<<endl;
    getline(cin, product);
    cout<<"Enter the Quantity of the Product"<<endl;
    cin>>qty;
    cout<<"Enter the Rate of the Product"<<endl;
    cin>>rate;

    obj = details(product, qty, rate);

    obj1 = details(obj);

    obj.showDetails();
    obj1.showFinalData();

    return 0;
}