//
//  expr_tests.cpp
//  interview
//
//  Created by Iyed Bennour on 19/11/14.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include <iostream>
#include "expr_tests.h"
#include "expr.h"

bool test_expr() {
  
  auto ret = true;
  
  auto expr1 = IExpr::create(1);
  
  assert(expr1 != nullptr);
  auto expr2 = IExpr::create(2);
  auto expr4 = IExpr::create(expr2, expr2, Operation::ADD);//IExpr::create(4);
  
  assert(expr1 != nullptr);
  auto exprAdd = IExpr::create(expr1, expr2, Operation::ADD);
  assert(exprAdd != nullptr);
  assert(exprAdd->eval() == 3);
  auto exprMinus = IExpr::create(expr1, expr2, Operation::MINUS);
  assert(exprMinus == nullptr);
  auto exprMult = IExpr::create(expr1, expr2, Operation::MULT);
  assert(exprMult == nullptr);
  auto exprDiv = IExpr::create(expr4, expr2, Operation::DIV);
  assert(exprDiv != nullptr);
  auto expr5 = IExpr::create(exprDiv, expr1, Operation::ADD);
  std::cout << expr5->toString() << "=" << expr5->eval() <<"\n";
  auto expr9 = IExpr::create(expr5, expr1, Operation::MULT);
  assert(expr9 == nullptr);
  
  return (ret = (expr5->eval() == 3));
}

bool test_find_solution() {
  
  auto sofar = IExpr::create(0);
  std::vector<std::shared_ptr<IExpr>> v;
  v.push_back(IExpr::create(99));
  v.push_back(IExpr::create(2));
  v.push_back(IExpr::create(36));
  v.push_back(IExpr::create(7));
  v.push_back(IExpr::create(1));
  v.push_back(IExpr::create(10));
  
  auto ret = true;
  auto results = find_solution(v, sofar, 773);
  for (auto &e: results) {
    ret = (e->eval() == 546) && ret;
    std::cout << e->toString() << "\n";
  }
  std::cout << results.size() << "\n";
  
  return true;
}
