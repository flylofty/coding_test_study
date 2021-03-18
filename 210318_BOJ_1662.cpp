#include <iostream>
#include <string>

using namespace std;

string s;

pair<int, int> findAnswer(int start) {

	int count = 0;
	int i = start;
	for (; i < s.size(); ++i) {

		if ('0' <= s[i] && s[i] <= '9') {

			if (s[i + 1] == '(') {
				pair<int, int> p = findAnswer(i + 2);
				count = count + (s[i] - '0') * p.first;
				i = p.second;
			}
			else
				count++;
		}
		else if (s[i] == ')')
			return { count, i };
	}

	return {count, i};
}

int main() {

	cin >> s;
	cout << findAnswer(0).first << "\n";

	return 0;
}


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s;
//
//void expandString(int index) {
//
//	int mul = s[index - 1] - '0';
//
//	int i = index + 1;
//	string t, t3;
//	while (s[i] != ')') {
//		t.push_back(s[i++]);
//	}
//
//	string t2;
//	for (int j = 0; j < mul; ++j)
//		t2 = t2 + t;
//
//	t = s.substr(0, index - 1);
//	t3 = s.substr(i + 1, s.size() - i - 1);
//
//	s = t + t2 + t3;
//}
//
//int main() {
//
//	cin >> s;
//
//	for (int i = s.size() - 1; i >= 0; --i) {
//		if ('1' <= s[i] && s[i] <= '9') {
//			if (s[i + 1] == '(') {
//				expandString(i + 1);
//			}
//		}
//	}
//
//	cout << s.size() << "\n";
//
//	return 0;
//}