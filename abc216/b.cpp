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
    vector<string> fn(N), ln(N);
    rep(i,N) {
        cin >> fn[i] >> ln[i];
    }
    rep(i,N) for(int j=i+1; j<N; j++) {
        if(fn[i] == fn[j] && ln[i] == ln[j]){
            cout << "Yes" << endl;
            return 0;
        }            
    }
    cout<<"No"<<endl;
    return 0;
}