#include<iostream>
#include<cmath>
using namespace std;

class simple_calculator {
    int a, b;
    public:
        void simple_data(){
            cout<<"Enter the value of a"<<endl;
            cin>>a;
            cout<<"Enter the value of b"<<endl;
            cin>>b;
        }
        void simple_ope(){
            cout<<"The value of a + b is: "<<a + b<<endl;
            cout<<"The value of a - b is: "<<a - b<<endl;
            cout<<"The value of a * b is: "<<a * b<<endl;
            cout<<"The value of a / b is: "<<a / b<<endl;
        }
};
class scientific_calculator{
    int a;
    public:
        void scientific_data(){
            cout << "Enter the value of a" << endl;
            cin>>a;
        }
        void scientific_ope(){ 
            cout << "The value of cos(a) is: " << cos(a) << endl;
            cout << "The value of sin(a) is: " << sin(a) << endl;
            cout << "The value of exp(a) is: " << exp(a) << endl;
            cout << "The value of tan(a) is: " << tan(a) << endl;
        }
};
class hybrid_cal : public simple_calculator, public scientific_calculator{
    public:
    int a;
};
int main(){
    hybrid_cal x;
    x.scientific_data();
    x.simple_data();
    x.scientific_ope();
    x.simple_ope();
}
