#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<pair<ll,int>> A(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i;
    }
    vector<ll> ans(N,0);
    int r = 1;
    while(A.size() > 1){
        vector<pair<ll,int>> B;
        ll M = A.size();
        for(int i=0; i<M; i+=2) {
            if(A[i].first > A[i+1].first) {
                swap(A[i], A[i+1]);
            }
            B.push_back(A[i+1]);
            ans[A[i].second] = r;
        }
        r++;
        swap(A,B);
    }
    rep(i,N) cout<<ans[i]<<" \n"[i==N-1];
}