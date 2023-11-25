#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>
using namespace std;

class bank_account{
    int account_num ;
    char name[50];
    char type;
    int money_deposit;

    public:
        void create_account(){
            system("cls");
            cout<<"\t Enter the Mobile number :";
            cin>>account_num;
            cout<<"\t Enter the name of the account holder : ";
            cin.ignore();
            cin.getline(name,50);
            cout<<"\t Enter the type of the account (C/S): ";
            cin>>type;
            type = toupper(type);
            cout<<"\t Enter the initial amount (>=500 for current & >=1000 for savings): ";
            cin>>money_deposit;
            cout<<"\t Account is created !!";
            cout<<endl;
        }
        void display_account(){
            cout<<"\t Bank account Number : "<<account_num<<endl;
            cout<<"\t Account holder name : "<<name<<endl;
            cout<<"\t Type of account : "<<type<<endl;
            cout<<"\t Balance amount : "<<money_deposit<<endl;
        }

};

int main(){
    char ch;
    int num;

    cout<<"\t\t......................................."<<endl;
    cout<<"\t \t |                                   |"<<endl;
    cout<<"\t\t  | WELCOME TO BANK MANAGEMNET SYSTEM |"<<endl;
    cout<<"\t \t |                                   |"<<endl;
    cout<<"\t\t......................................."<<endl;
    cout<<endl;

    cout<<"\t --- Main Menu "<<endl;
    cout<<"\t 1. Create account "<<endl;
    cout<<"\t 2. Deposit Money"<<endl;
    cout<<"\t 3. Withdraw Money"<<endl;
    cout<<"\t 4. Balance Enquiry"<<endl;
    cout<<"\t 5. All account holder list"<<endl;
    cout<<"\t 6. Close an account"<<endl;
    cout<<"\t 7. Modify the account"<<endl;
    cout<<"\t 8. Exit"<<endl;
    cout<<endl;

    cout<<"enter your choice : ";
    cin>>ch;
    bank_account one;
    one.create_account();
    cout<<endl;
    one.display_account();
}
