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
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<pair<int, int>> grp{};
    bool isLas0 = true;
    int ind;
    rep(i, N) {
        if(isLas0 && S[i] == '1') {
            grp.push_back({i, i});
            ind = grp.size()-1;
            isLas0 = false;
        } else if (S[i] == '1') {          
            grp[ind].second = i;
            isLas0 = false;
        } else {
            isLas0 = true;
        }
    }
    string T = S;
    int indT=0;
    rep(i, grp[K-2].second + 1) {
        T[indT++] = S[i];
    }
    for(int i = grp[K-1].first; i <= grp[K-1].second; i++) {
        T[indT++] = S[i];
    }
    for(int i = grp[K-2].second + 1; i < grp[K-1].first; i++){
        T[indT++] = S[i];
    }
    for(int i = grp[K-1].second + 1; i < N; i++){
        T[indT++] = S[i];
    }
    cout << T << endl;
    return 0;
}