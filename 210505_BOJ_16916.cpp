#include <iostream>
#include <string>

using namespace std;

string parent, pattern;
int table[1000000];

void makeTable() {

	int j = 0;
	table[0] = 0;
	for (int i = 1; i < pattern.size(); ++i) {
		while (j > 0 && pattern[j] != pattern[i]) {
			j = table[j - 1];
		}
		if (pattern[j] == pattern[i]) {
			table[i] = ++j;
		}
	}
}

int KMP() {

	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;

	for (int i = 0; i < parentSize; ++i) {

		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				j = table[j];
				return 1;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}

int main() {

    /**
    * 참고
    * https://www.youtube.com/watch?v=yWWbLrV4PZ8
    */

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> parent;
	cin >> pattern;
	makeTable();
	int result = KMP();
	cout << result << "\n";

	return 0;
}