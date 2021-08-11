#include "bits/stdc++.h"
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int count = 0;
        for (int a=1; a<=N; a++) {
            for (int b=1; b<=N; b++) {
                for (int c=1; c<=min(a, b); c++) {
                    if ((a%b == c) && (b%c == 0))
                        count++;
                }
            }
        }
        cout << count << endl;
    }
}