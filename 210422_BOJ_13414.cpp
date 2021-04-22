#include <iostream>
#include <map>
#include <string>

using namespace std;

pair<string, bool> students[500000];
map<string, int> m;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int K, L; cin >> K >> L;
	for (int i = 0; i < L; ++i) {

		cin >> students[i].first;

		if (m.find(students[i].first) == m.end()) {
			m[students[i].first] = i;
			students[i].second = true;
		}
		else {
			int idx = m[students[i].first];
			students[idx].second = false;
			students[i].second = true;
			m[students[i].first] = i;
		}
	}

	int cnt = 0;
	for (int i = 0; i < L; ++i) {
		if (students[i].second) {
			cout << students[i].first << "\n";
			cnt++;
		}

		if (cnt == K)
			break;
	}

	return 0;
}