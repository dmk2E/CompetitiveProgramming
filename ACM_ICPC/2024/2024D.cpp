#include<bits/stdc++.h>
#define rep(i,n)for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
#define MAX 101

struct ins
{
    ll x,y,w;
    ll d;
};


int main(){
    ll n,i,x,y,a,b;
    ll d;
    while(cin>>n,n){
        cin>>a>>b>>d;
        vector<vector<bool>> m(MAX,vector<bool>(MAX,0));
        vector<vector<vector<ll>>> c(MAX,vector<vector<ll>>(MAX,vector<ll>(4,-1)));
        rep(i,n){
            cin>>x>>y;
            m[y][x]=1;
        }

        queue<ins> q;
        q.push({a,b,0,0});
        ins t;
        int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
        bool roop=0;
        while (!q.empty())
        {
            t=q.front();
            q.pop();
            //printf("%lld:%lld %lld\n",t.d,t.x,t.y);
            if(t.d==d)break;
            if(t.x<=100&&t.x>=0&&t.y<=100&&t.y>=0){
                if(!roop&&c[t.y][t.x][t.w]!=-1){
                    q.push({t.x,t.y,t.w,
                    t.d+((d-t.d)/(t.d-c[t.y][t.x][t.w]))*(t.d-c[t.y][t.x][t.w])});
                    roop=1;
                    continue;
                }
                c[t.y][t.x][t.w]=t.d;
            }
            x=t.x+dx[t.w],y=t.y+dy[t.w];
            if(x<0){
                t.x-=d-t.d;
                break;
            }else if(x>100){
                t.x+=d-t.d;
                break;
            }
            if(y<0){
                t.y-=d-t.d;
                break;
            }else if(y>100){
                t.y+=d-t.d;
                break;
            }
            if(m[y][x]){
                while(t.y+dy[(t.w+1)%4]<=100&&t.y+dy[(t.w+1)%4]>=0&&
                    t.x+dx[(t.w+1)%4]<=100&&t.x+dx[(t.w+1)%4]>=0&&
                    m[t.y+dy[(t.w+1)%4]][t.x+dx[(t.w+1)%4]]){
                    t.w=(t.w+1)%4;
                }
                q.push({t.x+dx[(t.w+1)%4],t.y+dy[(t.w+1)%4],(t.w+1)%4,t.d+1});
            }else{
                q.push({x,y,t.w,t.d+1});
            }
        }
        printf("%lld %lld\n",t.x,t.y);
    }
    return 0;
}