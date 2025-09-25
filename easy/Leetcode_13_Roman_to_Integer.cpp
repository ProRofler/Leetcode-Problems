#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // my hash map solution
  int romanToInt(string s) {
    unordered_map<string, int> map;

    map.insert({"I", 1});
    map.insert({"V", 5});
    map.insert({"X", 10});
    map.insert({"L", 50});
    map.insert({"C", 100});
    map.insert({"D", 500});
    map.insert({"M", 1000});

    map.insert({"IV", 4});
    map.insert({"IX", 9});
    map.insert({"XL", 40});
    map.insert({"XC", 90});
    map.insert({"CD", 400});
    map.insert({"CM", 900});
    // map is filled

    char cur = '\0';
    int sum = 0;

    for (const char i : s) {
      auto composite = map.find(string{cur}.append(string{i}));
      if (composite != map.end()) {
        sum += composite->second;
        sum -= map.find(string{cur})->second;
        cur = i;
        continue;
      }

      sum += map.find(string{i})->second;
      cur = i;
    }

    return sum;
  }
  
  // but this shit is constant
  int romanToInt_brute(string s) {
    int result = 0;
    switch (s[0]) {
      case 'I':
        result += 1;
        break;
      case 'V':
        result += 5;
        break;
      case 'X':
        result += 10;
        break;
      case 'L':
        result += 50;
        break;
      case 'C':
        result += 100;
        break;
      case 'D':
        result += 500;
        break;
      case 'M':
        result += 1000;
        break;
    }

    for (size_t i = 1; i < s.length(); ++i) {
      switch (s[i]) {
        case 'I':
          result += 1;
          break;
        case 'V':
          if (s[i - 1] == 'I')
            result += 3;
          else
            result += 5;
          break;
        case 'X':
          if (s[i - 1] == 'I')
            result += 8;
          else
            result += 10;
          break;
        case 'L':
          if (s[i - 1] == 'X')
            result += 30;
          else
            result += 50;
          break;
        case 'C':
          if (s[i - 1] == 'X')
            result += 80;
          else
            result += 100;
          break;
        case 'D':
          if (s[i - 1] == 'C')
            result += 300;
          else
            result += 500;
          break;
        case 'M':
          if (s[i - 1] == 'C')
            result += 800;
          else
            result += 1000;
          break;
      }
    }
    return result;
  }
};
int main() {
  Solution s;

  std::cout << s.romanToInt("MCMXCIV") << std::endl;
}

/*
    Hash table
    contains key as roman numeral and value as integer representation?



*/