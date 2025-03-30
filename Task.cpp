#include "Task.h"

bool Task::operator<(const Task& other) const {
    // Min-Heap based on deadline
    return deadline < other.deadline;
}
