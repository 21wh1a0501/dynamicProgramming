//cses bookshop
#include <bits/stdc++.h>
using namespace std;
//state -> dp[r][c]  no of ways required to reach r, c
const int MOD = 1e9 + 7;
void solve(){
    int n, x, i, j;
    cin>>n>>x;
    vector <int> price(n), pages(n);
    for (int &v : price) cin>>v;
    for (int &v : pages) cin>>v;
    vector<vector<int>> dp(n + 1, vector <int>(x + 1, 0));
    for(i = 1; i <= n; i++){ //pages
        for(j = 0; j <= x; j++){//price
            dp[i][j] = dp[i - 1][j];
            int left = j - price[i - 1];
            if(left >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i - 1]);
            }
        }
    }
    cout<<dp[n][x]<<"\n";
}
int main(){
    solve();
    return 0;
}
