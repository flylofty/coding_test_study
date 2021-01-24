#include <iostream>
#include <vector>

using namespace std;

vector<int> po(10000001, 0);
vector<int> ne(10000001, 0);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> num;

		if (num >= 0) {
			po[num]++;
		}
		else {
			ne[num * -1]++;
		}
	}

	int M = 0;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		cin >> num;

		if (num >= 0)
			cout << po[num] << " ";
		else
			cout << ne[num * -1] << " ";
	}
	cout << "\n";

	return 0;
}

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main() {
//
//	int num;
//	
//	int N = 0;
//	cin >> N;
//
//	map<int, int> m;
//	for (int i = 0; i < N; ++i) {
//		cin >> num;
//
//		auto it = m.find(num);
//
//		if (it == m.end()) {
//			m.insert({ num, 1 });
//		}
//		else {
//			m[num]++;
//		}
//	}
//
//	int M = 0;
//	cin >> M;
//	for (int i = 0; i < M; ++i) {
//
//		cin >> num;
//
//		auto it = m.find(num);
//
//		if (it == m.end())
//			cout << "0 ";
//		else
//			cout << m[num] << " ";
//	}
//	cout << "\n";
//
//	return 0;
//}