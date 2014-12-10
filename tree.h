//
//  tree.h
//  datalgo
//
//  Created by Iyed Bennour on 06/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __datalgo__tree__
#define __datalgo__tree__

#include <iostream>
#include <stack>
#include <queue>


template <typename value_type> class Tree {
  
public:
  struct node_t {
    node_t(value_type _val, node_t *par):val(_val) {
      left = nullptr;
      right = nullptr;
      parent = par;
    }
    value_type val;
    node_t *left;
    node_t *right;
    node_t *parent;
  };

  
private:
  
  node_t *_root;
  
  
public:
  Tree():_root(nullptr) {}
  
  void delete_nodes() {
    _delete_tree(_root);
    _root = nullptr;
  }
  
  const node_t* root() {
    return _root;
  }
  
  size_t size() {
    return _size(_root);
  }
  
  size_t length() {
    return _length(_root);
  }
  
  void add(const value_type& value) {
    _addNode(value, &_root, nullptr);
  }
  
  void add_nodes(value_type arr[], int begin, int end) {
    _add_nodes(arr, begin, end, &_root, nullptr);
  }
  
  void in_order() {
    _in_order(_root);
  }
  
  void in_order(std::vector<value_type>& v) {
    _in_order(_root, v);
  }
  
  const node_t* find(value_type val) {
    return _find(val, _root);
  }
  
  std::stack<node_t*> route_to_node(value_type val) {
    std::stack<node_t*> stack;
    _record_route(val, _root, stack);
    return stack;
  }
  
  std::vector<std::vector<node_t*>> get_tree_levels() {
    return _get_tree_levels(_root);
  }
  
  bool is_balanced() {
    return _is_balanced(_root);
  }
  
  virtual ~Tree() {
      delete_nodes();
  }
  
  
  

private:
  
  void _record_route(value_type val, node_t* n, std::stack<node_t*>& stack) {
    if (n == nullptr) {
      while (!stack.empty()) {
        stack.pop();
      }
     return;
    }
    else {
      
      if (n->val == val) {
        stack.push(n);
        return;
      }
      else if (val > n->val) {
        stack.push(n);
        _record_route(val, n->right, stack);
      }
      else {
        stack.push(n);
        _record_route(val, n->left, stack);
      }
      
    }
  }
  
  const node_t* _find(value_type val, node_t* n) {
    if (n == nullptr) {
      return nullptr;
    }
    else {
      if (n->val == val) return n;
      else if (val > n->val) return _find(val, n->right);
      else return _find(val, n->left);
    }
  }
  
  
  
  
  void _add_nodes(value_type sorted_arr[], int begin, int end, node_t **n, node_t *par) {
    
    if (end < begin) {
      return;
    }
    else {
      int half = (begin + end) / 2;
      *n =  new node_t(sorted_arr[half], par);
      _add_nodes(sorted_arr, begin, half - 1, &((*n)->left), *n);
      _add_nodes(sorted_arr, half + 1, end, &((*n)->right), *n);
    }
  }
  
  
  void _in_order(node_t *r) {
    if (r) {
      _in_order(r->left);
      std::cout << r->val << "\n";
      _in_order(r->right);
    }
  }
  
  void _in_order(node_t *r, std::vector<value_type>& v) {
    if (r) {
      _in_order(r->left, v);
      //std::cout << r->val << "\n";
      v.push_back(r->val);
      _in_order(r->right, v);
    }
  }

  
  size_t _size(node_t *r) {
    if (r == nullptr) return 0;
    else return 1 + _size(r->left) + _size(r->right);
  }
  
  
  void _addNode(const value_type& val, node_t **root, node_t *par) {
    if (*root == nullptr) {
      *root = new node_t(val, par);
    }
    else {
      if (val <= (*root)->val) {
        _addNode(val, &((*root)->left), *root);
      }
      else
        _addNode(val, &((*root)->right), *root);
    }
  }
  
  void _delete_tree(node_t *node) {
    if (node != nullptr) {
      if (node->left == nullptr && node->right == nullptr) {
        if (node->parent && node->parent->left == node) {
          node->parent->left = nullptr;
        }
        else if (node->parent && node->parent->right == node) {
          node->parent->right = nullptr;
        }
        delete node;
      }
      else {
        _delete_tree(node->left);
        _delete_tree(node->right);
        delete node;
      }
    }
  }
  
  std::vector<std::vector<node_t*>> _get_tree_levels(node_t* root) {
    
    std::queue<std::vector<node_t*>> queue;
    std::vector<std::vector<node_t*>> levels;
    
    if (root == nullptr) return levels;
    
    queue.push({root});
    
    levels.push_back({root});
    
    while(!queue.empty()) {
      
      auto l = queue.front();
      std::vector<node_t*> v;
      std::vector<node_t*> q;
      for (auto& e :l) {
        if (e->left != nullptr) {
          v.push_back(e->left);
          q.push_back(e->left);
        }
        if (e->right != nullptr) {
          v.push_back(e->right);
          q.push_back(e->right);
        }
      }
      if (q.size() != 0)
        queue.push(q);
      
      levels.push_back(v);
      
      queue.pop();
    }
    return levels;
  }
  
  size_t _length(node_t* n) {
    if (n == nullptr)
      return 0;
    else {
      return 1 + std::max(_length(n->left), _length(n->right));
    }
  }
  
  bool _is_balanced(node_t* tree) {
    if (tree == nullptr)
      return true;
    else {
      size_t ltl = _length(tree->left);
      size_t rtl = _length(tree->right);
      return abs(ltl - rtl) <= 1 && _is_balanced(tree->left) && _is_balanced(tree->right);
    }
    
  }
  
};




#endif /* defined(__datalgo__tree__) */
