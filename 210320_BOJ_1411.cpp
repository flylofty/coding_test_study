#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 각각 한 쌍씩만 비교하면 됨
int main() {

	ios::sync_with_stdio(0), cin.tie(0);

	int N;
	cin >> N;

	vector<string> v;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;

		map<char, char> m;
		int counter = 0;

		string temp;
		for (int j = 0; j < s.size(); ++j) {
			char ch = s[j];

			if (m.find(ch) == m.end()) {
				counter++;
				m[ch] = counter + '0';
			}

			temp.push_back(m[ch]);
		}
		v.push_back(temp);
	}

	int res = 0;

	for (int i = 0; i < v.size() - 1; ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[i] == v[j]) res++;
		}
	}

	cout << res << "\n";
	return 0;
}

//// 비슷한 단어, 문제 이해를 잘못하여 작성한 풀이...
//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <map>
//
//using namespace std;
//
//int N, M;
//set<string> v;
//vector<char> ch;
//map<char, char> mapping;
//int Max = 0;
//
//void input() {
//
//	bool alpha[26]{ false };
//
//	cin >> N;
//	for (int i = 0; i < N; ++i) {
//		string t; cin >> t;
//		v.insert(t);
//		for (int j = 0; j < t.size(); ++j) {
//			alpha[t[j] - 'a'] = true;
//		}
//	}
//	
//	for (int i = 0; i < 26; ++i) {
//		if (alpha[i]) {
//			mapping['a' + i] = '.';
//			ch.push_back('a' + i);
//		}
//	}
//}
//
//void findMax() {
//
//	int cnt = 0;
//	for (auto it : v) {
//		string temp = it;
//
//		for (int i = 0; i < temp.size(); ++i) {
//			temp[i] = mapping[temp[i]];
//		}
//
//		if (v.find(temp) != v.end())
//			cnt++;
//	}
//
//	if (Max < cnt)
//		Max = cnt;
//}
//
//void findAnswer() {
//
//	M = mapping.size();
//
//	for (int i = 0; i < M - 1; ++i) {
//
//		auto it = mapping.begin();
//		for (int j = 0; j < M; ++j, ++it) {
//			char t = ch[(j + i + 1) % M];
//			it->second = t;
//			mapping[t] = it->first;
//		}
//
//		findMax();
//	}
//
//	cout << Max << "\n";
//}
//
//int main() {
//
//	ios::sync_with_stdio(0), cin.tie(0);
//	input();
//	findAnswer();
//
//	return 0;
//}