// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 12-11-2015

/********************************************************************************** 
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
* For example:
* Given "25525511135",
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
**********************************************************************************/

<<<<<<< HEAD
=======
/* This is first example of Depth First search */
>>>>>>> 39b04954ba463736bc4d675a3e953858797f6887
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
<<<<<<< HEAD
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
=======
        string temp;
        getIpAddress(output, s, temp, n, 0, 0);
        return output;
    }
private:
	void getIpAddress(vector<string>& output, string s, string temp, int n, int pos, int start){
		//remaining digits: more than filling and less than all
		if(n-start < 4-pos || n-start > 3*(4-pos)) return;

		//Hit requirement: use up all digits && total 4 sections
		if(start == n && pos == 4){
			temp.pop_back();
			output.push_back(temp);
			return;
		}

		//num is to record the number of this section, every time a iteration -> pos++, num=0
		int num = 0;

		//Backtracing from start and forward for at most 3 digit
		for(int i=start; i<start+3 && i<n; i++){
			num = num*10 + (s[i]-'0');
			if(num < 256){
				temp += s[i];
				temp += '.';
				getIpAddress(output,s,temp,n,pos+1,i+1);
				temp.pop_back();
				/* another way that needs no pop_back():
				getIpAddress(output,s,temp+'.',n,pos+1,i+1);
				temp+'.' -> perform the backtracing
				*/
			}
			if(num == 0) break;
		}
	}
};

/* //For testing
int main(){
	Solution test;
	string s = "103227134";
	vector<string> re;
	re = test.restoreIpAddresses(s);
	for(int i=0; i<re.size(); i++){
		cout<<re[i]<<endl;
	}

	return 0;
}
*/
>>>>>>> 39b04954ba463736bc4d675a3e953858797f6887
