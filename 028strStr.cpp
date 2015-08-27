// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 27-08-2015

/********************************************************************************** 
* Given an array and a value, remove all instances of that value in place and return the new length.
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.          
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsize = haystack.size();
		int nsize = needle.size();
	    if(nsize==0) return 0;
		if (nsize>hsize) return -1;
		if (nsize==hsize) {
		    if(haystack==needle) return 0;
		    else return -1;
		}

		for(int i=0;i<hsize;i++){
			if(haystack[i] == needle[0]){
			    bool flag=true;
				int n=0;
				int k=i;
				while(k<hsize && n<nsize){
					if(haystack[k]!=needle[n]){
						flag = false;
						break;
					}
					k++;
					n++;
				}
				if(flag == true && n==nsize){
					return i;
				}
			}
			else{
				while(haystack[i+1] == haystack[i]){
					i++;
				}
			}
		}
		return -1;
    }
};

/* //For testing
int main(){
	Solution test;
	string h = "mississippi";
	string n = "issip";
	cout << test.strStr(h,n) << endl;

	return 0;
}
*/
