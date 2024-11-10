#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    string s;
    set<string> st;    

    for(int i=0; i<N;i++) {
        cin >> s;
        bool flg = true;
        if (st.find(s) == st.end()){
            reverse(s.begin(), s.end());
            if (st.find(s) == st.end()) {
                flg = false;
            }
        }
        if(!flg) st.insert(s);
    }
    
    cout << st.size() << endl;
    return 0;
}