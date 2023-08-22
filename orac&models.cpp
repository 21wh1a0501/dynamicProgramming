//codeforces : orac and models
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, arr[N] , dp[N];
//state -> dp(i) = max len of required sequence till index i
int solve(int idx){
    int ans = 1;
    if(dp[idx] != -1){
        return dp[idx];
    }
    for(int i = 1; i * i <= idx; i++){
        if(idx % i == 0){
            if(arr[i] < arr[idx]){
                ans = max(ans, solve(i) + 1);
            }
            if(arr[idx / i] < arr[idx]){
                ans = max(ans, solve(idx / i) + 1);
            }
        }
    }
    return dp[idx] = ans;
}
void answer(){
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, solve(i));
    }
    cout<<ans<<"\n";
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        answer();
    }
}
