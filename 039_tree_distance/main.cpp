#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
//using mint = modint1000000007;
using mint = modint998244353;
//using mint = static_modint<1000000009>;
#define rep1(a)          for (int i = 0; i < (a); i++)
#define rep2(i, a)       for (int i = 0; i < (a); i++)
#define rep3(i, a, b)    for (int i = a; i < (b); i++)
#define rep4(i, a, b, c) for (int i = a; i < (b); i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
using ll = long long;
constexpr int dx8[8] = {1,0,-1,0,1,-1,-1,1 }, dy8[8] = {0,1,0,-1,1,1,-1,-1 };
constexpr int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};
constexpr ll INF = (1LL << 62);
template<class T>
bool chmax(T& a, const T& b) { if (a < b) return a = b, true; return false; }
template<class T>
bool chmin(T& a, const T& b) { if (a > b) return a = b, true; return false; }
inline void YesNo(bool ok) {
  cout << (ok ? "Yes\n" : "No\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N-1), B(N-1);
  vector<vector<int>> g(N);
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    A[i] = a; B[i] = b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> seq, par(N, -1);
  {
    queue<int> que;
    que.push(0);
    seq.push_back(0);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int to : g[v]) {
        if (to == par[v]) continue;
        par[to] = v;
        seq.push_back(to);
        que.push(to);
      }
    }
  }
  reverse(seq.begin(), seq.end());
  vector<ll> dp(N, 1);
  for (int v : seq) {
    int p = par[v];
    if (p != -1) dp[p] += dp[v];
  }
  ll ans = 0;
  rep(i, N-1) {
    int a = A[i], b = B[i];
    if (a == par[b]) swap(a, b);
    ans += dp[a] * (N - dp[a]);
  }
  cout << ans << endl;

  return 0;
}
