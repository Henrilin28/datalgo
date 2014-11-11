//
//  strings.cpp
//  interview
//
//  Created by Iyed Bennour on 11/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include "strings.h"
#include <iostream>
#include <unordered_map>
#include <map>

void reverse_string(std::string& s) {
  for (int i = 0; i < s.length() / 2; i++) {
    std::swap(s[i], s[s.length() - 1 - i]);
  }
}

bool test_revers_string() {
  std::string s("bennour");
  reverse_string(s);
  //std::cout << s << "\n";
  return s == std::string("ruonneb");
}


char find_first_non_repeating_char(const std::string& s) {
  
  char c = '\0';
  std::unordered_map<char, size_t> hashmap;
  
  for (auto i: s) {
    
    auto it2 = hashmap.find(i);
    if (it2 != hashmap.end()) {
      hashmap[i] += 1;
    }
    else
      hashmap[i] = 1;
  }
  
  for (auto i:s) {
    if (hashmap[i] == 1) {
      c = i;
      break;
    }
  }
  
  return c;
}

bool test_find_first_non_repeating_char() {
  std::string s("dcbaa");
  char c = find_first_non_repeating_char(s);
  return c == 'd';
  
}

