#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    int st = -1, st2 = -1, edX = -1, edY = -1;
    ll cnt = 0;
    rep(i,N) {
        if(A[i] < Y || A[i] > X) {
            st = -1;
            edX = -1, edY = -1;
        } else {
            if(st == -1) st = i;            
            if(A[i] == X) {
                chmax(edX, i);
            }
            if(A[i] == Y) {
                chmax(edY, i);
            }  
            st2 = min(edX, edY);
            if(st2 != -1) {
                cnt += st2-st+1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
