#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> isIn;
vector<int> c;

int main() {

	cin >> N;
	cin >> M;

	isIn.assign(M + 1, 0);


	for (int i = 0; i < M; ++i) {
		int t; cin >> t;

		if (isIn[t] == 0) { // 새로운 추천
			if (c.size() == N) {
				int Min = isIn[c[0]];
				int index = 0;
				for (int i = 1; i < c.size(); ++i) {
					if (Min > isIn[c[i]]) {
						Min = isIn[c[i]];
						index = i;
					}
				}
				isIn[c[index]] = 0;
				c.erase(c.begin() + index);
			}
			c.push_back(t);
		}

		isIn[t]++;
	}

	for (int i = 1; i < isIn.size(); ++i) {
		if (isIn[i] > 0)
			cout << i << " ";
	}
	cout << "\n";

	return 0;
}