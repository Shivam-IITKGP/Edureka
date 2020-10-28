#include <bits/stdc++.h>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#define vi vector<int>
#define vl vector<long long>
#define vpi vector<pair<int,int> >
#define ll long long 
#define vpl vector<pair<long long,long long> > 
#define f first
#define s second
#define mp make_pair
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pci pair<char,int>
#define vs vector<string> 
#define un unsigned
# define M_PI           3.14159265358979323846  /* pi */
 //#define mod 998244353
//#define mod 1000000007
#define MAXN  1000001
using namespace std; 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
/*
//------------------------------------------DSU--------------------------------------------------------//
int parent[1000001];
int ssize[1000001];
 
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void make_set(int v) {
    parent[v] = v;
    ssize[v] = 1;
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ssize[a] < ssize[b])
            swap(a, b);
        parent[b] = a;
        ssize[a] += ssize[b];
    }
}
*/
 
//-----------------------------Sieve Of Eratosthenes--------------------------------------//
 
/*
v<int> primes;
void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.pb(p); 
}
 
*/
 
//----------------DFS------------------------
/*
int n;
vi adj[100001];
int p[100001];
int d[100001];
bool visited[100001];
 
 
void dfs(int start)
{
    visited[start] = true;
    for(auto u : adj[start])
    {
        if(!visited[u])
        {
            // visited[u] = start;
            p[u] = start;
            d[u] = d[start]+1;
            dfs(u);
        }
    }
}
*/
//----------------------------------------------
 
//----------------BFS------------------------
/*
int n;
vi adj[100001];
int p[100001];
int d[100001];
bool visited[100001];
 
 
void bfs(int start)
{
    visited[start] = true;
    queue<int> q;
    q.push(start);
    d[start] = 0;
    p[start] = -1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto u : adj[v])
        {
            if(!visited[u])
            {
                visited[u] = true;
                parent[u] = v;
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
}
*/
//----------------------------------------------
ll mod= 1000000007;
ll n;

ll func(vector<ll>adj[],int node, int parent,vector<ll> &ed){
	
	ll ret=1;
	
	for(auto i:adj[node]){
		if(i==parent) continue;
		ret+= func(adj,i,node,ed);
	}
	ll tmp = (ret*(n-ret));
	//cout<<"f"<<tmp<<' '<<node<<' '<<parent<<' ';
	if(parent) ed.push_back(tmp);
	return ret;
}

int main()
{
    fast;
    int t;
    t=1;
    cin>>t;
    
    while(t--)
   {

    cin >> n ;
    vector <ll> adj[n+1];
    for(int i=0;i<n-1;i++){
    	ll u,v;
    	cin >> u >>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
	}
	int m;
	cin >>m;
	vector <ll> p(m);
	for(int i=0;i<m;i++) cin >> p[i];
	sort(p.begin(),p.end(),greater<ll>());
	vector <ll> ed;
	func(adj,1,0,ed);
	sort(ed.begin(),ed.end(),greater<ll>());
	
   // for(auto i:ed) cout<<i<<' ';
    //cout<<endl;
    cout<<ed.size()<<"cc"<<n-1<<endl;
	int k= ed.size();
	ll ans=0;
	int i=0;
	int j=0;
	while(j<k){
		if(i>=m){
			ans+= ed[j++];
			ans%=mod;
		}
		else{
			ans+= (ed[j++]*p[i++])%mod;
			ans%= mod;
		}
	}
	cout<<ans<<endl;
   }
   
    return 0;
}
