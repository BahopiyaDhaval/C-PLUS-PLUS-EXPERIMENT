#include <iostream>
using namespace std;


int main() {
    int a[] = {2,0,2,1,1,0};
    int n = 6;
    int low = 0, mid = 0, high = n - 1;


    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++; mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else { // a[mid] == 2
            swap(a[mid], a[high]);
            high--;
        }
    }


    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}


