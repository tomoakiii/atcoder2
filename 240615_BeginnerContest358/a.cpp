#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string s, t;
    cin >> s >> t;
    string s2 = s + " " + t;
    if (s2 == "AtCoder Land") {
        cout << "Yes" << endl;
    } else 
    {
        cout << "No" << endl;
    }
    return 0;
}