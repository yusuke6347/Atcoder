#include  <iostream>
#include  <vector>
using namespace std;

class UnionFind{
    vector<int> p; //�e
    vector<int> Rank; //�؂̐[��

    UnionFind(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++) p[i] = i; //�����̐e���������g�ɏ��������Ă���
        Rank.resize(n, 0); //�����̏�����
    }

    int find(int x)
    {
        //�e��Ԃ��A�T�����łɐe���X�V���A�ӂ��k��
        if (p[x] == x)  return x;
        else return p[x] = find(p[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return; //x==y�̏ꍇ�̏���
        //���������������������ɂ���
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