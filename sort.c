//
//  sort.c
//  interview
//
//  Created by Iyed Bennour on 22/10/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>


#include "sort.h"



int partition_func(int arr[], int low, int high)
{
  
  int low_boudary = low;
  int pivot = high;
  
  for (int i = low; i < high; i++) {
    if (arr[i] < arr[pivot]) {
      int temp = arr[i];
      arr[i] = arr[low_boudary];
      arr[low_boudary] = temp;
      low_boudary++;
    }
  }
  
  int temp = arr[pivot];
  arr[pivot] = arr[low_boudary];
  arr[low_boudary] = temp;
  return low_boudary;
}


int partitioner(int arr[], int low, int high) {
  int pivot = high;
  int low_boudary = low;
  
  for (int i = low; i < high; ++i) {
    if (arr[i] < arr[pivot]) {
      int temp = arr[i];
      arr[i] = arr[low_boudary];
      arr[low_boudary] = temp;
      low_boudary++;
    }
  }
  
  int temp = arr[pivot];
  arr[pivot] = arr[low_boudary];
  arr[low_boudary] = temp;
  
  return low_boudary;
}


void quick_sort(int arr[], int begin, int end)
{
  
  int pivot;
  if (end > begin) {
    pivot = partitioner(arr, begin, end);
    //This test is needed for when the pivot
    //is at index 0 of the array. Note that this
    //is the worst case.
    if (pivot == 0) {
      quick_sort(arr, pivot + 1, end);
    }
    else {
      quick_sort(arr, begin, pivot - 1);
      quick_sort(arr, pivot + 1, end);
    }
  }
}

int* merge(int arr1[], unsigned int size1, int arr2[], unsigned int size2) {
  
  int *merged = (int *) malloc((size1 + size2) * sizeof(int));
  int i = 0, k = 0, j = 0;
  int min_diff = INT_MAX;
  unsigned int x, y;
  
  while ( i < size1 && k < size2 ) {
    
    int diff = abs(arr1[i] - arr2[k]);
    
    if (diff < min_diff){
      min_diff = diff;
      x = i; y = k;
    }
    
    if (arr1[i] <= arr2[k]) {
      merged[j] = arr1[i];
      i++;
    }
    else {
      merged[j] = arr2[k];
      k++;
    }
    
    j++;
    
  }
  
  while (i < size1) {
    merged[j] = arr1[i];
    i++;
    j++;
  }
  
  while (k < size2) {
    merged[j] = arr2[k];
    j++;
    k++;
  }
  
  printf("x = %d, y = %d, min diff = %d\n", x, y, min_diff);
  return merged;
}


int part(int arr[], int start, int end) {
  int low_bounary = start;
  int pivot = end;
  
  
  for (int i = start; i < end; i++) {
    if (arr[i] <= arr[pivot]) {
      int temp = arr[i];
      arr[i] = arr[low_bounary];
      arr[low_bounary] = temp;
      low_bounary++;
    }
  }
    
  int temp = arr[pivot];
  arr[pivot] = arr[low_bounary];
  arr[low_bounary] = temp;
  return low_bounary;
}



