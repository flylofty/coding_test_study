#include <iostream>
#include <string>

// 브루트포스로 풀 수 없음.
// 동적 프로그래밍을 통해 풀어야함!!

using namespace std;

int N = 0;
int cnt = 0;
int dir[2]{ -1, 1 };

void stairsNumber(int num) {

	if (to_string(num).size() == N) {
		cnt++;
		cout << num << "\n";
		return;
	}
	else if (to_string(num).size() < N) {
		
		for (int i = 0; i < 2; ++i) {
			int next = (num % 10) + dir[i];

			if (next < 0 || next > 9)
				continue;

			stairsNumber(num * 10 + next);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	cout << "\n";

	for(int i = 1; i <= 9; ++i)
		stairsNumber(i);

	cout << "\n\n";
	cout << cnt % 1000000000 << "\n";

	return 0;
}