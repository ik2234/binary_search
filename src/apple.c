#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int n, int k, int x){
  for(int i = 0; i < n; i++) {
    int ceil = (A[i] + x - 1)/x; // A[i]/x の切り上げ
    if(k < ceil) return 0;
    else k -= ceil;
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
  ub = 1000000000; // 10^9
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(p(A, n, k, mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
