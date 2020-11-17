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
#define vInput(v, n) for(int i=0; i<n; i++){lli x;cin>>x;v.push_back(x);}
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
#define yo(x) cerr<<(#x)<<" = "<<(x)<<endl;
#define ff first
#define ss second
using namespace std;
const lli inf = INT_MAX;
const int mod = 100000007;
lli findLCM(lli a, lli b){return ((a*b)/__gcd(a,b));}
lli input(){lli x; cin >> x; return x;}
int digitCNT(int n){return ceil(log10(n)+0.00000001);}
string to_binary(lli num){if(num==0) return ""; return to_binary(num/2)+to_string(num%2);}
bool isPalindrome(string s){for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){if(s[i]!=s[j]) return 0;}return 1;}
bool isPrime(int n){if(n<2){return false;}if(n==2||n==3){return true;}if(n%2==0){return false;}for(lli i=3; i*i<=n; i+=2){if(n%i==0){return false;}}return true;}

typedef struct{
    string name="";
    int AT=0, ST=0, CT=0, TAT=0, WT=0, id;
} process;

bool cmp(process a, process b){
    if(a.AT==b.AT) return a.name<b.name;
    return a.AT<b.AT;
}

bool cmp2(process a, process b){
    return a.name<b.name;
}

void solve(int tc){
    ///FULL OKEY
    int totalProcess = IN;
    process p[totalProcess];
    bool flag[totalProcess]={0};
    for(int i=0; i<totalProcess; i++){
        cin >> p[i].name >> p[i].AT >> p[i].ST;
        p[i].id = i;
    }
    int QT = IN;
    sort(p, p+totalProcess, cmp);
    vector<process> v, gratt;
    vector<int> timeline;
    queue<process> Q;
    process tmp = p[0];
    int c=0;
    while(p[c].AT == tmp.AT && c<totalProcess){
        v.push_back(p[c]);
        c++;
    }
    sort(ALL(v), cmp);
    for(process x : v){
        Q.push(x);
    }

    int track = v[0].AT;
    again:
    timeline.push_back(track);
    while(!Q.empty()){
        process now = Q.front();
        flag[now.id] = true;

        int k = min(now.ST, QT), prev=track;
        gratt.push_back(now);
        now.ST -= k, track += k;
        for(int i=0; i<totalProcess; i++){
            if(p[i].name == now.name){p[i].CT=track;}
        }
        timeline.push_back(track);

        v.clear();
        for(process x : p){
            if(x.AT>prev && x.AT<=track){
                v.push_back(x);
            }
        }
        sort(ALL(v), cmp);
        for(process x : v){
            Q.push(x);
        }
        if(now.ST){
            Q.push(now);
        }
        Q.pop();
    }
    for(int i=0; i<totalProcess; i++){
        if(!flag[i]){
            Q.push(p[i]);
            track = p[i].AT;
            goto again;
        }
    }
    print("Gantt chart:")
    for(process x : gratt){
        cout << x.name << ' ';
    }nl;
    for(int x : timeline){
        cout << x << ' ';
    }nl;nl;
    print("Ready Queue:")
    for(process x : gratt){
        cout << x.ST-1 << ' ';
    }nl;
    for(process x : gratt){
        cout << x.name << ' ';
    }nl;
    for(process x : gratt){
        cout << x.ST << ' ';
    }nl;

    int tat=0, wt=0;
    for(int k=0; k<totalProcess; k++){
        for(int i=gratt.size()-1; i>=0; i--){
            if(p[k].name == gratt[i].name){
                p[k].TAT = p[k].CT - p[k].AT;
                tat += p[k].TAT;
                p[k].WT = p[k].TAT - p[k].ST;
                wt += p[k].WT;
                break;
            }
        }
    }
    nl;nl;nl;
    sort(p, p+totalProcess, cmp2);
    print("Prcss  AT  ST CT  TAT WT\n------------------------")
    for(process x : p){
        printf("%3s %4d %3d %3d %3d %3d\n", x.name.c_str(), x.AT, x.ST, x.CT, x.TAT, x.WT);
    }nl;
    print("Total TAT = " << tat)
    print("Total WT = " << wt)
    nl;
    cout << point(2);
    print("AVG TAT = " << tat << "/" << totalProcess << " = " << (double)tat/totalProcess << " ms")
    print("AVG WT = " << wt << "/" << totalProcess << " = " << (double)wt/totalProcess << " ms")
    nl;nl;nl;
}

int main(){
    ANUPAM_AKIB;
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        INPUT;
        //OUTPUT;
    #endif

    int tc = 1;
    //cin >> tc; //TEST CASE
    for(int i=1; i<=tc; i++){
        solve(i);
    }

    #ifndef ONLINE_JUDGE
        execution_time;
    #endif
    return EXIT_SUCCESS;
}
