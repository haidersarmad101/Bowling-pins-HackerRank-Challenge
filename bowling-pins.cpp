#include <bits/stdc++.h>
using namespace std;

const int Maxn = 301;

int n, t;
int nim[Maxn];
char str[Maxn];

int main() {
	for (int i = 1; i < Maxn; i++) {
		bool S[i] = {};
		for (int j = 0; j < (i + 1) / 2; j++)
			S[nim[j] ^ nim[i - 1 - j]] = true;

		for (int j = 0; j < i / 2; j++)
			S[nim[j] ^ nim[i - 2 - j]] = true;

		int v = 0;
		while (S[v]) v++;
		nim[i] = v;
	}
	cin >> t;

	while (t--) {
		cin >> n;
		cin >> str;
		int res = 0;
		for (int i = 0; i < n; i++)
			if (str[i] == 'I') {
				int j = i;
				while (j < n && str[j] == 'I')
					j++;
				res ^= nim[j - i];
				i = j;
			}
		cout << (res ? "WIN" : "LOSE") << endl;
	}
	return 0;
}