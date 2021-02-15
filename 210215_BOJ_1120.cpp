#include <iostream>
#include <string>

using namespace std;

string A, B;

int findMin(string& A, string& B) {

	int Min = 51;
	for (int i = 0; i <= B.size() - A.size(); ++i) {

		int count = 0;
		for (int j = 0; j < A.size(); ++j) {
			if (A[j] != B[i + j])
				count++;
		}

		if (Min > count)
			Min = count;
	}

	return Min;
}

int main() {

	cin >> A >> B;

	cout << findMin(A, B) << "\n";

	return 0;
}