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
    vector<int> C(N), A(N);
    rep(i,N-1) cin>>C[i+1];    
    rep(i,N-1) cin>>A[i+1];
    ll cnt = 0;
    for(int i = N-1; i>0; i--) {
        if(A[i] == 0) continue;
        int mn = INFi;
        bool flg = false;
        int nx = -1;
        for(int j = i-C[i]; j<i; j++) {
            if(mn > j-C[j]) {
                nx = j;
                mn = j - C[j];
            }            
            if(A[j] == 0) continue;            
            flg = true;
            cnt++;
            break;
        }
        if(!flg) {
            A[nx] = 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}