# 📝 Group Anagrams in C++

## Problem

Given an array of strings, group the anagrams together.
Example:

```cpp
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]
```

---

## Solution 1: Sorting-based key

### Methodology

* For each string:

  * Sort the characters alphabetically.
  * Use the sorted string as the key in a hash map.
* All anagrams will share the same sorted string → grouped together.

### Complexity

* Sorting each string of length `k` costs `O(k log k)`.
* For `n` strings total: **O(n · k log k)**.
* Space: **O(n · k)** (map + output).

### Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result;

        for (auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // O(k log k)
            result[sortedStr].push_back(str);
        }

        vector<vector<string>> results;
        for (auto& pair : result) {
            results.push_back(pair.second);
        }
        return results;
    }
};
```

---

## Solution 2: Counting-based key

### Methodology

* Instead of sorting:

  * Count frequency of each character (`a–z`) → 26-length vector.
  * Serialize the frequency vector into a string (e.g., `"#1#0#0#2..."`) to avoid ambiguity.
  * Use this serialized string as the key.
* Faster because counting is linear in `k`.

### Complexity

* Counting letters in each string costs `O(k)`.
* For `n` strings total: **O(n · k)**.
* Space: **O(n · k)** (map + output).

### Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapToChar;

        for (auto& str : strs) {
            vector<int> count(26, 0);
            for (char chr : str) {
                count[chr - 'a']++;   // build frequency vector
            }

            // serialize frequency vector into a key
            string key;
            for (int c : count) {
                key += "#" + to_string(c);  // use separator to avoid ambiguity
            }

            mapToChar[key].push_back(str);
        }

        vector<vector<string>> results;
        for (auto& pair : mapToChar) {
            results.push_back(pair.second);
        }
        return results;
    }
};
```

---

In practice, sort() version has more speed.

Both are valid. Counting-based is generally preferred for performance when `k` (string length) is large.


