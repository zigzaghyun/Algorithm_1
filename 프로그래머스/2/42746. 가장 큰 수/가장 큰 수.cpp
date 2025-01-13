#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

   //비교 함수
    bool compare(string a, string b)
    {
        return a+b>b+a;
    }
    
string solution(vector<int> numbers) {
    vector<string> str_numbers;
    
    //숫자 -> 문자
    for(int num:numbers)
    {
        str_numbers.push_back(to_string(num));
    }
    //큰 값부터 정렬
    sort(str_numbers.begin(),str_numbers.end(), compare);
    
    //만약 0이 제일 크면
    if(str_numbers[0]=="0")
    {
        return "0";
    }
    //정렬된 숫자를 붙여 큰 수로 만들기
    string result = "";
    for(string str:str_numbers)
        {
            result=result+str;
        }
    
    return result;
}