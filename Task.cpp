#include "Task.h"

bool Task::operator<(const Task& other) const {
    if (deadline == other.deadline) {
        return priority < other.priority;
    } else if (deadline == 1) {
        return priority * deadline < other.priority * other.deadline;
    } else {
        return deadline < other.deadline;
    }
}
