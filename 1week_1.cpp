#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int find_warrior(vector<int> enemy_stat, vector<int> stat) {

	int warrior;
	if (enemy_stat.size() == 1) {
		warrior = enemy_stat[0];
	}
	else {
		warrior = gcd(enemy_stat[0], enemy_stat[1]);

		for (int i = 2; i < enemy_stat.size(); i++) {
			warrior = gcd(warrior, enemy_stat[i]);
		}

	}
	for (int i = 0; i < stat.size(); i++) {
		if (stat[i] % warrior == 0) {
			return -1;
		}
	}
	return warrior;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int inha, bi;
		cin >> inha >> bi;

		int in_res, bi_res;

		vector<int> in_stat;
		vector<int> bi_stat;

		for (int i = 0; i < inha; i++) {
			int a;
			cin >> a;
			in_stat.push_back(a);
		}

		for (int i = 0; i < bi; i++) {
			int a;
			cin >> a;
			bi_stat.push_back(a);
		}

		cout << find_warrior(bi_stat, in_stat) << " ";
		cout << find_warrior(in_stat, bi_stat) << "\n";
	}
}
