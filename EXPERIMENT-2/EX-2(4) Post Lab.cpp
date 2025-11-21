#include <iostream>
using namespace std;


int main() {
    int a[] = {2,7,11,15};
    int n = 4;
    int target = 9;
    int iIndex = -1, jIndex = -1;
    bool found = false;


    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] + a[j] == target) {
                found = true;
                iIndex = i;
                jIndex = j;
                break;
            }
        }
        if (found) break;
    }


    if (found) {
        cout << "YES\n";
        cout << "Indices: " << iIndex << " " << jIndex;
    } else {
        cout << "NO\n";
        cout << "Indices: -1 -1";
    }
    return 0;
}
