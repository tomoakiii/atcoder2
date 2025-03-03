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
    string S;
    cin >> S;
    vector<char> dq;
    for(auto c: S){        
        if(c == '(' || c == '[' || c == '<') {
            dq.push_back(c);
        } else {
            if(dq.size() == 0) {
                cout << "No" << endl;
                return 0;
            }
            auto d = dq.end(); d--;
            if (c == ')') {            
                
                if(*d == '(') dq.pop_back();
                else {
                    cout << "No" << endl;
                    return 0;
                }
            } else if (c == ']'){                
                if(*d == '[') dq.pop_back();
                else {
                    cout << "No" << endl;
                    return 0;
                }
            } else if (c == '>'){
                if(*d == '<') dq.pop_back();
                else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    if(dq.size() != 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}