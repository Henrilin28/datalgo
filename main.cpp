//
//  main.cpp
//  interview
//
//  Created by Iyed Bennour on 21/10/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include <assert.h>
#include "sort.h"
#include "lists.h"
#include <set>
#include <string>
#include <algorithm>
#include <list>
#include <unordered_map>
#include "tree.h"
#include <map>
#include "randomexamples.h"
#include "strings.h"
#include "tree_tests.h"
#include "expr_tests.h"
#include "nqueens.h"

namespace detail {
  template <int N> struct BIT {
    static const unsigned int value = 1 << N;
  };
}


typedef detail::BIT<0> BIT0;
typedef detail::BIT<1> BIT1;
typedef detail::BIT<2> BIT2;
typedef detail::BIT<3> BIT3;
typedef detail::BIT<4> BIT4;
typedef detail::BIT<5> BIT5;
typedef detail::BIT<6> BIT6;
typedef detail::BIT<7> BIT7;
typedef detail::BIT<8> BIT8;
typedef detail::BIT<9> BIT9;
typedef detail::BIT<10> BIT10;
typedef detail::BIT<11> BIT11;
typedef detail::BIT<12> BIT12;
typedef detail::BIT<13> BIT13;
typedef detail::BIT<14> BIT14;
typedef detail::BIT<15> BIT15;
typedef detail::BIT<16> BIT16;
typedef detail::BIT<17> BIT17;
typedef detail::BIT<18> BIT18;
typedef detail::BIT<19> BIT19;
typedef detail::BIT<20> BIT20;
typedef detail::BIT<21> BIT21;
typedef detail::BIT<22> BIT22;
typedef detail::BIT<23> BIT23;
typedef detail::BIT<24> BIT24;
typedef detail::BIT<25> BIT25;
typedef detail::BIT<26> BIT26;
typedef detail::BIT<27> BIT27;
typedef detail::BIT<28> BIT28;
typedef detail::BIT<29> BIT29;
typedef detail::BIT<30> BIT30;
typedef detail::BIT<31> BIT31;


class MyClass {
public:
  MyClass(const MyClass& rhs) {
    //std::cout << "MyClass copy ctor called\n";
  }
  
public:
  
  MyClass() {
    
  }
};

void print_node(node_t *n) {
  printf("%d\n", n->val);
}


#define RUN_TEST(function) do {\
printf("running test: *********** %s ************: ", #function);\
if (function())\
printf("OK\n");\
else \
printf("KO\n");\
}\
while(0);

bool test_add_node() {
  
  bool test_result = true;
  
  node_t *head = NULL;
  add_node(&head, 1);
  assert(head->val == 1);
  assert(list_len(head) == 1);
  add_node(&head, 2);
  assert(list_len(head) == 2);
  
  assert(find_node(head, 1) != NULL);
  assert(find_node(head, 2) != NULL);
  assert(find_node(head, 3) == NULL);
  add_node(&head, 3);
  
  //traverse_node(head, print_node);
  
  assert(find_node(head, 3) != NULL);
  assert(find_node(head, 3)->next->val == 3);
  
  return test_result && find_node(head, 3) != NULL;
}

bool test_find_node() {
  node_t *head = NULL;
  add_node(&head, 2);
  add_node(&head, 1);
  
  return find_node_rec(head, 1) != NULL && find_node_rec(head, 1) != NULL && find_node_rec(head, 3) == NULL;
  
}


void test_remove_dups() {
  
  
  node_t *head = NULL;
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 2);

  
  
  node_t *new_head = remove_list_dups(&head);
  
  assert(list_len(new_head) == 2);
  
  traverse_node(new_head, print_node);
  
}

bool test_delete_list() {
  
  
  node_t *head = NULL;
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 2);
  
  free_list(&head);
  
  assert(list_len(head) == 0);
  return head == NULL;
}

bool test_remove_dups2() {
  
  node_t *head = NULL;
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 2);
  add_node(&head, 1);

  
  
  
  remove_list_dups2(head);
  
  assert(list_len(head) == 2);
  
  //traverse_node(head, print_node);
  
  return list_len(head) == 2;
  
  
}

bool test_reverser_list() {
  
  node_t *head = NULL;
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 3);
  add_node(&head, 4);
  add_node(&head, 5);
  add_node(&head, 6);

  
  reverse_list(&head);
  
  traverse_node(head, print_node);
  
  return list_len_rec(head) == 6 && head->val == 6;
}

bool test_remove_node() {
  
  node_t *head = NULL;
  add_node(&head, 2);
  add_node(&head, 1);
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 4);
  add_node(&head, 1);
  add_node(&head, 1);
  
  remove_node(&head, 1);
  
  //traverse_node(head, print_node);
  
  return list_len(head) == 3 && find_node(head, 1) == NULL;
  
}


bool test_quick_sort() {
  int arr[] = {3, 4, 2, 1, 3};
  quick_sort(arr, 0, 4);
  
  for (auto i: arr) {
    std::cout << i << "\n";
  }
  
  bool flag = true;
  
  for (int i = 0; i < 4; i++) {
    if (arr[i] == arr[i + 1]) {
      flag = false;
      break;
    }
  }
  if (!flag) {
    std::cout << "array contains duplicates\n";
  }
  return true;
}




bool number_is_palindrom(unsigned int x) {
  bool flag = true;

  
  for (int i = 0; i < 16; ++i) {
    unsigned int mask_r = 1 << i;
    unsigned int mask_l = 1 << (31 - i);
    printf("mask_l = %x, mask_r = %x\n", mask_l, mask_r);
    printf("left: 0x%x, right: 0x%x\n", (x & mask_l), (mask_r & x));
    
    flag = ((x & mask_l) && (mask_r & x)) || (!(x & mask_l) && !(mask_r & x));
    if (!flag) break;
    
  }
  
  return flag;
}


unsigned char swap_nibbles(unsigned char b) {
  return b >> 4 | b << 4;
}

unsigned int set_bit(unsigned int x, unsigned int bit) {
  assert(bit < 32);
  return x | (1 << bit);
}

unsigned int set_bits(unsigned x, unsigned bits) {
  return x | bits;
}



void swap (char *x, char *y)
{
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void permute(char *a, int i, int n)
{
  int j;
  if (i == n)
    printf("%s\n", a);
  else
  {
    for (j = i; j <= n; j++)
    {
      swap(a + i, a + j);
      permute(a, i + 1, n);
      swap(a + i, a + j); //backtrack
    }
  }
}

void test_partition() {
  int arr[] = {3, 4, 2, 1, 3};
  int pivot = part(arr, 0, 4);
  for (auto &i: arr) {
    printf("%d\n", i);
  }
  printf("pivot: %d\n", pivot);
  
}

class Polynomial {
public:
  typedef int degree;
  typedef double coefficient;
  
public:
  Polynomial(const std::vector<double>& coefs) {
    for (int i = 0; i < coefs.size(); i++) {
      poly.insert(std::make_pair(i, coefs[i]));
    }
  }
  
  Polynomial(const std::map<degree, coefficient>& m) {
    this->poly = m;
  }
  
  Polynomial& operator = (const Polynomial& rhs) {
    if (this != &rhs) {
      this->poly = rhs.poly;
      
    }
    return *this;
  }
  
  
  void print() {
    for (auto &e: poly) {
      if (e.second > 0 && e.first > 0)
        std::cout << " + ";
      std::cout << e.second << ".X^" << e.first << " ";
    }
    std::cout << "\n";
  }
  
  double eval(double x) {
    double acc = 0;
    for (auto e: poly) {
      acc += e.second * pow(x, e.first);
    }
    return acc;
  }
  friend const Polynomial operator + (const Polynomial& lhs, const Polynomial& rhs);
private:
  std::map<degree, coefficient> poly;
  
};

const Polynomial operator + (const Polynomial& lhs, const Polynomial& rhs) {
  
  std::map<Polynomial::degree, Polynomial::coefficient> m;
  
  for (auto e: lhs.poly) {
    
    auto it = m.find(e.first);
    if (it != m.end()) {
      m[e.first] = e.second + it->second;
    }
    else
      m.insert(std::make_pair(e.first, e.second));
  }
  
  for (auto e: rhs.poly) {
    
    auto it = m.find(e.first);
    if (it != m.end()) {
      m[e.first] = e.second + it->second;
    }
    else
      m.insert(std::make_pair(e.first, e.second));
  }

  
  return Polynomial(m);
}

void test_polynomial() {
  Polynomial p({1, -1, 3});
  p.print();
  std::cout << p.eval(2) << "\n";
  Polynomial p2 = p;
  Polynomial p3({1, 1, 1});
  std::cout << p2.eval(2) << "\n";
  p2 = p3;
  std::cout << p2.eval(2) << "\n";
  Polynomial p5({0, 2, 0, 2});
  Polynomial p4 = p2 + p + p5;
  p4.print();
  std::cout << p4.eval(5) << "\n";

}


template <typename Key, typename Value> class LRUCache {
  typedef std::pair<Key, Value> key_value_pair_t;
  typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;
  
public:
  LRUCache(unsigned int size):_max_size(size) {}
  
  void put(const Key& k, const Value& v) {
    auto it = _cache.find(k);
    if (it != _cache.end()) {
      _list.erase(it->second);
      _cache.erase(it);
    }
    
    _list.push_front(key_value_pair_t(k, v));
    _cache[k] = _list.begin();
    
    if (_cache.size() > _max_size) {
      auto last = _list.end();
      last--;
      _cache.erase(last->first);
      _list.pop_back();
    }
  }
  
  const Value& get(Key k) {
    auto it = _cache.find(k);
    if (it == _cache.end()) {
      throw std::out_of_range("no such key in cache");
    }
    else {
      _list.splice(_list.begin(), _list, it->second);
      return it->second->second;
    }
  }
  
private:
  std::size_t _max_size;
  std::list<key_value_pair_t> _list;
  std::unordered_map<Key, list_iterator_t> _cache;
};

void test_lrucache() {
  LRUCache<std::string, int> lru_cache(2);
  lru_cache.put("iyed", 1);
  lru_cache.put("bennour", 1);
  lru_cache.put("toto", 1);
  
  
  try {
    lru_cache.get("iyed");
  } catch (...) {
    std::cout << "could not get key\n";
  }
  std::cout << lru_cache.get("bennour") << "\n";
}

bool is_palindrome(const char *s, size_t len) {
  
  for (int i = 0; i < len/2; i++) {
    if (s[i] != s[len - 1 - i])
      return false;
  }
  return true;
}


bool test_is_palindrome() {
  
  bool ret = true;
  ret &= is_palindrome("abba", 4);
  ret &= is_palindrome("sexes", 5);
  
  return ret;
}


int fibo(unsigned int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  else
    return fibo(n - 1) + fibo(n - 2);
}

class WebHistory {
public:
  void add_url(std::string url) {
    
    auto it = map.find(url);
    if (it != map.end()) {
      urls.erase(it->second);
      
    }
    auto new_url_it = urls.insert(urls.end(), url);
    map[url] = new_url_it;
  }
  
  void showUrls() {
    for (auto it = urls.rbegin(); it != urls.rend(); ++it) {
      std::cout << *it << "\n";
    }
  }
private:
  std::list<std::string> urls;
  typedef std::list<std::string>::const_iterator list_iter;
  std::map<std::string, list_iter> map;
};


void test_WebHistory() {
  WebHistory wh;
  wh.add_url("google.com");
  wh.add_url("yahoo.com");
  wh.add_url("apple.com");
  wh.add_url("google.com");
  
  wh.showUrls();
}



bool test_add_numbers_as_list() {
  bool ret = true;
  node_t *head1 = NULL;
  add_node(&head1, 3);
  add_node(&head1, 1);
  add_node(&head1, 5);
  node_t *head2 = NULL;
  add_node(&head2, 5);
  add_node(&head2, 9);
  add_node(&head2, 2);
  //add_node(&head2, 1);
  
  node_t *new_head = add_numbers_as_list_rec(head1, head2, 0);
  
  //traverse_node(new_head, print_node);
  
  return (from_list_to_number2(new_head, 0, 0) == 808);
}


struct res {
  int i;
  int j;
  int sum;
};


res max_sum_subarray(int arr[], int len) {
  res r;
  r.i = 0;
  r.j = 0;
  r.sum = std::numeric_limits<int>::min();
  
  res curr_sum {0, 0, r.sum};
  
  for (int k = 0; k < len; k++) {
    
    if (curr_sum.sum <= 0) {
      curr_sum.i = k;
      curr_sum.j = k;
      curr_sum.sum = 0;
    }
    
    curr_sum.sum += arr[k];
    curr_sum.j = k;
    
    if (curr_sum.sum > r.sum) {
      r.sum = curr_sum.sum;
      r.j = curr_sum.j;
      r.i = curr_sum.i;
    }
  }
  return r;
}

bool test_max_sum_subarray() {
  int arr[] = {-1, -3, 4, -1, -2, 1, 5, -3, -4, 1};
  res r = max_sum_subarray(arr, 10);
  std::cout << r.sum << ", " << r.i << " " << r.j << "\n";
  return true;//r.sum == 1 && r.i == 9 && r.j == 9;
  
}

int longest_increasing_seq(int arr[], int len) {
  
  int seq_len = 0;
  int k = 0, p = 0;
  
  int curr_seq_len = 0;
  int curr_k = 0, curr_p = 0;
  
  int previous = std::numeric_limits<int>::min();
  
  for (int i = 0; i < len; i++) {
    
    if (curr_seq_len == 0) {
      curr_k = i;
      curr_p = i;
    }
    
    if (arr[i] > previous) {
     
      previous = arr[i];
      curr_seq_len++;
      curr_p = i;
      
      if (curr_seq_len > seq_len) {
        seq_len = curr_seq_len;
        k = curr_k;
        p = curr_p;
      }
    }
    else {
      curr_seq_len = 0;
    }
      
  }
  std::cout << seq_len << ", " << k << " " << p << "\n";
  return seq_len;
}

bool test_longest_inc_seq() {
  int arr[] = {1, 2, 3, 0, -1, 4, 5, 6, 7};
  int len = longest_increasing_seq(arr, 9);
  return len == 4;
}


void array_sub_arrays(std::vector<int> vec) {
  for (int i = 1; i < pow(2, vec.size()); i++) {
    std::vector<int> sub_array;
    for (int j = 0; j <= vec.size(); j++) {
      if (i & (1 << j))
        sub_array.push_back(vec[j]);
        
    }
    for (auto e: sub_array)
      std::cout << e << " ";
    std::cout << "\n";
  }
}


std::list<std::vector<int>> _array_sub_arrays(std::vector<int> vec) {
  
  std::list<std::vector<int>> l;
  
  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j <= vec.size(); j++) {
      std::vector<int> curr(vec.begin() + i, vec.begin() + j);
      l.push_back(curr);
    }
  }
  return l;
}


bool test_sub_arr() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
  auto l = _array_sub_arrays(v);
  std::cout << l.size() << "\n";
  for (auto e: l) {
    for (auto i: e) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
  return true;
}

int main(int argc, const char * argv[]) {
  
  int arr[] = {1, 10, 6, 9};
  int arr2[] = {3, 14};
  std::list<int> l;
  l.push_back(1);
  l.erase(l.begin());
  
  int pivot = 0;
  std::vector<MyClass> v;
  MyClass myclass_arr[2];
  
  v.push_back(MyClass());
  quick_sort(arr, 0, 3);
  
  std::vector<int> vint{1, 2, 3};
  std::swap(vint[0], vint[2]);
  
  for (auto &i: vint ) {
    std::cout << i << std::endl;
  }
  
  //std::cout << "pivot: " << pivot << std::endl;
  
  /*
  for (auto i: arr) {
    std::cout << i << std::endl;
  }
   */
  
  /*
  int *merged = merge(arr, 4, arr2, 2);
  
  for (int i = 0; i < (4 + 2); i++)
    std::cout << merged[i] << "\n";
  */
  
  
  
  boost::asio::io_service io_service;
  io_service.run();
  
  //test_add_node();
  //test_remove_dups();
  //test_find_node();
  //test_delete_list();
  RUN_TEST(test_delete_list)
  RUN_TEST(test_add_node)
  RUN_TEST(test_remove_dups2)
  
  //printf ("%x\n", 0x1 << 8 );
  
  unsigned short x = 0x8181;
  unsigned short y = 0x8100;
  
  bool flag = true;
  
  
  //printf("%d\n", y);
  
  
  /*
  for (int i = 0; i < 8; ++i) {
    unsigned short mask_r = 1 << i;
    unsigned short mask_l = 1 << (15 - i);
    //printf("mask_l = %x, mask_r = %x\n", mask_l, mask_r);
    printf("left: 0x%x, right: 0x%x\n", (x & mask_l), (mask_r & x));
    
    flag = ((x & mask_l) && (mask_r & x)) || (!(x & mask_l) && !(mask_r & x));

  }
  
  printf("flag = %d\n", flag);
  
  unsigned char b = 1;
  */
  /*
  for (int i = 0; i < 8; ++i) {
    printf("b << %d = 0x%x\n", i, b << i);
  }
   */
  
  //unsigned int ux = 0x88099011;
  
  //printf("%d\n", number_is_palindrom(ux));
  //printf("%x\n", swap_nibbles(0x21));
  //assert(set_bit(1, 15) == 0x00008001);
  //assert(set_bits(1, BIT31::value | BIT1::value) == 0x80000003);
  //printf("%x\n", (BIT31::value | BIT1::value) | 1);
  RUN_TEST(test_reverser_list)
  RUN_TEST(test_remove_node)
  //test_partition();
  //for (int j = 0; j <= 3; j++) printf("j, %d\n", j, arr[j]);
  //char s[] = {'a', 'b', 'c', '\0'};
  //permute(s, 0, 2);
  /*
  std::vector<int> v1{1, 2, 3};
  std::vector<int> v2(v1.size());
  std::copy_if(v1.begin(), v1.end(), v2.begin(), [](int i) {
    return i % 2 == 0;
  });
  v2.shrink_to_fit();
  
  for (auto i: v2) {
    std::cout << i << "\n";
  }
   */
  //test_polynomial();
  //test_lrucache();
  //test_quick_sort();
  RUN_TEST(test_is_palindrome)
  RUN_TEST(test_find_node)
  RUN_TEST(test_tree)
  test_WebHistory();
  test_sortbin();
  RUN_TEST(test_reverser_list)
  RUN_TEST(test_remove_dups_from_array)
  RUN_TEST(test_add_numbers_as_list)
  RUN_TEST(test_string_in_string)
  RUN_TEST(test_revers_string)
  RUN_TEST(test_find_first_non_repeating_char)
  RUN_TEST(test_binary_search)
  RUN_TEST(test_permut)
  RUN_TEST(test_find_last_n)
  RUN_TEST(test_french_flag)
  RUN_TEST(test_sortbin2);
  RUN_TEST(test_sortbin3);
  RUN_TEST(test_find_min_plt);
  RUN_TEST(test_check_paren);
  RUN_TEST(test_tree_find_node)
  RUN_TEST(test_tree_route_to_node)
  RUN_TEST(test_expr)
  //RUN_TEST(test_find_solution)
  RUN_TEST(test_node_per_level)
  //RUN_TEST(test_set_combinations)
  RUN_TEST(test_is_bst)
  RUN_TEST(test_is_sorted)
  RUN_TEST(test_tree_length)
  RUN_TEST(test_tree_balanced)
  RUN_TEST(test_free_list)
  RUN_TEST(test_max_sum_subarray)
  RUN_TEST(test_longest_inc_seq)
  RUN_TEST(test_nqueens)

  return 0;
  
}


