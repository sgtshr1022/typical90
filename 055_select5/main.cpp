#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
//using mint = modint1000000007;
//using mint = modint998244353;
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

using mint = modint;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  ll P, Q;
  cin >> N >> P >> Q;
  mint::set_mod(P);
  vector<mint> A(N);
  map<mint, ll> mp;
  rep(i, N) {
    ll a;
    cin >> a;
    A[i] = a;
  }
  ll ans = 0;
  for (int i = 0; i < N - 4; i++) {
    for (int j = i + 1; j < N - 3; j++) {
      for (int k = j + 1; k < N - 2; k++) {
        for (int l = k + 1; l < N - 1; l++) {
          for (int m = l + 1; m < N; m++) {
            mint temp = A[i] * A[j] * A[k] * A[l] * A[m];
            if (temp.val() == Q) ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
