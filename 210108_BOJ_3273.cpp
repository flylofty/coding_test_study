#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<int> v;
int x = 0;

void input() {
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	cin >> x;

	sort(v.begin(), v.end());
}

void findAnswer() {

	int result = 0;

	int a = 0;
	int b = v.size() - 1;
	while (b > a) {
		int sum = v[a] + v[b];
		if (sum == x) {
			result++;
			a++;
			b--;
		}
		else if (sum < x) {
			a++;
		}
		else {
			b--;
		}
	}

	//for (int b = v.size() - 1; b >= 0 && b > a; --b) {
	//	int sum = v[a] + v[b];
	//	if (sum == x) {
	//		result++;
	//		a++;
	//	} 
	//}

	cout << result << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	findAnswer();
	return 0;
}