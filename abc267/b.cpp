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
    int assign[] = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
    string S;
    cin >> S;
    if (S[0] == '1') { 
        cout << "No" << endl;
        return 0;
    }
    vector<int> line(7);
    rep(i,10) {
        if (S[i] == '1') {
            line[assign[i]]++;
        }
    }
    
    int step = 0;
    rep(i, 7) {
        if(step == 0 && line[i] > 0) step = 1;
        else if(step == 1 && line[i] == 0) step = 2;
        else if(step == 2 && line[i] > 0) step = 3;
    }
    if(step == 3) cout <<"Yes"<<endl;
    else cout << "No" << endl;

    return 0;
}