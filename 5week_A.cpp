#include <iostream>
#include <string>
using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;

		int len1 = s1.length();
		int len2 = s2.length();

		int* check1 = new int[len1];
		int* check2 = new int[len2];
		bool emp = true;

		for (int i = 0; i < len1; i++) {
			check1[i] = 0;
		}
		for (int i = 0; i < len2; i++){
			check2[i] = 0;
		}

		//s1의 모든 글자가 s2에 있는지 확인
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (s1[i] == s2[j]) {
					check1[i] = 1;
				}
			}
		}
		
		for (int i = 0; i < len1; i++) {
			if (check1[i] == 0) {
				emp = false;
			}
		}

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len1; j++) {
				if (s2[i] == s1[j]) {
					check2[i] = 1;
				}
			}
		}

		for (int i = 0; i < len2; i++) {
			if (check2[i] == 0)
				emp = false;
		}

		if (!emp) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}

}