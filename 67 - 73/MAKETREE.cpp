/*******************************************|
|===========================================|

                    ال
                Time Limit
                  صابتني
              ورب العرش نجاني

|===========================================|
|*******************************************/

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
vector<bool> visited;
vector<int> topsort;

void dfs(int node){
    visited[node] = 1;
    for(int child : adj[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
    topsort.push_back(node+1);
}



int main()
{
    fast_io(); file_i();
    
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, 0);
    lp(i, m){
        int w;
        cin >> w;
        while(w--){
            int to;
            cin >> to;
            adj[i].push_back(to-1);
        }
    }
    lp(i, n){
        if(!visited[i]){
            dfs(i);
        }
    }
    vi parent(n+1, 0);
    reverse(all(topsort));
    parent[topsort[0]] = 0;
    lpi(i, 1, n){
        parent[topsort[i]] = topsort[i-1];
    }
    lpi(i, 1, n+1){
        cout << parent[i] <<el;
    }
    return 0;
}