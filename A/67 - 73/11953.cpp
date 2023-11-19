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

vector<vector<char>> grid;
vector<vector<bool>> visited;
int n;

bool valid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<n);
}

int dx[] = {1, -1, 0,  0}; 
int dy[] = {0,  0, 1, -1}; 

void dfs(int x, int y){
    if(!valid(x, y) || visited[x][y] || grid[x][y]=='.') return;
    visited[x][y] = 1;
    lp(i, 4){
        dfs(x+dx[i], y+dy[i]);
    }
}

int main()
{
    fast_io(); file_i();
    int t;
    cin >> t;
    lpi(CaseNum, 1, t+1){
        cin >> n;
        int cnt = 0;
        grid = vector<vector<char>> (n, vector<char> (n, '.'));
        visited = vector<vector<bool>> (n, vector<bool>(n, 0));
        lp(i, n){
            lp(j, n){
                cin >> grid[i][j];
            }
        }
        lp(i, n){
            lp(j, n){
                if(grid[i][j] == 'x' && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << "Case "<<CaseNum<<": "<<cnt<<el;
    }
    
    return 0;
}