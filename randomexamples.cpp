//
//  randomexamples.cpp
//  interview
//
//  Created by Iyed Bennour on 09/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include "randomexamples.h"
#include <math.h>

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

