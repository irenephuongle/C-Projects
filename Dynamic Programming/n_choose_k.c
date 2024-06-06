#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int min(int a, int b);
int min(int a, int b){
        return a < b ? a : b;
}
int n_choose_k(int n, int k, int t[n][k]);
int n_choose_k(int n, int k, int t[n][k]){
return 0;


}
int main(){
    int n = 5;
    int k = 3;
    int t[n+1][k+1];
    t[0][0] = 1;

 for (int i = 0; i <= n; i++){
        for (int j = 0; j <= min(i,k); j++){
            if (j == 0 || j == i)
                t[i][j] = 1;
        
            else
                t[i][j] = t[i-1][j-1] + t[i-1][j]; 
        }
    }
    printf("%d", t[n][k]);
    return 0;

   }

    
