#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    //전화번호 정렬
    sort(phone_book.begin(), phone_book.end());
    
    //인접한 두 번호 비교
        for(size_t i=0; i < phone_book.size()-1; i++){
            if(phone_book[i+1].find(phone_book[i])==0)
                return false;
        }
            
    //아니면
    return true;
}