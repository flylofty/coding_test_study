#include <iostream>
#include <vector>
#include <string>

using namespace std;

int End = 0;
int M = 0;
vector<int> remote;
int maxSize = 0;
int Min = 987654321;

void findMin(string temp) {

	if (temp.size() == maxSize) {

		int ch = stoi(temp);

		if (Min > abs(End - ch) + temp.size())
			Min = abs(End - ch) + temp.size();

		return;
	}

	for (int i = 0; i < remote.size(); ++i) {

		if (maxSize > 1 && remote[i] == 0 && temp.empty())
			continue;

		temp.push_back(remote[i] + '0');
		findMin(temp);
		temp.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> End;
	cin >> M;

	vector<bool> breakdown(10, true);
	for (int i = 0; i < M; ++i) {
		int num; cin >> num;
		breakdown[num] = false;
	}

	for (int i = 0; i < 10; ++i) {
		if (breakdown[i])
			remote.push_back(i);
	}

	for (int i = 6; i >= 1; --i) {
		maxSize = i;
		findMin("");
	}

	int start = 100;
	int anotherMin = abs(start - End);

	if (anotherMin < Min)
		cout << anotherMin << "\n";
	else
		cout << Min << "\n";

	return 0;
}