#include <stdio.h>

int n;
int k;
int A[100000];
int B[100000];
int ans;
int m;

int p(int x){
	int i,j,sum,k;
	ans=0;
	k=0;
	for(i = 0;i < n; i++){
		sum = 0;
		for(j = i;j < n;j++){
			sum = sum + A[j];
			B[k] = sum;
			k = k + 1;
		}
	}
	m = n*(n+1)/2;
	 int min;
	 for(i = 0; i < m; i++){
	 	min = i;
	 	for(j = i+1; j < m; j++){
	 		if(B[j] < B[min]){ 
	 		min = j;
	 		}
	 	}
	 	int z = B[i]; 
	 	B[i] = B[min]; 
	 	B[min] = z;
	 }
	for(i = 0;i < n; i++){
	ans = ans + A[i];
	}
	return B[x] > ans/2 && x>= m/2;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);  }
  lb = 0 ;
    ub = n*(n+1)/2 ;
    while (ub - lb > 1) {
    	int x = (lb + ub) / 2 ;
    	if(p(x)){
    		ub = x ;
    	}
    	else {
    		lb = x ;
    	}
    }
  printf("%d\n" , B[ub]) ;
  return 0;
}