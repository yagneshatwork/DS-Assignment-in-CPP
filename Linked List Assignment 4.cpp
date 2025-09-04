#include <iostream>
#include <string>
using namespace std;

// Task Node
class Node {
public:
    string task_name;
    int priority;
    int exec_time;
    Node* next;
    Node(string n, int p, int t) : task_name(n), priority(p), exec_time(t), next(nullptr) {}
};

// Task Scheduler Class
class TaskScheduler {
    Node* head;
public:
    TaskScheduler() : head(nullptr) {}

    // Insert task sorted by priority (highest first)
    void addTask(string name, int priority, int exec_time) {
        Node* newnode = new Node(name, priority, exec_time);
        if (!head || priority > head->priority) {
            newnode->next = head;
            head = newnode;
        } else {
            Node* curr = head;
            while (curr->next && curr->next->priority >= priority)
                curr = curr->next;
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }

    // Print scheduled tasks (sorted by priority)
    void printScheduledTasks() {
        Node* temp = head;
        cout << "\nScheduled Tasks (Highest Priority First):\n";
        while (temp) {
            cout << "Task: " << temp->task_name << ", Priority: " << temp->priority
                 << ", Execution Time: " << temp->exec_time << " ms\n";
            temp = temp->next;
        }
    }

    // Build a new linked list sorted by execution time
    Node* getExecTimeSortedList() {
        Node* sorted = nullptr;
        Node* curr = head;
        while (curr) {
            Node* newnode = new Node(curr->task_name, curr->priority, curr->exec_time);
            if (!sorted || newnode->exec_time < sorted->exec_time) {
                newnode->next = sorted;
                sorted = newnode;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->exec_time <= newnode->exec_time)
                    temp = temp->next;
                newnode->next = temp->next;
                temp->next = newnode;
            }
            curr = curr->next;
        }
        return sorted;
    }

    // Execute tasks sorted by execution time
    void executeTasks() {
        Node* sorted = getExecTimeSortedList();
        cout << "\nExecuting Tasks according to execution time(lower execution time will have higher priority):\n";
        Node* temp = sorted;
        while (temp) {
            cout << "Executing Task '" << temp->task_name << "' : " << temp->exec_time << " ms...\n";
            temp = temp->next;
        }
        // Free memory for sorted list
        while (sorted) {
            Node* del = sorted;
            sorted = sorted->next;
            delete del;
        }
        cout << "\n\nAll tasks executed.\n";
    }

    // Destructor to clean up
    ~TaskScheduler() {
        Node* curr = head;
        while (curr) {
            Node* del = curr;
            curr = curr->next;
            delete del;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of tasks to schedule: ";
    cin >> n;

    TaskScheduler scheduler;
    for (int i = 1; i <= n; ++i) {
        string name;
        int priority, exec_time;
        cout << "\nTask " << i << " Name: ";
        cin >> name;
        cout << "\nPriority (higher = more important): ";
        cin >> priority;
        cout << "\nExecution Time (ms): ";
        cin >> exec_time;
        scheduler.addTask(name, priority, exec_time);
    }

    scheduler.printScheduledTasks();
    scheduler.executeTasks();
    return 0;
}
