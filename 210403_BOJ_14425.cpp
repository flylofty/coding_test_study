#include <iostream>
#include <string>

using namespace std;

const int Size = 26;
int N, M;
string s;

typedef struct Node {
	bool isEnd;
	Node* next;
};

Node* root = (Node *)malloc(26 * sizeof(Node));
Node* pre;

void init(Node* v) {
	for (int i = 0; i < Size; ++i) {
		v[i].isEnd = false;
		v[i].next = NULL;
	}
}

void insert(int index, bool isEnd) {
	if (!isEnd) {
		if (pre[index].next == NULL) {
			pre[index].next = (Node *)malloc(26 * sizeof(Node));
			init(pre[index].next);
		}
		pre = pre[index].next;
	}
	else {
		pre[index].isEnd = true;
	}
}

bool find(int index, bool isEnd) {

	if (isEnd) {
		if (pre[index].isEnd)
			return true;
		else
			return false;
	}

	if (pre[index].next == NULL)
		return false;

	pre = pre[index].next;
	return true;
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	init(root);

	for (int i = 0; i < N; ++i) {

		s; cin >> s;

		pre = root;
		for (int j = 0; j < s.size(); ++j) {
			if (j == s.size() - 1)
				insert(s[j] - 'a', true);
			else
				insert(s[j] - 'a', false);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		cin >> s;
		pre = root;
		int j = 0;
		for (; j < s.size(); ++j) {
			bool isEnd = false;
			if (j == s.size() - 1)
				isEnd = true;
			if (!find(s[j] - 'a', isEnd))
				break;
		}

		if (j == s.size())
			cnt++;
	}

	cout << cnt << "\n";
	return 0;
}