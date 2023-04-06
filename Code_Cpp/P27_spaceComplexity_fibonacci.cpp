#include<iostream>
#include<chrono>
#include<thread>

using namespace std::chrono;

int fibonacci(int i){
    if(i<=0){
        return 0;
    }
    else if(i==1){
        return 1;
    }
    else{
        return fibonacci(i-1)+fibonacci(i-2);
    } 
}

int fibonacci_2(int first, int second, int i){
    if(i<=0){
        return 0;
    }
    else if(i<3){
        return 1;
    }
    else if(i==3){
        return first+second;
    }
    else{
        return fibonacci_2(second, first+second, i-1);
    }
}

void time_consumption(){
    int i = 0;
    while(std::cin>>i){
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        int result = 0;
        // result = fibonacci(i);
        result = fibonacci_2(1, 1, i);
        std::cout<<result<<std::endl;
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        std::cout<<"i="<<i<<", 耗时:"<<milliseconds(end_time).count() - \
            milliseconds(start_time).count()<<"ms"<<std::endl;
    }
}

int main(){
    time_consumption();
    return 0;
}