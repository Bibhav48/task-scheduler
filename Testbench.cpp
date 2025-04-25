#include <fstream>
#include <iomanip>
#include <iostream>

#include "DHeap.h"

using namespace std;

int main() {
    DHeap heap(3);
    int choice;
    string filename = "tasks.csv";
    // Load tasks from CSV file if it exists
    // if file exists, load tasks
    ifstream file(filename);
    if (file.good()) {
        file.close();
        try {
            heap.loadFromCSV(filename);
            cout << "\nTasks loaded successfully from " << filename << ".\n";
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } else {
        file.close();
        cout << "\nWelcome to the Task Scheduler for the first time!\n";
    }

    while (true) {
        cout << "\n===== Task Scheduler =====\n";
        cout << "1. Add Task\n2. View Top Task\n3. Remove Top Task\n4. Delete Specific Task\n5. Display All Tasks\n6. Update\n7. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            Task task;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, task.name);  // Use getline to allow spaces in the task name
            cout << "Enter task description: ";
            getline(cin, task.description);
            cout << "Enter priority: ";
            cin >> task.priority;
            cout << "Enter deadline: ";
            cin >> task.deadline;
            heap.insert(task);
        } else if (choice == 2) {
            try {
                Task top = heap.getTop();
                cout << "Next Task: " << top.name << ", Priority: " << top.priority << ", Deadline: " << top.deadline << endl;
            } catch (runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (choice == 3) {
            heap.deleteTop();
            cout << "Top task removed.\n";
        } else if (choice == 4) {
            string taskName;
            cout << "Enter task name to delete: ";
            cin >> taskName;
            heap.deleteTask(taskName);
        } else if (choice == 5) {
            cout << "\nTasks:\n";
            cout << left << setw(35) << "Task Name" << setw(30) << "Description" << setw(10) << "Deadline" << setw(10) << "Priority" << endl;
            cout << string(85, '-') << endl;
            for (const auto& task : heap.getTasks()) {
                cout << left << setw(35) << task.name << setw(30) << task.description << setw(10) << task.deadline << setw(10) << task.priority << endl;
            }
        } else if (choice == 6) {
            string taskName;
            cout << "Enter task name to update: ";
            cin.ignore();
            getline(cin, taskName);
            Task task;
            cout << "Enter new description: ";
            getline(cin, task.description);
            cout << "Enter new priority: ";
            cin >> task.priority;
            cout << "Enter new deadline: ";
            cin >> task.deadline;
            task.name = taskName;
            heap.update(task);
            cout << "Task updated successfully.\n";
        } else if (choice == 7) {
            cout << "Saving tasks to CSV...\n";
            heap.saveToCSV("tasks.csv");
            cout << "Tasks saved successfully.\n";
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
