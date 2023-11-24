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


ll pow(ll x, ll p, int m){
    if(p == 1 || x == 1 || x == 0) return x;
    else if(!p) return 1;

    ll sq = pow(x, p/2, m)%m;
    sq = (sq%m * sq%m)%m;
    if(p%2) sq *= x;

    return sq%m;
}


int main()
{
    fast_io(); file_i();
    ll n, m;
    while(cin >> n >> m && n){
        int temp_m = m;
        m = min(m, n-m);
        vi v(m);
        lp(i, m) v[i] = n-i;
        ll left = 1;
        lpd(mod, m, 2){
            int i= m-1;
            for(; i >= 0; i--){
                if(v[i]%mod == 0){
                    v[i] /= mod;
                    break;
                }
            }
            if(i == -1)
                left *= mod;
        }
        ll ans = 1;
        lp(i, m) ans *= v[i];
        cout << n << " things taken " << temp_m <<" at a time is "<< ans/left <<" exactly.\n";
    }
    
    return 0;
}