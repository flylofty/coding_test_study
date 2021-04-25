#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);
	s.push_back('#');

	string res;
	for (int i = 0; i < s.size() - 1; ++i) {

		if (s[i] == '<') {
			while (1) {
				res.push_back(s[i]);
				if (s[i] == '>')
					break;
				++i;
			}
		}
		else {
			string t;
			while (s[i] != '<' && s[i] != ' ' && s[i] != '#') {
				t.push_back(s[i]);
				i++;
			}
			
			reverse(t.begin(), t.end());
			res.append(t);

			if (s[i] == '<') {
				--i;
			}
			else if (s[i] == ' ') {
				res.push_back(' ');
			}
		}
	}

	cout << res << "\n";

	return 0;
}