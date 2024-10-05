#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;


int main(){
    ll N;
    cin >> N;
    string Td;
    cin >> Td;
    vector<ll> ans;
    for (ll i=1; i<=N; i++){
        string s;
        cin >> s;
        bool flg = true;        
         
        if (s.size() == Td.size()) {
            ll fcnt = 0;
            for (ll p = 0; p < s.size(); p++) {
                if (s[p] == Td[p]) continue;
                fcnt++;
                if (fcnt > 1) {
                    flg = false;
                    break;
                }
            }
        } else {
            string a, b;
            if (s.size() == Td.size() + 1) {
                a = Td;
                b = s; 
            } else if (s.size() + 1 == Td.size()) {
                a = s;
                b = Td;
            } else {
                flg = false;
            }
            if (flg) {    
                ll fcnt = 0;
                ll ind = 0;
                while (ind < a.size()) {
                    if (b[ind+fcnt] == a[ind]) {
                        ind++;
                        continue;
                    }
                    fcnt++;
                    if (fcnt > 1) {
                        flg = false;
                        break;
                    }
                }
            }
        }
        if (flg) ans.push_back(i);
    }
    
    cout << ans.size() << endl;
    for (auto a: ans) cout << a << " ";
    cout << endl;
    return 0;
}