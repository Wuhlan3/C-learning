#include<iostream>
#include<vector>
using namespace std;

//针对子串计算处next数组
void buildNext(vector<int>& next, string &patt){
    next[0] = 0;
    int prefix_len = 0;     //共同前后缀长度
    int i = 1;
    while(i < patt.size()){
        //如果当前字符与前缀的下一个字符相同，那么可以跳过prefix_len个字符
        if(patt[prefix_len] == patt[i]){
            prefix_len++;
            next[i] = prefix_len;
            i++;
        }else{//不相同
            if(prefix_len == 0){
                next[i] = 0;
                i++;
            }else{
                prefix_len = next[prefix_len - 1];  //查看前缀的前一个
            }
        }
    }
    return;
}

void buildNext2(vector<int>& next, string &patt){
    next[0] = 0;
    int prefix_len = 0;
    for(int i = 1;i < patt.size(); i++){
        while(prefix_len > 0 && patt[i] != patt[prefix_len]) {
            prefix_len = next[prefix_len - 1];
        }
        if(patt[i] == patt[prefix_len]) {
            prefix_len++;
        }
        next[i] = prefix_len;
    }
}

bool kmp(string& str, string& pattern){
    //ToDo:
}

int main(){
    string str = "abaaabcabababaab";
    string pattern = "ababc";
                    //00120
    vector<int> next(pattern.size(), 0);
    buildNext2(next, pattern);
    //next代表了，当匹配失败后，根据最后一个匹配的字符的next值来跳过pattern的指针，可以避免主串指针的回退
    for(auto x : next){
        cout << x << " ";
    }
    cout << endl;
}