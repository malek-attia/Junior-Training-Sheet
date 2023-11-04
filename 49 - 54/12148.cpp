#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>

#define el "\n"
#define spc <<" "<<

#define lpi(i, j, n)   for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)   for(int i=(j);i>=(int)(n);--i)
#define lp(i,n)    lpi(i,0,n)

#define all(v)  ((v).begin()), ((v).end())
#define sz(v)  ((int)((v).size()))
#define maxi(v) *max_element(all(v))
#define mini(v) *min_element(all(v))
#define sort(v) sort(all(v))
#define sum(v) accumulate(all(v),0)

void fast_io()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

void file_i()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}
bool leap(int y){
    return y%4==0 && (y%100!=0 || y%400==0);
}

bool is_consecutive(int d1,int m1,int y1,int d2,int m2,int y2){
    if(y1 == y2){
        if(m1 == m2){
            return (d2-d1)==1;
        }else if((m2-m1)==1){
            if(m1==2){
                if(leap(y1)){
                    return d1==29 && d2==1;
                }else{
                    return d1==28 && d2==1;
                }
            }else{
                if((m1<8 && m1%2) || (m1>7 && m1%2==0)){
                    return d1==31 && d2==1;
                }else{
                    return d1==30 && d2==1;
                }
            }
        }
    }
    return ((y2-y1)==1 && m1==12 && m2==1 && d1==31 && d2==1);
}

int main()
{
    fast_io; file_i();
    int tc;
    while(cin >> tc, tc){
        int sum = 0, cons = 0;
        int d1, m1, y1, c1, d2, m2, y2, c2;
        cin >> d1 >> m1 >> y1 >> c1;
        tc--;
        while(tc--){
            cin >> d2 >> m2 >> y2 >> c2;
            if(is_consecutive(d1, m1, y1, d2, m2, y2)){
                sum += c2 - c1;
                cons++;
            }
            d1=d2;m1=m2;y1=y2;c1=c2;
        }
        cout << cons spc sum << el;
    }
    
    return 0;
}