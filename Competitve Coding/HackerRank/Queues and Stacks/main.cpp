#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
    //Write your code here
    public:
    char* st = new char;
    char* q = new char;

    int front = 0;
    int rear = 0;
    int top = 0;

    void pushCharacter(char a){
        st[top++] = a;
    }
    char popCharacter() {
        return st[--top] ;
    }

    void enqueueCharacter(char a){
        q[rear++] = a;
    }

    char dequeueCharacter() {
        return q[front++];
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);

  	// create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
            char a = obj.popCharacter();
            char b = obj.dequeueCharacter();
        if ( a != b) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
