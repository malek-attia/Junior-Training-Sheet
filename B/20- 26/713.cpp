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
#define ins [&](){string s; cin >> s; return s;}()
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



int main()
{
    fast_io(); file_i();
    int n = in;
    while(n--){
        string n = ins, m = ins;
        int mx = max(sz(n), sz(m));
        vi ans(mx+1, 0);
        lp(i, mx){
            if(i < sz(n)) ans[i] += n[i]-'0';
            if(i < sz(m)) ans[i] += m[i]-'0';
        }
        int remainder = 0;
        lp(i, mx+1){
            ans[i] += remainder;
            remainder = 0;
            if(ans[i] > 9){
                remainder += ans[i]/10;
                ans[i] %= 10;
            }
        }
        int i = 0;
        while(i < mx && ans[i]==0) i++;
        for(; i < mx; i++) cout << ans[i];
        if(ans[mx]) cout << ans[mx];
        cout << el;
    }
    
    return 0;
}