#include<bits/stdc++.h>
#define rep(i,n)for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;

int i,j;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        int cnt=0;
        rep(i,n){
            if(a[i]+cnt<=300){
                cnt+=a[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}