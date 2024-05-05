#include <atcoder/dsu>
#include <cstdio>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

// https://atcoder.github.io/ac-library/production/document_ja/dsu.html
// 


int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        scanf("%d %d %d", &t, &u, &v);
        if (t == 0) {
            d.merge(u, v);
        } else {
            if (d.same(u, v)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
