#include "DHeap.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

DHeap::DHeap(int d) : d(d) {}

int DHeap::parent(int i) { return (i - 1) / d; }
int DHeap::child(int i, int k) { return d * i + k + 1; }

void DHeap::heapifyUp(int index) {
    while (index > 0 && heap[index] < heap[parent(index)]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

void DHeap::heapifyDown(int index) {
    int smallest = index;
    for (int k = 0; k <= d; k++) {
        int c = child(index, k);
        if (c < heap.size() && heap[c] < heap[smallest]) {
            smallest = c;
        }
    }
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void DHeap::buildHeap(vector<Task> tasks) {
    heap = tasks;  // Copy the input tasks into the internal heap vector

    // Start from the last parent node and heapify down to fix the heap
    for (int i = (heap.size() - 1) / d; i >= 0; --i) {
        heapifyDown(i);
    }
}

void DHeap::update(Task task) {
    for (size_t i = 0; i < heap.size(); i++) {
        if (heap[i].name == task.name) {
            int oldDeadline = heap[i].deadline;
            heap[i] = task;  // Update the task

            // Decide direction based on the change in deadline
            if (task.deadline < oldDeadline) {
                cout << "Task priority increased!\n";
                heapifyUp(i);
            } else {
                cout << "Task priority decreased!\n";
                heapifyDown(i);
            }
            return;
        }
    }
    cout << "Task not found!\n";
}

void DHeap::insert(Task task) {
    heap.push_back(task);        // Add to the end of the heap
    heapifyUp(heap.size() - 1);  // Fix the heap property upward
}

Task DHeap::getTop() {
    if (!heap.empty()) return heap[0];
    throw runtime_error("Heap is empty!");
}

void DHeap::deleteTop() {
    if (heap.empty()) {
        cout << "Heap is empty, nothing to remove!\n";
        return;
    }

    heap[0] = heap.back();  // Replace root with last element
    heap.pop_back();        // Remove last element
    heapifyDown(0);         // Restore heap order
    cout << "Top task removed successfully.\n";
}

void DHeap::deleteTask(string taskName) {
    for (size_t i = 0; i < heap.size(); i++) {
        if (heap[i].name == taskName) {
            heap[i] = heap.back();  // Replace with last element
            heap.pop_back();        // Remove last element
            heapifyDown(i);         // Restore heap order
            cout << "Task '" << taskName << "' deleted successfully.\n";
            return;
        }
    }
    cout << "Task '" << taskName << "' not found!\n";
}

vector<Task> DHeap::getTasks() {
    return heap;
}

void DHeap::saveToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file for writing: " + filename);
    }

    for (const auto& task : heap) {
        file << task.name << "," << task.description << "," << task.deadline << "," << task.priority << "\n";
    }

    file.close();
    cout << "Heap saved to " << filename << " successfully.\n";
}

void DHeap::loadFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file for reading: " + filename);
    }

    vector<Task> tasks;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, description, deadlineStr, priorityStr;

        if (getline(ss, name, ',') && getline(ss, description, ',') && getline(ss, deadlineStr, ',') && getline(ss, priorityStr)) {
            try {
                int deadline = stoi(deadlineStr);
                int priority = stoi(priorityStr);
                tasks.push_back(Task{name, description, deadline, priority});
            } catch (const invalid_argument& e) {
                cerr << "Invalid format in CSV: " << line << endl;
            }
        }
    }

    file.close();
    buildHeap(tasks);
    cout << "Heap loaded from " << filename << " successfully.\n";
}
