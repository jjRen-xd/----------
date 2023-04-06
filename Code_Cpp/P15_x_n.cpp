// P15, 计算x的n次方
#include<iostream>

int num = 0;

int x_n_1(int x, int n){
    int result = 1;         // 任何数的0次方都是1
    for(int i = 0; i<n; i++){
        result *= x;    
        num++;
    }
    return result;
}

int x_n_2(int x, int n){
    if(n == 0){
        return 1;
    }
    else{
        return x_n_2(x, n-1)*x;
    }
}

int x_n_3(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    if(n % 2 == 0){
        num ++;
        return x_n_3(x, n/2) * x_n_3(x, n/2);
    }
    else{
        num ++;
        return x_n_3(x, n/2) * x_n_3(x, n/2) * x;
    }
}   

int x_n_4(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    int temp = x_n_4(x, n/2);
    if(n % 2 == 0){
        num ++;
        return temp * temp;
    }
    else{
        num ++;
        return temp * temp * x;
    }
}

int main(){
    int x, n;
    std::cin>>x>>n;
    std::cout<<x_n_4(x, n);
    std::cout<<std::endl<<num;
    return 0;
}