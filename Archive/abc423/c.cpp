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
    ll N,R;
    cin >> N >> R;
    vector<ll> A(N);
    ll fst = INF, lst = -1;
    rep(i,N) {
        cin>>A[i];
        if(A[i] == 0) {
            chmin(fst, i);
            chmax(lst, i);
        }
    }    
    ll ans = 0;
    int now = R;
    if(fst < R) {        
        while(now > 0 && now > fst+1) {
            if(A[now-1] == 1) {
                ans++;
                A[now-1] = 0;
            }
            now--;
        }
        ans++;
        A[fst] = 1;
        while(now < R) {            
            if(A[now] == 0) {
                A[now] = 1;
                ans++;
            }
            now++;
        }
    }
    if(lst >= R) {
        while(now < N-1 && now < lst) {
            if(A[now] == 1) {
                ans++;
                A[now] = 0;
            }
            now++;
        }
        ans++;
        A[lst] = 1;
        while(now > 0) {
            if(A[now-1] == 0) {
                A[now-1] = 1;
                ans++;
            }
            now--;
        }
    }
    cout << ans << endl;
    return 0;
}