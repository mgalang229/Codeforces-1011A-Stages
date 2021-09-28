#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	// set 'last' to (0 - 2 = -2), so we can include the first letter
	char last = 'a' - 2;
	int ans = 0;
	int len = 0;
	for (int i = 0; i < n; i++) {
		// check if the current letter is at least two positions away from the previous letter
		// (except for the first letter since we need to start with this)
		// calculate the value for every letter and increment 'len'
		// once 'len' is equal to 'k', then print the answer and exit the program
		if (s[i] >= last + 2) {
			last = s[i];
			ans += (s[i] - 'a' + 1);
			len += 1;
			if (len == k) {
				cout << ans << '\n';
				exit(0);
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}
