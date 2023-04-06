#include <iostream>
#include<vector>
using namespace std;


void func(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    int size = vec.size();
    for(int i = size; i>=0; i--){
        vec.insert(vec.begin()+i, 9);
        cout<<vec[i]<<endl;
    }

}

int main(){
    func();
    return 0;
}
