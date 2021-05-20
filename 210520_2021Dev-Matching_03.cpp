#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;

	map<string, int> position;

	for (int i = 0; i < enroll.size(); ++i) {
		answer.push_back(0);
		position[enroll[i]] = i;
	}

	for (int i = 0; i < seller.size(); ++i) {

		string child = seller[i];
		int profit = amount[i] * 100;

		while (child != "-") {

			int a = 0;
			int b = profit * 0.1;

			if (b < 1) {
				a = profit;
				b = 0;
			}
			else {
				a = profit - b;
			}

			answer[position[child]] += a;

			string parent = referral[position[child]];

			child = parent;
			profit = b;
		}
	}

	return answer;
}

int main() {

	/*vector<string> enroll{ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
	vector<string> referral{ "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
	vector<string> seller{ "young", "john", "tod", "emily", "mary" };
	vector<int> amount{ 12, 4, 2, 5, 10 };
	vector<int> res = solution(enroll, referral, seller, amount);*/

	vector<string> enroll{ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
	vector<string> referral{ "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
	vector<string> seller{ "sam", "emily", "jaimie", "edward" };
	vector<int> amount{ 2, 3, 5, 4 };
	vector<int> res = solution(enroll, referral, seller, amount);


	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}