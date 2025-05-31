/*アルゴリズムと工夫点(ジェットコースター 2/CPU:  ms Memory:  KB  Length:  B)
dic[i][m]:元の順番が変わらない行列で，i-1番目まで既にジェットコースターに乗っている状態で，残りの席数がmである時，そこから全員乗せるまでアトラクションを開始した回数
とするメモ化で解いた．
ACできるかはAOJに追加されるまで分からない．
*/
#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)n;i++)
#define NIL -1
using namespace std;
typedef long long ll;

typedef pair<int,int> p;

int n,m;
map<p,bool> dic;
map<p,int> dicv;
vector<int> a,rest,c;

int res(int now,int rest,int cnt){
    //printf("now:%d rest:%d cnt:%d\n",now,rest,cnt);
    if(now==n){
        return cnt+(rest==m?0:1);
    }
    int temp;
    if(dic[p(now,rest)])return cnt+dicv[p(now,rest)];
    if(rest>=a[now]){
        dicv[p(now+1,rest-a[now])]=res(now+1,rest-a[now],cnt)-cnt;
        dic[p(now+1,rest-a[now])]=true;
        return cnt+dicv[p(now+1,rest-a[now])];
    }else{
        dicv[p(now,m)]=res(now,m,cnt+1)-cnt;
        dic[p(now,m)]=true;
        return cnt+dicv[p(now,m)];
    }
}

int main(){
    int i,j,mm,cnt,ans;
    while(1){
        scanf("%d%d",&n,&m);
        if(!(n||m))break;
        a=vector<int>(n);
        rest=vector<int>(n,NIL);
        c=vector<int>(n,NIL);
        dic.clear();
        dicv.clear();
        cnt=0;
        rep(i,n)
            scanf("%d",&a[i]);
        mm=m;
        rep(i,n){
            while(i<n&&mm>=a[i]){
                if(rest[i]==NIL){
                    rest[i]=mm;
                    c[i]=cnt;
                }
                mm-=a[i];
                i++;
            }
            if(rest[i]==NIL){
                rest[i]=mm;
                c[i]=cnt;
            }
            cnt++;
            i--;
            mm=m;
        }
        //printf("cnt:%d\n",cnt);
        rep(i,n){
            dic[p(i,rest[i])]=true;
            dicv[p(i,rest[i])]=cnt-c[i];
            //printf("i:%d rest:%d dic:%d c:%d\n",i,rest[i],cnt-c[i],c[i]);
        }
        ans=cnt;
        vector<int> tmp;
        rep(i,n-1){
            tmp=vector<int>(0);
            tmp.push_back(a[i+1]);
            tmp.push_back(a[i]);
            mm=rest[i];
            cnt=c[i];
            //printf("i:%d mm:%d cnt:%d\n",i,mm,cnt);
            rep(j,2){
                while(j<2&&mm>=tmp[j]){
                    mm-=tmp[j];
                    j++;
                }
                //printf("j:%d mm:%d\n",j,mm);
                if(j==2)break;
                cnt++;
                j--;
                mm=m;
            }
            //printf("i:%d mm:%d cnt:%d\n",i+2,mm,cnt);
            int tmp;
            ans=min(ans,tmp=res(i+2,mm,cnt));
            //printf("ans:%d\n",tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}