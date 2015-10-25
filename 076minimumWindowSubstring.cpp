// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 25-10-2015

/**********************************************************************************
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * Note:
 * > If there is no such window in S that covers all characters in T,
 *   return the emtpy string "".
 * > If there are multiple such windows, you are guaranteed that there
 *   will always be only one unique minimum window in S.
 **********************************************************************************/


/* idea adopted from: https://leetcode.com/discuss/18584/sharing-my-straightforward-o-n-solution-with-explanation */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        int minLength = INT_MAX;
        int letterCount = 0;
        string output;
        unordered_map<char, int> tmap;
        unordered_map<char, int> window;
        
        for(int i=0; i<m; i++){
            tmap[t[i]]++;
        }
        for(int slow=0,fast=0; fast<n; fast++){
            char c = s[fast];
            if(tmap.find(c) != tmap.end()){ //char is find in string t
                window[c]++; // insert char into window
                if(window[c] <= tmap[c]) letterCount++; // letterCount indicate find all chars in t
            }
            // shrink the window
            if(letterCount >= m){
                // s[slow] is not found in tmap or s[slow] count is more than that in tmap
                while(tmap.find(s[slow]) == tmap.end() || window[s[slow]] > tmap[s[slow]]){
                    window[s[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minLength){
                    minLength = fast - slow +1;
                    output = s.substr(slow, minLength);
                }
                window[s[slow]]--;
                slow++;
                letterCount--;
            }
        }
        return output;
    }
};
/* //For testing
int main(){
    Solution test;
    string a = "ADOBECODEBANC";
    string b = "ABC";
    string re;
    
    re = test.minWindow(a, b);
    
    cout << re << endl;
    
    
    return 0;
}
*/
