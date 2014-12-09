//
//  expr.cpp
//  datalgo
//
//  Created by Iyed Bennour on 19/11/14.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//
#include <sstream>
#include <iostream>
#include "expr.h"


std::string opToString(Operation op) {
  switch (op) {
    case Operation::ADD:
      return std::string("+");
      break;
    case Operation::DIV:
      return std::string("/");
      break;
    case Operation::MINUS:
      return std::string("-");
      break;
    case Operation::MULT:
      return std::string("*");
      break;
    default:
      break;
  }
  return std::string("");
}


BinExpr::BinExpr(std::shared_ptr<IExpr>& _exprL, std::shared_ptr<IExpr>& _exprR, Operation _op):  op(_op), exprL(_exprL), exprR(_exprR) {
}

int BinExpr::eval() {
  int res = 0;
  switch (op) {
    case Operation::ADD:
      res = exprL->eval() + exprR->eval();
      break;
    case Operation::MINUS:
      res = exprL->eval() - exprR->eval();
      break;
    case Operation::MULT:
      res = exprL->eval() * exprR->eval();
      break;
    case Operation::DIV:
      res = exprL->eval() / exprR->eval();
      break;
    default:
      break;
  }
  return res;
}

TerminalExpr::TerminalExpr(int val) : value(val) {}
int TerminalExpr::eval() {
  return value;
}
std::string TerminalExpr::toString() {
  std::stringstream ss;
  ss << value;
  return ss.str();
}


std::string BinExpr::toString() {
  std::stringstream ss;
  ss << "(" << exprL->toString() << " " << opToString(op) << " " << exprR->toString() << ")";
  return ss.str();
}

std::shared_ptr<IExpr> IExpr::create(int value) {
  return std::shared_ptr<IExpr>(new TerminalExpr(value));
}

std::shared_ptr<IExpr> IExpr::create(std::shared_ptr<IExpr>& l, std::shared_ptr<IExpr>& r, Operation op){
  if (op == Operation::MINUS) {
    if (l->eval() < r->eval()) {
      return nullptr;
    }
    else if (l->eval() == 0 || r->eval() == 0) {
      return nullptr;
    }
    else
    {
      return std::shared_ptr<IExpr>(new BinExpr(l, r, op));
    }
  }
  else if (op == Operation::DIV){
    if (r->eval() == 0) {
      return nullptr;
    }
    else if (r->eval() == 1) {
      return nullptr;
    }
    else if (l->eval() % r->eval() == 0) {
      return std::shared_ptr<IExpr>(new BinExpr(l, r, op));
    }
    else
    {
      return nullptr;
    }
  }
  else if (op == Operation::ADD) {
    if (l->eval() == 0 || r->eval() == 0)
      return nullptr;
    return std::shared_ptr<IExpr>(new BinExpr(l, r, op));
  }
  else if (op == Operation::MULT) {
    if (l->eval() == 1 || r->eval() == 1)
      return nullptr;
    else
      return std::shared_ptr<IExpr>(new BinExpr(l, r, op));
  }
  else {
    return nullptr;
  }
}

std::vector<std::shared_ptr<IExpr>> find_solution(std::vector<std::shared_ptr<IExpr>> exprs, std::shared_ptr<IExpr> sofar, int target) {
  
  std::vector<std::shared_ptr<IExpr>> solutions;
  if (sofar->eval() == target) {
    solutions.push_back(sofar);
  }
  
  for (int i = 0; i < exprs.size(); i++) {
      
    for (int j = i + 1; j < exprs.size(); j++) {
        
      for (int k = 0; k < 4; k++) {
        
        // combine
        auto new_expr = IExpr::create(exprs[i], exprs[j], ops[k]);
        if (!new_expr)
          new_expr = IExpr::create(exprs[j], exprs[i], ops[k]);
        
        //prepare the input for the next recursive call
        if (new_expr) {
          decltype(exprs) new_exprs;
          new_exprs.push_back(new_expr);
          for (int p = 0; p < exprs.size(); p++) {
            if (p != i && p != j)
              new_exprs.push_back(exprs[p]);
          }
          //recursive call
          auto res = find_solution(new_exprs, new_expr, target);
          for (auto e: res) {
            solutions.push_back(e);
          }
        }
      }
    }
  }
  return solutions;
}

