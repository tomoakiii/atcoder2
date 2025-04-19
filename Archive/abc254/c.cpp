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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector v(K, vector<ll>{});  
    rep(i, K) {
        int j = i;
        while(j < N) {
            v[i].emplace_back(A[j]);
            j += K;
        }
        sort(v[i].begin(), v[i].end());
    }
    bool flg = true;
    ll lst = 0;
    int j = 0;
    while(flg){
        rep(i, K) {
            if(j >= v[i].size()){
                flg = false;
                break;
            }
            if (v[i][j] < lst) {
                cout << "No" << endl;
                return 0;
            }
            lst = v[i][j];
        }
        j++;
    }
    cout << "Yes" << endl;
    return 0;
}