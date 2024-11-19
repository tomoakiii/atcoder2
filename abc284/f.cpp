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
    string T;
    cin >> T;
    deque S1(N,'A'), S2(N,'A');
    rep(i,N) S1[i] = T[i];
    rep(i,N) S2[i] = T[N+i];
    reverse(S2.begin(), S2.end());
    map<deque<ll>, bool> mp; 
    rep(i,N+1){
        mp[S1] = true;
        if(mp.count(S2)) {
            for(auto c:S1) cout<<c;
            cout << endl << N-i << endl;
            return 0;
        }
        mp.clear();
        char c = S1.back();
        S1.pop_back();
        char c2 = S2.front();
        S2.pop_front();
        S1.push_back(c2);
        S2.push_back(c);        
    }
    
    cout << -1 << endl;
    return 0;
}