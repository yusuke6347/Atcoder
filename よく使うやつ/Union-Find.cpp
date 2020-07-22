#include  <iostream>
#include  <vector>
using namespace std;

class UnionFind{
    vector<int> p; //親
    vector<int> Rank; //木の深さ

public:
    UnionFind(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i; //自分の親を自分自身に初期化しておく
        Rank.resize(n, 0); //高さの初期化
    }

    int find(int x)
    {
        //親を返し、探すついでに親を更新し、辺を縮約
        if (p[x] == x)  return x;
        else return p[x] = find(p[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return; //x==yの場合の処理
        //高さが小さい方をしたにする
        if (Rank[x] < Rank[y]) {
            p[x] = y;
        }
        else {
            p[y] = x;
            if (Rank[x] == Rank[y]) Rank[x]++;
        }
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};
