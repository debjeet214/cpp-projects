#include <iostream>
using namespace std;
int main(){
    int num1, num2;
    char operation;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter an operation among + for addition, - for subtraction, * for multiplication, / for division : ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> num2;
    float result;
    switch (operation){
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
    return 0;
}
