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
    vector<pair<ll,int>> A(1<<N);    
    rep(i,1<<N) {
        cin>>A[i].first;
        A[i].second = 1+i;
    }
    while(A.size() > 2) {
        vector<pair<ll,int>> B;
        rep(i, A.size()/2) {
            if(A[2*i].first > A[2*i+1].first) {
                B.push_back(A[2*i]);
            } else {
                B.push_back(A[2*i+1]);
            }            
        }
        swap(A,B);
    }
    if(A[0].first > A[1].first) cout << A[1].second << endl;
    else cout << A[0].second << endl;
    return 0;
}