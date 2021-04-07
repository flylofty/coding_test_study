#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int goods[101];

int main() {

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; ++i) 
		cin >> goods[i];

	set<int> multiTap;
	for (int i = 0; i < N; ++i)
		multiTap.insert(goods[i]);

	int cnt = 0;
	for (int i = N; i < K; ++i) {

		int now = goods[i];

		if (multiTap.size() == N && multiTap.find(now) == multiTap.end()) {

			vector<int> pull;
			bool isExist = true;
			int out;

			for (auto it : multiTap) {

				int j = i + 1;
				for (; j < K; ++j) {
					if (it == goods[j]) {
						pull.push_back(j);
						break;
					}
				}

				// 꽂혀 있는 것중 앞으로 나오지 않을 것
				if (j == K) {
					out = it;
					isExist = false;
					break;
				}
			}

			// 멀티탭에 꽂혀있으면서 앞으로 또 사용될 예정 중인 것 중에 가장 늦게 나오는 것을 뽑음
			if (!pull.empty() && isExist) {
				sort(pull.begin(), pull.end());
				out = goods[pull[pull.size() - 1]];
			}

			multiTap.erase(out);
			cnt++;
		}

		multiTap.insert(now);
	}

	cout << cnt << "\n";

	return 0;
}