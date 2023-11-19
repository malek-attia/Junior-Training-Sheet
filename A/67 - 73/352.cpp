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
#define find(set, x) set.find(x) != set.end()

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

vector<vector<bool>> adj;
vector<vector<bool>> visited;
int n;

bool valid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<n);
}

void dfs(int x, int y){
    if(!valid(x, y) || adj[x][y] == 0 || visited[x][y]) return;
    visited[x][y] = 1;
    int dx[] = {1,  1, 1, 0,  0, -1, -1, -1};
    int dy[] = {1, -1, 0, 1, -1,  1, -1,  0};
    lp(i, 8){
        dfs(x+dx[i], y+dy[i]);
    }
}

int main()
{
    fast_io(); file_i();
    int img = 0;
    while(cin>>n){
        img++;
        adj = visited = vector<vector<bool>> (n, vector<bool>(n, 0));
        lp(i, n){
            lp(j, n){
                char c;
                cin >> c;
                adj[i][j] = c-'0';
            }
        }
        int cnt = 0;
        lp(i, n){
            lp(j, n){
                if(!visited[i][j] && adj[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << "Image number "<<img<< " contains "<<cnt<<" war eagles."<<el;
    }
    
    return 0;
}