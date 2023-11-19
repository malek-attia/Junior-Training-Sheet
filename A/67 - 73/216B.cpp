#include<bits/stdc++.h>
//color a & curl parrot.live

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>

#define tc    \
    int tc_counter ;    \
    cin >> tc_counter ; \
    while (tc_counter--)

#define el "\n"
#define spc <<" "<<

#define lpi(i, j, n)   for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)   for(int i=(j);i>=(int)(n);--i)
#define lp(i,n)    lpi(i,0,n)

#define all(v)  ((v).begin()), ((v).end())
#define sz(v)  ((int)((v).size()))
#define maxi(v) *max_element(all(v))
#define mini(v) *min_element(all(v))
#define asort(v) sort(all(v))
#define sum(v) accumulate(all(v),0)
#define sfind(set, x) set.find(x) != set.end()

void fast_io()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
}

void file_i()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}

vector<vector<int>> adj;
vector<int> start;
int timer = 0;
int cycleLen = 0;

void dfs(int node, int parent){
    start[node] = timer++;
    for(int child : adj[node]){
        if(start[child] == -1){
            dfs(child, node);
        }else if(start[node] > start[child]+1 && child != parent){ // Back edge
            cycleLen = start[node]-start[child]+1;
        }
    }
}

int main()
{
    fast_io(); file_i();
    
    int n, e, discarded = 0;
    cin >> n >> e;
    adj.resize(n);
    start  = vector<int>(n, -1);
    lp(i, e){
        int from, to;
        cin >> from >> to;
        adj[from-1].push_back(to-1);
        adj[to-1].push_back(from-1);
    }
    lp(i, n){
        if(start[i] == -1){
            cycleLen = 0;
            dfs(i, -1);
            discarded += cycleLen%2;
        }
    }
    cout << discarded + (n - discarded)%2;
    
    return 0;
}