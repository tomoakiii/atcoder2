#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

using mint = modint998244353;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;
int main(){
    mint ans;
    mint A = 1001;
    mint B = 5;
    mint C = 1000000;
    mint D = 1000000000;
    mint E = 100000;
    ans += 4*E;
    ans += 1000000 * (A+B+C+D);
    ans += 3*D;
    ans += 10000000000*(A+B+C);
    ans += 2*C;
    ans += 10000000*(A+B);
    ans += 1*B;    
    ans += 10 * A;

    // ans+=10015;
    // ans+=10011000000;
    // ans+=10011000000000;
    // ans+=1001100000;
    // ans+=51000000;
    // ans+=51000000000;
    // ans+=5100000;
    // ans+=10000001000000000;
    // ans+=1000000100000;
    // ans+=1000000000100000;
    cout << ans.val() << endl;
    return 0;
}