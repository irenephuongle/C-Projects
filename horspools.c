#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int search(char ascii_table[], char pattern[], char text[], int p_len, int t_len, int *comparisons);
int search(char ascii_table[], char pattern[], char text[], int p_len, int t_len, int *comparisons){
    int i = p_len-1;
    int j;

    while(i < t_len){
        j = 0;
        while((j < p_len) && (pattern[p_len-1-j]== text[i-j])){
          *comparisons = 1 + *comparisons;
            j++;
        }
        
        if(j == p_len){
            return i-p_len;
        }
        else {          
            *comparisons = 1 + *comparisons;
            i += ascii_table[text[i]];
        }

    }
    return 1;
}
void initialize(char ascii_table[], char pattern[], int p_len);
void initialize(char ascii_table[], char pattern[], int p_len){
    for(int i = 0; i<128; i++){
        ascii_table[i] = p_len;
    }

    for(int i = 0; i < p_len-1; i++){
        ascii_table[pattern[i]] = p_len - 1 - i;
    }
}

int main(){
char ascii_table[128]; //array of size 100 to
char pattern[1000]; //pattern read from user
char text[1000]; //text read from user
int found;
int comparisons = 0;

//get pattern from user
printf("Enter the pattern: ");
scanf("%s", pattern);
size_t p_len = strlen(pattern);

printf("Enter the text: ");
scanf("%s", text);
size_t t_len = strlen(text);

//initialize the ascii table with length of pattern
initialize(ascii_table, pattern, p_len);

found = search(ascii_table, pattern, text, p_len, t_len, &comparisons);
if(found == 1){
    printf("\nThe string was not found.");
    printf("\n%d comparisons took place. ", comparisons);
}
else{
    printf("\nThe string was found at index: %d", found+1);
    printf("\n%d comparisons took place. ", comparisons);
    }


return 0;
}