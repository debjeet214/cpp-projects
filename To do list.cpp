#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> toDoList;
void displayToDoList(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the to-do list." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}
void add(){
        string task;
        cout << "Enter a task: ";
        cin.ignore(); 
        getline(cin, task);
        toDoList.push_back(task);
        cout << "Task added!" << endl;
}
int main() {
    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Remove task" << endl;
        cout << "3. List tasks" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
            	add();
            	break;
            }
            case 2: {
                displayToDoList(toDoList);
                if (!toDoList.empty()) {
                    int taskNumber;
                    cout << "Enter the task number to remove: ";
                    cin >> taskNumber;
                    if (taskNumber >= 1 && taskNumber <= static_cast<int>(toDoList.size())) {
                        toDoList.erase(toDoList.begin() + taskNumber - 1);
                        cout << "Task removed!" << endl;
                    } else {
                        cout << "Invalid task number." << endl;
                    }
                }
                break;
            }
            case 3: {
                displayToDoList(toDoList);
                break;
            }
            case 4: {
                cout << "Exiting the to-do list program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}

