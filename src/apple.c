#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];

int p(int x){
    int i;
    int ans;
    ans=0;
    for(i = 0; i < n; i++){
        if (A[i]%x==0) {B[i] = A[i]/x;}
        else {B[i] = A[i]/x + 1;}
        ans = ans + B[i];
    }
    return ans <= k;
}

int main(){
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    lb = 0 ;
    ub = A[n-1] ;
    while (ub - lb > 1) {
        int x = (lb + ub) / 2 ;
        if(p(x)){
            ub = x ;
        }
        else {
            lb = x ;
        }
    }
    printf("%d\n" , ub) ;
    return 0;
}
