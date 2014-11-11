//
//  randomexamples.cpp
//  interview
//
//  Created by Iyed Bennour on 09/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include "randomexamples.h"
#include <math.h>
#include <unordered_map>
#include <iostream>


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
  
  for (int i = 0; i < len; i++) {
    if (arr[i] == 1) arr[i] = 2;
  }
  
  int last_zero = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] < 1) {
      std::swap(arr[i], arr[last_zero++]);
    }
    else arr[i] = 1;
  }
}

int* createOneZeroArray(int len)
{
  int* arr = new int[len];
  
  for(int i = 0; i < len; ++i){
    arr[i] = rand() % 2;
  }
  
  return arr;
}

void test_sortbin() {
  
  for (int j = 0; j < 5; j++) {
    int *parr = createOneZeroArray(10);
    
    for (int i = 0; i < 10; i++) {
      std::cout << parr[i] << " ";
    }
    std::cout << "\n";
    
    sortbin(parr, 10);
    
    for (int i = 0; i < 10; i++) {
      std::cout << parr[i] << " ";
    }
    
    std::cout << "\n";
    
    delete [] parr;
  }
  
}



