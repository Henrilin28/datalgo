//
//  tree.h
//  interview
//
//  Created by Iyed Bennour on 06/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __interview__tree__
#define __interview__tree__

#include <iostream>


template <typename value_type> class Tree {

private:
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
    //~node_t() { std::cout << "node " << val << " deleted\n";}
  };
  
  node_t *_root;
  
  
public:
  Tree():_root(nullptr) {}
  
  void delete_nodes() {
    _delete_tree(_root);
    _root = nullptr;
  }
  
  size_t size() {
    return _size(_root);
  }
  
  void add(const value_type& value) {
    _addNode(value, &_root, nullptr);
  }
  void in_order() {
    _in_order(_root);
  }
  ~Tree() {
      delete_nodes();
  }

private:
  void _in_order(node_t *r) {
    if (r) {
      _in_order(r->left);
      std::cout << r->val << "\n";
      _in_order(r->right);
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

  
};


#endif /* defined(__interview__tree__) */
