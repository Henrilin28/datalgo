//
//  lists.h
//  interview
//
//  Created by Iyed Bennour on 28/10/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __interview__lists__
#define __interview__lists__


#ifdef __cplusplus
extern "C" {
#endif
  
  typedef struct _node {
    int val;
    struct _node *next;
  } node_t;
  
  typedef struct {
    node_t *head;
    node_t *tail;
  } list_t;

  typedef void(*func_ptr)(node_t *node);

  node_t* new_node(int val);
  void add_node(node_t **head, int val);
  void remove_node(node_t **head, int val);
  node_t* find_node(node_t *head, int val);
  node_t* find_node_rec(node_t *head, int val);
  node_t* remove_list_dups(node_t **head);
  void remove_list_dups2(node_t *head);
  unsigned int list_len(node_t *head);
  void traverse_node(node_t *head, func_ptr func);
  void free_list(node_t **head);
  void reverse_list(node_t **phead);
  void longest_substr(char *str1, char *str2);

  
#ifdef __cplusplus
}
#endif


#endif /* defined(__interview__lists__) */
