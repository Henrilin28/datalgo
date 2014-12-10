//
//  randomexamples.cpp
//  datalgo
//
//  Created by Iyed Bennour on 09/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include <unordered_map>
#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <algorithm>
#include <math.h>

#include "miscellaneous.h"



/*
 * Removes dups from an array in linear time using a hashmap
 * Returns the index in the array before which there is all
 * the elements of the array without dups.
 */
int remove_dups_from_array(int arr[], unsigned int len) {
  std::unordered_map<int, int> hashmap;
  int next_slot = 0;
  
  for (int i = 0; i < len; i++) {
    if (hashmap.find(arr[i]) == hashmap.end()) {
      arr[next_slot++] = arr[i];
      hashmap.insert({arr[i], arr[i]});
    }
  }
  return next_slot;
}

node_t *add_numbers_as_list(node_t *head1, node_t *head2) {
  node_t *new_head = NULL;
  unsigned int reste = 0;
  
  while (head1 && head2) {
    unsigned int a = (head1->val + head2->val + reste) / 10; //pour la retenue
    unsigned int b = (head1->val + head2->val + reste) % 10; //pour le reste
    
    add_node(&new_head, b);
    reste = a;
    
    head1 = head1->next;
    head2 = head2->next;
  }
  
  if (!head1 && !head2 && reste)
    add_node(&new_head, reste);
  else {
    while (head1) {
      add_node(&new_head, head1->val + reste);
      head1 = head1->next;
      reste = 0;
    }
    while (head2) {
      add_node(&new_head, head2->val + reste);
      head2 = head2->next;
      reste = 0;
    }
  }
  
  return new_head;
}

node_t *add_numbers_as_list_rec(node_t *head1, node_t *head2, unsigned int carry) {
  node_t *head = NULL;
  
  if (!head1 && !head2) {
    return head;
  }
  else {
    unsigned int current = 0;
    if (head1) {
      current += head1->val;
    }
    if (head2) {
      current += head2->val;
    }
    current += carry;
    add_node(&head, current % 10);
    node_t *p = add_numbers_as_list_rec(head1? head1->next: NULL,
                                        head2? head2->next: NULL,
                                        current / 10);
    head->next = p;
  }
  
  return head;
}

int from_list_to_number(node_t *head, unsigned int exp) {
  if (!head) {
    return 0;
  }
  else {
    return (head->val * pow(10, exp) + from_list_to_number(head->next, exp + 1));
  }
}

int from_list_to_number2(node_t *head, unsigned int exp, int sofar) {
  if (!head) {
    return sofar;
  }
  else {
    return from_list_to_number2(head->next, exp + 1, sofar + (head->val * pow(10, exp)));
  }
}

/*
 sort an array of 0s and 1s in linear time
 */
void sortbin(int arr[], int len) {
  int last_zero = 0;
  
  while (arr[last_zero] == 0) {
    last_zero++;
  }
  
  for (int i = last_zero; i < len - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      std::swap(arr[i + 1], arr[last_zero++]);
    }
  }
}

/*
 sort an array of 0s and 1s in linear time
 another way
 */
void sortbin2(int arr[], int len) {

  int i = 0;
  int j = len - 1;
  
  while (arr[i] == 0) {
    i++;
  }
  while (arr[j] == 1) {
    j--;
  }
  
  while (i < j) {
    if (arr[i] > arr[j]) {
      std::swap(arr[i], arr[j]);
    }
    j--;
    i++;
  }
}

void sortbin3(int arr[], int len) {
  int last_zero = 0;
  int i = 0;
  while (i < len) {
    if (arr[i] == 0) {
      std::swap(arr[i++], arr[last_zero++]);
    }
    else
      i++;
  }
}


bool binary_search(int sorted[], size_t first, size_t last, int elem, size_t& index) {
  if (last < first)
    return false;
  else {
    size_t half = (first + last) / 2;
    
    if (elem < sorted[half])
      return binary_search(sorted, first, half - 1, elem, index);
    else if (elem > sorted[half])
      return binary_search(sorted, half + 1, last, elem, index);
    else {
      index = half;
      return true;
    }
  }
}

bool check_paren(const std::string expr) {
  bool res = true;
  std::stack<char> stack;
  stack.push(expr[0]);
  for (int i = 1; i < expr.size(); i++) {
    if (!stack.empty() && stack.top() == '(' && expr[i] == ')') {
      stack.pop();
    }
    else if (expr[i] == '(' || expr[i] == ')') {
      stack.push(expr[i]);
    }
  }
  res = stack.size() == 0;
  return res;
}


int find_min_plt(int arr[], int len, int dep[], int len2) {
  int A = 1;
  int D = 0;
  int P = std::numeric_limits<int>::min();
  
  for (int i = 1; i < len; i++) {
    if (arr[i] > dep[i - 1]) {
      D++;
    }
    int tmp = A - D;
    if (tmp > P) P = tmp;
    A++;
  }
  return P;
}

int find_min_plt2(int arr[], int dep[], int len) {
  int max_plt = 0;
  std::stack<int> stack;
  int current = 1;
  int i = 1;
  int j = 0;
  
  stack.push(arr[0]);
  
  while (i < len && j < len) {
    if (dep[j] < arr[i]) {
      stack.pop();
      current--;
      j++;
    }
    else {
      stack.push(arr[i]);
      current++;
      i++;
      if (stack.size() > max_plt)
        max_plt = stack.size();
    }
    
  }
  return max_plt;
}


/*
 * example input: 1, 1, 2, 1, 2, 3, 3, 1
 * output: 1, 1, 1, 2, 2, 3, 3
 * without using sort i.e. in linear time.
 */
void french_flag(int arr[], int len, int low, int high) {
  
  int first = 0;
  int last = len - 1;
  int i = 0;
  while (i < last) {
    
    if (arr[i] == low) {
      std::swap(arr[i], arr[first++]);
      i++;
    } else if (arr[i] == high) {
      std::swap(arr[i], arr[last--]);
    } else {
      i++;
    }
  }
  
}

int* createOneZeroArray(int len) {
  int* arr = new int[len];
  
  for(int i = 0; i < len; ++i){
    arr[i] = rand() % 2;
  }
  
  return arr;
}

static bool _is_sorted(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

void test_sortbin() {
  
  bool ret = true;

  for (int j = 0; j < 5; j++) {
    int *arr = createOneZeroArray(10);
  
    sortbin(arr, 10);
      
    ret &= _is_sorted(arr, 10);
    delete [] arr;
  }
  
}

bool test_sortbin2() {
  int arr1[] = {1, 1, 0, 0, 0, 1, 1, 1};
  int arr2[] = {0, 0, 0, 0, 1, 0, 0, 1};
  int arr3[] = {0, 1, 0, 1, 0, 1, 0, 1};
  int arr4[] = {0, 0, 0, 0, 1, 1, 0, 1};
  
  sortbin2(arr1, 8);
  if (!_is_sorted(arr1, 8))
    return false;
  
  sortbin2(arr2, 8);
  if (!_is_sorted(arr2, 8))
    return false;
  
  sortbin2(arr3, 8);
  if (!_is_sorted(arr3, 8))
    return false;
  
  sortbin2(arr4, 8);
  if (!_is_sorted(arr4, 8))
    return false;
  
  return true;
}

bool test_sortbin3() {
  int arr1[] = {1, 1, 0, 0, 0, 1, 1, 1};
  int arr2[] = {0, 0, 0, 0, 1, 0, 0, 1};
  int arr3[] = {0, 1, 0, 1, 0, 1, 0, 1};
  int arr4[] = {0, 0, 0, 0, 1, 1, 0, 1};
  
  sortbin3(arr1, 8);
  if (!_is_sorted(arr1, 8))
    return false;
  
  sortbin3(arr2, 8);
  if (!_is_sorted(arr2, 8))
    return false;
  
  sortbin3(arr3, 8);
  if (!_is_sorted(arr3, 8))
    return false;
  
  sortbin3(arr4, 8);
  if (!_is_sorted(arr4, 8))
    return false;
  
  return true;
}

bool test_french_flag() {
  int arr[] = {1, 1, 2, 1, 2, 3, 3, 1};
  // 1, 1, 1, 2, 2, 3, 3
  french_flag(arr, 8, 1, 3);
  if (!_is_sorted(arr, 8))
    return false;
  return true;
}

bool test_binary_search() {
  int arr[] = {1, 3, 5, 5, 11, 20};
  size_t index = -1;
  bool ret = binary_search(arr, 0, 5, 9, index);
  ret = index == -1;
  ret &= binary_search(arr, 0, 5, 20, index);
  ret &= index == 5;
  return ret;
}

bool test_remove_dups_from_array() {
  bool ret = true;
  int arr[] = {1, 0, 0, 2, 2, 2, 4, 3, 3, 5, 6, 6};
  int result[] = {1, 0, 2, 4, 3, 5, 6};
  
  int index = remove_dups_from_array(arr, 12);
  
  
  for (int j = 0; j < index; j++) {
    std::cout << arr[j] << "\n";
  }
  
  
  ret = std::equal(arr, arr + 7, result);
  
  return ret;
}



unsigned int factorial(unsigned int n) {
  if (n == 0) return 1;
  else return n * factorial(n - 1);
}

bool test_permut() {

  std::vector<int> syms{1, 2, 3, 4, 5};
  std::vector<int> sofar;
  
  auto s = permutations(syms, sofar);
  
  return factorial(syms.size()) == s.size();
}



bool test_find_min_plt() {
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  
  int p = find_min_plt(arr, 6, dep, 6);
  
  std::cout << find_min_plt2(arr, dep, 6) << "\n";
  
  return true;
}


bool test_check_paren() {
  return check_paren("(((a + b))(c + d))()");
}

bool test_set_combinations() {
  std::vector<int> set {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24};
  std::vector<std::vector<int>> initial{{}};
  
  auto combinations = set_combinations_iter(set);
  
  return combinations.size() == pow(2, 23);
}



