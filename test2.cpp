#include "bits/stdc++.h"
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
	    int N, M, Q;
		cin >> N >> M >> Q;
		int inBus = 0;
		int arr[M+1] = {0};
		char action, temp;
		int passenger;
		bool consistent = true;
		for (int k=0; k<Q; k++) {
			if (inBus > M) {
				consistent = false;
				break;
			}
			cin >> action;
			cin.sync();
			cin >> passenger;
			if (action == '+') {
				if (arr[passenger] == 1) {
					cout << "Plus if" << endl;
					consistent = false;
					break;
				} else {
					inBus++;
					arr[passenger]++;
				}
			} else {
				if (arr[passenger] == 0) {
					cout << "Minus if" << endl;
					consistent = false;
					break;
				} else {
					inBus--;
					arr[passenger]--;
				}
			}
		}
		if (consistent)
			cout << "Consistent" << endl;
		else
			cout << "Inconsistent" << endl;
	}
	return 0;
}
