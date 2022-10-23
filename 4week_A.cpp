#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N, K;
int W[500];
int V[500];
int P[500];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> W[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> V[i];
		}
		for (int i = 0; i < N; i++) {
			P[i] = V[i] / W[i];
		}


		int count = N;

		long long result =0;

		while (K > 0) {
			if (count == 0) break;

			int max = 0;
			int index = 0;

			for (int i = 0; i < N; i++) {
				if (max < P[i]) {
					max = P[i];
					index = i;
				}
			}
			count--;

			if (W[index] <= K) {
				K -= W[index];
				result += V[index];

			}
			else {
				result += P[index] * K;
				K = 0;
			}
			P[index] = 0;
			
		}

		cout << result << "\n";

	}

}