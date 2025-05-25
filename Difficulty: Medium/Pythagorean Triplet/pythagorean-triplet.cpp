class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int present[1000001] = {0};
        for(auto i : arr) {
            present[i*i]++;
        }
        for(int i = 1; i < 1001; i++) {
            for(int j = i; j < 1001; j++) {
                int req = i*i + j*j;
                int f1 = present[i*i];
                int f2 = present[j*j];
                if(i == j && f1 >= 2) {
                    if(present[req]) return true;
                }
                else if(f1 && f2) {
                    if(present[req]) return true;
                }
            }
        }
        return false;
    }
};