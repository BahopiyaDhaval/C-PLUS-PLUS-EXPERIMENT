#include <iostream>
using namespace std;


int main() {
    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6};
    int n = 4, m = 3;
    int i = 0, j = 0;
    int res[10], k = 0;


    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) res[k++] = arr1[i++];
        else res[k++] = arr2[j++];
    }
    while (i < n) res[k++] = arr1[i++];
    while (j < m) res[k++] = arr2[j++];


    for (int x = 0; x < k; x++) cout << res[x] << " ";
    return 0;
}
