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
enum Tag{
    Link,
    Thread
};
struct TreeNode{
    TreeNode* lc;
    TreeNode* rc;
    Tag ltag, rtag;
    TreeNode(): lc(NULL), rc(NULL), ltag(Link), rtag(Link) {}
};

int idx = 0;
TreeNode* build_tree(vector<Node>, TreeNode*);

int main(){
    int x, u, v, n;
    vector<Node> t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d%d%d", &x, &u, &v);
        Node tmp(x, u, v);
        t.push_back(tmp);
    }

    return 0;
}

TreeNode* build_tree(vector<Node> t, TreeNode* root){
    if(idx == t.size()){
        return NULL;
    }
    
}