#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
//소수판별
bool isPrime(int num)
{
    

    if(num<2) return false;
    for(int i=2; i<=sqrt(num); i++)
    {
        if(num%i==0) 
            return false;
    }
    return true;
}

int solution(string numbers) 
{
    set<int> primes;
    
    //1~7까지 적힌 종이 배열 
    sort(numbers.begin(),numbers.end());
    
    do
    {
        string temp = "";
        //처리
        for(int i=0; i<numbers.size(); i++)
        {
            temp = temp+numbers[i];
            int num = stoi(temp); //숫자로 변환
            //set에 추가
            if(isPrime(num))
            
                primes.insert(num);
            
        }
     }
        //다음 생성
        while(next_permutation(numbers.begin(), numbers.end()));
        
        return primes.size();
   
   
}