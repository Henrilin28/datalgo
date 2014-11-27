//
//  tree_tests.cpp
//  interview
//
//  Created by Iyed Bennour on 17/11/14.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include "tree.h"
#include "tree_tests.h"
#include <stack>

bool test_tree() {
  Tree<int> tree;
  int arr[] = {1, 2, 3, 4, 5};
  //tree.add(1);
  //tree.add(0);
  //tree.add(2);
  //tree.in_order();
  //std::cout << tree.size() << "\n";
  //tree.delete_nodes();
  //std::cout << tree.size() << "\n";
  tree.add_nodes(arr, 0, 4);
  tree.in_order();
  //std::cout << tree.root()->val << "\n";
  tree.delete_nodes();
  return tree.size() == 0;
}

bool test_tree_find_node() {

  bool ret = false;
  Tree<int> tree;
  int arr[] = {1, 2, 3, 4, 5};
  //tree.add(1);
  //tree.add(0);
  //tree.add(2);
  //tree.in_order();
  //std::cout << tree.size() << "\n";
  //tree.delete_nodes();
  //std::cout << tree.size() << "\n";
  tree.add_nodes(arr, 0, 4);
  tree.in_order();
  
  ret = tree.find(4) != nullptr;
  
  tree.delete_nodes();
  return ret;
}

bool test_tree_route_to_node() {

  bool ret = false;
  Tree<int> tree;
  int arr[] = {1, 2, 3, 4, 5};
  tree.add_nodes(arr, 0, 4);
  
  std::stack<Tree<int>::node_t*> path_to_4;
  std::stack<Tree<int>::node_t*> path_to_2;

  path_to_4 = tree.route_to_node(4);
  path_to_2 = tree.route_to_node(2);
  
  /*
  while (!path_to_2.empty()) {
    std::cout << path_to_2.top()->val << "\n";
    path_to_2.pop();
  }
  std::cout << "--\n";
  while (!path_to_4.empty()) {
    std::cout << path_to_4.top()->val << "\n";
    path_to_4.pop();
  }
  */
  
  
  while (!path_to_4.empty() && !path_to_2.empty()) {
    if (path_to_4.top() == path_to_2.top()) {
      break;
    }
    else if (path_to_4.size() > path_to_2.size()) {
      path_to_4.pop();
    }
    else if (path_to_4.size() < path_to_2.size()) {
      path_to_2.pop();
    }
    else {
      path_to_2.pop();
      path_to_4.pop();
    }
    
  }
  
  if (!path_to_2.empty() && !path_to_4.empty()) {
    ret = true;
  }
  std::cout << path_to_4.top()->val << "\n";
  //ret = path_to_4.top() == tree.root();
  tree.delete_nodes();
  return ret;
}

bool test_node_per_level() {
  
  Tree<int> tree;
  int arr[] = {1, 2, 3, 4, 5};
  tree.add_nodes(arr, 0, 4);
  tree.add(6);
  auto levels = tree.get_tree_levels();
  
  
  for (auto& e: levels) {
    for (auto& i: e) {
      std::cout << i->val << " ";
    }
    std::cout << "\n";
  }
  
  return true;
}

bool test_is_bst()
{
  Tree<int> tree;
  int arr[] = {3, 1, 2, 4, 5};
  for(auto& i: arr) {
    tree.add(i);
  }
  
  std::vector<int> v;
  tree.in_order();
  std::cout << "==\n";

  tree.in_order(v);
  for(auto& e: v)
    std::cout << e << "\n";

  return true;
}

bool test_tree_length() {
  Tree<int> tree;
  int arr[] = {3, 1, 2, 10, 5, 6, 7};
  
  for(auto& i: arr) {
    tree.add(i);
  }
  return tree.length() == 5;
}

bool test_tree_balanced() {
  bool ret = false;
  Tree<int> tree;
  tree.add(10);
  tree.add(8);
  tree.add(9);
  tree.add(7);
  tree.add(6);
  tree.add(5);
  tree.add(13);
  tree.add(12);
  tree.add(14);
  tree.add(15);
  tree.add(16);
  
  ret = tree.is_balanced();
  
  auto levels = tree.get_tree_levels();
  
  
  for (auto& e: levels) {
    for (auto& i: e) {
      std::cout << i->val << " ";
    }
    std::cout << "\n";
  }


  return ret;
}


