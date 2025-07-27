#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    set<char> st;
    int ind = 0;
    auto reg = [&](string S)->void{
        for(auto c:S) st.insert(c);        
    };    
    reg(S1),reg(S2),reg(S3);    
    if(st.size() > 10) {
        cout<<"UNSOLVABLE"<<endl;
        return 0;
    }
    bool flg = false;
    vector<int> num(st.size());
    auto sol = [&](auto sol, int i, ll NG)->void{
        if(flg) return;
        if(i == st.size()) { 
            vector<int> DIC('Z'-'A'+1);
            auto s2n = [&](string S)->ll{
                ll ret = 0;
                for(auto c: S) {
                    ret = ret * 10 + DIC[c-'a'];
                }
                return ret;
            };            
            int i = 0;
            for(auto c: st) {
                DIC[c-'a'] = num[i++];
            }
            if(DIC[S1[0]-'a'] == 0 || DIC[S2[0]-'a'] == 0 || DIC[S3[0]-'a'] == 0 ) return;
            ll n1=s2n(S1),n2=s2n(S2),n3=s2n(S3);
            if(n1 + n2 == n3) {
                cout << n1 << endl;
                cout << n2 << endl;
                cout << n3 << endl;
                flg = true;
                return;
            }
            return;
        }
        rep(x,10) {
            if(NG>>x & 1) continue;
            num[i] = x;
            ll NG2 = NG | 1<<x;
            sol(sol, i+1, NG2);
        }
    };
    sol(sol, 0, 0);
    if(!flg)cout<<"UNSOLVABLE"<<endl;
    return 0;
}