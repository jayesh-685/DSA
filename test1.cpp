#include "bits/stdc++.h"

using namespace std;

int main () {

    int arr [] = {19, 8, 16, 4, 3, 1};
    int max1  = INT_MIN, max2 = INT_MIN;
    for (int i=0; i<6; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] > max2 && arr[i] != max1)
            max2 = arr[i];
    }
    cout << max1 << " " << max2;

    return 0;
}