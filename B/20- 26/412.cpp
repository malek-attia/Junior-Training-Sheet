#include<bits/stdc++.h>
//color a & curl parrot.live

using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vll vector<ll>

#define in [&](){int num; cin >> num; return num;}()
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

const int π = M_PI;

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

ll gcd(ll a, ll b) { return (!b? a : gcd(b, a % b));}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}

bool isPrime (int x){
    for(int i = 2; i*i <= x; i++) if(x%i == 0) return 0;
    return (x<2? 0 : 1);
}


int count(vi v, int idx){
    int ans = 0;
    if(idx == sz(v)-1) return ans;

    lpi(i, idx+1, sz(v)){
        ans += (gcd(v[idx], v[i]) == 1);
    }
    return ans + count(v, idx+1);
}



int main()
{
    fast_io(); file_i();
    int n;
    cout << fixed << setprecision(6);
    string blank;
    while(cin >> n && n){
        vi v(n);
        lp(i, n) cin >> v[i];
        int cnt = count(v, 0);
        if(!cnt){
            cout << "No estimate for this data set.\n";
        }else{
            double tot = n * (n - 1) * 3;
            cout << sqrt(tot / (double)cnt) << el;
        }
    }
    
    return 0;
}