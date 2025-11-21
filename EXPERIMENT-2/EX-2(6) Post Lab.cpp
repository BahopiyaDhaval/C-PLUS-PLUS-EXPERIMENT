#include <iostream>
using namespace std;

int main() {
    int n = 3, m = 4;
    int a[3][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9,10,11,12}};

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // left to right
        for (int j = left; j <= right; j++)
            cout << a[top][j] << " ";
        top++;

        // top to bottom
        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";
        right--;

        if (top <= bottom) {
            // right to left
            for (int j = right; j >= left; j--)
                cout << a[bottom][j] << " ";
            bottom--;
        }

        if (left <= right) {
            // bottom to top
            for (int i = bottom; i >= top; i--)
                cout << a[i][left] << " ";
            left++;
        }
    }
    return 0;
}
