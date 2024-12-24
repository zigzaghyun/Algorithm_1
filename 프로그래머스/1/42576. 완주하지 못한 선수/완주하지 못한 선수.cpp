#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    //배열
    sort(participant.begin(),participant.end() );
    sort(completion.begin(),completion.end() );
    
    //비교
    for(size_t i=0; i<completion.size(); i++){
        //완주 못한사람 리턴
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    //마지막 참가자가 완주하지 못한 경우
    return participant.back();
}