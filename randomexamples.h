//
//  randomexamples.h
//  interview
//
//  Created by Iyed Bennour on 09/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __interview__randomexamples__
#define __interview__randomexamples__

#include <stdio.h>


#include "lists.h"

int remove_dups_from_array(int arr[], unsigned int len);
node_t *add_numbers_as_list(node_t *head1, node_t *head2);
node_t *add_numbers_as_list_rec(node_t *head1, node_t *head2, unsigned int carry);
int from_list_to_number(node_t *head, unsigned int exp);
int from_list_to_number2(node_t *head, unsigned int exp, int sofar);
void sortbin(int arr[], int len);
void test_sortbin();

#endif /* defined(__interview__randomexamples__) */
