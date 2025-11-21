#include <iostream>
using namespace std;


// print array
void traverse(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


// linear search
int searchElement(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}


// insert val at position pos (0-based)
int insertElement(int a[], int n, int pos, int val) {
    for (int i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = val;
    return n + 1;
}


// delete element at position pos (0-based)
int deleteElement(int a[], int n, int pos) {
    for (int i = pos; i < n - 1; i++)
        a[i] = a[i + 1];
    return n - 1;
}


// (a) delete all occurrences of x
int deleteAll(int a[], int n, int x) {
    int j = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != x)
            a[j++] = a[i];
    return j;          // new size
}


// (b) frequency of all elements
void frequency(int a[], int n) {
    bool used[100] = {false};     // assume n <= 100
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        int c = 1;
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j]) {
                c++;
                used[j] = true;
            }
        cout << a[i] << " occurs " << c << " times\n";
    }
}


int main() {
    int a[100] = {1, 2, 3, 2, 4, 2, 5};
    int n = 7;


    cout << "Initial: ";
    traverse(a, n);


    cout << "Search 4 at index: " << searchElement(a, n, 4) << endl;


    n = insertElement(a, n, 2, 9);
    cout << "After insert 9 at 2: ";
    traverse(a, n);


    n = deleteElement(a, n, 3);
    cout << "After delete at 3: ";
    traverse(a, n);


    n = deleteAll(a, n, 2);
    cout << "After delete all 2: ";
    traverse(a, n);


    cout << "Frequencies:\n";
    frequency(a, n);


    return 0;
}


