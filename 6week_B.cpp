#include <iostream>
#include <stack>
using namespace std;

int T, N, K, cnt;
stack<int> st[3];
stack<int> result;
int oneban[11];

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		for (int i = 0; i < oneban[1]; i++) {
			st[to].push(st[from].top());
			st[from].pop();
			cnt++;
			if (cnt == K) {
				result = st[1];
			}
		}
	}
	else {
		hanoi(n - 1, from, to, by);
		for (int i = 0; i < oneban[n]; i++) {
			st[to].push(st[from].top());
			st[from].pop();
			cnt++;
			if (cnt == K) {
				result = st[1];
			}
		}
		hanoi(n - 1, by, from, to);
	}
}

void init() {
	for (int i = 0; i < 10; i++) {
		oneban[i] = 0;
	}

	for (int i = 0; i < 3; i++) {
		while (!st[i].empty()) {
			st[i].pop();
		}
	}
	while (!result.empty()) {
		result.pop();
	}
	cnt = 0;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		init();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> oneban[i];
		}
		cin >> K;

		for (int i = N; i >= 1 ; i--) {
			for (int j = 0; j < oneban[i]; j++){
				st[0].push(i);
			}
		}

		hanoi(N, 0, 1, 2);

		if (result.empty()) {
			cout << 0 << "\n";
		}
		else {
			while (!result.empty()) {
				cout << result.top() << " ";
				result.pop();
			}
			cout << "\n";
		}
	}
	return 0;
}