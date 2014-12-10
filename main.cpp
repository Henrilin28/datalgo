//
//  main.cpp
//  datalgo
//
//  Created by Iyed Bennour on 21/10/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <string>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>

#include "miscellaneous.h"
#include "strings.h"
#include "tree_tests.h"
#include "expr_tests.h"
#include "sort.h"
#include "list.h"
#include "tree.h"
#include "list_tests.h"


#define RUN_TEST(function) do {\
printf("running test: *********** %s ************: ", #function);\
if (function())\
printf("OK\n");\
else \
printf("KO\n");\
}\
while(0);



int main(int argc, const char * argv[]) {
  RUN_TEST(test_delete_list)
  RUN_TEST(test_add_node)
  RUN_TEST(test_remove_dups2)
  
  RUN_TEST(test_reverser_list)
  RUN_TEST(test_remove_node)
  RUN_TEST(test_find_node)
  RUN_TEST(test_tree)
  test_sortbin();
  RUN_TEST(test_reverser_list)
  RUN_TEST(test_remove_dups_from_array)
  RUN_TEST(test_string_in_string)
  RUN_TEST(test_reverse_string)
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
  RUN_TEST(test_tree_length)
  RUN_TEST(test_tree_balanced)
  RUN_TEST(test_free_list)

  return 0;
}


