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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll L,N,C;
    cin >> L >> N >> C;
    ll SoC = C;
    ll last=0;
    rep(i,N){
        ll p,w;
        cin>>p>>w;
        ll dist = p-last;
        if(dist > SoC){
            cout<<-1<<endl;
            return 0;
        }
        SoC -= dist;
        SoC += w;
        chmin(SoC,C);
        last = p;
    }
    if(L-last>SoC){
        cout<<-1<<endl;
        return 0;
    }
    SoC -= (L-last);
    cout<<SoC<<endl;
    return 0;
}