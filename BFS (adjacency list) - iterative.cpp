#include "bits/stdc++.h"
typedef long long lli;
using namespace std;
#define yo cout << "yo" << endl;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define ALL(x) x.begin(), x.end()

int node, edge, a, b, visited[100];
vector<int> adjList[100];

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    visited[u] = 1;
    while(!Q.empty()){
        int n = Q.front();
        cout << n << ' ';
        for(int i=0; i<adjList[n].size(); i++){
            if(!visited[adjList[n][i]]){
                Q.push(adjList[n][i]);
                visited[adjList[n][i]] = 1;
            }
        }
        Q.pop();
    }
}

void solution(){
    cin >> node >> edge;
    for(int i=0; i<edge; i++){
        cin >> a >> b;
        adjList[a].push_back(b); //creating an adjacency list
        adjList[b].push_back(a);
    }
    for(int i=1; i<=node; i++){ //printing the adjacency list
        cout << i << " -> ";
        for(int j=0; j<adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }
    BFS(1); //starting BFS from node 1
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    int TEST_CASE=1;
    //cin >> TEST_CASE;
    while(TEST_CASE--){
        solution();
    }
    return 0;
}
