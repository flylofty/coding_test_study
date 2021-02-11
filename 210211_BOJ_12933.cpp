#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

	string s;
	cin >> s;
	
	string duck = "quack";
	vector<int> visit(s.size(), 0);

	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {

		if (s[i] == 'q' && visit[i] == 0) {

			cnt++;
			vector<int> idxs;
			int index = 0;
			for (int j = i; j < s.size(); ++j) {
				if (duck[index % 5] == s[j] && visit[j] == 0) {
					visit[j] = cnt;
					index++;
					idxs.push_back(j);
				}
			}

			while (index % 5 != 0) {
				visit[idxs[--index]] = 0;
			}
		}
	}

	for (int i = 0; i < visit.size(); ++i) {
		if (visit[i] == 0) {
			cout << "-1\n";
			return 0;
		}
	}

	cout << cnt << "\n";

	return 0;
}