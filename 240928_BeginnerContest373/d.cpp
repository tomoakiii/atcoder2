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

class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parents(n)
		, m_sizes(n, 1)
	{
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parents[i] == i)
		{
			return i;
		}

		// 経路圧縮
		return (m_parents[i] = find(m_parents[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	bool unite(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (m_sizes[a] < m_sizes[b])
			{
				std::swap(a, b);
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
            return true;
		} else {
            return false;
        }
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool same(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return m_sizes[find(i)];
	}
	vector<int> par(){
		return m_parents;
	}

private:
	// m_parents[i] は i の 親, root の場合は自身が親
	std::vector<int> m_parents;

	// グループの要素数 (root 用), i が root のときのみ, m_sizes[i] はそのグループに属する要素数を表す
	std::vector<int> m_sizes;
};

int main(){
    int N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int, ll>>{});
    vector<ll> U(M), V(M), W(M);
    ll u, v, w;
    map<pair<int, ll>, int> mp;
    UnionFind uf(N);
    rep(i,M) {
        cin >> u >> v >> w;        
        u--, v--;
        U[i] = u, V[i] = v, W[i] = w;
        uv[u].push_back({v, w});
        uv[v].push_back({u, -1*w});
        uf.same(u, v);
    }
    queue<int> que;
    que.push(u);
    vector<ll> ans(N, 1E18);
    ans[u] = 0;
    vector<bool> visit(N, false);
    vector<int> route(N);

    rep(i,N) {
        if (visit[uf.find(i)]) continue;
        
        auto f = [&](auto f, int cur, ll p)->void {
            if (visit[cur]) return;
            visit[cur] = true;
            ans[cur] = p;
            rep(j, uv[cur].size()) {
                f(f, uv[cur][j].first, p+uv[cur][j].second);
            }
        };

        f(f, i, 0);
    }
    rep(i, N) cout << ans[i] << " ";
    cout<<endl;
    return 0;
}