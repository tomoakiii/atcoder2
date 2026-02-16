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
    ll N,D;
    cin >> N >> D;
    vector<ll> A(N);
    ll ans = 0;
    rep(i,N) {
        cin>>A[i];
        cout << A[i] << " ";
    }
    cout << endl;
    rep(i,N) {
        int r = i;
        for(int j=i; j<N; j++) {
            vector<ll> t;
            for(int k=i; k<=j; k++) {
                t.push_back(A[k]);
            }
            sort(t.begin(), t.end());
            int flg = true;
            rep(k, t.size()-1) {
                if(t[k+1] - t[k] < D) {
                    flg = false;
                    break;
                }
            }
            if(!flg) break;
            r = j;
        }
        cout << i << " : " << r << " --- " << r-i+1 << endl;
        ans += r-i+1;
    }
    cout << ans << endl;
    return 0;
}