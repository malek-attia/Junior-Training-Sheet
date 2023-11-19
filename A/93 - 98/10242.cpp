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
    double x, y;
};

const double EPSILON = 1e-6;

bool equal(double x, double y){
    return (fabs(x - y) < 1e-6);
}


int main()
{
    fast_io(); file_i();
    cout << fixed << setprecision(3);
    point s1 , e1 , s2 , e2;
    while(cin >> s1.x >> s1.y >> e1.x >> e1.y){
        cin >> s2.x >> s2.y >> e2.x >> e2.y;

        double vec2x = e2.x - s2.x, vec2y = e2.y - s2.y;
        // Move V1 by increase
        s1.x += vec2x; e1.x += vec2x;
        s1.y += vec2y; e1.y += vec2y;

        if(equal(s1.x, s2.x) && equal(s1.y, s2.y) || equal(s1.x, e2.x) && equal(s1.y, e2.y)){
            cout << e1.x spc e1.y <<el; continue;
        }else if(equal(e1.x, s2.x) && equal(e1.y, s2.y) || equal(e1.x, e2.x) && equal(e1.y, e2.y)){
            cout << s1.x spc s1.y <<el; continue;
        }

        //Move V1 by decrease
        s1.x -= 2*vec2x; e1.x -= 2*vec2x;
        s1.y -= 2*vec2y; e1.y -= 2*vec2y;

        if(equal(s1.x, s2.x) && equal(s1.y, s2.y) || equal(s1.x, e2.x) && equal(s1.y, e2.y)){
            cout << e1.x spc e1.y <<el; continue;
        }else if(equal(e1.x, s2.x) && equal(e1.y, s2.y) || equal(e1.x, e2.x) && equal(e1.y, e2.y)){
            cout << s1.x spc s1.y <<el; continue;
        }
    }
    
    return 0;
}