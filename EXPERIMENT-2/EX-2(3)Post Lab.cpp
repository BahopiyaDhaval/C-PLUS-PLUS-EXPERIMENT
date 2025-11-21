EX-2(3)Post Lab
#include <iostream>
using namespace std;


int main() {
    int a[] = {1,3,4,2,2};
    int n = 5;           // size = N+1
    int freq[6] = {0};   // size N+1+1


    int dup = -1;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] > 1) {
            dup = a[i];
            break;
        }
    }
    cout << "Duplicate: " << dup;
    return 0;}
