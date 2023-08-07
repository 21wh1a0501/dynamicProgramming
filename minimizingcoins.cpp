//cses minimizing coins
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
//dp -> finding no of minimal ways
//dp state -> dp[i] is the minimal no ways to get sum i;
void solve(){
    int n, t;
    cin>>n>>t;
    vector <int> dp(t + 1, 1e9);
    vector <int> coins(n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= t; i++){
        for(int j = 0; j < n; j++){ // transition
            if(i - coins[j] >= 0){
                dp[i] =  min(dp[i], dp[i - coins[j]] + 1);
           }
        }
    }
    if(dp[t] == 1e9 ) cout<<-1<<"\n";//subproblem
    else cout<<dp[t]<<"\n";
    
}
int main()
{
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
