//
//  BinaryExpr.h
//  interview
//
//  Created by Iyed Bennour on 10/11/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __interview__BinaryExpr__
#define __interview__BinaryExpr__

#include <stdio.h>


template <typename ConcreteOp, typename T>
class BinaryOperator {
  
public:
  const T operator()(const T &a, const T& b) {
    return static_cast<ConcreteOp*>(this)->operator()(a, b);
  }
};

template <typename T> class OpAdd: public BinaryOperator<OpAdd<T>, T> {
public:
  
  T operator()(const T& a, const T& b) {
    return a + b;
  }
  
};





#endif /* defined(__interview__BinaryExpr__) */
