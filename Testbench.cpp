#include <iostream>

#include "DHeap.h"

using namespace std;

int main() {
    DHeap heap(3);
    int choice;

    while (true) {
        cout << "\n===== Task Scheduler =====\n";
        cout << "1. Add Task\n2. View Top Task\n3. Remove Top Task\n4. Delete Specific Task\n5. Display All Tasks\n6. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            Task task;
            cout << "Enter task name: ";
            cin >> task.name;
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
            cout << "Tasks:\n";
            for (const auto& task : heap.getTasks()) {
                cout << "Name: " << task.name << ", Priority: " << task.priority << ", Deadline: " << task.deadline << endl;
            }
        } else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
