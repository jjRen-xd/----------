#include<iostream>

int binary_search(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l+(r-l)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            return binary_search(arr, l, mid-1, x);
        }
        else{
            return binary_search(arr, mid+1, r, x);
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 8;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = binary_search(arr, 0, n-1, x);
    if(result == -1){
        std::cout<<"Element is not present in array"<<std::endl;
    }
    else{
        std::cout<<"Element is present at index "<<result<<std::endl;
    }
    return 0;
}