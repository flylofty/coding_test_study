#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> II;

II alphabet[26];
II L[100];
II R[100];
int l = 0, r = 0;

void findPosition(char ch) {
	if (ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'p' || ch == 'h'
		|| ch == 'j' || ch == 'k' || ch == 'l' || ch == 'b' || ch == 'n' || ch == 'm') {
		R[r++] = alphabet[ch - 'a'];
	}
	else
		L[l++] = alphabet[ch - 'a'];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	char k1[10]{ 'q','w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
	for (int i = 0; i < 10; ++i) alphabet[k1[i] - 'a'] = {0, i};
	char k2[9]{ 'a','s', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
	for (int i = 0; i < 9; ++i) alphabet[k2[i] - 'a'] = { 1, i };
	char k3[7]{ 'z','x', 'c', 'v', 'b', 'n', 'm'};
	for (int i = 0; i < 7; ++i) alphabet[k3[i] - 'a'] = { 2, i };

	for (int i = 0; i < 2; ++i) {
		char ch; cin >> ch;
		findPosition(ch);
	}

	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i) 
		findPosition(s[i]);

	int sum = 0;
	for (int i = 0; i < l - 1; ++i) // 이동시간 + 누르는 시간
		sum = sum + abs(L[i].first - L[i + 1].first) + abs(L[i].second - L[i + 1].second) + 1;

	for (int i = 0; i < r - 1; ++i)
		sum = sum + abs(R[i].first - R[i + 1].first) + abs(R[i].second - R[i + 1].second) + 1;

	cout << sum << "\n";
	return 0;
}