#include <iostream>
using namespace std;

int T;
int n, d;
int cal[100001];
int cntArr[201];

int calMedian() {
	int med = 0;
	int medCount = 0;
	int c = -1;

	if (d % 2 == 1) {
		for (int i = 0; i < 201; i++) {
			medCount += cntArr[i];
			if (medCount > d / 2) {
				med = i * 2;
				break;
			}
		}

	}
	else {
		for (int i = 0; i < 201; i++) {
			medCount += cntArr[i];
			if (medCount >= d / 2 && c == -1) {
				c = i;
			}
			if (medCount >= d / 2 + 1) {
				med = c + i;
				break;
			}
		}

	}
	return med;

}

void init() {
	for (int i = 0; i < 100001; i++) {
		cal[i] = 0;
	}
	for (int i = 0; i < 201; i++){
		cntArr[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		init();
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {
			cin >> cal[i];
		}

		for (int i = 1; i <= d; i++) {
			cntArr[cal[i]]++;
		}

		int median = 0;
		int alarm = 0;

		for (int i = d+1; i <= n; i++) {
			median = calMedian();
			if (median <= cal[i]) {
				alarm++;
			}
			cntArr[cal[i-d]]--;
			cntArr[cal[i]]++;

		}

		cout << alarm << "\n";
	}

}