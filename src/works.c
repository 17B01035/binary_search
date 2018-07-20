#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];
int ans;
int m;

int p(int x){
	int i,sum,l;
	sum = 0;
	l = 1;
	for(i = 0;i < n; i++){
		if(A[i] > x) return 0;
		if(sum + A[i] <= x) sum += A[i];
		else {
			l++;
			sum = A[i];
		}
	}
	return l <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);  }
  lb = 0 ;
    ub = 1000000000 ;
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