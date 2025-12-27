#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
  public:
    bool rec(string& s, string& target, int i, int j, int len) {
        // base condition
        if(s.substr(i, len) == target.substr(j,  len)) return true;
        if(len == 1) return false;

        // possible cuts
        for(int k = 1; k < len; k++) {
            // Without Swap
            if(rec(s, target, i, j, k)
            && rec(s, target, i + k, j + k, len - k)) {
                return true;
            }
            // With Swap
            if(rec(s, target, i, j + len - k, k)
            && rec(s, target, i + k, j, len - k)) {
                return true;
            }
        }

        return false;
    }
    bool isScramble(string s, string target) {
        int n = (int) s.length();
        int m = (int) target.length();
        if(n != m) return false;
        return rec(s, target, 0, 0, n);
    }
};
int main() {
    string s = "coder";
    string target = "ocder";
    Solution obj;
    if (obj.isScramble(s, target)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
