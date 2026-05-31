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
    ll N;
    cin >> N;
    ll mn=INF, mx=0;
    int mni, mxi;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        if(chmin(mn,A[i])) mni = i;
        if(chmax(mx,A[i])) mxi = i;
    }
    vector<pair<int,int>> ans;
    auto fneg = [&]()->void{
        for(int i=N-1; i>=1; i--) {
            ans.push_back({i,i-1});
            A[i-1] += A[i];
        }
    };
    auto fpos = [&]()->void{
        rep(i,N-1){
            ans.push_back({i,i+1});
            A[i+1] += A[i];
        }
    };
    if(mx <= 0) fneg();
    else if(mn >= 0) fpos();
    else if(-mn <= mx) {
        rep(i,N) {
            if(i!=mxi) {
                ans.push_back({mxi, i});
                A[i] += A[mxi];
            }
        }
        fpos();
    } else {
        rep(i,N) {
            if(i!=mni) {
                ans.push_back({mni, i});
                A[i] += A[mni];
            }
        }
        fneg();
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x+1<<" "<<y+1<<endl;
    return 0;
}