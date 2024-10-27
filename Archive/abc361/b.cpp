#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){    
    struct xyz{
        int x;
        int y;
        int z;
    } p1a, p1b, p2a, p2b;

    cin >> p1a.x >> p1a.y >> p1a.z >> p1b.x >> p1b.y >> p1b.z;
    cin >> p2a.x >> p2a.y >> p2a.z >> p2b.x >> p2b.y >> p2b.z;
    auto func = [&](int a1, int b1, int a2, int b2)->bool {
        if (b2 <= a1 || b1 <= a2) {
            return false;
        }
        return true;
    };
    bool flg = true;
    flg &= func(p1a.x, p1b.x, p2a.x, p2b.x);
    flg &= func(p1a.y, p1b.y, p2a.y, p2b.y);
    flg &= func(p1a.z, p1b.z, p2a.z, p2b.z);
    if (flg) cout << "Yes" << endl;
    else  cout << "No" << endl;    
    return 0;
}