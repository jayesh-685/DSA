#include "bits/stdc++.h"
using namespace std;

void traverse (int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int secondLargest (int arr[], int n) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] < max1 && arr[i] > max2)
            max2 = arr[i];
    }
    return max2;
}

// Theta(1)
void reverseArr (int arr[], int n) {
    for (int i=0; i<n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

int removeDuplicates (int arr[], int n) {
    int size = 1;
    for (int i=1; i<n; i++) {
        if (arr[i] != arr[size-1]) {
            arr[size] = arr[i];
            size++;
        }
    }
    return size;
}

int main () {
    int arr[] = {9, 9, 9, 8, 8};
    //cout << secondLargest(arr, 5) << endl;
    traverse(arr, 5);
    //reverseArr(arr, 5);
    int n = removeDuplicates(arr, 5);
    traverse(arr, n);
}