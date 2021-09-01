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

void zeroToLast (int arr[], int n) {
    // whenever you find a non zero element just swap it with the first zero index of which can be found by keeping track of no of non zero elements

    int count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

void leftRotate (int arr[], int n) {
    int temp = arr[0];
    for (int i=1; i<n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}

// left rotate by d
// Theta(nd) solution is to simply call the left rotate by 1 function d times

// solution with time complexity theta(n) but uses theta(d) extra space

/* void leftRotateD (int arr[], int n, int d) {
    int tempArr [d];

    for (int i=0; i<d; i++)
        tempArr[i] = arr[i];
    
    for (int i=d; i<n; i++)
        arr[i-d] = arr[i];

    for (int i=n-d; i<n; i++)
        arr[i] = tempArr[i-n+d];
} */

// uses O(1) extra space

void leftRotateD (int arr[], int n, int d) {
    // reverse the first d elements, then the remaining d and then the complete array
    reverseArr(arr, d);
    reverseArr(arr+d, n-d);
    reverseArr(arr, n);
}

void leaderInArray (int arr[], int n) {
    // if there is no greater element to the right of an element then it is a leader in the array
    vector <int> vec;
    int currLeader = arr[n-1];
    vec.push_back(arr[n-1]);

    for (int i=n-2; i>=0; i--) {
        if (arr[i] > currLeader) {
            vec.push_back(arr[i]);
            currLeader = arr[i];
        }
    }
    reverse(vec.begin(), vec.end());
    for (int v : vec)
        cout << v << " ";
} // Theta(n)

int maxDiff (int arr[], int n) {
    // max value of arr[j] - arr[i] such that j > i

    int ans = INT_MIN;
    int currMax = arr[n-1];

    for (int i=n-2; i>=0; i--) {
        ans = max(ans, currMax-arr[i]);
        currMax = max(currMax, arr[i]);
    }

    return ans;
}  // Theta(n)

int main () {
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    //cout << secondLargest(arr, 5) << endl;
    traverse(arr, 8);
    //reverseArr(arr, 5);
    //int n = removeDuplicates(arr, 5);
    //leftRotateD(arr, 8, 3);
    //traverse(arr, 8); 
    cout << maxDiff(arr, 8) << endl;
}