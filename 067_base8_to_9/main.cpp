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
  string S; // 8進数
  int K;
  cin >> S >> K;
  if (S == "0") {
    cout << 0 << endl;
    return 0;
  }
  while (K--) {
    // 8進数の文字列S→10進数の整数nに変換
    reverse(S.begin(), S.end());
    ll n = 0;
    ll base = 1;
    for (int i = 0; i < S.size(); i++) {
      ll s = S[i] - '0';
      n += base * s;
      base *= 8;
    }
//    cout << "n: " << n << endl;
    // 10進数の整数n→9進数の文字列Tに変換
    string T = "";
    while (n > 0) {
      int t = n % 9;
      T += (char)(t + '0');
      n /= 9;
    }
    reverse(T.begin(), T.end());
    // 8を5に書き直す
    for (int i = 0; i < T.size(); i++) if (T[i] == '8') T[i] = '5';
    S = T;
//    cout << "S: " << S << endl;
  }
  cout << S << endl;

  return 0;
}
