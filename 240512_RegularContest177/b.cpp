#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;    
    string s;
    cin >> s;
    vector<char> ans(0);
    for(int i=N-1; i>=0; i--) {
        if(s[i] == '0') continue;
        rep(j, i+1) ans.push_back('A');
        rep(j, i) ans.push_back('B');
    }

    cout << ans.size() << endl;
    for(auto c: ans) cout << c;
    cout << endl;
    return 0;
}