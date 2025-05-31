/*アルゴリズムと工夫点(Forbidden Difference/CPU: 65 ms Memory: 5680 KB  Length: 2605 B)
各整数毎に頂点を用意したグラフ上で，|Ai+Aj|=Dを満たす場合，辺を張る．
すると，各連結成分ごとに，辺を全て消すためにかかる最小のコストを求めればよい．
ここでコストとは消去する頂点数のことを指す．これは動的計画法を用いれば解ける．
最悪計算量は，O(N)<10^6 となり十分高速．
※コンテスト後にAC
※例外処理を行わなければならない入力値について考慮できず，撃沈...
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef class CordinatedCompression{
    bool initiated;
    vector<int> xs;
public:
    CordinatedCompression(){
        xs=vector<int>(0);
        initiated=false;
    }
private:
    void init(){
        initiated=true;
        sort(xs.begin(),xs.end());
        xs.erase(unique(xs.begin(),xs.end()),xs.end());
    }
public:
    /// @brief 要素を追加する関数
    /// @param x 追加する座標
    void add(int x){
        initiated=false;
        xs.push_back(x);
    }

    int operator()(int k){
        if(!initiated)init();
        return lower_bound(xs.begin(),xs.end(),k)-xs.begin();
    }

    int operator[](int id){
        if(!initiated)init();
        return xs[id];
    }

    /// @brief 座標圧縮後の座標総数を返す
    /// @return 座圧後の座標総数
    int size(){
        if(!initiated)init();
        return xs.size();
    }
}CC;

int n,d;

int main(){
    int i,j,k,ans=0;
    scanf("%d%d",&n,&d);
    vector<int> a(n);
    CC as;
    rep(i,n){
        scanf("%d",&a[i]);
        as.add(a[i]);
    }
    vector<int> cnt(as.size());
    vector<bool> vis(as.size(),false);
    rep(i,n)cnt[as(a[i])]++;
    if(d==0){// 例外処理d==0 の場合を忘れてしまった...
        rep(i,as.size())ans+=cnt[i]-1;
        printf("%d\n",ans);
        return 0;
    }
    rep(i,as.size()){
        if(vis[i]==false){
            vector<int> ids(1,i);
            vis[i]=true;
            j=i;
            k=as(as[j]+d);
            while(k<as.size()&&as[k]==as[j]+d){// d==0の場合に無限ループしてしまう
                vis[k]=true;
                ids.push_back(k);
                j=k;
                k=as(as[j]+d);
            }
            if(ids.size()>1){
                //printf("contents:");rep(k,ids.size())printf("%d ",as[ids[k]]);puts("");
                vector<int> dp(2,0);
                for(int id:ids){
                    vector<int> now(2,0);
                    now[0]=dp[1];// 頂点を消さない
                    now[1]=min(dp[0],dp[1])+cnt[id]; // 頂点を消す
                    swap(now,dp);
                    //printf("%d %d\n",dp[0],dp[1]);
                }
                //printf("ans:%d\n",min(dp[0],dp[1]));
                ans+=min(dp[0],dp[1]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}