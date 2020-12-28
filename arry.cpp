#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2005];
int main(){
    ll int i,j,k,l,t,c,d,p,q,n,m,x,y,sm;
    scanf("%lld",&t);
    while(t--){
        vector<ll>v[5];
        scanf("%lld",&n);
        for(i=0; i<n; i++){
            scanf("%lld %lld",&x,&y);
            v[x].push_back(y);
        }
        sm=0;
        for(i=1; i<=3; i++){
            sort(v[i].begin(),v[i].end());
        }
        for(i=1; i<=3; i++){
            for(j=1; j<=3; j++){
                if(i==j)
                    continue;
                for(k=1; k<v[i].size(); k++){
                    p=v[j].size()*(v[i][k]-v[i][k-1])*abs(i-j);
                    sm+=p*k*(v[i].size()-k);
                }
            }
        }
        for(j=0; j<v[2].size(); j++)
            a[j+1]=a[j]+v[2][j];
        for(i=0; i<v[1].size(); i++){
            c=0;
            for(k=0; k<v[3].size(); k++){
                p=(v[1][i]+v[3][k]);
                while(c<v[2].size() && 2*v[2][c]<=p)
                    c++;
                sm+=((p*c)-2*a[c])+(2*(a[v[2].size()]-a[c])-p*(v[2].size()-c));
            }
        }
        cout << fixed << setprecision(7) << (double)sm/2.00 << endl;
    }
    return 0;
}
