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
    ll cnt = 0;
    rep(i, N){
        string s;
        cin >> s;
        if (s == "Takahashi") cnt++;
    }

    cout << cnt << endl;
    return 0;
}