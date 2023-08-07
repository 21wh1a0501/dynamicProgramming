//cses dicecombinations

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
//dp -> finding no of ways
//dp state -> dp[i] is the no of ways to through sum i;
void solve(){
    int n;
    cin>>n;
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){ // transition
            if(j > i){
                break;
            }
            dp[i] += dp[i - j];
        }
    }
    cout<<dp[n]<<"\n";//subproblem
    
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
