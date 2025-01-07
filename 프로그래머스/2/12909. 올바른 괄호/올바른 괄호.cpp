#include <string>
#include <iostream>
#include <stack>


using namespace std;

bool solution(string s)
{
   
   	stack<char> stk;
	
    for(char ch:s)
    {
        //열린 괄호 스택 추가
        if(ch=='(')
        {
            stk.push(ch);
        }
        //닫힌 괄호 팝 제거
        else if(ch==')')
        {
            if(stk.empty())
            {
                 return false;
            }
               stk.pop();
        }     
    }
	return stk.empty();

}