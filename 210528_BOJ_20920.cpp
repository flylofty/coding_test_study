#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, string> IS;

int N, M;
vector<IS> alpha;
map<string, int> m;

bool cmp(IS A, IS B) {
	if (A.first > B.first)
		return true;
	else if (A.first < B.first)
		return false;
	else {
		if (A.second.size() > B.second.size())
			return true;
		else if (A.second.size() < B.second.size())
			return false;
		else {
			if (A.second.compare(B.second) >= 0)
				return false;
			else
				return true;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		
		string s; cin >> s;

		if (s.size() >= M) {

			if (m.find(s) == m.end()) {
				alpha.push_back({ 1, s });
				m[s] = alpha.size() - 1;
			}
			else {
				int idx = m[s];
				alpha[idx].first++;
			}
		}
	}

	sort(alpha.begin(), alpha.end(), cmp);
	for (int i = 0; i < alpha.size(); ++i)
		cout << alpha[i].second << "\n";

	return 0;
}