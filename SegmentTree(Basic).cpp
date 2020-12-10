/*BISMILLAHIR RAHMANIR RAHIM*/
#include<bits/stdc++.h>
#define lli long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
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
const int mod = 1000000007;
lli findLCM(lli a, lli b){return ((a*b)/__gcd(a,b));}
lli input(){lli x; cin >> x; return x;}
int digitCNT(int n){return ceil(log10(n)+0.00000001);}
string to_binary(lli num){if(num==0) return ""; return to_binary(num/2)+to_string(num%2);}
bool isPalindrome(string s){for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){if(s[i]!=s[j]) return 0;}return 1;}
bool isPrime(int n){if(n<2){return false;}if(n==2||n==3){return true;}if(n%2==0){return false;}for(lli i=3; i*i<=n; i+=2){if(n%i==0){return false;}}return true;}
bool cmp(pair<lli, int> a, pair<lli, int> b){ return a.first>b.first;}

/// SEGMENT TREE - Complexity: O(nlogn)

/*
we have an int array a[]. we have to print the sum of 'st' to 'ed' (1 indexed) when query comes.
when update comes, we have to update a[idx] with 'val'

q = query (l, r)
u = update (idx, val)
*/

typedef struct{
    int sum = 0;
} node;

const int N = 10; //array size is 10
int a[N] = {2, 5, 1, 6, 7, 3, 2, 1, 9, 12}; //given array

node tree[N*4]; //tree size should be N*4

void init(int node, int start, int end){
    if(start == end){ //leaf found
        tree[node].sum = a[start];
        return;
    }
    int mid = (start + end) / 2; //find the mid of the segment
    int left = node * 2, right = node * 2 + 1; //find left and right node
    init(left, start, mid); //go left
    init(right, mid+1, end); //go right
    tree[node].sum = tree[left].sum + tree[right].sum; //merge
} // O(n)

int query(int node, int f, int l, int start, int end){
    if(f>end || l<start) return 0; //out of segment so return 0
    if(f>=start && l<=end) return tree[node].sum; //inside the segment
    int mid = (f + l) / 2; //find the mid of the segment
    int left = node * 2, right = node * 2 + 1; //find left and right node
    return query(left, f, mid, start, end) + query(right, mid+1, l, start, end); //go both side
} // O(logN)

void update(int node, int start, int end, int idx, int value){
    if(start == end){
        if(start == idx) tree[node].sum = value; //index found and change value
        return;
    }
    int mid = (start + end) / 2;
    int left = node * 2, right = node * 2 + 1;
    if(idx <= mid) update(left, start, mid, idx, value); //idx is in left side. so go left
    else update(right, mid+1, end, idx, value); //idx is in right side. so go right
    tree[node].sum = tree[left].sum + tree[right].sum; //merge
} // O(logN)

void solve(lli tc){
    char c; cin >> c;
    int x = IN, y = IN;
    if(c=='q'){ //Query
        int st = x-1, ed = y-1; //make 0 indexed
        int sum = query(1, 0, N-1, st, ed);
        print(sum)
    }
    else{ //Update
        int idx = x-1, val = y;
        update(1, 0, N-1, idx, val);
    }

/*
    INPUT DATA:
    6
    q 3 8
    u 4 10
    q 2 9
    q 4 4
    u 6 3
    q 3 9
*/
}

int main(){
    ANUPAM_AKIB;
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        INPUT;
        OUTPUT;
    #endif

    init(1, 0, N-1); //initializing the segment tree

    int tc = 1;
    cin >> tc; //TEST CASE
    for(int i=1; i<=tc; i++){
        solve(i);
    }

    #ifndef ONLINE_JUDGE
        execution_time;
    #endif
    return EXIT_SUCCESS;
}
