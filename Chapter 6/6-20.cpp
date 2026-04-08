#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
struct Node{
    int id;
    int lc, rc;
    Node(int x, int u, int v): id(x), lc(u), rc(v) {}
};
// 维护一个并查集，查询有几棵独立的树，合并之后做线索化（复制一份操作）
// enum Tag{
//     Link,
//     Thread
// };
// struct TreeNode{
//     TreeNode* lc;
//     TreeNode* rc;
//     Tag ltag, rtag;
//     int data;
//     TreeNode(int d): lc(NULL), rc(NULL), ltag(Link), rtag(Link), data(d) {}
// };

// int idx = 0;
// TreeNode* build_tree(vector<Node>, TreeNode*);

int main(){
    int x, u, v, n;
    vector<Node> t;
    t.push_back({-1, -1, -1});
    scanf("%d", &n);
    int f[n+5];
    for(int i=1; i<=n; ++i){
        f[i] = i;
    }
    for(int i=0; i<n; ++i){
        scanf("%d%d%d", &x, &u, &v);
        Node tmp(x, u, v);
        t.push_back(tmp);
        f[u] = i;
        f[v] = i;
    }

    return 0;
}

// TreeNode* build_tree(vector<Node> t, TreeNode* parent){
//     if(idx == t.size()){
//         return NULL;
//     }
//     TreeNode *p = new TreeNode(t[idx].id);
//     p->lc
// }