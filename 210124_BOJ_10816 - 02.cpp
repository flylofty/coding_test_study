#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;

	int N = 0;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int M = 0;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		cin >> num;

		int a = lower_bound(v.begin(), v.end(), num) - v.begin();
		int b = upper_bound(v.begin(), v.end(), num) - v.begin();

		//cout << "a: " << a << " //  b: " << b << " ==>>   ";
		//cout << b - a << " \n";
		cout << b - a << " ";
	}
	cout << "\n";

	return 0;
}