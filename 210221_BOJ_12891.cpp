#include <iostream>
#include <string>
#include <vector>

using namespace std;

int S, P;
vector<int> minimum(4 ,0);
vector<int> cnt(4, 0);

bool isGood() {
	for (int i = 0; i < 4; ++i) {
		if (cnt[i] < minimum[i])
			return false;
	}
	return true;
}

int indexNumber(char ch) {
	if (ch == 'A')
		return 0;
	else if (ch == 'C')
		return 1;
	else if (ch == 'G')
		return 2;
	else if (ch == 'T')
		return 3;
}

int main() {

	cin >> S >> P;

	string str; cin >> str;

	for (int i = 0; i < 4; ++i) {
		cin >> minimum[i];
	}

	for (int i = 0; i < P; ++i) {
		int insert = indexNumber(str[i]);
		cnt[insert]++;
	}

	int result = 0;

	if (isGood())
		result++;

	for (int i = 1; i <= str.size() - P; ++i) {
		int remove = indexNumber(str[i - 1]);
		cnt[remove]--;
		int insert = indexNumber(str[i - 1 + P]);
		cnt[insert]++;
		if (isGood())
			result++;
	}

	cout << result << "\n";

	return 0;
}

// 연속된 부분문자열이라고 생각하지 않고 작성한 코드;;;;;
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int S, P;
//vector<char> arr{ 'A', 'C', 'G', 'T' };
//vector<int> store(4, 0);
//vector<int> minimum;
//
//int main() {
//
//	cin >> S >> P;
//
//	string str; cin >> str;
//
//	for (int i = 0; i < str.size(); ++i) {
//		if (str[i] == 'A')
//			store[0]++;
//		else if (str[i] == 'C')
//			store[1]++;
//		else if (str[i] == 'G')
//			store[2]++;
//		else if (str[i] == 'T')
//			store[3]++;
//	}
//
//	for (int i = 0; i < 4; ++i) {
//		int num; cin >> num;
//
//		if (store[i] < num) {
//			cout << "0\n";
//			return 0;
//		}
//	}
//
//	return 0;
//}