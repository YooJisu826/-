#include <iostream>
using namespace std;

int T;
long long m;
long long days;

void doWork(long long num) {
	days += (10 - num);
	m += (10 - num);
}

void buyProduct(long long num) {
	days += num;
	m -= num;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {

		cin >> m;
		days = 0;

		for (int i = 0; i < 11; i++) {
			if (m == 0) {
				break;
			}

			long long num = m % 10;

			if (num > 5) {
				doWork(num);
			}
			else if (num == 5) {
				long long next_num = m % 100 / 10;

				if (next_num >= 5) {
					doWork(num);
				}
				else {
					buyProduct(num);
				}
			}
			else {
				buyProduct(num);
			}

			m /= 10;
		}
		cout << days << "\n";
	}
}