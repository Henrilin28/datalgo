//
//  strings.cpp
//  datalgo
//
//  Created by Iyed Bennour on 11/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include "strings.h"
#include <iostream>
#include <unordered_map>
#include <map>


bool str_in_str(const char *str1, const char *str2) {
  
  const char *p1 = str1;
  const char *p2 = str2;
  
  while (*p2 != '\0') {
    if (*p2 == *p1) {
      p2++;
      p1++;
      while (*p1 == *p2 && *p2 != '\0' && *p1 != '\0') {
        p1++;
        p2++;
      }
      if (*p1 == '\0') return true;
    }
    else {
      p2++;
    }
    p1 = str1;
  }
  
  return false;
  
}

void reverse_string(std::string& s) {
  for (int i = 0; i < s.length() / 2; i++) {
    std::swap(s[i], s[s.length() - 1 - i]);
  }
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

bool test_string_in_string() {
  const char *s1 = "iyed";
  const char *s2 = "bennour iyed";
  
  return str_in_str(s1, s2);
}

bool test_revers_string() {
  std::string s("bennour");
  reverse_string(s);
  return s == std::string("ruonneb");
}


bool test_find_first_non_repeating_char() {
  std::string s("dcbaa");
  char c = find_first_non_repeating_char(s);
  return c == 'd';
  
}

