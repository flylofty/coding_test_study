#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	string stick;
	cin >> stick;

	stack<char> s;

	int count = 0;
	for (int i = 0; i < stick.size(); ++i) {

		if (stick[i] == '(') {
			if (stick[i + 1] == ')') {
				count += s.size();
				i++;
			}
			else {
				s.push('(');
			}
		}
		else {
			count++;
			s.pop();
		}
	}

	cout << count << "\n";

	return 0;
}