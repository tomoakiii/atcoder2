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
    string S;
    cin >> S;
    int w[2] = {0, 0};
    string winner;
    for(auto c:S){
        if (c=='T') {
            w[0]++;
        } else {
            w[1]++;
        }
        if (w[0] > w[1]) winner =  "T";
        if (w[1] > w[0]) winner =  "A";        
    }
    cout << winner << endl;
    return 0;
}