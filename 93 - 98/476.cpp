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
//type in cmd w ed3ely ;)

using namespace std;

#define ll long long
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

ll gcd(ll a, ll b) { return (!b? a : gcd(b, a % b));}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}

bool isPrime (int x){
    for(int i = 2; i*i <= x; i++) if(x%i == 0) return 0;
    return (x<2? 0 : 1);
}

struct point{
    double x;
    double y;
};

struct rectangle{
    point UL;
    point LR;
    bool point_in_fig(point p){
        return (p.x > UL.x && p.x < LR.x && p.y < UL.y && p.y > LR.y);
    }
};


int main()
{
    fast_io(); file_i();
    rectangle figures[10];
    char c;
    for(int i = 0; cin >> c; i++){
        if(c == '*') break;
        cin >> figures[i].UL.x >> figures[i].UL.y >> figures[i].LR.x >> figures[i].LR.y;
    }
    point p;
    for(int i = 1; cin >> p.x >> p.y; i++){
        if(p.x == 9999.9 && p.y == 9999.9) break;
        bool in = 0;
        lp(j, 10){
            if(figures[j].point_in_fig(p)){
                cout << "Point "<<i<<" is contained in figure "<< j+1 <<el;
                in = 1;
            }
        }
        if(!in){
            cout << "Point "<<i<<" is not contained in any figure"<< el;
        }
    }
    
    
    return 0;
}