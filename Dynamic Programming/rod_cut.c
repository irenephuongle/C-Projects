#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b);
int max(int a, int b)
{
    return a > b ? a : b;
}
int rod_cut(int t[], int n);
int rod_cut(int t[], int n){
  int rev[n+1];
  // n = number of rod pieces
  rev[0] = 0;

  for(int i = 1; i <= n; i++){
    int max_rev = -1;

    for(int k = 0; k < i; k++){
        max_rev = max(max_rev, t[k] + rev[i-k-1]);
    }
    rev[i] = max_rev;
  }
  return rev[n]; 
}
int main(){
        //      0 1 2 3 4
    int t[5] = {2,5,7,1,5};
    int n = 5;
    int max_rev = 0;

    max_rev = rod_cut(t,n);
    printf("The maximum revenue is: %d", max_rev);

    return 0;
}