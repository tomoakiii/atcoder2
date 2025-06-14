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
    ll N,M;
    cin >> N >> M;
    vector<string> A(2*N);
    rep(i,2*N) cin>>A[i];
    vector<pair<int,int>> ord(2*N);
    rep(i,2*N) ord[i].second = i;
    auto win = [](char a, char b)->int{
        if(a=='G'){
            if(b=='G') return -1;
            if(b=='C') return 0;
            if(b=='P') return 1;            
        } else if (a=='C') {
            if(b=='G') return 1;
            if(b=='C') return -1;
            if(b=='P') return 0;
        } else {
            if(b=='G') return 0;
            if(b=='C') return 1;
            if(b=='P') return -1;
        }
    };
    rep(j, M){
        rep(i, N) {
            int a = ord[2*i].second;
            int b = ord[2*i+1].second;
            int w = win(A[a][j], A[b][j]);
            if(w == 0) ord[2*i].first--;
            else if(w == 1) ord[2*i+1].first--;
        }
        sort(ord.begin(), ord.end());
    }
    rep(i,2*N) cout<<ord[i].second+1<<endl;

    return 0;
}
