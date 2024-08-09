#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

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
    int N, D;
    cin >> N >> D;
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    UnionFind uf(N);
    rep(i,N) for(int j=i+1; j<N; j++){
        if ((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]) <= D*D) {
            uf.unite(i,j);
        }
    }
    rep(i,N) {
        if (uf.same(i, 0)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}