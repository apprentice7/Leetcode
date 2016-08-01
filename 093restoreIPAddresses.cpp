// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 12-11-2015

/********************************************************************************** 
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
* For example:
* Given "25525511135",
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> output;
        if(n<4 || n>12) return output;
        stirng temp;

        getIpAddress(output, s, temp, n, 0);
        return output;
    }
private:
	void getIpAddress(vector<string> output, string s, string temp, int n, int pos){
		int count = 0;
		for(int i=0; i<temp.size(); i++){
			if(temp[i] == '.') count++;
			if(count > 3) return;
		}

		if(temp.size() == n+3 && count == 3){
			output.push_back(temp);
		}
		else{
			for(int i=0; i<n; i++){
				temp += s[i];
				if(pos==0 || pos==1){
					temp += '.';
					getIpAddress(output,s,temp,n,++pos);
					temp.pop_back();
				}
				else if(pos==2){

				}
				
			}

		}

	}
};

 //For testing
int main(){
	Solution test;


	return 0;
}