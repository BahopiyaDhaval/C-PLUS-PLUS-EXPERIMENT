#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    int n;

    cout << "Enter number of customers: ";
    cin >> n;

    cout << "Enter customer names:\n";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        q.push(name);
    }

    cout << "\n--- Customer Service Simulation ---\n";

    while (!q.empty()) {
        cout << "\nServing: " << q.front() << endl;
        q.pop();

        cout << "Current Queue: ";
        if (q.empty()) {
            cout << "No customers left.\n";
        } else {
            queue<string> temp = q;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }

    return 0;
}
