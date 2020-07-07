#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int n, int k, int x){
  k -= 1;
  int mem = x;
  for(int i = 0; i < n; i++) {
    if(A[i] > x || (k == 0 && A[i] > mem)) return 0;
    else if(mem >= A[i]) mem -= A[i];
    else{
      k -= 1;
      mem = x - A[i];
    }
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
    if(mid && p(A, n, k, mid)) ub = mid; // midが0でないかつ...
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
