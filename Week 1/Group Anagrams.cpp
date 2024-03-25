/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> value;     //initialize a unorders_map as value
        for(int i = 0; i < strs.size(); i++ ) {
            string s = strs[i];
            sort(s.begin(), s.end());
            value[s].push_back(strs[i]);  // here key is the sorted string ans its value is the original string
          // for any other string , once it is sorted we will get the same key, so the string is added to the vlaue os the same key
        }

        vector<vector<string>> result;   //initialize the result vecore
        for(const auto& key : value){   
            result.push_back(key.second);   //push the value part of each key to the result vector and return it.
        }

        return result;
    }
};
