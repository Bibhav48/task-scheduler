#ifndef DHEAP_H
#define DHEAP_H

#include <vector>

#include "Task.h"

using namespace std;

class DHeap {
   private:
    vector<Task> heap;
    // Number of children per node
    int d;

    int parent(int i);
    int child(int i, int k);
    void heapifyUp(int index);
    void heapifyDown(int index);

   public:
    DHeap(int d);
    void insert(Task task);
    Task getTop();
    void deleteTop();
    void buildHeap(vector<Task> tasks);
};

#endif
