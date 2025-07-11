#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,X;
    cin >> N>>X;    
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    X--;
    vector<bool> ans(N);
    queue<int> que;
    que.push(X);
    ans[X] = true;
    int cnt = 1;
    while(!que.empty()) {
        int q = que.front();
        que.pop();
        if(ans[A[q]]) continue;
        que.push(A[q]);
        ans[A[q]] = true;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}