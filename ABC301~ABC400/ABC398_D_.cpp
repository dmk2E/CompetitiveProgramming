/*アルゴリズムと工夫点(Bonfire/CPU: 1126 ms Memory: 99372 KB  Length: 2376 B)
y,x座標それぞれについて累積和を取り，sum_yx[r]-sum_yx[l]==(R,C) となるようなrの値を求めればよい．
lを固定すると，sum_yx[r]の値は，"sum_yx[l]+(R,C)"となることを利用して，setを使って高速化する．
一度条件を満たしたら，その値は集合から消すようにすることで高速化した．
※sum[r]-sum[l]の計算式において，r>=lでないといけないという条件を見落としていた...
※本番終了後10分後にAC
*/
#include<iostream>
#include<vector>
#include<set>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,r,c;
string s;

int main(){
    int i,j;
    scanf("%d%d%d",&n,&r,&c);
    cin>>s;
    const int HASH=2*n;
    vector<int> sum_x(n+1,0),sum_y(n+1,0);
    vector<set<int> > dict_x(4*n+1),dict_y(4*n+1);
    dict_x[HASH].insert(0);
    dict_y[HASH].insert(0);
    rep(i,n){
        switch(s[i]){
            case 'N':
                sum_y[i+1]=sum_y[i]-1;
                sum_x[i+1]=sum_x[i];
                break;
            case 'W':
                sum_y[i+1]=sum_y[i];
                sum_x[i+1]=sum_x[i]-1;
                break;
            case 'S':
                sum_y[i+1]=sum_y[i]+1;
                sum_x[i+1]=sum_x[i];
                break;
            default:
                sum_y[i+1]=sum_y[i];
                sum_x[i+1]=sum_x[i]+1;
                break;
        }
        dict_y[sum_y[i+1]+HASH].insert(i+1);
        dict_x[sum_x[i+1]+HASH].insert(i+1);
    }
    string ans="";
    rep(i,n)ans+='0';
    rep(i,n){
        if((int)dict_y[r+sum_y[i]+HASH].size()>0&&(int)dict_x[c+sum_x[i]+HASH].size()>0){
            vector<int> tmp;
            if((int)dict_y[r+sum_y[i]+HASH].size()<(int)dict_x[c+sum_x[i]+HASH].size()){
                for(int y:dict_y[r+sum_y[i]+HASH]){
                    if(i<y&&dict_x[c+sum_x[i]+HASH].find(y)!=dict_x[c+sum_x[i]+HASH].end()){
                        if(0<=y-1&&y-1<n){
                            ans[y-1]='1';
                            tmp.push_back(y);
                        }
                    }
                }
            }else{
                for(int x:dict_x[c+sum_x[i]+HASH]){
                    if(dict_y[r+sum_y[i]+HASH].find(x)!=dict_y[r+sum_y[i]+HASH].end()){
                        if(i<x&&0<=x-1&&x-1<n){
                            ans[x-1]='1';
                            tmp.push_back(x);
                        }
                    }
                }
            }
            while(tmp.size()){
                dict_y[r+sum_y[i]+HASH].erase(tmp.back());
                dict_x[c+sum_x[i]+HASH].erase(tmp.back());
                tmp.pop_back();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}