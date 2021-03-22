#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() > b.size())
		return false;
	else if (a.size() < b.size())
		return true;
	else {
		if (a < b)
			return true;
		else
			return false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N; cin >> N;

	vector<string> vs;
	set<string> ss;
	for (int i = 0; i < N; ++i) {
		string s;  cin >> s;

		if (ss.find(s) == ss.end()) {
			ss.insert(s);
			vs.push_back(s);
		}
	}

	sort(vs.begin(), vs.end(), cmp);

	for (int i = 0; i < vs.size(); ++i)
		cout << vs[i] << "\n";

	return 0;
}