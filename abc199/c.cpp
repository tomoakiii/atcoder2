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
    string S;
    cin >> N >> S >> Q;
    bool flg = false;
    while(Q--){
        int T,A,B; cin>>T>>A>>B;
        if(T==2) flg = !flg;
        else {
            A--, B--;
            if(flg) {
                A += N;
                A = A % (2*N);
                B += N;
                B = B % (2*N);
            }
            
            swap(S[A], S[B]);
        }
    }
    if(flg) rep(i,N) swap(S[i], S[i+N]);
    cout<<S<<endl;
    return 0;
}