#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<ll> X(N, 0);
    rep(i, N) cin>>X[i];
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return X[i] < X[j]; });
    ll fa = 0;
    int st = -1, gl = -1;
    ll sm = 0;
    while(true){
        st++;
        while(true) {
            if(st == N) {
                cout << sm << endl;
                return 0;
            };
            if(S[ord[st]] == '1') break;        
            if(S[ord[st]] == '0') fa=max((ll)0, fa-1);
            st++;
        }
        while(true) {
            if(gl >= N-1) break;
            if(X[ord[gl+1]] > X[ord[st]] + 2*T) break;
            gl++;
            if(gl>st && S[ord[gl]] == '0') fa++;
        }
        sm += fa;
    }
    return 0;
}