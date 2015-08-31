// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 31-08-2015

/********************************************************************************** 
* You are given a string, S, and a list of words, L, that are all of the same length. 
* Find all starting indices of substring(s) in S that is a concatenation of each word 
* in L exactly once and without any intervening characters.
* For example, given:
* S: "barfoothefoobarman"
* L: ["foo", "bar"]
* You should return the indices: [0,9].
* (order does not matter). 
**********************************************************************************/

#include <iostream>
#include <vector>
//#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> output;
        int len = s.size();
        int wordsLen = words.size();
        int wordLen = words[0].size();
        if(len < (wordsLen * wordLen) || wordLen <=0 ) return output;

        //Put words into hash table
        map<string,int> expected;
        for(int i=0; i<wordsLen; i++){
        	if(expected.find(words[i]) != expected.end()){
        		//cout << words[i] << "1" <<endl;
        		expected[words[i]]++;
        	}
        	else{
        		//cout << words[i] << "2" << endl;
        		expected[words[i]] = 1;
        	}
        }

        for(int j=0; j<len; j++){
        	map<string, int> test;
        	int count = 0;
        	int mark = j;
        	for(int k=j; k<len-wordLen; k=k+wordLen){
        		string w = s.substr(k,wordLen);
        		if(expected.find(w) == expected.end()){
        			test.clear();
        			count = 0;
        			mark = k + wordLen;
        			continue;
        		}
        		count++;

        		//calculate the times of occurence of w
        		if(test.find(w) == test.end()){
        			test[w] = 1;
        		}
        		else{
        			test[w]++;
        		}

        		if(test[w] > expected[w]){
        			string temp;
        			do{
        				temp = s.substr(mark,wordLen);
        				test[temp]--;
        				mark = mark + wordLen;
        				count--;
        			}while(temp != w);
        		}

        		if(count == wordsLen){
        			output.push_back(mark);
        			string temp2 = s.substr(mark, wordLen);
        			test[temp2]--;
        			mark = mark + wordLen;
        			count--;
        		}
        	}
        }
        return output;
    }
};
/* //For testing
int main(){
	Solution test;
	string s = "barfoobarfoothefoobarman";
    vector<string> l;
    vector<int> result;
    l.push_back("foo");
    l.push_back("bar");
    l.push_back("foo");

    result = test.findSubstring(s,l);
    for(int i=0; i<result.size(); i++){
    	cout << result[i] << endl;
    }
    
	return 0;
}
*/
