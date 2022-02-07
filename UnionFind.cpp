/*
root(x): 要素xが属する集合を求める.
issame(x, y): 要素x,yが同じ集合に属するか判定する.
merge(x, y): 集合xとyを併合する.併合済のときfalse,未併合のときtrueが返される.
size(x): 要素xが属する集合の要素の数を求める.
*/
struct UnionFind{
    vector<int> par;

    UnionFind(int n) : par(n,-1) { }
    void init(int n) { par.assign(n,-1); }

    int root(int x){
        if(par[x]<0) return x;
        else return par[x]=root(par[x]);
    }

    bool issame(int x,int y){
        return root(x)==root(y);
    }

    bool merge(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y) return false;
        if(par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};
