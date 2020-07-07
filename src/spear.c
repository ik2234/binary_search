#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int n, int k, int x){
  for(int i = 0; i < n; i++){
    int mem = A[i]/x;
    if(mem >= k) return 0;
    else k -= mem;
  }
  return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001; // 10^9+1 
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(p(A, n, k, mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", lb);
  return 0;
}
