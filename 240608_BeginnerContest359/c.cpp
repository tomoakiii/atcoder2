#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if (ty < sy) {
        swap (ty, sy);
        swap (tx, sx);
    }
    ll sx1, sx2;
    if (sy % 2 == 0){
        sx1 = (sx/2) * 2;
    } else {
        if (sx % 2 == 1) {
            sx1 = sx;
        } else {
            sx1 = sx - 1;
        }
    }
    sx2 = sx1 + 1;

    ll ylen = ty - sy;
    ll tx1 = sx1 - ylen;
    ll tx2 = sx2 + ylen;
    if (tx >= tx1 && tx <= tx2) {
        cout << ylen << endl;
        return 0;
    }
    if (tx < tx1) {
        if (ty % 2 == 0){
            if (tx % 2 == 1) tx--;
        } else {
            if (tx % 2 == 0) tx--;
        }
        cout << ylen + ((tx1 - tx)/2) << endl;
        return 0;
    }
    if (tx > tx2) {
        if(ty % 2 == 0){
            if (tx % 2 == 0) tx++;
        } else {
            if (tx % 2 == 1) tx++;
        }
        cout << ylen + ((tx - tx2)/2) << endl;
        return 0;
    }
    return 0;
}