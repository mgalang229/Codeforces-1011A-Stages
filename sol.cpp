#include <bits/stdc++.h>

using namespace std;

// this function checks if all the letters in the string are at least 2 positions from each other
bool Check(string s) {
	bool checker = true;
	sort(s.begin(), s.end());
	for (int i = 0; i + 1 < (int) s.size(); i++) {
		int x = (s[i] - 'a');
		int y = (s[i + 1] - 'a');
		checker &= (abs(x - y) > 1);
	}
	return checker;
}

// this function calculates the total value of the letters in the string
int GetValue(string s) {
	int total = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		total += (s[i] -'a') + 1;
	}
	return total;
}

// this function checks if the collected string has a size of 'k' and stores the its total value
void GetMin(int temp_size, int k, int& mn, string temp) {
	if (temp_size == k) {
		mn = min(mn, GetValue(temp));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		// collect string subsequences of length 'k' and get its total value
		// don't forget to check if all the letters in the chosen subsequence are at least two
		// positions away in its alphabetical ordering
		string temp = string(1, s[i]);
		GetMin((int) temp.size(), k, mn, temp);
		for (int j = i + 1; j < n; j++) {
			if (Check(temp + string(1, s[j]))) {
				temp += s[j];
				GetMin((int) temp.size(), k, mn, temp);
			}
		}
	}
	cout << (mn == INT_MAX ? -1 : mn) << '\n';
	return 0;
}
