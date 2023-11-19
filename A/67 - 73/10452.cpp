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
    freopen("out.txt","w",stdout);
    #endif // ONLINE_JUDGE
}

vector<string> path;
vector<vector<bool>> visited;
int m, n;
bool finish;

bool valid(int x, int y){
    return (y>=0 && x<m && y<n);
}
string safe = "@IEHOVA#";

void dfs(int x, int y, string direction = "", int idx=0){
    if(!valid(x, y) || visited[x][y] || path[x][y]!=safe[idx]) return;
    visited[x][y] = 1;
    if(idx == 7) finish = 1;
    cout << direction <<(!finish && path[x][y]!='@'?" ":"");
    if(!finish)
        dfs(x+1, y, "forth", idx+1);
    if(!finish)
        dfs(x, y+1, "right", idx+1);
    if(!finish)
        dfs(x, y-1, "left", idx+1);
}

int main()
{
    fast_io(); file_i();
    tc{
        cin >> m >> n;
        int y;
        path = vector<string>(m);
        visited = vector<vector<bool>> (m, vector<bool>(n, 0));
        lpd(i, m-1, 0){
            lp(j, n){
                cin >> path[i][j];
                if(!i && path[i][j]=='@') y = j;
            }
        }
        finish = 0;
        dfs(0, y);
        cout << el;
    }
    
    return 0;
}