#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

struct Task {
    string name;
    string description;
    int deadline;
    int priority;

    Task() : name(""), description(""), deadline(0), priority(0) {}

    Task(const string& name, const string& description, int deadline, int priority)
        : name(name), description(description), deadline(deadline), priority(priority) {}

    bool operator<(const Task& other) const;
};

#endif