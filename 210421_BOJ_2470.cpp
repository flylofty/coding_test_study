#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int po[100000], p = 0;
	int ne[100000], n = 0;

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int num; cin >> num;
		if (num >= 0)
			po[p++] = num;
		else
			ne[n++] = num;
	}

	sort(po, po + p);
	sort(ne, ne + n);

	int res[2], Min = 2000000001, ABS;

	if (p >= 2) {
		ABS = abs(po[0] + po[1]);
		if (Min > ABS) {
			Min = ABS;
			res[0] = po[0];
			res[1] = po[1];
		}
	}

	if (n >= 2) {
		ABS = abs(ne[n - 2] + ne[n - 1]);
		if (Min > ABS) {
			Min = ABS;
			res[0] = ne[n - 2];
			res[1] = ne[n - 1];
		}
	}

	if (p >= 1 && n >= 1) {
		for (int i = 0; i < p; ++i) {
			int index = upper_bound(ne, ne + n, -po[i]) - ne - 1;
			//cout << po[i] << "  " << ne[index] << "  " << index << "\n";
			for (int j = 0; j < 2; ++j) {
				int idx = index + j;
				if (idx < 0 || idx >= n)
					continue;

				ABS = abs(ne[idx] + po[i]);
				if (Min > ABS) {
					Min = ABS;
					res[0] = ne[idx];
					res[1] = po[i];
				}
			}
		}
	}

	cout << res[0] << " " << res[1] << "\n";

	return 0;
}