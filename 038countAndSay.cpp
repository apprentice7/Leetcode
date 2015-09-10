// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 11-09-2015

/********************************************************************************** 
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* Given an integer n, generate the nth sequence.
* Note: The sequence of integers will be represented as a string.
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string test = "1";
        
        while(n>1){
        	string temp;
        	for(int i=0; i<test.size(); i++){
        		int count = 1;
        		if(i == test.size()-1){
        			temp += "1";
        			temp += test[i];
        		}
        		else{
        			while(test[i] == test[i+1] && i!=test.size()-1){
        				count++;
        				i++;
        			}
        			char tmp = count + '0';
        			temp += tmp;
        			temp += test[i];
        		}
        	}
        	test = temp;
        	n--;
        }
        return test;
    }
};
/* //For testing
int main(){
	Solution test;
	cout << test.countAndSay(1) << endl;
	return 0;
}
*/
