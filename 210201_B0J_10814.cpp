#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first > b.first) {
		return false;
	}
	else if (a.first < b.first) {
		return true;
	}
	else {
		if (a.second > b.second) {
			return false;
		}
		else
			return true;
	}
}

int N = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<pair<int, int>> v(N);
	vector<string> s(N);

	for (int i = 0; i < N; ++i) {
		int a; string b;
		cin >> a >> b;
		v[i].first = a;
		v[i].second = i;
		s[i] = b;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << " " << s[v[i].second] << "\n";
	}

	return 0;
}

//struct cmp {
//	bool operator()(const pair<pair<int, string>, int> &a, const pair<pair<int, string>, int> &b) {
//		if (a.first.first > b.first.first) {
//			return true;
//		}
//		else if (a.first.first < b.first.first) {
//			return false;
//		}
//		else {
//			if (a.second > b.second) {
//				return true;
//			}
//			else
//				return false;
//		}
//	}
//};
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	
//	cin >> N;
//	priority_queue<pair<pair<int, string>, int>, vector<pair<pair<int, string>, int>>, cmp> pq;
//
//	for (int i = 0; i < N; ++i) {
//		pair<pair<int, string>, int> temp;
//		cin >> temp.first.first >> temp.first.second;
//		temp.second = i + 1;
//		pq.push(temp);
//	}
//
//	while (!pq.empty()) {
//		cout << pq.top().first.first << " " << pq.top().first.second << "\n";
//		pq.pop();
//	}
//
//	return 0;
//}