/*アルゴリズムと工夫点(引っ越し/CPU:  ms Memory:  KB  Length:  B)
保留
*/
#include<iostream>
#include<vector>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_H 8
#define MAX_W 8
#define MAX_C 4
using namespace std;
typedef long long ll;

int h,w;
vector<vector<vector<int> > > dp;
bool mmap[MAX_H][MAX_W],carpet[MAX_C][2][2]={
                                         {{0,1},
                                          {1,1}},
                                         {{1,0},
                                          {1,1}},
                                         {{1,1},
                                          {1,0}},
                                         {{1,1},
                                          {0,1}},};

bool judge(int y,int x,int state,int num){
    int i,j;
    rep(j,2){
        if(carpet[num][0][j]&&(mmap[y][x+j]||state&(1<<(x+j))))return false;
    }
    rep(j,2){
        if(carpet[num][1][j]&&mmap[y+1][x+j])return false;
    }
    return true;
}

int main(){
    int i,j,state;
    while(1){
        scanf("%d%d",&h,&w);
        if(!(h||w))break;
        rep(i,h){
            getchar();
            rep(j,w)
                mmap[i][j]=getchar()=='#';//True:壁,False:床
        }
        dp=vector<vector<vector<int> > >(h+1,vector<vector<int> >(w,vector<int>(1<<w,0)));
        dp[0][0][0]=1;
        i=j=0;
        while(i<h){
            rep(state,1<<w){
                if((state&(1<<j))||mmap[i][j]){//マス(i,j)が空でない場合
                    if(j<=w-2)
                        dp[(i+(j==w-2))][(j+2)%w][state+(1<<j)+(1<<(j+1))]+=dp[i][j][state];
                }else{//マス(i,j)が空である場合
                    if(j<=w-2){
                        dp[(i+(j==w-2))][(j+2)%w][state+(1<<j)+(1<<(j+1))]+=dp[i][j][state];
                    }
                    dp[i+(j==w-1)][(j+1)%w][state&(~(1<<j))]+=dp[i][j][state];
                }
            }
            i+=(j==w-1);
            j=(j+1)%w;
        }
        printf("%d\n",dp[h][0][0]);
    }
    return 0;
}