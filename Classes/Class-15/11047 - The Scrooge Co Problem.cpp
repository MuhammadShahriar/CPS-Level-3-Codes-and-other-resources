///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

const int mx = 123;
ll dist[mx][mx];
int nxt[mx][mx];

int main()
{
	optimize();

    int T;
    cin >> T;

    while ( T-- ) {
        int n;
        cin >> n;

        vector<string> node(n);
        map<string, int> id;
        for ( int i = 0; i < n; i++ ) {
            cin >> node[i];
            id[node[i]] = i;
        }

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                cin >> dist[i][j];
                if ( dist[i][j] == -1 ) dist[i][j] = inf;
            }
        }

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                nxt[i][j] = j;
            }
        }


        for ( int k = 0; k < n; k++ ) {
            for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                    if ( dist[i][k] + dist[k][j] < dist[i][j] ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        nxt[i][j] = nxt[i][k];
                    }
                }
            }
        }


        int q;
        cin >> q;

        while ( q-- ) {
            string empl, start, end;
            cin >> empl >> start >> end;

            int s = id[start];
            int t = id[end];

            if ( dist[s][t] == inf ) {
                cout << "Sorry Mr "<< empl << " you can not go from " << start << " to " << end << endl;
                continue;
            }

            cout << "Mr " << empl << " to go from " << start << " to " << end << ", you will receive " << dist[s][t] << " euros" << endl;

            int cur = s;
            vector<int> path;
            path.PB ( s );

            while ( cur != t ) {
                cur = nxt[cur][t];
                path.PB ( cur );
            }

            if ( sz(path) == 1 ) path.PB ( path[0] );

            cout << "Path:" << node[path[0]];
            path.erase(path.begin());

            for ( auto u : path ) cout << " " << node[u];
            cout << endl;


        }


    }




	return 0;
}


/*

2
6
Ofi1 Ofi2 Ofi3 ofi4 ofi5 ofi6
0 4 1 -1 4 -1
4 0 -1 2 3 4
1 -1 0 -1 3 -1
-1 2 -1 0 -1 1
4 3 3 -1 0 2
-1 4 -1 1 2 0
1
emp1 Ofi1 ofi4
3
Murcia Alicante Albacete
0 3 -1
-1 0 4
-1 -1 0
2
Dofyl Murcia Albacete
Dofyl Albacete Murcia

*/











