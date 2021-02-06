#include <iostream>
#include <vector>

using namespace std;

int T = 0;
int N = 0;
//vector<int> v;
//vector<bool> visit;
int v[1001];
bool visit[1001];
int cnt = 0;
int pre = 0;

void findAnswer(int s) {

	visit[s] = true;

	if (pre == v[s]) {
		cnt++;
		return;
	}
	else {
		findAnswer(v[s]);
	}
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> v[i];
		}

		for (int i = 1; i <= N; ++i)
			visit[i] = false;

		for (int i = 1; i <= N; ++i) {
			if (!visit[i]) {
				pre = i;
				findAnswer(i);
			}
		}

		cout << cnt << "\n";
		
		cnt = 0;
	}

	return 0;
}