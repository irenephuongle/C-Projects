#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions
void user_input(int n, int *data);
void user_input(int n, int *data){
    int input;
    for(int k =0; k<n ; k++){
        //printf("Enter the data: ");
        scanf("%d", &input);
        data[k] = input;
    }
    return;
}
void print_data(int n, int *data);
/// @brief 
/// @param n 
/// @param data 
void print_data(int n, int *data){
  for(int k=0; k<n; k++){
        printf("%d ", data[k]);
    }
    printf("\n");
    return;
}
void merge_sort(int *data, int low, int high, int n);
void merge(int *data, int low, int mid, int high, int n);
void merge(int *data, int low, int mid, int high, int n){
    //make two temporary arrays to store the values of the array in
    int len1 = mid - low +1;
    int len2 = high - mid;

    int temp1[len1];
    int temp2[len2];

    //copy content of the array into temporary arrays
    for(int i = 0; i < len1; i++){
        temp1[i] = data[low + i];
    }
    for(int i = 0; i < len2; i++){
        temp2[i] = data[mid + 1 + i];
    }
    int i,j,k;
    //merge 
    for(i = 0, j = 0, k = low; k <= high; k++){
        //if data in temp1 is smaller than data in temp2, store temp1 data in array
        if((i < len1) &&
        (j >= len2 || temp1[i] <= temp2[j])){
            data[k] = temp1[i];
            i++;
        }
        //if data in temp2 is smaller than data in temp1, store temp2 data in array
        else{
            data[k] = temp2[j];
            j++;
        }
    }
   
    return;
}
void merge_sort(int *data, int low, int high, int n){
    if(low < high){
        int mid = low+(high-low)/2;
        /* left side */ merge_sort(data,low,mid,n);
        /* right side */merge_sort(data,mid+1,high,n);
                //merge both sides of the arrays into one
        merge(data,low,mid,high, n);

    }

    return;
}


int main(){
    //array of data (size 1000)
    int n = 0;
    int data[1000];

    //Read user input for n (amount of data in the array)
    printf("Enter the number of data: ");
    scanf("%d", &n);

    //Reads all input from user and stores it into array data[1000]
    user_input(n,data);

    //print unsorted data
    printf("Your unsorted data is: ");
    print_data(n,data);

    merge_sort(data,0,n-1,n);

    printf("Your sorted data is: ");
    print_data(n,data);

    system("pause");
    return 0;
}