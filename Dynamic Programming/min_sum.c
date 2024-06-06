#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int min(int a, int b);
int min(int a, int b){
        return a < b ? a : b;

}
int main(){
    int n = 4;
    int table[4][4] = {
        [0][0] = 2,
        [1][0] = 5,
        [1][1] = 4,
        [2][0] = 1,
        [2][1] = 4,
        [2][2] = 7,
        [3][0] = 8,
        [3][1] = 6,
        [3][2] = 9,
        [3][3] = 6 };
    int sum;

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i; j++)
            table[i][j] = table[i][j] + min(table[i+1][j], table[i+1][j+1]);
        }

    printf("The minimum sum is: %d", table[0][0]);

    return 0;
}