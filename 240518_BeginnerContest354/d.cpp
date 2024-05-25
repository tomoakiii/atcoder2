#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    A+=1000000000;
    B+=1000000000;
    C+=1000000000;
    D+=1000000000;
    ll AA = A;
    AA += 3;
    AA -= (AA%4);
    ll CC = C;
    CC -= (CC%4);
    ll BB = B;
    BB += 1;
    BB -= (BB%2);
    ll DD = D;
    DD -= (DD%2);
    ll sq1 = 0;
    ll sq2 = 0;
    ll sq3 = 0;
    ll sq4 = 0;
    if(DD>BB) {
        sq1 = 3 * (DD-BB)/2;
        sq2 = 3 * (DD-BB)/2;
        sq3 = (DD-BB)/2;
        sq4 = (DD-BB)/2;
    }
    if (B%2) {
        sq1 += 1;
        sq2 += 2;
        sq3 += 1;
    } 
    if (D%2) {
        sq1 += 2;
        sq2 += 1;
        sq4 += 1;
    }
    
    ll sq = 0;
    if (CC>AA){
        sq += (sq1 + sq2 + sq3 + sq4) * (CC-AA)/4;
    }
    if (AA > A){
        if (A%4 == 1) {
            sq += sq2 + sq3 + sq4;
        } else if (A%4 == 2) {
            sq += sq3 + sq4;
        } else if (A%4 == 3) {
            sq += sq4;
        }
    }
    if (CC < C) {
        if (C%4 == 3) {
            sq += sq1 + sq2 + sq3;
        } else if (C%4 == 2) {
            sq += sq1 + sq2;
        } else if (C%4 == 1) {
            sq += sq1;
        }
    }
    cout << sq << endl;
    return 0;
}