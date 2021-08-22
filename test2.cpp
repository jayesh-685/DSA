#include "bits/stdc++.h"
using namespace std;

int main() {
	// your code goes here
	int Q;
	cin >> Q;
	while (Q--) {
	    int N;
	    cin >> N;
	    string S;
	    cin >> S;
	    string T;
	    cin >> T;
	    int comp=0, eng=0, both=0, nil=0;
	    for (int i=0; i<S.length(); i++) {
            if (S[i] == '0') {
                if (T[i] == '0')
                    nil++;
                else
                    eng++;
            } else {
                if (T[i] == '1')
                    both++;
                else 
                    comp++;
            }
        }
        int count = min(both, nil);
        count += min(comp, eng);

        if (both > nil) {
            both -= nil;
            int diff = abs(comp - eng);
            count += min(both, diff);
        }

        cout << count << endl;
	}
	return 0;
}
