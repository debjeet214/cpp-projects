#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

class bank_account
{
    int account_num;
    char name[50];
    char type;
    int money_deposit;

public:
    int retacno() const
    {
        return account_num;
    }
    void create_account()
    {
        system("cls");
        cout << "\t Enter the Account number :";
        cin >> account_num;
        cout << "\t Enter the name of the account holder : ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "\t Enter the type of the account (C/S): ";
        cin >> type;
        type = toupper(type);
        cout << "\t Enter the initial amount (>=500 for current & >=1000 for savings): ";
        cin >> money_deposit;
        cout << "\t Account is created !!";
        cout << endl;
    }
    void display_account()
    {
        cout << "\t Bank account Number : " << account_num << endl;
        cout << "\t Account holder name : " << name << endl;
        cout << "\t Type of account : " << type << endl;
        cout << "\t Balance amount : " << money_deposit << endl;
    }

    void report() const
    {
        cout << account_num << setw(10) << " " << name << setw(10) << type << setw(6) << money_deposit << endl;
    }

    void depo(int x)
    {
        money_deposit += x;
    }

    void draw(int x)
    {
        money_deposit -= x;
    }
    int retdeposit()
    {
        return money_deposit;
    }

    void modify()
    {
        cout << "\t account number :" << account_num << endl;
        cout << "\t modify account holder name :";
        cin.ignore();
        cin.getline(name, 60);
        cout << "\t modify type of account : ";
        cin >> type;
        type = toupper(type);
    }
};

void write_account();
void display_detail(int x);
void delete_account(int y);
void display_all();
void money_deposit_withdrawl(int, int);
void update_account(int);

int main()
{
    char ch;
    int num;

    cout << "\t\t......................................." << endl;
    cout << "\t\t |                                   |" << endl;
    cout << "\t\t | WELCOME TO BANK MANAGEMNET SYSTEM |" << endl;
    cout << "\t\t |                                   |" << endl;
    cout << "\t\t......................................." << endl;
    cout << endl;
    ch = 9;
    do
    {
        cout << endl;
        cout << endl;
        cout << "\t 1. Create account " << endl;         // done
        cout << "\t 2. Deposit Money" << endl;           // done
        cout << "\t 3. Withdraw Money" << endl;          // done
        cout << "\t 4. Balance Enquiry" << endl;         // done
        cout << "\t 5. All account holder list" << endl; // done
        cout << "\t 6. Close an account" << endl;        // done
        cout << "\t 7. Modify the account" << endl;
        cout << "\t 8. Exit" << endl; // done
        cout << endl;

        cout << "enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case '1': // create account
            write_account();
            break;

        case '2': // deposit money
            system("cls");
            cout << "enter the account number : ";
            cin >> num;
            void money_deposit_withdrawl(num, 1);
            break;

        case '3': // withdraw function
            system("cls");
            cout << "\t Enter the account number : ";
            cin >> num;
            void money_deposit_withdrawl(num, 2);
            break;

        case '4': // balance enquiry function
            system("cls");
            cout << "Enter the account number : ";
            cin >> num;
            display_detail(num);
            break;

        case '5': // display all holders
            display_all();
            break;

        case '6': // close account
            system("cls");
            cout << "Enter the account number : ";
            cin >> num;
            delete_account(num);
            break;

        case '7': // modify account details
            system("cls");
            cout << "Enter the account number : ";
            cin >> num;
            update_account(num);
            break;

        case '8':
            cout << "\t Thanks for using our bank management system" << endl;
            break;
        }
        cin.ignore();
        cin.get();
        // bank_account one;
        // one.create_account();
        // cout<<endl;
        // one.display_account();
    } while (ch != '8');
    return 0;
}

void write_account()
{
    bank_account ac;
    ofstream outfile;
    outfile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char *>(&ac), sizeof(bank_account));
    outfile.close();
}

void delete_account(int n)
{
    bank_account ac;
    ifstream infile;  // input file stream
    ofstream outfile; // input file stream
    infile.open("account.dat", ios::binary);
    if (!infile)
    {
        cout << "file could not be opened || press other key";
        return;
    }
    infile.open("temp.dat", ios::binary);
    infile.seekg(0, ios::beg);

    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(bank_account)))
    {
        if (ac.retacno() != n)
        {
            outfile.write(reinterpret_cast<char *>(&ac), sizeof(bank_account));
        }
    }
    infile.close();
    outfile.close();
    remove("bank_account.dat");
    rename("temp.dat", "bank_account.dat");
    cout << "\t record deleted........" << endl;
}

void display_detail(int n)
{
    bank_account ac;
    bool flag = false;
    ifstream infile;
    infile.open("account.dat", ios::binary);
    if (!infile)
    {
        cout << "file could not be opened || press other key";
        return;
    }
    cout << "\t bank account details :" << endl;
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(bank_account)))
    {
        if (ac.retacno() == n)
        {
            ac.display_account();
            flag = true;
        }
    }
    infile.close();
    if (flag == false)
    {
        cout << "/t account number does not exist" << endl;
    }
}

void display_all()
{
    system("cls");
    bank_account ac;
    ifstream infile;
    infile.open("account.dat", ios::binary);
    if (!infile)
    {
        cout << "file could not be opened || press other key";
        return;
    }
    cout << "\t bank account holders are :" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "A/C no.      NAME      TYPE      BALANCE" << endl;
    cout << "========================================" << endl;
    while (infile.read(reinterpret_cast<char *>(&ac), sizeof(bank_account)))
    {
        ac.report();
    }
    infile.close();
}

void money_deposit_withdrawl(int n, int option)
{
    int amt;
    bool found = false;
    bank_account ac;
    fstream file;
    file.open("account.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "file could not be opened || press other key";
        return;
    }
    while (!file.eof && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(bank_account));
        if (ac.retacno() == n)
        {
            ac.display_account();
            if (option == 1)
            {
                cout << "enter the amount to be deposited : ";
                cin >> amt;
                ac.depo(amt);
            }
            if (option == 2)
            {
                cout << "enter the amount to be withdrawn : ";
                cin >> amt;
                int balance = ac.retdeposit() - amt;
                if (balance < amt)
                {
                    cout << "\t insufficient balance" << endl;
                }
                else
                {
                    ac.draw(amt);
                }
            }
            int pos = (-1) * static_cast<int>(sizeof(bank_account));
            file.seekp(pos, ios::cur); // move the pointeer to the position of the file
            file.write(reinterpret_cast<char *>(&ac), sizeof(bank_account));
            cout << "\t recordv updated" << endl;
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << "\t record not found" << endl;
    }
}

void update_account(int n)
{
    bool found = false;
    bank_account ac;
    fstream file;
    file.open("account.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "file could not be opened || press other key";
        return;
    }
    while (!file.eof && found == false)
    {
        file.read(reinterpret_cast<char *>(&ac), sizeof(bank_account));
        if (ac.retacno() == n)
        {
            ac.display_account();
            cout << "\t enter the new details you want to update :" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(bank_account));
            file.seekp(pos, ios::cur); // move the pointeer to the position of the file
            file.write(reinterpret_cast<char *>(&ac), sizeof(bank_account));
            cout << "\t record updated" << endl;
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        cout << "\t record not found" << endl;
    }
}
