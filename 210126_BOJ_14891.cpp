#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> contact;

void input() {
	v.assign(5, vector<int>(8));
	for (int i = 1; i <= 4; ++i) {
		string temp; cin >> temp;
		for (int j = 0; j < 8; ++j) {
			v[i][j] = temp[j] - '0';
		}
	}

	contact.assign(4, vector<int>(2, 0));
	for (int i = 1; i <= 3; ++i) {
		contact[i][0] = 2;
		contact[i][1] = 6;
	}
}

int lotation(int current, int dir) { // 회전방법

	int pre;

	if (dir == 1) { // 시계
		pre = current - 1;
		if (pre == -1) pre = 7;
	}
	else { // 반시계
		pre = (current + 1) % 8;
	}

	return pre;
}

void findAnswer() {
	
	int K = 0;
	cin >> K;

	vector<vector<int>> rCase{ { 0, 1, -1, 1, -1 }, { 0, -1, 1, -1, 1 } }; // 회전의 경우
	vector<bool> isPossible;

	while (K--) { // 극이 같으면 회전하지 않는다 v[i][j]

		int num, dir;
		cin >> num >> dir; // -1 : 반시계, 1 : 시계

		int Case = 0;
		for (int i = 0; i < 2; ++i) { // 회전하는 경우 찾기
			if (rCase[i][num] == dir) 
				Case = i;
		}

		isPossible.assign(5, false);
		isPossible[num] = true;

		for (int i = num; i <= 3; ++i) {
			
			if (v[i][contact[i][0]] == v[i + 1][contact[i][1]]) // 극이 같음
				break;

			isPossible[i + 1] = true;
		}

		for (int i = num - 1; i >= 1; --i) {

			if (v[i + 1][contact[i][1]] == v[i][contact[i][0]])
				break;

			isPossible[i] = true;
		}

		for (int i = 1; i <= 4; ++i) {
			if (isPossible[i]) {
                
				if (i == 1) {
					contact[i][0] = lotation(contact[i][0], rCase[Case][i]);
				}
				else if (i == 2 || i == 3) {
					contact[i - 1][1] = lotation(contact[i - 1][1], rCase[Case][i]);
					contact[i][0] = lotation(contact[i][0], rCase[Case][i]);
				}
				else if (i == 4) {
					contact[i - 1][1] = lotation(contact[i - 1][1], rCase[Case][i]);
				}

			}
		}

	}

	int sum = 0;
	
	// N극 == 0, S 극 == 1
	if (v[1][(contact[1][0] + 6) % 8] == 1)
		sum += 1;
	if (v[2][(contact[1][1] + 2) % 8] == 1)
		sum += 2;
	if (v[3][(contact[2][1] + 2) % 8] == 1)
		sum += 4;
	if (v[4][(contact[3][1] + 2) % 8] == 1)
		sum += 8;

	cout << sum << "\n";
}

int main() {

	input();
	findAnswer();

	return 0;
}