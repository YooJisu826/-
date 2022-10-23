#include <iostream>
#include <set>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T--) {

		multiset<int> level;

		int M, N;
		cin >> M >> N;

		for (int i = 0; i < M; i++) {
			int a;
			cin >> a;
			level.insert(a);
		}

		for (int i = 0; i < N; i++) {
			string cmd;
			cin >> cmd;

			if (cmd == "Add") {
				int a;
				cin >> a;
				level.insert(a);
			}
			else if (cmd == "Delete") {
				string cmd2;
				cin >> cmd2;

				if (cmd2 == "max") {
					auto iter = level.end();
					iter--;
					level.erase(iter);
				}
				else if (cmd2 == "min") {
					level.erase(level.begin());
				}
			}
		}

		cout << *level.begin() << " ";

		auto iter = level.end();
		iter--;
		cout << *iter << "\n";
	}

}
