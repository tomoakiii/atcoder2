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
    vector<deque<ll>> A(M);
    vector match(N, vector<int>{});
    queue<pair<int,int>> que;
    rep(i,M) {
        int k; cin>>k;
        rep(j,k) {
            int a; cin>>a; a--;
            A[i].push_back(a);            
        }
        int a = A[i].front();
        match[a].push_back(i);
        if(match[a].size() == 2) {
            que.push({match[a][0], match[a][1]});
        }
    }
    while(!que.empty()) {
        auto [i,j] = que.front();
        que.pop();
        A[i].pop_front();
        A[j].pop_front();
        if(A[i].size() > 0){
            int a = A[i].front();
            match[a].push_back(i);
            if(match[a].size() == 2) {
                que.push({match[a][0], match[a][1]});
            }
        }
        if(A[j].size() > 0) {
            int a = A[j].front();
            match[a].push_back(j);
            if(match[a].size() == 2) {
                que.push({match[a][0], match[a][1]});
            }
        }
    }
    rep(i,M) if(A[i].size() > 0) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}