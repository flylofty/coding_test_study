#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int H = 0;

int main() {

	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> N >> H;
	vector<int> v1(N / 2);
	vector<int> v2(N / 2);
	for (int i = 0; i < N / 2; ++i) {
		cin >> v1[i] >> v2[i];
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int Min = 987654321;
	int cnt = 0;
	for (int i = 1; i <= H; ++i) {
		
		int r_o = lower_bound(v1.begin(), v1.end(), i) - v1.begin();
		r_o += upper_bound(v2.begin(), v2.end(), H - i) - v2.begin();
		int o = N - r_o;

		if (Min > o) {
			Min = o;
			cnt = 1;
		}
		else if (Min == o) {
			cnt++;
		}
	}

	cout << Min << " " << cnt << "\n";

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N = 0;
//int H = 0;
//vector<int> v;
//
//int main() {
//
//	cin >> N >> H;
//
//	/** 여기서 시간초과 발생 최악의 경우 N == 200,000 X H == 500,000 경우... 1억이 넘는 경우는 많음...
//	v.assign(H, 0);
//	for (int i = 0; i < N; ++i) {
//
//		int o; cin >> o;
//
//		if (i % 2 == 0) {
//			for (int j = H - 1; j > H - 1 - o; --j)
//				v[j]++;
//		}
//		else {
//			for(int j = 0; j < o; ++j)
//				v[j]++;
//		}
//	}
//	**/
//
//	sort(v.begin(), v.end());
//	int Min = v[0];
//	int cnt = 0;
//
//	for (int i = 0; i < v.size(); ++i) {
//		if (Min == v[i]) cnt++;
//		else break;
//	}
//
//	cout << Min << " " << cnt << "\n";
//
//	return 0;
//}