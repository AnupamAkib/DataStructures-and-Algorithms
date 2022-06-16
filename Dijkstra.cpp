//problem: https://atcoder.jp/contests/abc191/tasks/abc191_e
//approach: Dijkstra


/*BISMILLAHIR RAHMANIR RAHIM*/
#include<bits/stdc++.h>
#define lli long long int
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define ALL(x) x.begin(), x.end()
#define print(x) cout<<x<<endl;
#define PI acos(-1.0)
#define nl cout<<"\n"
#define mem(ar, val) memset(ar, val, sizeof(ar))
#define point(x) fixed<<setprecision(x)
#define printcase(n) cout << "Case " << tc << ": " << n <<endl;
#define printcaseii(n, m) cout << "Case " << tc << ": " << n << " " << m <<endl;
#define aInput(ar, n) for(int i=0; i<n; i++)cin>>ar[i];
#define vInput(v, n) for(int i=0; i<n; i++){lli xwq;cin>>xwq;v.push_back(xwq);}
#define input2D(ar, row, col) for(int i=0; i<row; i++){for(int j=0; j<col; j++){cin >> ar[i][j];}}
#define print2D(ar, row, col) for(int i=0; i<row; i++){for(int j=0; j<col; j++){cout << ar[i][j] << " ";}cout<<endl;}
#define vprint(vec) for(int i=0; i<vec.size(); i++){cout << vec[i]; (i==vec.size()-1? cout<<endl : cout<<" ");}
#define aprint(ar, n) for(int i=0; i<n; i++){cout << ar[i] << " ";}cout<<endl
#define ANUPAM_AKIB ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define execution_time cerr<<endl;int z=30;while(z--){cerr<<'-';}cerr<<endl;cerr<<point(16)<<"**Time -> "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"fs"<<endl;
#define INPUT freopen("input.txt", "r", stdin)
#define OUTPUT freopen("output.txt", "w", stdout)
#define umap unordered_map
#define IN input()
#define yo(x) cout<<(#x)<<" = "<<(x)<<endl;
#define ff first
#define ss second
#define VEC vector<lli>
#define sz size()
using namespace std;
const lli inf = INT_MAX;
const int mod = 100000;
lli findLCM(lli a, lli b){return ((a*b)/__gcd(a,b));}
lli input(){lli x; cin >> x; return x;}
int digitCNT(int n){return ceil(log10(n)+0.00000001);}
string to_binary(lli num){if(num==0) return ""; return to_binary(num/2)+to_string(num%2);}
bool isPalindrome(string s){for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){if(s[i]!=s[j]) return 0;}return 1;}
bool isPrime(lli n){if(n<2){return false;}if(n==2||n==3){return true;}if(n%2==0){return false;}for(lli i=3; i*i<=n; i+=2){if(n%i==0){return false;}}return true;}
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.ff>b.ff;
}

class Node{
public:
    int u, cost;
    Node(int _u, int _cost){
        u = _u, cost = _cost;
    }
    bool operator < (const Node &p) const {
        return p.cost < cost;
    }
};

int nd, ed;
vector<int> graph[2005];
int cost[2005][2005], dist[2005];

int dijkstra(int src){
    priority_queue<Node> pq;
    pq.push(Node(src, 0));
    dist[src] = 0;
    while(!pq.empty()){
        Node head = pq.top();
        pq.pop();
        int u = head.u;
        for(int v : graph[u]){
            if(dist[u] + cost[u][v] < dist[v]){
                dist[v] = dist[u] + cost[u][v];
                pq.push(Node(v, dist[v]));
            }
        }
    }
    int res = inf;
    for(int i=1; i<=nd; i++){
        //yo(dist[i])
        //yo(cost[i][src])
        if(dist[i]!=inf && cost[i][src]!=inf){
            res = min(res, dist[i]+cost[i][src]);
        }
    }
    return (res!=inf? res : -1);
}

void reset(){
    for(int i=1; i<=nd; i++){
        dist[i] = inf;
    }
}

void solve(lli tc){
    cin >> nd >> ed;
    for(int i=0; i<2005; i++){
        for(int j=0; j<2005; j++){
            cost[i][j] = inf;
        }
    }
    while(ed--){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        cost[u][v] = min(cost[u][v], w);
    }
    for(int i=1; i<=nd; i++){
        reset();
        int ans = dijkstra(i);
        print(ans)
    }
}

int main(){
    ANUPAM_AKIB;
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        INPUT;
        OUTPUT;
    #endif

    lli tc = 1;
    //cin >> tc; //TEST CASE
    for(int i=1; i<=tc; i++){
        solve(i);
    }
    /*while(cin >> tc && tc!=-1) solve(tc);*/

    #ifndef ONLINE_JUDGE
        execution_time;
    #endif
    return EXIT_SUCCESS;
}
