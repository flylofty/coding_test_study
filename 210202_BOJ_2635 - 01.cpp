#include <iostream>
#include <vector>

using namespace std;

int main() {

	int first = 0;
	cin >> first;

	vector<int> answer;
	int Max = 0;

	for (int i = first; i >= 0; --i) {
		vector<int> temp;
		temp.push_back(first);
		temp.push_back(i);
		int next = first - i;
		while (next >= 0) {
			temp.push_back(next);
			next = temp[temp.size() - 2] - temp[temp.size() - 1];
		}

		if (temp.size() > Max) {
			Max = temp.size();
			answer.clear();
			answer = temp;
		}
	}

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";
	cout << "\n";

	return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int first = 0;
//
//void findAnswer() {
//
//	vector<int> answer;
//	int Max = 0;
//	int left = 0;
//	int right = first;
//
//	while (left <= right) {
//		int mid = (left + right) / 2;
//
//		vector<int> temp;
//		temp.push_back(first);
//		temp.push_back(mid);
//		int next = first - mid;
//		while (next >= 0) {
//			temp.push_back(next);
//			next = temp[temp.size() - 2] - temp[temp.size() - 1];
//		}
//
//		if (temp.size() > Max) {
//			Max = temp.size();
//			answer.clear();
//			answer = temp;
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	cout << answer.size() << "\n";
//	for (int i = 0; i < answer.size(); ++i)
//		cout << answer[i] << " ";
//	cout << "\n";
//}
//
//int main() {
//
//	cin >> first;
//	findAnswer();
//
//	return 0;
//}