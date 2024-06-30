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
struct Node
{
    // Array to store
    // links to child nodes
    Node *links[26];
    // Counter for number of
    // words that end at this node
    int cntEndWith = 0;
    // Counter for number of words
    // that have this node as a prefix
    int cntPrefix = 0;

    // Function to check if the
    // node contains a specific key
    bool containsKey(char ch)
    {
        // Check if the link corresponding
        // to the character exists
        return (links[ch - 'a'] != NULL);
    }

    // Function to get the child
    // node corresponding to a key
    Node *get(char ch)
    {
        // Return the link
        // corresponding to the character
        return links[ch - 'a'];
    }

    // Function to insert a child
    // node with a specific key
    void put(char ch, Node *node)
    {
        // Set the link corresponding to
        // the character to the provided node
        links[ch - 'a'] = node;
    }

    // Function to increment the
    // count of words that end at this node
    void increaseEnd()
    {
        // Increment the counter
        cntEndWith++;
    }

    // Function to increment the count of
    // words that have this node as a prefix
    void increasePrefix()
    {
        // Increment the counter
        cntPrefix++;
    }

    // Function to decrement the count
    // of words that end at this node
    void deleteEnd()
    {
        // Decrement the counter
        cntEndWith--;
    }

    // Function to decrement the count of
    // words that have this node as a prefix
    void reducePrefix()
    {
        // Decrement the counter
        cntPrefix--;
    }
};

// Define a class for the
// trie data structure
class Trie
{
private:
    // Pointer to the
    // root node of the trie
    Node *root;

public:
    // Constructor to initialize
    // the trie with an empty root node
    Trie()
    {
        // Create a new root node
        root = new Node();
    }

    // Function to insert
    // a word into the trie
    void insert(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is
            // not already in the trie
            if (!node->containsKey(word[i]))
            {
                // Create a new node
                // for the character
                node->put(word[i], new Node());
            }
            // Move to the child node
            // corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix
            // count for the node
            node->increasePrefix();
        }
        // Increment the end count
        // for the last node of the word
        node->increaseEnd();
    }

    // Function to count the number
    // of words equal to a given word
    int countWordsEqualTo(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is found in the trie
            if (node->containsKey(word[i]))
            {
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]);
            }
            else
            {
                // Return 0 if the
                // character is not found
                return 0;
            }
        }
        // Return the count of
        // words ending at the node
        return node->cntEndWith;
    }

    // Function to count the number of
    // words starting with a given prefix
    int countWordsStartingWith(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is found in the trie
            if (node->containsKey(word[i]))
            {
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]);
            }
            else
            {
                // Return 0 if the
                // character is not found
                return 0;
            }
        }
        // Return the count of
        // words with the prefix
        return node->cntPrefix;
    }

    // Function to erase a
    // word from the trie
    void erase(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each
        // character in the word
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is
            // found in the trie
            if (node->containsKey(word[i]))
            {
                // Move to the child node
                // corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix
                // count for the node
                node->reducePrefix();
            }
            else
            {
                // Return if the
                // character is not found
                return;
            }
        }
        // Decrement the end count
        // for the last node of the word
        node->deleteEnd();
    }
};
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :
/*
3.
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
4.
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
5.
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
6.
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
7.
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

    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    cout << "Inserting strings 'apple', 'app' into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'app' from trie" << endl;
    trie.erase("app");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl;

    //  End code here-------->>

    return 0;
}
