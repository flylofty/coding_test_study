#include <iostream>

using namespace std;

int H, Y, Max = 0;
double rate[6]{ 0, 1.05, 0, 1.2, 0, 1.35 };
int year[3]{ 1, 3, 5 };

void findCase(int sum, int total) {

	if (sum == Y) {

		if (total > Max)
			Max = total;

		return;
	}

	for (int i = 0; i < 3; ++i) {
		if (sum + year[i] <= Y)
			findCase(sum + year[i], total * rate[year[i]]);
	}
}

int main() {

	cin >> H >> Y;

	findCase(0, H);

	cout << Max;

	return 0;
}