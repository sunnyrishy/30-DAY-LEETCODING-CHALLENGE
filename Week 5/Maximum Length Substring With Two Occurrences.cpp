/* 
Given a string s, return the maximum length of a 
substring
 such that it contains at most two occurrences of each character.
 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.

*/


class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char, int> mp;
        int maxx = 0;
        int id = 0;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            while (mp[s[i]] > 2)
            {
                mp[s[id]]--;
                id++;
            }
            maxx = max(maxx, i - id + 1);
        }
        return maxx;
    }
};
