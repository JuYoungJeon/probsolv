#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int l=1; l<=s.size()/2; l++){
        int cl=0;
        string a="";
        for(int i=0; i<s.size(); ){
            if(i+2*l>s.size()) {
                cl+=s.size()-i;
                a+=s.substr(i, s.size()-i);
                break;
            }
            int numToAdd=0;
            int ir=1;
            while(i+l<=s.size()&&s.substr(i,l)==s.substr(i+l, l)){
                i+=l;
                ir+=1;
            }
            if(ir!=1)a+=to_string(ir); 
            a+=s.substr(i, l);
            i+=l;
        }
        answer=min(answer, (int)a.size());
    }
    return answer;
}
//problem faced: 10X일때 숫자 갯수세기; s[0..l]까지를 하나로 본다
//solution: 갯수를 count 하지 않고 string 으로 읽어서 len으로 출력, s[0..l]==s[l..2l]이아닐때 l개 skip한다
