#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<pair<int, int>> AB(N);
    rep(i,N) cin>>AB[i].first>>AB[i].second;
    auto comp = [&](pair<int, int>ab1, pair<int, int>ab2)->bool {
        return ab2.first*(ab1.first+ab1.second)+ab2.second < ab1.first*(ab2.first*1+ab2.second)+ab1.second;
    };
    sort(AB.begin(), AB.end(), comp());
    vector dp(N, vector<ll>(K));
    rep(i,K){
        dp[i][]=
    }
    cout << sm << endl;
    return 0;
}