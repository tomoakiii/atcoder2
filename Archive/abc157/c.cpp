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
    vector<int> d(N,-1);
    rep(i,M){
        int s,c;
        cin>>s>>c;
        s--;
        if(d[s] != -1 && d[s] != c) {
            cout<<-1<<endl;
            return 0;
        }
        d[s] = c;
    }
    if(d[0] == 0 && N > 1) {
        cout << -1 << endl;
        return 0;
    }
    if(N == 1 && d[0] == -1) {
        cout<<0<<endl;
        return 0;
    }
    if(d[0] == -1) d[0] = 1;
    for(int i=1;i<N;i++) {
        if(d[i] == -1) d[i] = 0;
    }
    for(auto dd:d) cout<<dd;
    cout<<endl;
    return 0;
}