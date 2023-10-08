#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class cal
{
public:
    int num1, num2;
    char ope;
    void calculate(int x, int y, char z)
    {
        float result;
        num1 = x;
        num2 = y;
        ope = z;
        switch (ope)
        {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            }
            else
            {
                cout << "Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation \n Please enter among +, -, *, or /." << endl;
        }
    }
};
class scientific_cal : public cal
{
public:
    float a;
    int z;
    void Sine(float);
    void Square(float);
    void Cos(float);
    void Tan(float);
    void Log(float);
    void Baselog(float);
    void sci_calc(float m, int n)
    {
        a = m;
        z = n;
        switch (z)
        {
        case 1:
            cout << "Enter the Number for Calculating SIN: " << endl;
            cin >> a;
            Sine(a);
            break;

        case 2:
            cout << "Enter the Number for Calculating Square: " << endl;
            cin >> a;
            Square(a);
            break;

        case 3:
            cout << "Enter the Number for Calculating COS: " << endl;
            cin >> a;
            Cos(a);
            break;

        case 4:
            cout << "Enter the Number for Calculating TAN: " << endl;
            cin >> a;
            Tan(a);
            break;

        case 5:
            cout << "Enter the Number for Calculating LOG: " << endl;
            cin >> a;
            Log(a);
            break;

        case 6:
            cout << "Enter the Number for Calculating LOG WITH BASE 10: " << endl;
            cin >> a;
            Baselog(a);
            break;
        }
    }
};
void scientific_cal ::Sine(float x)
{
    float s;
    s = sin(x);
    cout << "Sin: " << s;
}
void scientific_cal ::Square(float x)
{
    float sq;
    sq = sqrt(x);
    cout << "Square of a Given Value is: " << sq;
}
void scientific_cal ::Cos(float x)
{
    float c;
    c = cos(x);
    cout << "COS: " << c;
}
void scientific_cal ::Tan(float x)
{
    float t;
    t = tan(x);
    cout << "TAN: " << t;
}
void scientific_cal ::Log(float x)
{
    float l;
    l = log(x);
    cout << "Natural Logarithm: " << l;
}
void scientific_cal ::Baselog(float x)
{
    float bl;
    bl = log10(x);
    cout << "LOG with Base 10: " << bl;
}
int main()
{
    scientific_cal xp;
    int x;
    cout << "what kind of operation you want to do ?\nif you want to do normal calvculation enter 1 \notherwise enter 2 for scientific calculation\nEnter here : ";
    cin >> x;
    if (x == 1)
    {
        int n1, n2;
        char operation;
        cout << "Enter the first number: ";
        cin >> n1;
        cout << "Enter an operation among\n+ for addition,\n- for subtraction,\n* for multiplication,\n/ for division\nenter here: ";
        cin >> operation;
        cout << "Enter the second number: ";
        cin >> n2;
        xp.calculate(n1, n2, operation);
    }
    else if (x == 2)
    {
        float num0;
        int sci_ope;
        cout << "WHAT YOU WANT TO FIND: " << endl;
        cout << " Press '1' for Sin: " << endl;
        cout << " Press '2' for Square: " << endl;
        cout << " Press '3' for Cos: " << endl;
        cout << " Press '4' for Tan: " << endl;
        cout << " Press '5' for Log: " << endl;
        cout << " Press '6' for Base Log: " << endl;
        cin >> sci_ope;
        xp.sci_calc(num0, sci_ope);
    }
    else
        cout << "Please enter an valid option,, 1 or 2 !!" << endl;
}
