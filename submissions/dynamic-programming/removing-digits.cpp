#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000001];
 
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	
	for  (int i = 0; i < 10; i++) dp[i] = 1;
	for (int i = 10; i <= n; i++) {
		dp[i] = INT_MAX;
		string s = to_string(i);
		for (auto d : s) {
			dp[i] = min(dp[i], dp[i - (d - '0')] + 1);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}

