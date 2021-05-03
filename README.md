# Leetcode 211 Design Add and Search Words Data Structure
My solution for the problem 211 Design Add and Search Words Data Structure

# Problem Description 
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 
## Test Case

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

## Constraints:
- 1 <= word.length <= 500
- word in addWord consists lower-case English letters.
- word in search consist of  '.' or lower-case English letters.
- At most 50000 calls will be made to addWord and search.


## Solution 1 : Backtrack + Hashtable 
-------------------------------------

We could generate all possible combination of a word using backtrack/recursion and then store them in a hastable . 
For example for 'at' all possible combination would be 
- at
- .t
- a.
- ..

when searching , we would simply look up in the hashtable .

complexity : O(2^n) for insert operation where n is the lenght of the word and o(1) search operation. 
This might be a feasible solution if there are a lot of search operations comparing to the insert operations .


## Solution 2 : Trie + DFS 
------------------------------

we simply add a word in trie . when searching if we are at at node X and if we find '.' we can go to any neighbour node of X .

complexity : O(n) for insert operation and o(t*n) for search operation where t is the number of word and n is length of a word. The searching is exhaustive and exponential but optimized because there are pruning here. For example, if we find no satisfying next node we dont search any deeper .

another way to say the complexity of search is p^c where p is number of '.' (p<=n) and c is total possible charecter in trie . here c = 26 