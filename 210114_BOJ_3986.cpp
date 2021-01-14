#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N = 0;
string str;

void findAnswer() {

	cin >> N;

	int count = 0;

	for (int i = 0; i < N; ++i) {

		stack<char> s;

		cin >> str;

		for (int j = 0; j < str.size(); ++j) {

			if (!s.empty() && s.top() == str[j]) {
				s.pop();
			}
			else {
				s.push(str[j]);
			}
		}

		if (s.empty())
			count++;
	}

	cout << count << "\n";
}

int main() {

	findAnswer();
	return 0;
}