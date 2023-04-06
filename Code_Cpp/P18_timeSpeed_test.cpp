// 测试计算机1s可以处理多大量级的数据
#include<iostream>
#include<chrono>
#include<thread>

using namespace std::chrono;

// O(n)
void function1(long long n){
    long long k = 0;
    for(long long i = 0; i<n; i++){
        k++;
    }
}
// O(n^2)
void function2(long long n){
    long long k = 0;
    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<n; j++){
            k++;
        }
    }
}
// O(nlogn)
void function3(long long n){
    long long k = 0;
    for(long long i = 0; i<n; i++){
        for(long long j = 1; j<n; j*=2){    // 注意这里是j=1
            k++;
        }
    }
}

int main(){
    long long n;
    while(1){
        std::cout<<"输入n: ";
        std::cin>>n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        function3(n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        std::cout<<"O(n), 耗时:"<<milliseconds(end_time).count() - \
            milliseconds(start_time).count()<<"ms"<<std::endl;
    }
    return 0;
}
