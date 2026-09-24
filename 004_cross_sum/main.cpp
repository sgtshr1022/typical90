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
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i, H)rep(j, W) cin >> A[i][j];
  vector<ll> SH(H);
  vector<ll> SW(W);
  rep(i, H) {
    ll temp = 0;
    rep(j, W) temp += A[i][j];
    SH[i] = temp;
  }
  rep(j, W) {
    ll temp = 0;
    rep(i, H) temp += A[i][j];
    SW[j] = temp;
  }
//  rep(i, H) cout << SH[i] << " ";
//  cout << endl;
//  rep(i, W) cout << SW[i] << " ";
//  cout << endl;
  rep(i, H) {
    rep(j, W) cout << SH[i] + SW[j] - A[i][j] << " ";
    cout << endl;
  }

  return 0;
}
