#include "bits/stdc++.h"
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int minDiff = INT_MAX;

        for (int i=1; i*i<=n; i++) {
            if (n%i == 0) {
                minDiff = min(minDiff, abs(n/i - i));
            }
        }
        cout << minDiff << endl;
    }
	return 0;
}
