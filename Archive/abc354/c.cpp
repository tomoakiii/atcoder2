#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<ll, ll> pll;

int main(){
    ll N;
    cin >> N;
    vector<pll> AC(N);
    rep(i, N){
        cin >> AC[i].first >> AC[i].second;
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {         
        return AC[i].first > AC[j].first;        
    });    
    ll cost = AC[ord[0]].second;
    vector<bool> drop(N, true);
    ll dcnt = 0;
    for(int i=1; i<N; i++){
        ll ncost = AC[ord[i]].second;
        if (ncost > cost){
            drop[ord[i]] = false;
            dcnt++;
        } else {
            cost = ncost;
        }
    }
    cout << N-dcnt << endl;
    rep(i, N){
        if(drop[i]) cout << i+1 << " ";
    }
    return 0;
}