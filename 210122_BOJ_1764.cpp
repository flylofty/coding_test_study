#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N = 0;
	int M = 0;

	cin >> N >> M;

	map<string, int> m;
	vector<string> v;
	int cnt = 0;

	for (int i = 0; i < N + M; ++i) {
		string temp; cin >> temp;

		auto findPeople = m.find(temp);

		if (findPeople == m.end()) {
			m.insert({ temp, 1 });
		}
		else {
			m[temp]++;

			if (m[temp] >= 2) {
				cnt++;
				//v.push_back(temp);
			}
		}
	}

	cout << cnt << "\n";
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second >= 2)
			cout << it->first << "\n";
	}

	/*sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << "\n";
	}
	cout << "\n";*/

	return 0;
}