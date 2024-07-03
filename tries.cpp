#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;
#define ll long long
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<vector<vector<int>>> VVVI;
typedef vector<string> VS;
typedef queue<int> QU;
typedef queue<pair<int, int>> QP;
typedef queue<pair<pair<int, int>, int>> QPP;
#define PB push_back
#define SZA(arr) (sizeof(arr) / sizeof(arr[0]))
#define SZ(x) ((int)x.size())
#define LEN(x) ((int)x.length())
#define REV(x) reverse(x.begin(), x.end());
#define trav(a, x) for (auto &a : x)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORE(i, n) for (int i = 0; i <= n; i++)
#define FOR_INNER(j, i, n) for (int j = i; j < n; j++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(x.begin(), x.end(), 0LL)

// Short function start-->>
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void printAdjList(const vector<int> adj[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j = 0; j < adj[i].size(); ++j)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// Short function end-->>
/*
Li'll Interoduction----->>>
1️⃣ What is Trie??
-->>The word "Trie" is an excerpt from the word "retrieval". Trie is a sorted tree-based data-structure that stores the set of strings. It has the number of pointers equal to the number of characters of the alphabet in each node. It can search a word in the dictionary with the help of the word's prefix.
Trie is also known as the digital tree or prefix tree. The position of a node in the Trie determines the key with which that node is connected.
2️⃣ What're the besic operations?
-->> Insertion of a node
Searching a node
Deletion of a node
3️⃣ Applications of Trie?
-->>Spell checker
Auto complete
Browser history
4️⃣
5️⃣
6️⃣
7️⃣
8️⃣

9️⃣

🔟

1️⃣1️⃣

1️⃣2️⃣

1️⃣3️⃣
1️⃣4️⃣
1️⃣5️⃣
1️⃣6️⃣
*/

/*
1. Implement TRIE | INSERT | SEARCH | STARTSWITH
ANS : A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :Insertion: O(N) Search: O(N) Prefix Search: O(N)
// SC : O(N) For each character in a word, a new node may need to be created leading to space proportional to the number of characters.
/*
Intuition : A Trie node is a data structure used to construct Trie. Each node contains the following components:

Links to Child Nodes: A Trie node contains an array of pointers called “links” or “pointer to children” for each letter of the lowercase alphabet. These pointers represent connections to child nodes corresponding to each letter of the alphabet. For instance, the link at index 0 corresponds to the child node representing the letter 'a', the link at index 1 corresponds to 'b', and so forth.
Flag for End of Word: Each Trie node contains a boolean flag indicating whether the node marks the end of a word. This flag is essential for distinguishing between prefixes and complete words stored in the Trie.

Each node in the trie nodes support several operations:

Contains Key: This operation checks whether a specific letter (or key) exists as a child node of the current Trie node. It returns true if the letter is present, indicating a valid path in the Trie.
Get Child Node: Given a letter, this operation retrieves the corresponding child node of the current Trie node. If the letter is present, it returns the pointer to the child node; otherwise, it returns nullptr, signifying the absence of the letter.
Put Child Node: This operation establishes a connection between the current Trie node and a child node representing a particular letter. It sets the link at the corresponding index to point to the provided child node.
Set End Flag: Marks the current Trie node as the end of a word. This flag is crucial for determining whether a string stored in the Trie terminates at this node, indicating a complete word.
Is End of Word: Checks whether the current Trie node signifies the end of a word by examining the end flag. It returns true if the node marks the end of a word; otherwise, it returns false.
*/
// struct Node
// {
//     // Array to store links to child nodes,
//     // each index represents a letter
//     Node *links[26];
//     // Flag indicating if the node
//     // marks the end of a word
//     bool flag = false;

//     // Check if the node contains
//     // a specific key (letter)
//     bool containsKey(char ch)
//     {
//         return links[ch - 'a'] != NULL;
//     }

//     // Insert a new node with a specific
//     // key (letter) into the Trie
//     void put(char ch, Node *node)
//     {
//         links[ch - 'a'] = node;
//     }

//     // Get the node with a specific
//     // key (letter) from the Trie
//     Node *get(char ch)
//     {
//         return links[ch - 'a'];
//     }

//     // Set the current node
//     // as the end of a word
//     void setEnd()
//     {
//         flag = true;
//     }

//     // Check if the current node
//     // marks the end of a word
//     bool isEnd()
//     {
//         return flag;
//     }
// };

// Trie class
// class Trie
// {
// private:
//     Node *root;

// public:
//     // Constructor to initialize the
//     // Trie with an empty root node
//     Trie()
//     {
//         root = new Node();
//     }

//     // Inserts a word into the Trie
//     // Time Complexity O(len), where len
//     // is the length of the word
//     void insert(string word)
//     {
//         Node *node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             if (!node->containsKey(word[i]))
//             {
//                 // Create a new node for
//                 // the letter if not present
//                 node->put(word[i], new Node());
//             }
//             // Move to the next node
//             node = node->get(word[i]);
//         }
//         // Mark the end of the word
//         node->setEnd();
//     }

//     // Returns if the word
//     // is in the trie
//     bool search(string word)
//     {
//         Node *node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             if (!node->containsKey(word[i]))
//             {
//                 // If a letter is not found,
//                 // the word is not in the Trie
//                 return false;
//             }
//             // Move to the next node
//             node = node->get(word[i]);
//         }
//         // Check if the last node
//         // marks the end of a word
//         return node->isEnd();
//     }

//     // Returns if there is any word in the
//     // trie that starts with the given prefix
//     bool startsWith(string prefix)
//     {
//         Node *node = root;
//         for (int i = 0; i < prefix.length(); i++)
//         {
//             if (!node->containsKey(prefix[i]))
//             {
//                 // If a letter is not found, there is
//                 // no word with the given prefix
//                 return false;
//             }
//             // Move to the next node
//             node = node->get(prefix[i]);
//         }
//         // The prefix is found in the Trie
//         return true;
//     }
// };
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
2. Implement Trie - 2 (Prefix Tree)
ANS : Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
Note:

1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?
Input :   || Output :
*/
/*Intuition: The prefix tree specifically uses counters to keep track of the number of words ending with the current node and how many words contain the current node letter. A classical Trie accomplished this using the boolean flag to indicate that a word ends at this node.

Each node in this Prefix Trie contains:

An array of pointers to child nodes (26 slots, one for each lowercase English letter).
Counters for tracking the number of words that end at the node (‘cntEndWith’) and the number of words that have the node as a prefix (‘cntPrefix’).
*/
// Bruteforce ----------->
// TC :
// SC :
// struct Node
// {
//     // Array to store
//     // links to child nodes
//     Node *links[26];
//     // Counter for number of
//     // words that end at this node
//     int cntEndWith = 0;
//     // Counter for number of words
//     // that have this node as a prefix
//     int cntPrefix = 0;

//     // Function to check if the
//     // node contains a specific key
//     bool containsKey(char ch)
//     {
//         // Check if the link corresponding
//         // to the character exists
//         return (links[ch - 'a'] != NULL);
//     }

//     // Function to get the child
//     // node corresponding to a key
//     Node *get(char ch)
//     {
//         // Return the link
//         // corresponding to the character
//         return links[ch - 'a'];
//     }

//     // Function to insert a child
//     // node with a specific key
//     void put(char ch, Node *node)
//     {
//         // Set the link corresponding to
//         // the character to the provided node
//         links[ch - 'a'] = node;
//     }

//     // Function to increment the
//     // count of words that end at this node
//     void increaseEnd()
//     {
//         // Increment the counter
//         cntEndWith++;
//     }

//     // Function to increment the count of
//     // words that have this node as a prefix
//     void increasePrefix()
//     {
//         // Increment the counter
//         cntPrefix++;
//     }

//     // Function to decrement the count
//     // of words that end at this node
//     void deleteEnd()
//     {
//         // Decrement the counter
//         cntEndWith--;
//     }

//     // Function to decrement the count of
//     // words that have this node as a prefix
//     void reducePrefix()
//     {
//         // Decrement the counter
//         cntPrefix--;
//     }
// };

// // Define a class for the
// // trie data structure
// class Trie
// {
// private:
//     // Pointer to the
//     // root node of the trie
//     Node *root;

// public:
//     // Constructor to initialize
//     // the trie with an empty root node
//     Trie()
//     {
//         // Create a new root node
//         root = new Node();
//     }

//     // Function to insert
//     // a word into the trie
//     void insert(string word)
//     {
//         // Start from the root node
//         Node *node = root;
//         // Iterate over each
//         // character in the word
//         for (int i = 0; i < word.size(); i++)
//         {
//             // If the character is
//             // not already in the trie
//             if (!node->containsKey(word[i]))
//             {
//                 // Create a new node
//                 // for the character
//                 node->put(word[i], new Node());
//             }
//             // Move to the child node
//             // corresponding to the character
//             node = node->get(word[i]);
//             // Increment the prefix
//             // count for the node
//             node->increasePrefix();
//         }
//         // Increment the end count
//         // for the last node of the word
//         node->increaseEnd();
//     }

//     // Function to count the number
//     // of words equal to a given word
//     int countWordsEqualTo(string word)
//     {
//         // Start from the root node
//         Node *node = root;
//         // Iterate over each character in the word
//         for (int i = 0; i < word.size(); i++)
//         {
//             // If the character is found in the trie
//             if (node->containsKey(word[i]))
//             {
//                 // Move to the child node
//                 // corresponding to the character
//                 node = node->get(word[i]);
//             }
//             else
//             {
//                 // Return 0 if the
//                 // character is not found
//                 return 0;
//             }
//         }
//         // Return the count of
//         // words ending at the node
//         return node->cntEndWith;
//     }

//     // Function to count the number of
//     // words starting with a given prefix
//     int countWordsStartingWith(string word)
//     {
//         // Start from the root node
//         Node *node = root;
//         // Iterate over each character in the prefix
//         for (int i = 0; i < word.size(); i++)
//         {
//             // If the character is found in the trie
//             if (node->containsKey(word[i]))
//             {
//                 // Move to the child node
//                 // corresponding to the character
//                 node = node->get(word[i]);
//             }
//             else
//             {
//                 // Return 0 if the
//                 // character is not found
//                 return 0;
//             }
//         }
//         // Return the count of
//         // words with the prefix
//         return node->cntPrefix;
//     }

//     // Function to erase a
//     // word from the trie
//     void erase(string word)
//     {
//         // Start from the root node
//         Node *node = root;
//         // Iterate over each
//         // character in the word
//         for (int i = 0; i < word.size(); i++)
//         {
//             // If the character is
//             // found in the trie
//             if (node->containsKey(word[i]))
//             {
//                 // Move to the child node
//                 // corresponding to the character
//                 node = node->get(word[i]);
//                 // Decrement the prefix
//                 // count for the node
//                 node->reducePrefix();
//             }
//             else
//             {
//                 // Return if the
//                 // character is not found
//                 return;
//             }
//         }
//         // Decrement the end count
//         // for the last node of the word
//         node->deleteEnd();
//     }
// };
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
3.  Complete String
ANS : Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".
Note :
String ‘P’ is lexicographically smaller than string ‘Q’, if :
1. There exists some index ‘i’ such that for all ‘j’ < ‘i’ , ‘P[j] = Q[j]’ and ‘P[i] < Q[i]’. E.g. “ninja” < “noder”.
2. If ‘P’ is a prefix of string ‘Q’, e.g. “code” < “coder”.
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :

// class Node
// {
// public:
//     Node *links[26];
//     bool flag = false;

//     bool containsKey(char c) { return links[c - 'a'] != nullptr; }
//     Node *get(char ch) { return links[ch - 'a']; }
//     void put(char ch, Node *node) { links[ch - 'a'] = node; }
//     void setEnd() { flag = true; }
//     bool isEnd() { return flag; }
// };

// class Trie
// {
// private:
//     Node *root;

// public:
//     Trie() { root = new Node(); }

//     void insert(string word)
//     {
//         Node *node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             if (!node->containsKey(word[i]))
//             {
//                 node->put(word[i], new Node());
//             }
//             node = node->get(word[i]);
//         }
//         node->setEnd();
//     }

//     bool checkIfPrefixExists(string word)
//     {
//         Node *node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             if (node->containsKey(word[i]))
//             {
//                 node = node->get(word[i]);
//                 if (!node->isEnd())
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// string completeString(int n, vector<string> &a)
// {
//     Trie trie;
//     for (const string &it : a)
//     {
//         trie.insert(it);
//     }

//     string longest = "";
//     for (const string &it : a)
//     {
//         if (trie.checkIfPrefixExists(it))
//         {
//             if (it.length() > longest.length() ||
//                 (it.length() == longest.length() && it < longest))
//             {
//                 longest = it;
//             }
//         }
//     }

//     if (longest == "")
//     {
//         return "None";
//     }
//     return longest;
// }
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
4. Count Distinct Substrings
ANS : Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’.

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
Input :   || Output :
*/
// Bruteforce ----------->
// Time Complexity: O(N*N) where N is the number of characters in the given word. The implementation has two nested loops:
// The outer loop iterates over each character of the string, leading to O(N) iterations.
// The inner loop iterates over the remaining characters in the string for each character, also leading to O(N) iterations in the worst case.
// Space Complexity : O(N*N)where N is the number of characters in the given word. The size of the set to store distinct substrings can grow up to O(N*N) in the worst case where all substrings are distinct. Each substring stored in the set occupies space proportional to its length, but the total space occupied by all substrings will limit to O(N*N).
int countDistinctSubstringsB(string &s)
{
    int n = LEN(s);
    set<string> st;
    FOR(i, n)
    {
        string str = "";
        FOR_INNER(j, i, n)
        {
            str += s[j];
            st.insert(str);
        }
    }
    return SZ(st) + 1; // This +1 menas we added "" blank string as per question
}
// Better ----------->
// Time Complexity: O(N*N)where N is the length of the input string. This is because for each starting position of the substring, we traverse the entire substring once. However, due to the Trie structure, the actual number of comparisons is reduced as we progress.
// Space Complexity : O(N*N) where N is the length of the input string. In the worst-case scenario, where there are no common prefixes among substrings the number of nodes could be as high as the total number of substrings which is bounded by O(N*N).
int countDistinctSubstringsBetter(string &s)
{
    int n = LEN(s);
    int cnt = 0;
    Node *root = new Node();
    FOR(i, n)
    {
        Node *node = root;
        FOR_INNER(j, i, n)
        {
            if (!node->containsKey(s[j]))
            {
                cnt++;
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
    }
    return cnt + 1; // This +1 menas we added "" blank string as per question
}
// Optimal ---------->
// TC :
// SC :
/*
5. Bit PreRequisites for TRIE Problems
ANS : Geek is learning data structures. He wants to learn the trie data structure, but there are a few bit's prerequisites that he must first understand.

Given three bit manipulations functions: XOR, check and setBit.

In XOR function you are given two integers n and m return the xor of n and m.

In check function you are given two integer a and b return 1 if ath bit (1-indexed) of b is set otherwise return 0.

In setBit function you are given two integer c and d, set the cth bit (0-indexed) of d if not yet set .
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
6. Maximum XOR of Two Numbers in an Array
ANS : Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
Input :   || Output :
*/
/*
Intuition : First insert all arr nums in Tries in bits. After that maximize it usinf if x=8 then x^arr[i]=> that should be maximum. Preserve this maximum value that is arr[i] ^ arr[j] return this maximum value.
As we know bits is bigger if its left values is 1 so we have to make 2 numbers xor who can make any numbers 0->1
*/
// Bruteforce ------FOR 1 ARRAY----->
// Time Complexity: O(32*N + 32*M) where N is the length of the input array.
// Insertion: The time complexity of inserting each number into the Trie is O(32) as each number is composed of 32 bits in the Binary Representation. This operation is performed for each of the N numbers in the first array.
// Finding Maximum XOR Operation: To find the maximum XOR value for each number, we iterate through its 32 bits performing constant-time operations for each bit. This is performed for all M numbers in the second array hence this operation accounts for the second time complexity of O(32*N).
// Space Complexity: O(32N) where N is the length of the input array. This algorithm has a linear space complexity with respect to the size of the input array and each number takes up space proportional to 32 which is the size in Binary Representation.
//  struct Node
// {
//     // Array to store links
//     // to child nodes (0 and 1)
//     Node *links[2];

//     // Method to check if a specific
//     // bit key is present in the child nodes
//     bool containsKey(int bit)
//     {

//         // Returns true if the link at
//         // index 'bit' is not NULL
//         return (links[bit] != NULL);
//     }

//     // Method to get the child node
//     // corresponding to a specific bit
//     Node *get(int bit)
//     {

//         // Returns the child
//         // node at index 'bit'
//         return links[bit];
//     }

//     // Method to set a child node at a
//     // specific index in the links array
//     void put(int bit, Node *node)
//     {

//         // Sets the child node at index
//         // 'bit' to the provided node
//         links[bit] = node;
//     }
// };

// // Trie class
// class Trie
// {
// private:
//     // Root node of the Trie
//     Node *root;

// public:
//     // Constructor to initialize
//     // the Trie with a root node
//     Trie()
//     {
//         // Creates a new root
//         // node for the Trie
//         root = new Node();
//     }

//     // Method to insert a number into the Trie
//     void insert(int num)
//     {
//         // Start from the root node
//         Node *node = root;
//         // Iterate through each bit of the
//         // number (from left to right)
//         for (int i = 31; i >= 0; i--)
//         {
//             // Extract the i-th bit of the number
//             int bit = (num >> i) & 1;

//             // If the current node doesn't have a
//             // child node with the current bit
//             if (!node->containsKey(bit))
//             {

//                 // Create a new child node
//                 // with the current bit
//                 node->put(bit, new Node());
//             }

//             // Move to the child node
//             // corresponding to the current bit
//             node = node->get(bit);
//         }
//     }

//     // Method to find the maximum
//     // XOR value for a given number
//     int getMax(int num)
//     {
//         // Start from the root node
//         Node *node = root;

//         // Initialize the maximum XOR value
//         int maxNum = 0;

//         // Iterate through each bit of
//         // the number (from left to right)
//         for (int i = 31; i >= 0; i--)
//         {

//             // Extract the i-th
//             // bit of the number
//             int bit = (num >> i) & 1;

//             // If the complement of the current
//             // bit exists in the Trie
//             if (node->containsKey(1 - bit))
//             {

//                 // Update the maximum XOR
//                 // value with the current bit
//                 maxNum |= (1 << i);

//                 // Move to the child node corresponding
//                 // to the complement of the current bit
//                 node = node->get(1 - bit);
//             }
//             else
//             {

//                 // Move to the child node
//                 // corresponding to the current bit
//                 node = node->get(bit);
//             }
//         }

//         // Return the maximum XOR value
//         return maxNum;
//     }
// };
// class Solution
// {
// public:
//     int findMaximumXOR(vector<int> &nums)
//     {
//         int maxXOR = 0;
//         Trie trie;
//         trav(it, nums)
//         {
//             trie.insert(it);
//             maxXOR = max(maxXOR, trie.getMax(it));
//         }
//         return maxXOR;
//     }
// };
// Better ----------->
// TC :
// SC :
// int findMaximumXOR2(vector<int> &nums1, VI &nums2)
// {
//     int maxXOR = 0;
//     Trie trie;
//     trav(it, nums1) trie.insert(it);
//     trav(it, nums2) maxXOR = max(maxXOR, trie.get(it));
//     return maxXOR;
// }
// Optimal ---------->
// TC :
// SC :
/*
7. Maximum Xor Queries
ANS : You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.


Input :   || Output :
*/
// Bruteforce ----------->
// TC :O(nxm)
// SC :

vector<int> maximizeXor(vector<int> &arr, vector<vector<int>> &q)
{
    int n = SZ(q);
    int m = SZ(arr);
    VI ans;
    FOR(i, n)
    {
        int xi = q[i][0];
        int mi = q[i][1];
        int maxXor = -1;
        FOR(j, m)
        {
            if (arr[j] <= mi)
            {
                maxXor = max(maxXor, arr[j] ^ xi);
            }
        }
        ans.PB(maxXor);
    }
    return ans;
}
// Better ----------->
// Time Complexity: O(32*N + Q(logQ) + 32*Q) where N is the size of the input array and Q is the number of queries.
// For each number in the input array, we traverse its bits from left to right (total of 32 bits). Since there are ‘N’ numbers in the array, the total time complexity is O(32*N).
// Sorting the offline queries based on their endpoints requires O(Q log(Q) time using the inbuilt library for sorting.
// For each query, we traverse the bits of the numbers in the Trie to find the maximum XOR value. Since each number has 32 bits and there are Q Queries, the total time complexity for processing is O(32*Q).
// Space Complexity: O(32*N + Q) where N is the size of the input array and Q is the number of queries.

// The space complexity of the Trie depends on the number of bits required to represent the numbers in the input array. Each number is represented as a sequence of 32 bits hence the space required by the Trie is O(32*N).
// We store the queries and sort them based on the endpoint of each query. This requires an additional space complexity of O(Q).
struct Node
{
    // Array to store links
    // to child nodes (0 and 1)
    Node *links[2];

    // Method to check if a specific
    // bit key is present in the child nodes
    bool containsKey(int bit)
    {

        // Returns true if the link at
        // index 'bit' is not NULL
        return (links[bit] != NULL);
    }

    // Method to get the child node
    // corresponding to a specific bit
    Node *get(int bit)
    {

        // Returns the child
        // node at index 'bit'
        return links[bit];
    }

    // Method to set a child node at a
    // specific index in the links array
    void put(int bit, Node *node)
    {

        // Sets the child node at index
        // 'bit' to the provided node
        links[bit] = node;
    }
};

// Trie class
class Trie
{
private:
    // Root node of the Trie
    Node *root;

public:
    // Constructor to initialize
    // the Trie with a root node
    Trie()
    {
        // Creates a new root
        // node for the Trie
        root = new Node();
    }

    // Method to insert a number into the Trie
    void insert(int num)
    {
        // Start from the root node
        Node *node = root;
        // Iterate through each bit of the
        // number (from left to right)
        for (int i = 31; i >= 0; i--)
        {
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1;

            // If the current node doesn't have a
            // child node with the current bit
            if (!node->containsKey(bit))
            {

                // Create a new child node
                // with the current bit
                node->put(bit, new Node());
            }

            // Move to the child node
            // corresponding to the current bit
            node = node->get(bit);
        }
    }

    // Method to find the maximum
    // XOR value for a given number
    int getMax(int num)
    {
        // Start from the root node
        Node *node = root;

        // Initialize the maximum XOR value
        int maxNum = 0;

        // Iterate through each bit of
        // the number (from left to right)
        for (int i = 31; i >= 0; i--)
        {

            // Extract the i-th
            // bit of the number
            int bit = (num >> i) & 1;

            // If the complement of the current
            // bit exists in the Trie
            if (node->containsKey(1 - bit))
            {

                // Update the maximum XOR
                // value with the current bit
                maxNum |= (1 << i);

                // Move to the child node corresponding
                // to the complement of the current bit
                node = node->get(1 - bit);
            }
            else
            {

                // Move to the child node
                // corresponding to the current bit
                node = node->get(bit);
            }
        }

        // Return the maximum XOR value
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{

    // Initialize vector to
    // store results of queries
    vector<int> ans(queries.size(), 0);

    // Vector to store offline queries
    vector<pair<int, pair<int, int>>> offlineQueries;
    // Sort the array of numbers
    sort(arr.begin(), arr.end());

    int index = 0;

    // Convert queries to offline
    // queries and store them in a vector
    for (auto &it : queries)
    {
        offlineQueries.push_back({it[1], {it[0], index++}});
    }

    // Sort offline queries
    // based on their end points
    sort(offlineQueries.begin(), offlineQueries.end());

    // Pointer to iterate through
    // the array of numbers
    int i = 0;

    // Number of elements in the array
    int n = arr.size();

    // Create an instance of
    // the Trie data structure
    Trie trie;

    // Process each offline query
    for (auto &it : offlineQueries)
    {
        // Insert numbers into the trie
        // until the current query's end point
        while (i < n && arr[i] <= it.first)
        {
            trie.insert(arr[i]);
            i++;
        }

        // If there are numbers inserted
        // into the trie, find the maximum
        // XOR value for the query range
        if (i != 0)
            ans[it.second.second] = trie.getMax(it.second.first);
        else
            // If no numbers inserted,
            // set result to -1
            ans[it.second.second] = -1;
    }
    // Return the results
    // of all queries
    return ans;
}
// Optimal ---------->
// TC :
// SC :
/*
8.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
9.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
10.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
11.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
12.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
13.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
14.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
15.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
16.
ANS :
Input :   || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// ================================MAIN START=================================>>
int main()
{

    //  Start code here-------->>
    // Trie trie;
    // cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    // trie.insert("striver");
    // trie.insert("striving");
    // trie.insert("string");
    // trie.insert("strike");

    // cout << "Search if Strawberry exists in trie: " << (trie.search("strawberry") ? "True" : "False") << endl;

    // cout << "Search if Strike exists in trie: " << (trie.search("strike") ? "True" : "False") << endl;

    // cout << "If words is Trie start with Stri: " << (trie.startsWith("striv") ? "True" : "False") << endl;

    // Trie trie;
    // trie.insert("apple");
    // trie.insert("app");
    // cout << "Inserting strings 'apple', 'app' into Trie" << endl;
    // cout << "Count Words Equal to 'apple': ";
    // cout << trie.countWordsEqualTo("apple") << endl;
    // cout << "Count Words Starting With 'app': ";
    // cout << trie.countWordsStartingWith("app") << endl;
    // cout << "Erasing word 'app' from trie" << endl;
    // trie.erase("app");
    // cout << "Count Words Equal to 'apple': ";
    // cout << trie.countWordsEqualTo("apple") << endl;
    // cout << "Count Words Starting With 'apple': ";
    // cout << trie.countWordsStartingWith("app") << endl;

    // int n = 4;
    // vector<string> A = {"ab", "abc", "a", "bp"};
    // cout << completeString(n, A) << endl; // Output: "abc"

    // string s = "abc";
    // cout << "No of distince substring is " << countDistinctSubstringsB(s) << endl;
    // cout << "No of distince substring is " << countDistinctSubstringsBetter(s) << endl;
    //  End code here-------->>

    return 0;
}
