#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, p, q, X, result;
vector<long long> num;

long long cal() {
	long long res = num[0];
	int temp = 1;

	for (int i = 1; i < N; i++) {
		temp *= X;
		res += num[i] * temp;
	}

	return res % 1013;
}

void sol() {
	sort(num.begin(), num.end());

	do {
		long long res = cal();
		
		if (res >= p && res <= q) {
			result++;
		}
	} while (next_permutation(num.begin(), num.end()));

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		result = 0;
		num.clear();

		cin >> N;

		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			num.push_back(a);
		}

		cin >> p >> q >> X;

		sol();

		cout << result << "\n";

	}

}

/*

*/