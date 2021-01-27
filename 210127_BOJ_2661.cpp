#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 0;
vector<char> num{'1', '2', '3'};
bool isEnded = false;

void findAnswer(string temp) {

	if (isEnded)
		return;

	int ended = temp.size() - 1;

	/////////////////////////////////////////////////
	for (int i = 1; i <= temp.size() / 2; ++i) {

		string a = temp.substr(ended - i, i);
		string b = temp.substr(ended, i);

		if (a == b)
			return;

		ended--;
	}
	/////////////////////////////////////////////////

	if (temp.size() == N && !isEnded) {
		cout << temp << "\n";
		isEnded = true;
		return;
	}

	for (int i = 0; i < 3; ++i) {
		temp.push_back(num[i]);
		findAnswer(temp);
		temp.pop_back();
	}
}

int main() {

	cin >> N;

	findAnswer("");
	return 0;
}