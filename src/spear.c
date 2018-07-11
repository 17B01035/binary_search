#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
	int i,ans;
	ans =0;
	for(i = 0; i < n; i++){
	ans = ans + A[i]/x;
	}
	return ans >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0 ;
    ub = 1000000001 ;
    while (ub - lb > 1) {
    	int x = (lb + ub) / 2 ;
    	if(p(x)){
    		lb = x ;
    	}
    	else {
    		ub = x ;
    	}
    }
  printf("%d\n" , lb) ;
  return 0;
}