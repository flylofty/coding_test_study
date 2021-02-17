#include <iostream>
#include <string>

using namespace std;

string s;

int sum(int b, int e) {
	
	int temp = 0;
	int result = 0;

	for (int i = b; i <= e; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp = temp * 10 + (s[i] - '0');
		}
		else {
			result += temp;
			temp = 0;
		}
	}

	return result;
}

int main() {

	cin >> s;
	s.push_back('-');

	int j = 0;
	
	for (; j < s.size(); ++j)
		if (s[j] == '-')
			break;

	cout << sum(0, j) - sum(j + 1, s.size() - 1) << "\n";

	return 0;
}