//
//  randomexamples.h
//  datalgo
//
//  Created by Iyed Bennour on 09/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __datalgo__randomexamples__
#define __datalgo__randomexamples__

#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>

#include "lists.h"

int remove_dups_from_array(int arr[], unsigned int len);
node_t *add_numbers_as_list(node_t *head1, node_t *head2);
node_t *add_numbers_as_list_rec(node_t *head1, node_t *head2, unsigned int carry);
int from_list_to_number(node_t *head, unsigned int exp);
int from_list_to_number2(node_t *head, unsigned int exp, int sofar);
void sortbin(int arr[], int len);
void sortbin2(int arr[], int len);
void sortbin3(int arr[], int len);
void french_flag(int arr[], int len, int low, int high);
bool binary_search(int sorted[], size_t first, size_t last, int elem, size_t& index);
bool check_paren(const std::string expr);
void french_flag(int arr[], int len, int low, int high);
size_t find_min_plt(size_t arr[], size_t len, size_t dep[], int len2);

template <class T>
std::set<std::vector<T>> permutations(const std::vector<T>& syms, const std::vector<T>& sofar) {
  
  std::set<std::vector<T>> perms;
  
  if (syms.size() == 0) {
    perms.insert(sofar);
  }
  else {
    
    for (int i = 0; i < syms.size(); i++) {
      
      std::vector<T> v;
      
      for(int j = 0; j < syms.size(); j++) {
        if (j != i) {
          v.push_back(syms[j]);
        }
      }
      
      std::vector<T> prefix;
      for (auto x: sofar ) {
        prefix.push_back(x);
      }
      prefix.push_back(syms[i]);
      
      auto sub = permutations(v, prefix);
      
      for (auto e: sub) {
        perms.insert(e);
      }
    }
  }
  return perms;
}


template <typename T> std::vector<std::vector<T>> set_combinations(std::vector<T> set) {
  std::vector<std::vector<T>> ret;
  if (set.size() == 0) {
    ret.push_back({});
  }
  else {
    std::vector<T> sub_set(set.size() - 1);
    std::copy(++set.begin(), set.end(), sub_set.begin());
    
    
    auto sub_ret = combi(sub_set);
    
    for (auto& e: sub_ret)
    {
      ret.push_back(e);
      e.emplace(e.begin(), set[0]);
      ret.push_back(e);
    }
  }
  return ret;
}


template <typename T> void
set_combinations_tail_rec(const std::vector<T>& set,
                    std::vector<std::vector<T>>& combinations) {
  
  if (set.size() == 0) {

    return;
  }
  else {
    std::vector<T> sub_set(set.size() - 1);
    std::copy(++set.begin(), set.end(), sub_set.begin());
    
        std::vector<std::vector<T>> new_combinations(combinations.begin(), combinations.end());
    for (auto& e: combinations)
    {
      std::vector<T> v(e.begin(), e.end());
      v.push_back(set[0]);
      new_combinations.push_back(v);
    }
    std::swap(combinations, new_combinations);
    return set_combinations(sub_set, combinations);
    

  }
}

template <typename T> std::vector<std::vector<T>>
set_combinations_tail_rec2(const std::vector<T>& set,
                          const std::vector<std::vector<T>>& combinations) {
  
  if (set.size() == 0) {
    return combinations;
  }
  else {
    std::vector<T> sub_set(set.size() - 1);
    std::copy(++set.begin(), set.end(), sub_set.begin());
    
    std::vector<std::vector<T>> new_combinations(combinations.begin(), combinations.end());
    for (auto& e: combinations)
    {
      std::vector<T> v(e.begin(), e.end());
      v.push_back(set[0]);
      new_combinations.push_back(v);
    }
    
    return set_combinations_tail_rec2(sub_set, new_combinations);
    
  }
}

template <typename T> std::vector<std::vector<T>>
set_combinations_iter(const std::vector<T>& set) {
  
  std::stack<std::vector<T>> sets;
  std::stack<std::vector<std::vector<T>>> combinations;
  sets.push(set);
  combinations.push({{}});
  
  while (!sets.top().empty()) {
    auto v = sets.top();
    std::vector<T> sub_set(v.size() - 1);
    std::copy(++v.begin(), v.end(), sub_set.begin());
    auto c = combinations.top();
    std::vector<std::vector<T>> nc(c.begin(), c.end());
    for (auto& e: c) {
      std::vector<T> tmp(e.begin(), e.end());
      tmp.push_back(v[0]);
      nc.push_back(tmp);
    }
    sets.push(sub_set);
    combinations.push(nc);
  }
  
  return combinations.top();
}

bool test_set_combinations();
bool test_find_min_plt();
bool test_permut();
bool test_remove_dups_from_array();
bool test_binary_search();
bool test_french_flag();
void test_sortbin();
bool test_sortbin2();
bool test_sortbin3();
bool test_check_paren();
bool test_is_sorted();


#endif /* defined(__datalgo__randomexamples__) */
