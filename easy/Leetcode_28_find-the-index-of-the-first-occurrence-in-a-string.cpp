class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size() || needle.empty()) {
      return -1;
    }

    for (int i = 0; i < haystack.size() + 1 - needle.size(); i++) {
      for (int j = 0; j < needle.size(); j++) {
        if (haystack.at(i + j) != needle.at(j)) {
          break;
        }

        if (j == needle.size() - 1) {
          return i;
        }
      }
    }
    return -1;
  }
};

class Solution {
public:
    int strStr(string haystack, string needle) {

        for(int i = 0; i < (int)haystack.length() - (int)needle.length() + 1; i++){
            if(haystack.substr(i, needle.length()) == needle){
                return i;
            } 
        }
        return -1;
    }
};
