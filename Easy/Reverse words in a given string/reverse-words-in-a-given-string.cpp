//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string S) {
        stack<string> wordStack;
        string word;
        
        // Traverse through the string and push each word to the stack.
        for (char c : S) {
            if (c == '.') {
                wordStack.push(word);
                wordStack.push(".");
                word.clear();
            } else {
                word += c;
            }
        }
        
        // Don't forget to push the last word to the stack.
        wordStack.push(word);
        
        // Pop the words from the stack to form the reversed string.
        string reversedStr;
        while (!wordStack.empty()) {
            reversedStr += wordStack.top();
            wordStack.pop();
        }
        
        return reversedStr;
    }
};

// Example usage


//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends