#include <iostream>
#include <string>

using namespace std;

int alpha[26];

int main() {

	string t;
	cin >> t;

	char Max = 'A' - 1;
	for (int i = 0; i < t.size(); ++i) {

		alpha[t[i] - 'A']++;

		if (Max < t[i])
			Max = t[i];
	}

	string mid;
	for (int i = 0; i <= Max - 'A'; ++i) {
		if (alpha[i] == 0 || alpha[i] % 2 == 0) 
			continue;
		mid.push_back('A' + i);
		alpha[i]--;
	}
	
	if (mid.size() > 1) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}

	string head;
	for (int i = 0; i <= Max - 'A'; ++i) {
		int cnt = alpha[i] / 2;

		for (int j = 0; j < cnt; ++j) {
			head.push_back('A' + i);
			alpha[i]--;
		}
	}

	string tail;
	for (int i = Max - 'A'; i >= 0; --i) {
		while (alpha[i]--) {
			tail.push_back('A' + i);
		}
	}

	cout << head << mid << tail << "\n";

	return 0;
}