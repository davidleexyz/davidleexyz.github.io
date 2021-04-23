## Graph Node (operation)

```
class Operation final
    : public llvm::ilist_node_with_parent<Operation, Block>,
      private llvm::TrailingObjects<Operation, detail::InLineOpResult,
                                    detail::TrailingOpResult, BlockOperand,
                                    Region, detail::OperandStorage>
```

OpResult 和 OpOperand 作为 operation的 input 和 output

OpResult作为Value的子类, 实现getOwner() 指向生成这个result的 Operation
Value还可以通过getUses() 得到所有attach到其本身的OpOperand

```
template <typename DerivedT, typename IRValueTy> class IROperand
```
OpOperand继承IROperand其中Value作为其成员, 可以通过getOwner() 得到定义这个operand的 Operation, 要注意这里与Value getOwner()的区别.
同样可以从当前OpOperand得到其本身Value的 use chain.

所以operand对于Operation是独有的, 但是operand里的value是可以被多个operand共用的.


## Pass

RewritePattern / OpRewritePattern
针对某一个Operation来做一种优化变换

FunctionPass 和 OperationPass 和 Pass
PassManager注册和管理Pass 根据pass的id来执行pass,
在pass中根据pattern来做具体的工作

Attributes.h


