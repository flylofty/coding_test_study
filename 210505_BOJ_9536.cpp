#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {

	int T; cin >> T;
	getchar();

	while (T--) {

		string t;
		getline(cin, t);
		t += " ";
		vector<string> sounds;

		string sound;
		for (int i = 0; i < t.size(); ++i) {
			if (t[i] != ' ')
				sound.push_back(t[i]);
			else {
				sounds.push_back(sound);
				sound.clear();
			}
		}

		string c;
		vector <string> cry;
		map<string, string> cries;

		while (1) {
			getline(cin, t);
			t += ' ';

			for (int i = 0; i < t.size(); ++i) {
				if (t[i] != ' ')
					c.push_back(t[i]);
				else {
					cry.push_back(c);
					c.clear();
				}
			}

			if (cry.size() > 3)
				break;

			cries[cry[2]] = cry[0];
			cry.clear();
		}

		for (int i = 0; i < sounds.size(); ++i) {

			if (cries.find(sounds[i]) != cries.end())
				continue;

			cout << sounds[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}