#include <iostream>
#include <string>

using namespace std;

int wrong;

bool isPalindrome(string str) {

	int l = 0;
	int r = str.size() - 1;

	while (l <= r) {
		if (str[l] != str[r])
			break;
		++l, --r;
	}

	if (l > r) {
		return true;
	}
	else {
		wrong = l;
		return false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string t; cin >> t;

		if (isPalindrome(t)) {
			cout << "0\n";
		}
		else {
			string a = t.substr(wrong, t.size() - 1 - wrong - wrong);
			string b = t.substr(wrong + 1, t.size() - 1 - wrong - wrong);

			if (isPalindrome(a) || isPalindrome(b))
				cout << "1\n";
			else
				cout << "2\n";
		}
	}

	return 0;
}