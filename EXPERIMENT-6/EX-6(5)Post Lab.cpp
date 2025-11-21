#include <iostream>
using namespace std;

struct Process {
    int pid, bt;
    Process* next;
    Process(int id, int time) : pid(id), bt(time), next(nullptr) {}
};

int main() {
    int n = 3, quantum = 2;
    int burst[] = {5, 4, 3};
    Process* head = new Process(1, burst[0]);
    Process* prev = head;
    for (int i = 1; i < n; i++) {
        prev->next = new Process(i+1, burst[i]);
        prev = prev->next;
    }
prev->next = head; 

cout << "Round-Robin Execution:\n";
Process* curr = head;
bool done = false;
while (!done) {
done = true;
Process* start = curr;
        do {
if (curr->bt > 0) {
int t = (curr->bt >= quantum) ? quantum : curr->bt;
cout << "Process " << curr->pid << " executed for " << t << " units\n";
curr->bt -= t;
            }
if (curr->bt > 0) done = false;
curr = curr->next;
        } 
while (curr != start);
    }
return 0;
}
