#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int a[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};

    // transpose
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            swap(a[i][j], a[j][i]);

    // reverse each row
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            swap(a[i][l], a[i][r]);
            l++; r--;
        }
    }

    // print
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
