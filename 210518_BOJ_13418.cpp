#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> II;
int N, M, entrance;
int enter;
vector<II> up;
vector<II> down;
int group[1001];

int find(int a) {
	if (a == group[a]) return a;
	else return group[a] = find(group[a]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return true;

	group[b] = a;
	return false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	cin >> entrance >> entrance >> entrance;

	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;

		if (c == 0)
			up.push_back({ a, b });
		else
			down.push_back({ a, b });
	}

	int res1 = 0, res2 = N - 1;

	for (int i = 1; i <= N; ++i)
		group[i] = i;

	for (int i = 0; i < up.size(); ++i)
		if (!Union(up[i].first, up[i].second)) res1++;

	for (int i = 1; i <= N; ++i)
		group[i] = i;

	for (int i = 0; i < down.size(); ++i)
		if (!Union(down[i].first, down[i].second)) res2--;

	if (entrance == 0)
		res1++, res2++;

	cout << (res1 * res1) - (res2 * res2);

	return 0;
}