//Geeks for geeks
//Given a string s and a character c. The task is to remove all the occurrences of the character in the string.

class Solution {
public:
    void remove(string &s, int n, int i, char val) {
        if(i == n) {
            return;
        }

        if(s[i] == val) {
            s.erase(s.begin() + i);
            remove(s, n-1, i, val);
        }
        else {
            remove(s, n, i+1, val);
        }
    }

    void removeCharacter(string &s, char c) {
        int n = s.size();
        remove(s, n, 0, c);
    }
};
