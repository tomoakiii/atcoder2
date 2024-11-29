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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector S(N, vector<int>{});
    int ind = 0;
    int Sind = 0;
    int tcnt = 0;
    int last = -1;
    int ok = 1;

    while(ind < N-1) {         
        if(A[ind] == A[ind+1]) {            
            S[Sind].push_back(A[ind]);
            ind += 2;
        } else {
            if(!S[Sind].empty()) {
                Sind++;
            }
            if (Sind > 0 && A[ind] == A[ind-1]) {
                S[Sind].push_back(A[ind]);
            }
            ind += 1;
        }
    }
    int mx = 0;
    rep(i,N) {
        if(S[i].size() == 0) continue;
        chmax(mx, 2);
        map<int, int> mp;
        mp[S[i][0]] = 0;        
        int cnt = 0;
        int last = -1;
        for(int j=1;j<S[i].size();j++) {
            if(mp.count(S[i][j]) == 0) {       
            } else if (mp[S[i][j]] > last) {
                last = mp[S[i][j]];
            }
            cnt = j - last;
            mp[S[i][j]] = j;
            chmax(mx, 2*cnt);
        }
    }
    cout << mx << endl;
    return 0;
}