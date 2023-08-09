
#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
//state -> dp[i] states the number of ordered ways to get sum i
void solve(){
    int n, x;
    cin>>n>>x;
    vector <int> c(n);
    vector <long long> dp(x + 1);
    for(int i = 0; i < n; i++){
        cin>>c[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= x; w++){
            if(w - c[i - 1] >= 0){
                dp[w] = dp[w] + dp[w - c[i - 1]];
                dp[w] %= MOD;
            }
        }
    }
    cout<<dp[x]<<"\n";
}
int main(){
    solve();
    return 0;
}
