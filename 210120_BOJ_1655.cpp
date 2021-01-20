#include <iostream>
#include <queue>

// 0.1초의 시간제한이 있음
// n == 10만, 퀵 정렬은 nlogn ==> 10만log10만 == 50만 
// 그런데 50만을 10만번 동안 해야하므로 500억 ==> 시간초과
// 힙 logN ==> N * logN ==> 50만

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N = 0;
	cin >> N;

	priority_queue<int, vector<int>, less<int>> Max;
	priority_queue<int, vector<int>, greater<int>> Min;

	vector<int> answer;

	for (int i = 0; i < N; ++i) {

		int num; cin >> num;

		if (Max.size() <= Min.size()) {
			Max.push(num);
		}
		else {
			Min.push(num);
		}

		if (!Max.empty() && !Min.empty()) {
			if (Max.top() > Min.top()) {
				int a = Max.top();
				int b = Min.top();
				Max.pop();
				Min.pop();
				Max.push(b);
				Min.push(a);
			}
		}

		cout << Max.top() << "\n";
	}

	return 0;
}