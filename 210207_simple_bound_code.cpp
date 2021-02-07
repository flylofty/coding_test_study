#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v{ 1, 2, 3, 1, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 3, 1 };
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << "\n";

	// 1 1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 3
	// 1 : 7개, 2 : 5개, 3 : 6개

	for (int i = 1; i <= 3; ++i) {
		
		int number = upper_bound(v.begin(), v.end(), i)
			- lower_bound(v.begin(), v.end(), i);
		
		cout << i << " : " << number << " 개 \n";
	}

	// 1 : 7 개
	// 2 : 5 개
	// 3 : 6 개

	return 0;
}