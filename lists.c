//
//  lists.c
//  interview
//
//  Created by Iyed Bennour on 28/10/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//
#include <stdlib.h>
#include <string.h>
#include "lists.h"
#include <stdio.h>

node_t* new_node(int val) {
  node_t *n = (node_t *) malloc(sizeof(node_t));
  n->val = val;
  n->next = NULL;
  return  n;
}


void add_node(node_t **head, int val) {
  if (*head == NULL) {
    *head = new_node(val);
  }
  else {
    node_t *p = *head;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = new_node(val);
  }
}

unsigned int list_len(node_t *head) {
  if (head == NULL)
    return 0;
  else {
    int len = 0;
    while (head != NULL) {
      ++len;
      head = head->next;
    }
    return len;
  }
}


void traverse_node(node_t *head, func_ptr func) {
  while (head != NULL) {
    func(head);
    head = head->next;
  }
}


node_t* find_node(node_t *head, int val) {
  
  if (head == NULL)
    return NULL;
  else if (head->val == val)
    return head;
  else {
    node_t* p = head;
    while (p != NULL) {
      if (p->next != NULL && p->next->val == val) {
        break;
      }
      p = p->next;
    }
    return p;
  }
}

void free_list(node_t **head) {
  
  node_t *p = *head;
  if (p == NULL)
    return;
  
  while (p->next != NULL) {
    node_t *tmp = p->next->next;
    free(p->next);
    p->next = tmp;
  }
  
  while (p != NULL) {
    node_t *tmp = p;
    p = p->next;
    free(tmp);
  }
  
  free(p);
  *head = NULL;
  
}

node_t* remove_list_dups(node_t **head) {
  node_t *p1 = *head;
  node_t *new_head = NULL;
  
  while (p1 != NULL) {
    if (find_node(new_head, p1->val) == NULL)
      add_node(&new_head, p1->val);
    p1 = p1->next;
  }
  free_list(head);
  return new_head;
}

void remove_list_dups2(node_t *head) {
  
  if (head == NULL) {
    return;
  }
  node_t *p1 = head;
  
  while (p1 != NULL && p1->next != NULL) {
    node_t *p2 = p1;
    while (p2->next != NULL) {
      
      if (p2->next->val == p1->val) {
        node_t *dup = p2->next;
        p2->next = p2->next->next;
        free(dup);
      }
      else
        p2 = p2->next;
    }
    p1 = p1->next;
  }
  
}

unsigned int list_len_rec(node_t *head) {
  if (head == NULL) return 0;
  else return 1 + list_len_rec(head->next);
}

void remove_node(node_t **head, int val) {
  node_t *p1 = *head;
  
  while (p1 && p1->val == val) {
    node_t *tmp = p1;
    *head = p1->next;
    p1 = p1->next;
    free(tmp);
  }
  
  while (p1 != NULL && p1->next != NULL) {
    if (p1->next->val == val) {
      node_t *tmp = p1->next;
      p1->next = p1->next->next;
      free(tmp);
    }
    else
      p1 = p1->next;
  }
  
  
}

/*
 * reverse a linked list: the tail becomes the head ...
 *
 */
void reverse_list(node_t **phead) {
  
  node_t *head = *phead;
  
  /* if the list is empty or the list is 1 length return */
  if (head == NULL || head->next == NULL) {
    return;
  }
  
  /* look for the tail */
  node_t *tail = head;
  
  while (tail->next != NULL) {
    tail = tail->next;
  }
  
  
  node_t *p1 = tail;
  
  while (head->next != p1) {
    node_t *p2 = head;
    while (p2->next != p1) {
      p2 = p2->next;
    }
    
    p1->next = p2;
    p2->next = NULL;
    p1 = p2;
    
  }
  
  p1->next = head;
  head->next = NULL;

  /* update the head */
  *phead = tail;
}

node_t* find_node_rec(node_t *head, int val) {
  if (head == NULL) return NULL;
  if (head->val == val) {
    return head;
  }
  else
    return find_node_rec(head->next, val);
}


/*
 *
 * returns a pointer to the first of the last n elements of
 * a list or NULL if n > length of the list
 */

node_t* find_last_n(node_t *head, size_t n) {
  node_t *p1 = head;
  while (--n && p1 ) {
    
    p1 = p1->next;
  }
  if (!p1) return NULL;

  node_t *p2 = head;
  while (p1->next) {
    p2 = p2->next;
    p1 = p1->next;
  }
  
  return p2;
}

#ifdef TEST
int test_find_last_n() {
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
#endif