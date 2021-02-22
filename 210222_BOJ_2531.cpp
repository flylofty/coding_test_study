#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N = 0;
int d = 0;
int k = 0;
int c = 0;
map<int, int> user;

void removeSushi(int sushi) {

	auto it = user.find(sushi);

	if (it == user.end()) {
		return;
	}
	else {
		user[sushi]--;
		if (user[sushi] == 0)
			user.erase(sushi);
	}
}

void insertSushi(int sushi) {
	user[sushi]++;
}

int isIn() {
	auto it = user.find(c);
	if (it == user.end())
		return 1;
	else
		return 0;
}

int main() {

	cin >> N >> d >> k >> c;

	vector<int> velt(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> velt[i];
	}

	int a = 0, b = 0;
	for (; b < k; ++b) {
		auto it = user.find(velt[b]);

		if (it == user.end()) {
			user[velt[b]] = 1;
		}
		else {
			user[velt[b]]++;
		}
	}
	b--;

	int Max = user.size();

	Max += isIn();

	while (a <= N - 1) {
		removeSushi( velt[a % N] );
		a++; b++;
		insertSushi( velt[b % N] );

		int temp = user.size();
		temp += isIn();

		if (temp > Max)
			Max = temp;
	}

	cout << Max << "\n";

	return 0;
}