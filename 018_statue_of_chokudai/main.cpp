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
  ll T;
  cin >> T;
  ll L, X, Y;
  cin >> L >> X >> Y;
  int Q;
  cin >> Q;
  auto solve = [&](ll e)->double{
    double x = 0;
    double y = -(double)L/2 * sin(2 * M_PI / (double)T * (double)e);
    double z = (double)L/2 * (1 - cos(2 * M_PI / (double)T * (double)e));
//    cout << x << " " << y << " " << z << endl;
    double r = hypot(X - x, Y - y);
    double ret = atan2(z, r) * 180 / M_PI;
    return ret;
  };

  while (Q--) {
    ll e;
    cin >> e;
    cout << fixed << setprecision(10) << solve(e) << endl;
  }

  return 0;
}
