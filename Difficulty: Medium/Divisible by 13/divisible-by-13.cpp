class Solution {
  public:
    bool divby13(string &s) {
        int n = (int)s.length(), i = 0;
        string temp = "";
        while(i < n) {
            if(temp.empty() || (!temp.empty() && stoi(temp) < 13)) temp += s[i++];
            if(stoi(temp) >= 13) {
                int remainder = stoi(temp) % 13;
                temp = to_string(remainder);
            }
        }
        return stoi(temp) == 0;
    }
};