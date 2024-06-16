#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll A, B;
    int n;
    cin >> n >> A >> B;
    int N = 2*n;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0;
    rep(i,N){
        if(s[i] == '(') c1++;
        if(s[i] == ')') c2++;
    }
    ll ans = 0;
    int i = N-1;
    while(c1 - c2 > 0){
        if (s[i] == '(') {
            s[i] = ')';
            ans += B;
            c1--;
            c2++;
        }
        i--;
    }
    i = 0;
    while(c2 - c1 > 0){        
        if (s[i] == ')') {
            s[i] = '(';
            ans += B;
            c1++;
            c2--;
        }
        i++;
    }
    i = 0;
    int lv = 0;
    int j = N-1;
    auto func = [&](int x)->int{
        while (s[x] != '('){
            x--;
        }
        return x;
    };
    ll cost = min(A, 2*B);
    rep(i, N){
        if (s[i] == '(') lv++;
        if (s[i] == ')') {
            if (lv == 0) {
                j = func(j);
                s[i] = '(';
                s[j] = ')';
                ans += cost;
                lv++;
            } else {
                lv--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}