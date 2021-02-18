#include <iostream>
#include <string>
#include <vector>

using namespace std;

string bigInt(string a, string b) {

	if (a.empty())
		a = "0";
	if (b.empty())
		b = "0";

	if (a.size() < b.size()) {
		string temp = a;
		a = b;
		b = temp;
	}

	int i = a.size() - 1;
	int j = b.size() - 1;

	int num = a[i--] + b[j--] - '0' - '0';
	int up = num / 10;
	num = num % 10;

	string result;
	result.push_back('0' + num);

	while (i >= 0 && j >= 0) {
		num = a[i--] + b[j--] - '0' - '0' + up;
		up = num / 10;
		num = num % 10;
		string temp;
		temp.push_back('0' + num);
		result = temp + result;
	}

	while (i >= 0) {
		num = a[i--] - '0' + up;
		up = num / 10;
		num = num % 10;
		string temp;
		temp.push_back('0' + num);
		result = temp + result;
	}

	if (up == 1) {
		string temp;
		temp.push_back('0' + up);
		result = temp + result;
	}

	return result;
}

int main() {

	string Combination[101][101] = {};
	Combination[1][0] = "1";
	Combination[1][1] = "1";
	for (int i = 2; i <= 100; i++) {
		Combination[i][0] = "1";
		for (int j = 1; j <= i; j++) {
			Combination[i][j] = bigInt(Combination[i - 1][j - 1], Combination[i - 1][j]);
		}
	}

	int n, r;
	cin >> n >> r;

	cout << Combination[n][r] << "\n";
	return 0;
}