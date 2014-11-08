//
//  sort.h
//  interview
//
//  Created by Iyed Bennour on 21/10/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef interview_sort_h
#define interview_sort_h


#ifdef __cplusplus
extern "C" {
#endif
  
  int part(int arr[], int start, int end);
  void quick_sort(int arr[], int begin, int end);
  int* merge(int arr1[], unsigned int size1, int arr2[], unsigned int size2);
  int uniques(int arr[], int len);
  
#ifdef __cplusplus
}
#endif


#endif
