#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

struct Task {
    string name;
    string description;
    int deadline;  // Days from today
    int priority;
    bool operator<(const Task& other) const;
};

#endif