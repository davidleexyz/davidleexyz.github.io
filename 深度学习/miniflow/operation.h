#ifndef MINIFLOW_OPERATION_H
#define MINIFLOW_OPERATION_H

namespace miniflow {

template <typename ExprT1, typename ExprT2, typename Op>
class BinaryExpr {
public:
  BinaryExpr(ExprT1 e1, ExprT2 e2, Op op)
    : expr1(e1),
      expr2(e2),
      op(op) {}
  
private:
  ExprT1 expr1;
  ExprT2 expr2;
  Op op;
};

}

#endif