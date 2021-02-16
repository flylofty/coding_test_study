#include <iostream>
#include <string>

using namespace std;

int main() {

	int N = 0;
	cin >> N;

	while (N--) {

		string s;
		cin >> s;

		if (s[s.size() - 1] == 'O')
			s.push_back('X');

		int score = 0;
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; ++i) {

			if (s[i] == 'O') {
				cnt++;
				score += cnt;
			}
			else {
				cnt = 0;
			}
		}

		cout << score << "\n";
		s.clear();
	}

	return 0;
}