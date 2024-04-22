#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    string S;
    cin >> S;
    map<int, int> v;
    bool f = false;
    int nest = 0;
    stack<int> que;
    for(int i=0; i<S.size(); i++){
        if (S[i] == '('){            
            f = !f;
            que.push(i);
        } else if (S[i] == ')'){
            f = !f;
            auto qt = que.top();
            v[qt] = i;
            v[i] = qt;
            que.pop();
        } else if (f) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                S[i] = S[i] - 'A' + 'a';
            } else {
                S[i] = S[i] - 'a' + 'A';
            }
        }
    }    
    auto func = [&](auto func, int l, int r, bool mv) -> void {        
        // cout << mv << " " << l << " " << r << endl;
        if (mv){            
            int i=l+1;
            while (i < r) {            
                if (S[i] == '('){                    
                    func(func, i, v[i], !mv);
                    i = v[i] + 1;
                } else {
                    cout << S[i++];
                }
            }            
        } else {            
            int i=r-1;
            while (i > l){
                if (S[i] == ')'){                    
                    func(func, v[i], i, !mv);
                    i = v[i] - 1;
                } else {
                    cout << S[i--];
                }
            }
        }
    };
    func(func, -1, S.size(), true);
    cout << endl;
    return 0;
}