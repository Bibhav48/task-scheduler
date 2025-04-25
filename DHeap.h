#ifndef DHEAP_H
#define DHEAP_H

#include <iostream>
#include <string>
#include <vector>

#include "Task.h"

using namespace std;

class DHeap {
   public:
    vector<Task> getTasks();
    // Number of children per node
    int d;

    int parent(int i);
    int child(int i, int k);
    void heapifyUp(int index);
    void heapifyDown(int index);

   public:
    DHeap(int d);
    void insert(Task task);
    void update(Task task);
    Task getTop();
    void deleteTop();
    void buildHeap(vector<Task> tasks);
    void deleteTask(string taskName);
    void saveToCSV(const string& filename);
    void loadFromCSV(const string& filename);

   private:
    vector<Task> heap;
};

#endif
