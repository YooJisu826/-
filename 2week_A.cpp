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
		int M, N;
		cin >> M >> N;

		char alphabet[26] = { 'A','B','C','D','E','F',
							'G', 'H', 'I', 'J', 'K',
							'L', 'M', 'N', 'O', 'P',
							'Q','R','S','T','U','V',
							'W','X','Y','Z' };
		string alpha[26];
		string bit;

		for (int i = 0; i < M; i++) {
			cin >> alpha[i];
		}

		int L;
		cin >> L >> bit;
		

		//���� ����
		int alphaCount = L / N;
		string* characters = new string[alphaCount];

		for (int i = 0; i < alphaCount; i++) {
			characters[i] = bit.substr(i * N, N);
		}

		//�� ���� ����
		for (int i = 0; i < alphaCount; i++) {
			int minValue = N;
			int index = 0;
			//�� ���ĺ���
			for (int j = 0; j < M; j++) {
				int hDistance = 0;
				//�� �ڸ� ��
				for (int k = 0; k < N; k++) {
					if (characters[i][k] != alpha[j][k]) {
						hDistance++;
					}
				}

				if (hDistance <= minValue) {
					minValue = hDistance;
					index = j;
				}
			}
			cout << alphabet[index];
		}

		cout << "\n";
	}
}