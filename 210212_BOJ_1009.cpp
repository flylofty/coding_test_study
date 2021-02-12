#include <iostream>
#include <vector>

using namespace std;

int T;

vector<int> findRule(int num) {
	int t = num;
	vector<int> v;
	v.push_back(num % 10);

	if (v[0] == 0) {
		v[0] = 10;
		return v;
	}

	t = (t * num) % 10;
	while (v[0] != t) {
		v.push_back(t);
		t = (t * num) % 10;
	}

	return v;
}

int main() {

	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		vector<int> v = findRule(a);
		cout << v[(b - 1) % v.size()] << "\n";
	}

	return 0;
}