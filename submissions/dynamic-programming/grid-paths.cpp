#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1001][1001];
char grid[1001][1001];
const ll mod = 1e9 + 7;
 
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	
	bool row = true, col = true;
	
	for (int i = 0; i < n; i++) {
		if (grid[i][0] == '.' && col) dp[i][0] = 1;
		else col = false;
		if (grid[0][i] == '.' && row) dp[0][i] = 1;
		else row = false;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == '.') {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}
	
	cout << dp[n - 1][n - 1] % mod << "\n";
	return 0;
}
