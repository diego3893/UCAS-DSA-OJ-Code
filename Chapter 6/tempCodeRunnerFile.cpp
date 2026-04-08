#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

int main(){
    string line;
    int num;
    vector<int> L;
    vector<int> R;
    stringstream ss;

    getline(cin, line);
    ss.clear();
    ss.str(line);
    while(ss >> num){
        L.push_back(num);
    }
    getline(cin, line);
    ss.clear();
    ss.str(line);
    while(ss >> num){
        R.push_back(num);
    }

    for(int i=0; i<R.size(); ++i){
        printf("%d ", R[i]);
    }
    printf("\n");
    for(int i=0; i<L.size(); ++i){
        printf("%d ", L[i]);
    }
    printf("\n");

    return 0;
}