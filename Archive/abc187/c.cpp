#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N;
    cin >> N;
    string s1, s2;
    set<string> st;
    rep(i,N) {
        cin>>s1;
        if (s1[0] != '!') {
            if (st.find('!'+s1) != st.end()) {
                cout << s1 << endl;
                return 0;
            } 
        }else {
            s2 = s1.substr(1);
            if (st.find(s2) != st.end()) {
                cout << s2 << endl;
                return 0;
            }
        }
        st.insert(s1);
    }
    
    cout << "satisfiable" << endl;
    return 0;
}

