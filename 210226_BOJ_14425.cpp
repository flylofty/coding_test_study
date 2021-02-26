#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	set<string> s;

	int N;
	int M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string a; cin >> a;
		s.insert(a);
	}

	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		string b; cin >> b;

		if (s.find(b) != s.end())
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}