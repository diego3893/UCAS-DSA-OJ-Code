#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

struct Node{
    char data;
    int lc, rc;
};

void merge(int[], vector<Node>);
// vector<Node> get_depth(int, vector<Node>);
// bool cmp(const Node&, const Node&);

int main(){
    vector<Node> tree;
    char c;
    int l, r;
    while(cin>>c>>l>>r){
        Node tmp;
        tmp.data = c;
        tmp.lc = l-1;
        tmp.rc = r-1;
        tree.push_back(tmp);
    }
    int f[tree.size()+5];
    for(int i=0; i<tree.size(); ++i){
        f[i] = i;
    }
    merge(f, tree);
    int root = -1;
    for(int i=0; i<tree.size(); ++i){
        if(f[i] == i){
            root = i;
            break;
        }
    }
    queue<Node> q;
    q.push(tree[root]);
    bool get_null = 0, is_comp_tree = 1;
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        if(tmp.lc >= 0){
            q.push(tree[tmp.lc]);
        }else if(tmp.lc == -2){
            Node null;
            null.data = '#';
            null.lc = -1;
            null.rc = -1;
            q.push(null);
        }
        if(tmp.rc >= 0){
            q.push(tree[tmp.rc]);
        }else if(tmp.rc == -2){
            Node null;
            null.data = '#';
            null.lc = -1;
            null.rc = -1;
            q.push(null);
        }
        if(tmp.lc==-1 && tmp.rc==-1){
            get_null = 1;
        }
        if(get_null && !(tmp.lc==-1&&tmp.rc==-1)){
            is_comp_tree = 0;
            break;
        }
    }
    if(is_comp_tree){
        printf("Yes");
    }else{
        printf("No");
    }
    // tree = get_depth(root, tree);
    // sort(tree.begin(), tree.end(), cmp);
    // int max_dep = tree.back().depth;
    // int dep_cnt[max_dep+5];
    // memset(dep_cnt, 0, sizeof(dep_cnt));
    // for(int i=0; i<tree.size(); ++i){
    //     dep_cnt[tree[i].depth]++;
    // }
    // for(int i=0; i<=max_dep; ++i){
    //     if(dep_cnt[i] != pow(2, i)){
    //         printf("No");
    //         return 0;
    //     }
    // }

    return 0;
}

void merge(int f[], vector<Node>t){
    for(int i=0; i<t.size(); ++i){
        if(t[i].lc != -2){
            f[t[i].lc] = f[i];
        }
        if(t[i].rc != -2){
            f[t[i].rc] = f[i];
        }
    }
    return;
}

// vector<Node> get_depth(int root, vector<Node> t){
//     vector<Node> ans;
//     stack<Node> s;
//     Node cur = t[root];
//     cur.depth = 0;
//     ans.push_back(cur);
//     s.push(cur);
//     while(!s.empty()){
//         Node tmp;
//         cur = s.top();
//         s.pop();
//         if(cur.lc != -2){
//             tmp = t[cur.lc];
//             tmp.depth = cur.depth+1;
//             ans.push_back(tmp);
//         }
//         if(cur.rc != -2){
//             tmp = t[cur.rc];
//             tmp.depth = cur.depth+1;
//             ans.push_back(tmp);
//         }
//     }
//     return ans;
// }

// bool cmp(const Node& a, const Node& b){
//     return a.depth<b.depth;
// }