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
    ll N,M;
    cin >> N >> M;
    ll N1=N/2;
    ll N2=N-N1;
    vector<ll> A(N1),B(N2);
    rep(i,N1) {
        cin>>A[i];A[i]%=M;
    }
    rep(i,N2) {
        cin>>B[i];B[i]%=M;
    }
    reverse(A.begin(),A.end());
    auto func = [&](int n)->vector<ll>{
        vector<ll> v;
        v.push_back(0);
        rep(i,n) {
            vector<ll> v2;
            for(auto x:v){
                if(x%2==1){
                    v2.push_back(x<<1);
                } else {
                    v2.push_back(x<<1);
                    v2.push_back(1 + (x<<1));
                }
            }
            swap(v,v2);
        }
        return v;
    };
    auto ord=func(N1);
    auto ord2=func(N2);
    unordered_map<ll,ll> st[2], st2[2];
    rep(kkk,2){
        for(auto p:ord){
            ll sm = 0;
            rep(i,N1) {
                if(p>>i & 1) {
                    sm += A[i];
                    sm%=M;
                }
            }
            st[p%2][sm]++;
        }
        swap(st,st2);
        swap(A,B);
        swap(N1,N2);
        swap(ord,ord2);
    }
    ll ans = 0;
    for(auto [s,i]:st[0]){
        ll tg=M-s;
        tg%=M;
        if(st2[0].contains(tg))ans+=st2[0][tg]*i;
        if(st2[1].contains(tg))ans+=st2[1][tg]*i;        
    }
    for(auto [s,i]:st[1]){
        ll tg=M-s;
        tg%=M;
        if(st2[0].contains(tg))ans+=st2[0][tg]*i;
    }
    cout<<ans<<endl;
    return 0;
}