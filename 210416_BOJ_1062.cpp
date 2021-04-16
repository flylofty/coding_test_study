#include <iostream>
#include <string>

using namespace std;

int N, K;
bool alpha[26];
int Max = 0;
string s[50];


void findAnswer(int cnt, int pre) {

	if (cnt == K) {

		int count = 0;
		for (int i = 0; i < N; ++i) {
			int j = 0;
			for (; j < s[i].size(); ++j) {
				
				if (alpha[s[i][j] - 'a'] == false)
					break;
			}

			if (j == s[i].size())
				count++;
		}

		if (Max < count)
			Max = count;

		return;
	}

	for (int i = pre; i < 26; ++i) {
		if (alpha[i])
			continue;
		alpha[i] = true;
		findAnswer(cnt + 1, i + 1);
		alpha[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	alpha['a' - 'a'] = true;
	alpha['c' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	cin >> N >> K;
	K = K - 5;

	for (int i = 0; i < N; ++i) cin >> s[i];

	if (K >= 0)
		findAnswer(0, 0);

	cout << Max << "\n";

	return 0;
}