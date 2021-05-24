#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	int idx = 0;
	while (1) {

		idx++;
		string s; 
		cin >> s;

		if (s[0] == '-')
			break;

		stack<char> st;

		for (int i = 0; i < s.size(); ++i) {

			if (st.empty() || st.top() == s[i]) {
				st.push(s[i]);
			}
			else {
				if (st.top() == '{' && s[i] == '}')
					st.pop();
				else
					st.push(s[i]);
			}
		}

		int cnt = 0;
		while (!st.empty()) {

			char right = st.top();
			st.pop();

			char left = st.top();
			st.pop();

			if (left == '{' && right == '{')
				cnt++;
			else if (left == '}' && right == '}')
				cnt++;
			else
				cnt += 2;
		}

		cout << idx << ". " << cnt << "\n";
	}

	return 0;
}