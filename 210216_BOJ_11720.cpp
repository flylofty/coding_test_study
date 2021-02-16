#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int N; cin >> N;
	string num; cin >> num;

	int sum = 0;
	int pre = 0;
	while (N--) {
		pre = pre * 10 + ((num[num.size() - 1] - '0') % 10);
		num.pop_back();

		if (pre > 0) {
			sum += pre;
			pre = 0;
		}
	}

	cout << sum << "\n";

	return 0;
}