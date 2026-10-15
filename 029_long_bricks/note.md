# 029 Long Bricks (★5)

問題URL: https://atcoder.jp/contests/typical90/tasks/typical90_ac

## 問題の要点
- 幅 W の床に、区間 [L_i, R_i] を覆うレンガを N 個順に落とす
- 各レンガは覆う区間の中で一番高いところに乗る
- 各レンガを置いた直後の、そのレンガの上端の高さを出力する

## 使ったアルゴリズム・考え方
- 遅延セグ木（区間 max 取得 + 区間代入）
- 1個置く操作を「区間 max を取得 → 区間を h+1 で代入」の2ステップに分解
- 部品の設計

| 部品 | 設計 |
|---|---|
| S | ll（区間の最大の高さ） |
| op | max(a, b) |
| e | -INF |
| F | ll（代入する値。INF なら「代入なし」） |
| mapping | f == INF ? x : f |
| composition | f == INF ? g : f（後から来た代入 f が優先） |
| id | INF |

- 計算量：O(N log W)

```cpp
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF; }
ll mapping(ll f, ll x) { return (f == INF ? x : f); }
ll composition(ll f, ll g) { return (f == INF ? g : f); }
ll id() { return INF; }

// 各レンガ
l--;                          // 半開区間 [l, r) に直す
ll h = seg.prod(l, r);
cout << h + 1 << '\n';
seg.apply(l, r, h + 1);
```

## つまずいた点
- 遅延セグ木の F・mapping・composition が初見で、普通のセグ木との違いを整理する必要があった
- ABC340 E の「区間加算」とは作用が違い、今回は「区間代入」になる点

## 学び・次に活かすこと
- 遅延セグ木はまず S / op / e / F / mapping / composition / id の7部品を紙に書いてから実装する
- 区間代入の作用は「何もしない」を表す番兵（INF など）を id にし、実際に代入されうる値と被らないようにする
- composition(f, g) は「g の後に f」。代入なら新しい方 f が勝つ
- mapping の条件 f(op(x, y)) = op(f(x), f(y)) を確認する：区間全体を h で代入すれば max も h なので成立
- 「区間から取得 → 区間に作用」の分解は、落下・積み上げ系の問題（例：ABC382 F）でも使える

## 参考にした解説
- なし（遅延セグ木の7部品を設計してから実装）
