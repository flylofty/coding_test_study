#include <iostream>

using namespace std;

int main() {

	int L, P, V;

	int CASE = 0;
	while (1) {

		cin >> L >> P >> V;

		if (!(L*P*V))
			return 0;

		CASE++;

		if (V % P <= L)
			cout << "Case " << CASE << ": " << (V / P) * L + (V % P) << "\n";
		else
			cout << "Case " << CASE << ": " << (V / P) * L + L << "\n";
	}

	return 0;
}