#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFl = 0x0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F;
const int INF = 0x0F0F0F0F;

int main () {
    struct node{
        int cnt;
        ll rem;
        ll maxP;
        node(int cnt=INF, ll rem=-INF): cnt(cnt), rem(rem){}
        bool operator<(const node *n) const {
            if (cnt != n.cnt) return cnt < n.cnt;
            return rem > n.rem;
        }
    };
    return 0;
}
