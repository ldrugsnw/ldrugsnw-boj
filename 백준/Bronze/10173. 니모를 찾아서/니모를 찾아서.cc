#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char ans[] = { 'N','E','M','O','n','e','m','o' };
	while (1) {
		string str;
		getline(cin, str);
		if (str == "EOI") {
			break;
		}
		int cnt = 0;
		for (int i = 0; i < str.size() - 3; ++i) {
			if (str[i] == 'N' || str[i] == 'n') {
				string strNemo = str.substr(i, 4);
				for (int j = 0; j < strNemo.size(); ++j) {
					for (int k = 0; k < sizeof(ans) / sizeof(char); ++k) {
						if (strNemo[j] == ans[k]) {
							++cnt;
						}
					}
				}
				if (cnt == 4) {
					cout << "Found\n";
					break;
				}
				else {
					cnt = 0;
				}
			}
		}
		if (cnt == 0) {
			cout << "Missing\n";
		}
	}

	return 0;
}