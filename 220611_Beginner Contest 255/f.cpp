#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int val=-1;
    int l=-1;
    int r=-1;
    int par=-1;
    node(int v_, int l_, int r_, int p_){
        val = v_, l=l_, r=r_, par=p_;
    }
};


int main () {
    int N;
    cin >> N;
    vector<int> P(N), I(N);
    vector<int> Po(N), Io(N);
    for (int i=0; i<N; i++){
        cin >> P[i];
        P[i]--;
        Po[P[i]] = i;
    }
    for (int i=0; i<N; i++){
        cin >> I[i];
        I[i]--;
        Io[I[i]] = i;
    }
    vector<node> nd(N, {P[0], -1, -1, -1});
    nd[P[0]].val = P[0];
    int t = P[0];
    while (true){
        Io[t]
    }


    for (auto n: nd){
        cout << n.l << " " << n.r << endl;
    }
    
    return 0;
}

