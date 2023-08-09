//cses removing digits
#include <bits/stdc++.h>
using namespace std;
//state -> dp[i] states the minimum no of steps required to reach i to 0
void solve(){
    int n;
    cin>>n;
    vector <int> dp(n + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(char ch : to_string(i)){
            dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
        }
    }
    cout<<dp[n]<<"\n";
}
int main(){
    solve();
    return 0;
}
