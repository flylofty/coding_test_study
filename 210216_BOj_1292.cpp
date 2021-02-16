#include <iostream>

using namespace std;

int findNumber(int number) {

	int i = 1;
	while (1) {
		if (number <= i * (i + 1))
			return i;
		i++;
	}
}

int main() {

	int A, B;
	cin >> A >> B;

	int sum = 0;
	for (int i = A; i <= B; ++i)
		sum += findNumber(i * 2);

	cout << sum << "\n";

	return 0;
}