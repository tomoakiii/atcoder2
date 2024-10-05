#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x0F0F0F0F;

int main () {
    int N;
    cin >> N;
    struct node{
        int pre;
        int next;
        ll val;
    };
    vector<node> A(N+2);
    map<ll, int> ind;
    A[0].next = 1;
    for(int i=1; i<=N; i++){
        cin >> A[i].val;
        A[i].pre = i-1;
        A[i].next = i+1;
        ind[A[i].val] = i;
    }
    A[N+1].pre = N;
    int Q, p, x, y;
    cin >> Q;
    while (Q--) {
        cin >> p;
        if (p==1){
            cin >> x >> y;
            node n;
            n.val = y;
            n.pre = ind[x];
            n.next = A[ind[x]].next;
            A.push_back(n);
            A[ind[x]].next = A.size()-1;
            A[n.next].pre = A.size()-1;
            ind[y] = A.size()-1;
        } else if (p==2) {
            cin >> x;
            A[A[ind[x]].pre].next = A[ind[x]].next;
            A[A[ind[x]].next].pre = A[ind[x]].pre;
        }
    }
    int ct = A[0].next;
    while (true){
        cout << A[ct].val << " ";
        ct = A[ct].next;
        if (ct == N+1) break;
    }
    cout << endl;

    return 0;
}

