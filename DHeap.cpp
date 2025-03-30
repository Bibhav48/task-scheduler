#include "DHeap.h"

#include <iostream>
#include <stdexcept>

using namespace std;

DHeap::DHeap(int d) : d(d) {}

int DHeap::parent(int i) { return (i - 1) / d; }
int DHeap::child(int i, int k) { return d * i + k + 1; }

void DHeap::heapifyUp(int index) {
}

void DHeap::heapifyDown(int index) {
}

void DHeap::buildHeap(vector<Task> tasks) {
}

void DHeap::insert(Task task) {
}

Task DHeap::getTop() {
    if (!heap.empty()) return heap[0];
    throw runtime_error("Heap is empty!");
}

void DHeap::deleteTop() {
}