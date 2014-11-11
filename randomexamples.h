//
//  randomexamples.h
//  interview
//
//  Created by Iyed Bennour on 09/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __interview__randomexamples__
#define __interview__randomexamples__

#include <stdio.h>
#include <vector>
#include <set>


#include "lists.h"

int remove_dups_from_array(int arr[], unsigned int len);
bool test_remove_dups_from_array();
node_t *add_numbers_as_list(node_t *head1, node_t *head2);
node_t *add_numbers_as_list_rec(node_t *head1, node_t *head2, unsigned int carry);
int from_list_to_number(node_t *head, unsigned int exp);
int from_list_to_number2(node_t *head, unsigned int exp, int sofar);
void sortbin(int arr[], int len);
void test_sortbin();
void special_sort(int arr[], size_t len);
bool binary_search(int sorted[], size_t first, size_t last, int elem, size_t& index);
bool test_binary_search();

template <class T>
std::set<std::vector<T>> permutations(const std::vector<T>& syms, const std::vector<T>& sofar) {
  
  std::set<std::vector<T>> perms;
  
  if (syms.size() == 0) {
    perms.insert(sofar);
  }
  else {
    
    for (int i = 0; i < syms.size(); i++) {
      
      std::vector<T> v;
      /*
       for (auto x: syms) {
       if (x != syms[i])
       v.push_back(x);
       }
       */
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

bool test_permut();

#endif /* defined(__interview__randomexamples__) */
