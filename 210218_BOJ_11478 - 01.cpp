#include <iostream>
#include <string>
#include <set>

using namespace std;

string s;
set<string> se;

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> s;
	for (int num = 1; num <= s.size(); ++num) {

		for (int j = 0; j <= s.size() - num; j++) {
			string temp = s.substr(j, num);
			se.insert(temp);
		}
	}

	cout << se.size() << "\n";

	return 0;
}