#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int A, B;
    cin >> A >> B;
    int ans;
    if (A > B) {
        swap(A,B);
    }
    if (A == B){
        ans = -1;
    } else if(A == 1 && B == 2) {
        ans = 3;
    } else if (A == 1 && B == 3) {
        ans = 2;
    } else if (A == 2 && B == 3) {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}