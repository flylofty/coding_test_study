#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.first > b.first;
	}
};

int N = 0;
int L = 0;
vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;



void input() {
	cin >> N >> L;
	v.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		cin >> v[i];
	}
}

void findAnswer() {

	int a = 1;
	int b = 1;
	for (int i = 1; i <= N; ++i) {

		pq.push({ v[i], i });

		a = i - L + 1;

		if (a < 1)
			a = 1;

		b = i;

		while (pq.top().second < a || pq.top().second > b) 
			pq.pop();

		cout << pq.top().first << " ";
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	findAnswer();
	return 0;
}

// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>

// using namespace std;

// int N = 0;
// int L = 0;
// vector<int> v;
// map<int, int> m;
// priority_queue<int, vector<int>, greater<int>> pq;
// int a, b;

// void input() {
// 	cin >> N >> L;
// 	v.assign(N + 1, 0);
// 	for (int i = 1; i <= N; ++i) {
// 		cin >> v[i];
// 	}
// }

// bool isIn(int num) {
// 	auto it = m.find(num);

// 	if (it == m.end())
// 		return false;
// 	else if (m[num] == 0)
// 		return false;
// 	else
// 		return true;
// }

// void insert_number() {
// 	auto it = m.find(v[b]);

// 	if (it == m.end()) {
// 		m.insert({ v[b], 1});
// 	}
// 	else {
// 		m[v[b]]++;
// 	}
// }

// void delete_number() {
	
// 	m[v[a]]--;
// }

// void print_number() {
	
// 	while (m[pq.top()] == 0) {
// 		pq.pop();
// 	}
// 	cout << pq.top() << " ";
// }

// void findAnswer() {

// 	a = 1;
// 	b = 1;
// 	for (; b <= L; ++b) {
// 		pq.push(v[b]);
// 		insert_number();
// 		print_number();
// 	}

// 	while (b <= N) {
// 		pq.push(v[b]);
// 		insert_number();
// 		b++;
// 		delete_number();
// 		a++;
// 		print_number();
// 	}
// }

// int main() {
    
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL), cout.tie(NULL);
// 	input();
// 	findAnswer();

// 	return 0;
// }