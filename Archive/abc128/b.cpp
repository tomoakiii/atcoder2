#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N; cin>>N;
    vector<string> S(N);
    vector<ll> P(N);
    vector<pair<string, pair<ll, int>>> SP(N);
    rep(i,N) {
        cin>>SP[i].first>>SP[i].second.first;
        SP[i].second.first *= -1;
        SP[i].second.second = i+1;
    }
    sort(SP.begin(),SP.end());
    for(auto [a,b]: SP) cout<<b.second<<endl;
    return 0;
}