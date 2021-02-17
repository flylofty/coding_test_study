#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N = 0;
	cin >> N;

	map<string, string> m;

	while (N--) {
		string a, b; cin >> a >> b;
		m[a] = b;
	}

	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		if (it->second == "enter")
			cout << it->first << "\n";
	}

	return 0;
}