//
//	list_tests.c
//  datalgo
//  Created by Iyed Bennour on 09/12/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//
//


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "lists.h"
#include "list_tests.h"

void print_node(node_t *n) {
  printf("%d\n", n->val);
}



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

bool test_find_last_n() {
  node_t *head = NULL;
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 3);
  add_node(&head, 4);
  add_node(&head, 5);
  add_node(&head, 6);
  node_t *n = find_last_n(head, 6);
  return n->val == 1;
  
}

bool test_free_list() {
  node_t *head = NULL;
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 3);
  add_node(&head, 4);
  add_node(&head, 5);
  add_node(&head, 6);
  
  free_list(&head);
  if (head == NULL && list_len(head) == 0)
    return 1;
  else
    return 0;
}


