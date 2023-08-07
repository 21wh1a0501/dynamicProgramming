//cses coin combinations I 
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
//dp -> finding no of  ways
//dp state -> dp[i] is the  no ways to get sum i;
void solve(){
    int n, t;
    cin>>n>>t;
    vector <int> dp(t + 1, 0);
    vector <int> coins(n);
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= t; i++){
        for(int j : coins){ // transition
            if(i >= j){
                dp[i] =  (dp[i] + dp[i - j]);
           }
        }
    }
    cout<<dp[t]<<"\n";
    
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
