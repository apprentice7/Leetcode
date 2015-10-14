// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 14-10-2015

/********************************************************************************** 
* Given an array of words and a length L, format the text such that each line has 
* exactly L characters and is fully (left and right) justified.
* You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
* Pad extra spaces ' ' when necessary so that each line has exactly L characters.
* Extra spaces between words should be distributed as evenly as possible. 
* If the number of spaces on a line do not divide evenly between words, 
* the empty slots on the left will be assigned more spaces than the slots on the right.
* For the last line of text, it should be left justified and no extra space is inserted between words.
* For example,
* words: ["This", "is", "an", "example", "of", "text", "justification."]
* L: 16.
* Return the formatted lines as:
* [
*    "This    is    an",
*    "example  of text",
*    "justification.  "
* ]
* Note: Each word is guaranteed not to exceed L in length.
* Corner Cases:
* A line other than the last line might contain only one word. What should you do in this case?
* In this case, that line should be left-justified.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*adopted from https://github.com/haoel/leetcode/blob/master/algorithms/textJustification/textJustification.cpp*/
vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    int len=0;
    int start = 0;
    int end = 0;
    double space =0;
    bool lastLine = false;
    for (int i=0; i<words.size(); i++){
        len += words[i].size();
        if (len + i - start > L || i == words.size()-1) {
            //remove the last one
            if (len + i - start > L) {  
                len -= words[i].size();
                end = i-1;
                lastLine = false;
            }else{
                end = i;
                lastLine = true;
            }
            //calculate the space number
            space = L - len;
            int mspace;
            int extra;
            if (lastLine){
                mspace = 1;
                extra = 0;
            } else {
                mspace = floor(space/(end-start));
                extra = space - mspace * (end-start);
            }
            string line = words[start];
            for (int j=start+1; j<=end; j++) {
                for(int k=0; k<mspace && space>0; k++, space--) {
                    line += " ";
                }   
                if (j-start-1 < extra){
                    line += " ";
                    space--;
                } 
                line += words[j];
            }
            //add the rest space
            if (space>0){
                for(; space>0; space--) {
                    line += " ";
                }
            }
            result.push_back(line);
            start = i;
            i = end;
            len = 0;
        } 
    }
    return result;
}








/* cannot pass the verification because the postition of space*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
	unsigned int max = maxWidth;
	vector<string> result;

	while(words.size() > 0){
		string output;
		int check = 0;
		int i = 0;
		int l = words[0].size();
		int wordsLen = 0;
		int space = 0;

		//check number of words
		while(i<words.size()-1 && l <= max){
			i++;
			l = l + 1 + words[i].size();
		}
		cout << i << endl;
		if(i == 0 ) check = 0;
		else if(l<=max && i==words.size()-1) check = 1;
		else check = 2;
		cout << "check: " << check << endl;
			
		//check the number of space

		/* Only one word*/
		if(check == 0){
			space = maxWidth - words[0].size();
			output += words[0];
			while(space>0){
				output += ' ';
				space--;
			}
			result.push_back(output);
			words.erase(words.begin(),words.begin()+1);
			cout << "here" << endl;
		}

		/* count i is equal to number of words*/
		else if(check == 1){
			for(int j=0; j<=i; j++){
				wordsLen += words[j].size();
			}
			space = maxWidth - wordsLen;
			appendWords(space, i, words, result);
		}
			/* count i is greater than number of words by one*/
		else if(check == 2){
			for(int j=0; j<i; j++){
				wordsLen += words[j].size();
			}
			if(i==1) space = maxWidth - words[0].size();
			space = maxWidth - wordsLen;
			appendWords(space, i-1, words, result);
		}
				
	}
	return result;
    }

    void appendWords(int space, int i, vector<string>& words, vector<string>& result){
    	string output;
    	string fSpace;
	string rSpace;
	if(i==0){
		output += words[0];
		while(space>0){
			output += ' ';
			space--;
		}
		result.push_back(output);
		words.erase(words.begin(),words.begin()+1);
		return;
	}
	int rearSpace = space / i;
	int addSpace = space % i;
		for(int s=0; s<rearSpace;s++){
		rSpace += ' ';
	}
	fSpace = rSpace + ' ';
			
	//append words and space to a new string
	for(int s=0; s<=i; s++){
		output += words[s];
		if(s==i) break;
		if(addSpace>0) {
			output += fSpace;
			addSpace--;
		}
		else{
			output += rSpace;
		}
	}
	
	result.push_back(output);
	words.erase(words.begin(),words.begin()+i+1);
	return;
    }
};

/* //For testing
int main(){
	Solution test;
	vector<string> v;
	//string arr[] = {"this","is","an","example","of","text","justification."};
	//string arr[] = {"a","b","c","d","e"};
	string arr[] = {"What","must","be","shall","be."};
	v.assign(arr,arr+5);
	vector<string> out;
	out = test.fullJustify(v,12);
	for(int i=0; i<out.size();i++){
		cout<<out[i]<<endl;
	}
	return 0;
}
*/
