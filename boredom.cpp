//codeforces :: boredom
#include <bits/stdc++.h>
using namespace std;
//state - > dp[i] = max points that he can get upto i;
int main(){
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector <long long int> cnt(100006, 0);
    for(auto e: a){
        cnt[e]++;
    }
    vector <long long int> dp(100006, 0);
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2; i <= 100005; i++){
        dp[i] = max(dp[i - 1] , dp[i - 2] + i * 1LL * cnt[i]);
        
    }
    cout<<dp[100005]<<"\n";
    return 0;
}
