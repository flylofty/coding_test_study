#include <iostream>
#include <vector>

using namespace std;

vector<int> cards(4, 0);
int Min = 10000;

void input() {

	for (int i = 0; i < 4; ++i)
		cin >> cards[i];
}

int findMin() {

	int m = 10000;
	for (int i = 0; i < 4; ++i) {
		int sum = 0;
		for (int j = i; j < i + 4; ++j) {
			sum = sum * 10 + cards[j % 4];
		}
		if (m > sum)
			m = sum;
	}
	return m;
}

void findAnswer() {

	int cnt = 0;
	vector<bool> check(Min + 1, false);

	for (int i = 1111; i <= Min; ++i) {

		int j = 3;
		int temp = i;

		for ( ; j >= 0; --j) {
			cards[j] = temp % 10;
			temp = temp / 10;
			if (cards[j] == 0) break;
		}

		temp = findMin();
		if (j == -1 && !check[temp]) {
			cnt++;
			check[temp] = true;
		}
	}

	cout << cnt << "\n";
}

int main() {

	input();
	Min = findMin();
	findAnswer();

	return 0;
}