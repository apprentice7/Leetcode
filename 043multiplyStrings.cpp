
/********************************************************************************** 
* 
* Given two numbers represented as strings, return multiplication of the numbers as a string.
* 
* Note: The numbers can be arbitrarily large and are non-negative.
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> set;
		vector<int> output;
		vector< vector <int> > result;
		string OutputString;
		int a = num1.size();
		int b = num2.size();
		if(a==1 && (num1[0]-'0')==0) return "0";
		if(b==1 && (num2[0]-'0')==0) return "0";
		
		for(int i=b-1; i>=0; i--){
			int remainder = 0;
			for(int j=a-1; j>=0; j--){
				int Operator = num2[i] - '0';
				int target = num1[j] - '0';
				int temp = Operator * target + remainder;
				remainder = temp / 10;
				set.push_back(temp % 10);
				if(j == 0 && ((temp/10)>0) ) set.push_back(temp / 10);
			}
			result.push_back(set);
			set.clear();
		}
		//int TempSize = result.size();
		int mark = 0;
		int i = 0;
		int rem = 0;
		while(!result[b-1].empty()){
			int out = 0;
			i = mark;
			out = out + rem;
			while(i >= 0){
				while(i>b-1){
					i--;
				}
				if(result[i].empty()) break;
				out = out + result[i][0];
				result[i].erase(result[i].begin());
				i--;
			}
			rem = out / 10;
			output.push_back(out % 10);
			if(result[b-1].empty() && rem !=0) output.push_back(rem);
			out = 0;
			mark++;
		}
		reverse(output.begin(), output.end());
		for(int n=0; n<output.size(); n++){
			char tmp = output[n] + '0';
			OutputString = OutputString + tmp;
		}
		return OutputString;
    }
};

int main(){
	Solution test;
	string x = "140";
	string y = "721";

	cout << test.multiply(x, y) << endl;
	return 0;
}
