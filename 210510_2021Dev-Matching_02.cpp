#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int matrix[101][101];

int rotate(int x1, int y1, int x2, int y2) {
	int Min = 10001;

	deque<int> dq;

	for (int i = y1; i <= y2; ++i) {
		dq.push_back(matrix[x1][i]);
		Min = min(Min, matrix[x1][i]);
	}

	for (int i = x1 + 1; i <= x2; ++i) {
		dq.push_back(matrix[i][y2]);
		Min = min(Min, matrix[i][y2]);
	}

	for (int i = y2 - 1; i >= y1; --i) {
		dq.push_back(matrix[x2][i]);
		Min = min(Min, matrix[x2][i]);
	}

	for (int i = x2 - 1; i > x1; --i) {
		dq.push_back(matrix[i][y1]);
		Min = min(Min, matrix[i][y1]);
	}

	dq.push_front(dq[dq.size() - 1]);
	dq.pop_back();

	int idx = 0;
	for (int i = y1; i <= y2; ++i)
		matrix[x1][i] = dq[idx++];

	for (int i = x1 + 1; i <= x2; ++i)
		matrix[i][y2] = dq[idx++];

	for (int i = y2 - 1; i >= y1; --i)
		matrix[x2][i] = dq[idx++];

	for (int i = x2 - 1; i > x1; --i)
		matrix[i][y1] = dq[idx++];

	return Min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= columns; ++j) {
			matrix[i][j] = columns * (i - 1) + j;
		}
	}

	for (int i = 0; i < queries.size(); ++i) {
		answer.push_back(rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3]));
	}

	return answer;
}

int main() {

	//int rows = 6;
	//int columns = 6;
	//vector<vector<int>> queries{ {2,2,5,4}, {3,3,6,6}, {5,1,6,3} };

	//int rows = 3;
	//int columns = 3;
	//vector<vector<int>> queries{ {1, 1, 2, 2}, { 1, 2, 2, 3 }, { 2, 1, 3, 2 }, { 2, 2, 3, 3 } };

	int rows = 100;
	int columns = 97;
	vector<vector<int>> queries{ {1, 1, 100, 97} };

	vector<int> res = solution(rows, columns, queries);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}