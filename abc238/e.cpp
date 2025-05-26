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
    ll N,Q;
    cin >> N >> Q;
    if(N>Q) {
        cout<<"No"<<endl;
        return 0;
    }
    vector<int> sm(N+1);    
    while(Q--) {
        int l,r;
        cin>>l>>r;
        l--;
        sm[l]++;
        sm[r]--;
    }
    rep(i,N) {
        sm[i+1] += sm[i];
    }
    rep(i,N) {
        if(sm[i] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}