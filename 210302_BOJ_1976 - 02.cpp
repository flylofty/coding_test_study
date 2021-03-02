#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v(201);
vector<int> p(1001);

int Find(int a) {
	if (v[a] == a) return a;
	else return v[a] = Find(v[a]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b)
		return true;
	
	if (a < b)
		v[b] = a;
	else
		v[a] = b;

	return true;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; ++i)
		v[i] = i;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int a; cin >> a;

			if (a)
				Union(i, j);
		}
	}

	for (int i = 0; i < M; ++i)
		cin >> p[i];

	int i = 1;
	for (; i < M; ++i) {
		if (v[p[i - 1]] != v[p[i]])
			break;
	}

	if (i == M)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}