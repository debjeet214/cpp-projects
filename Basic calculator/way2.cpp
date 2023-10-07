#include <iostream>
using namespace std;
class cal{
    public:
    int num1, num2;
     char ope;
    void calculate(int x, int y, char z){
        float result;
        num1 = x;
        num2 = y;
        ope = z;
    switch (ope){
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
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation \n Please enter among +, -, *, or /." << endl;
    }
    }
};
int main(){
    int n1, n2;
    char operation;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter an operation among + for addition, - for subtraction, * for multiplication, / for division : ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> n2;
    cal xp;
    xp.calculate(n1,n2,operation);
}
