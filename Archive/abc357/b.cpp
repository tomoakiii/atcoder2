#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string S;
    cin >> S;
    int cl=0, cu=0;
    rep(i, S.size()) {
        if (S[i] >= 'a' && S[i] <= 'z') cl++;
        else cu++;
    }
    rep(i, S.size()) {
        if (S[i] >= 'a' && S[i] <= 'z'){
            if (cl < cu) S[i] = S[i] - 'a' + 'A';
        } else {
            if (cl > cu) S[i] = S[i] - 'A' + 'a';
        }

    }   
    cout << S << endl;
    return 0;
}