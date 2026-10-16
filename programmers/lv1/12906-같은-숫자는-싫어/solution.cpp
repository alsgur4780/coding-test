#include <vector>
#include <iostream>
#include <cstdio>


using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int num = arr[0];
    answer.push_back(arr[0]);
    
    for(int i = 1; i < arr.size(); i++){
        if(num != arr[i]){
            answer.push_back(arr[i]);
            num = arr[i];
        }
    }
    
    return answer;
}
