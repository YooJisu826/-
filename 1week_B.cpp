#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;

		int life=0;
		int cur_num = 0;
		int result = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'C') {
				life++;
			}
			else {
				if (life == 0) {
					result = max(result, cur_num);
					cur_num = 0;
				}
				else {
					life--;
					cur_num += 2;

					if (life == 0) {
						result = max(result, cur_num);
					}
				}
			}
		}

		int life2 = 0;
		int cur_num2 = 0;
		int result2 = 0;
		for (int i = str.length(); i >=0; i--) {
			if (str[i] == 'T') {
				life2++;
			}
			else {
				if (life2 == 0) {
					result2 = max(result2, cur_num2);
					cur_num2 = 0;
				}
				else {
					life2--;
					cur_num2 += 2;

					if (life2 == 0) {
						result2 = max(result2, cur_num2);
					}
				}
			}
		}

		cout << max(result, result2) << "\n";

	}
}