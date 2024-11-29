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
    ll N,P,Q,R;
    cin >> N>>P>>Q>>R;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> S(N+1);
    rep(i,N) {
        S[i+1] = S[i] + A[i];
    }
    int x=0,y=1,z=2,w=3;
    while(w<=N){
        while(z<w) {
            if(S[w]-S[z] > R) {
                z++;
                continue;
            }
            if(S[w]-S[z] < R) {
                break;
            }
            while(y<z){
                if(S[z]-S[y] > Q) {
                    y++;
                    continue;
                }
                if(S[z]-S[y] < Q) {
                    break;
                }
                while(x<y){
                    if(S[y]-S[x] > P) {
                        x++;
                        continue;
                    }
                    if(S[y]-S[x] < P) {
                        break;
                    }
                    cout << "Yes" << endl;
                    return 0;
                }
                break;
            }
            break;
        }
        w++;
    }
    cout << "No" << endl;
    return 0;
}