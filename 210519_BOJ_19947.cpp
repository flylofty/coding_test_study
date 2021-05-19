#include <iostream>
#include <vector>

using namespace std;

int H, Y, Max = 0;
double rate[6]{ 0, 1.05, 0, 1.2, 0, 1.35 };
int year[3]{ 1, 3, 5 };
vector<int> v;
vector<int> allCase;

void findCase(int sum) {

	if (sum == Y) {

		int total = H;
		for (int i = 0; i < v.size(); ++i) {

			total = (int)(total * rate[v[i]]);
		}

		if (total > Max)
			Max = total;

		return;
	}

	for (int i = 0; i < 3; ++i) {
		if (sum + year[i] <= Y) {
			v.push_back(year[i]);
			findCase(sum + year[i]);
			v.pop_back();
		}
	}
}

int main() {

	cin >> H >> Y;

	findCase(0);

	cout << Max;

	return 0;
}