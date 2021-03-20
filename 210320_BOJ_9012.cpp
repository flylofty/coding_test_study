#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

	int N; 
	cin >> N;

	while (N--) {
		string s;
		cin >> s;

		stack<char> st;
		for (int i = 0; i < s.size(); ++i) {

			if (s[i] == '(')
				st.push('(');

			else if (s[i] == ')') {
				if (st.empty()) {
					st.push(')');
					break;
				}
				else {
					st.pop();
				}
			}
		}

		if (st.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}