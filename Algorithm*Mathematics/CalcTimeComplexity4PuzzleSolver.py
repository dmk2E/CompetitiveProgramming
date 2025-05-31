'''アルゴリズムと工夫点(PuzzleSolver計算量出力器/CPU: - ms Memory: - KB  Length: - B)
丁度今参考書精進で扱っている逆元の復習も兼ねて，PuzzleSolverの最悪計算量の値を出力するコードを書いてみました．
参考にしてください．最悪計算量は 前処理:O(MAX) 各クエリ:O(1)
(全状態数の計算はMODで割った時の余りで計算しているので，全状態数がそもそもMOD以上の値だと，正しい値になりません)
-入力形式-
H W C (ただし H*W<=MAX,C<=MAX)
----------
入力例 出力例
3 4 3 : 4158000
2 7 3 : 35315280
3 4 4 : 44352000
これ以下は10^8 を超えてしまうため，1秒以上かかる
3 4 5 : 199584000
2 7 4 : 588588000
3 5 3 : 25225200000
'''
MAX=100
MOD=1000000007
def power(x:int,a:int)->int:
    x%=MOD
    ans=1
    while a>0:
        if a & 1:
            ans=(ans*x)%MOD
        x=(x*x)%MOD
        a>>=1
    return ans

fac=[0 for _ in range(0,MAX+1)];fac[0]=1
for i in range(0,MAX):
    fac[i+1]=(fac[i]*(i+1))%MOD

inv=[0 for _ in range(0,MAX+1)]
inv[MAX]=power(fac[MAX],MOD-2)
for i in range(MAX-1,-1,-1):
    inv[i]=(inv[i+1]*(i+1))%MOD

while True:
    h,w,c=map(int,input().split())
    if max(0,min(MAX,h))==h and max(0,min(MAX,w))==w and max(0,min(MAX,c))==c:
        tmp=h*w
        imos=[0 for _ in range(0,c)]
        imos[0]+=(tmp//c)
        tmp%=c
        imos[0]+=1
        imos[tmp]-=1
        for i in range(0,c-1):
            imos[i+1]+=imos[i]

        mul_inv=1
        for i in range(0,c):
            mul_inv=(mul_inv*inv[imos[i]])%MOD
        print(f"ans:{((fac[h*w]*mul_inv)%MOD)*h*w*10}")
    else:
        break