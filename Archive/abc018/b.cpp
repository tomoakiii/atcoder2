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
    string S; ll N;
    cin >> S>>N;
    rep(i,N) {
        string T = "";
        int l,r; cin>>l>>r;
        l--,r--;
        for(int i=0; i<l; i++) T.push_back(S[i]);        
        for(int i=r; i>=l; i--) T.push_back(S[i]);
        for(int i=r+1; i<S.size(); i++) T.push_back(S[i]);
        swap(S,T);
    }
    cout << S << endl;
    return 0;
}