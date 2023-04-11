// P32, 给出一个以时间换空间的例子: 给出n个字符(小写字母a-z), 
// 找出其中出现次数最多的字母, 并输出出现的次数
#include<iostream>
#include<vector>

void solution1(const std::vector<char> &a){
    int max_emerge_num = 0;
    char max_char;
    for(int i = 0; i<a.size(); i++){
        int emerge_num = 0;
        for(int j = 0; j<a.size(); j++){
            if(a[i] == a[j]){
                emerge_num++;
            }
        }
        if(emerge_num > max_emerge_num){
            max_emerge_num = emerge_num;
            max_char = a[i];
        }
    }
    std::cout<<"最多的字符:"<<max_char<<", 出现次数:"<<max_emerge_num<<std::endl;
}

void solution2(const std::vector<char> &a){
    int record[26] = {0};
    for(int i = 0; i<a.size(); i++){
        record[a[i]-'a']++;
    }
    int max_emerge_num = 0;
    char max_char;
    for(int i = 0; i<26; i++){
        if(record[i]>max_emerge_num){
            max_emerge_num = record[i];
            max_char = i+'a';
        }
    }
    std::cout<<"最多的字符:"<<max_char<<", 出现次数:"<<max_emerge_num<<std::endl;
}

int main(){
    std::vector<char> a = {'a', 'b', 'c', 'd', 'c', 'f', 'g', 'h', 'j', 'j', \
        'k', 'l', 'm', 'n', 'o', 'p', 'c', 'r', 'j', 't', 'u', 'c', 'w', 'x', \
        'y', 'z'
    };
    solution2(a);
    return 0;
}