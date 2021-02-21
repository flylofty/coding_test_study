#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L = 0;
int C = 0;
vector<char> v;
vector<string> ans;

void findAnswer(string t, int now) {

	if (t.size() == L) {

		int mo = 0, ja = 0;
		for (int i = 0; i < t.size(); ++i) {
			if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')
				mo++;
			else
				ja++;
		}

		if (mo >= 1 && ja >= 2 && mo + ja == L) {
			sort(t.begin(), t.end());
			ans.push_back(t);
		}

		return;
	}
	else {
		for (int i = now; i < v.size(); ++i) {
			t.push_back(v[i]);
			findAnswer(t, i + 1);
			t.pop_back();
		}
	}

}

int main() {

	cin >> L >> C;
	for (int i = 0; i < C; ++i) {
		char ch; cin >> ch;
		v.push_back(ch);
	}

	findAnswer("", 0);

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << "\n";
	}

	return 0;
}

// 틀린 코드
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//int L = 0;
//int C = 0;
//vector<char> mo; // 최소 한 개의 모음
//vector<char> ja; // 최소 두 개의 자음
//int n, m;
//vector<string> ans;
//
//void findAnswer(string N, string M, int p1, int p2) { // 모음의 개수, 자음의 개수
//
//	if (N.size() < n) {
//		for (int i = p1 + 1; i < mo.size(); ++i) {
//			N.push_back(mo[i]);
//			findAnswer(N, M, i, p2);
//			N.pop_back();
//		}
//	}
//	else if (M.size() < m) {
//		for (int i = p2 + 1; i < ja.size(); ++i) {
//			M.push_back(ja[i]);
//			findAnswer(N, M, p1, i);
//			M.pop_back();
//		}
//	}
//	else {
//		ans.push_back(N + M);
//		sort(ans[ans.size() - 1].begin(), ans[ans.size() - 1].end());
//	}
//}
//
//int main() {
//
//	cin >> L >> C;
//	for (int i = 0; i < C; ++i) {
//		char ch; cin >> ch;
//		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//			mo.push_back(ch);
//		else
//			ja.push_back(ch);
//	}
//
//	sort(mo.begin(), mo.end());
//	sort(ja.begin(), ja.end());
//
//	for (int i = 1; i <= mo.size(); ++i) {
//		n = i;
//		m = L - i;
//		findAnswer("", "", -1, -1);
//	}
//
//	sort(ans.begin(), ans.end());
//	for (int i = 0; i < ans.size(); ++i) {
//		cout << ans[i] << "\n";
//	}
//
//	return 0;
//}