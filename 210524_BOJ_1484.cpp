#include <iostream>

using namespace std;

int main() {

    int G;
	cin >> G;

	int b = 2;
	int a = 1;

	int cnt = 0;
	while (b > a) {

		int res = b * b - a * a;

		if (res == G) {
			cout << b <<  "\n";
			cnt++;
			b++;
		}
		else if (res < G) {
			b++;
		}
		else {
			a++;
		}
	}

	if (cnt == 0)
		cout << -1;

	return 0;
}