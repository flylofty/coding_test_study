#include <iostream>
#include <string>

using namespace std;

int N;
string pattern;
int L = 0, R = 0;

bool isCorrect(string& str) {

	if (pattern.size() - 1 > str.size())
		return false;

	int a = 0;
	while (pattern[a] != '*') {
		if (pattern[a] != str[a])
			return false;
		a++;
	}

	a = str.size() - 1;
	int b = pattern.size() - 1;
	while (pattern[b] != '*') {
		if (pattern[b] != str[a])
			return false;
		a--;
		b--;
	}

	return true;
}

int main() {

	cin >> N;
	cin >> pattern;

	for (int i = 0; i < N; ++i) {
		string str; cin >> str;

		if (isCorrect(str))
			cout << "DA\n";
		else
			cout << "NE\n";
	}

	return 0;
}