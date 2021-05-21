#ifndef MYSTL_TYPE_TRAITS_H
#define MYSTL_TYPE_TRAITS_H

// [Q:]为什么需要type_traits
// [A:]为了效率, 因为对用户传递的类型是未知的, 可以根据类型是否trivial来构造数据或者释放内存
// POD (plain old data) => c++内建类型
// trivial 和 non-trivial 针对(ctor / copy ctor / assign operator / dector)
// (有基类 / 有非POD成员 / 显示定义了上述4类函数) => non-trivial
// 否则就是trivial (stl中会直接使用malloc 和 free)
namespace mystl {

// 模板元编程方式定义先定义 integral_constant
template <typename T, T v>
struct integral_constant {
  constexpr static T value = v;

  // 传入的值的真实类型
  typedef T value_type;
  
  // 类型本身
  typedef integral_constant<T, v> type;

  // 类型转换操作符 类中只有一个成员变量
  constexpr operator value_type() const { return value; }
};

// 类中的静态成员变量必须要在类外初始化
// 因为所有类共享static成员
template <typename T, T v>
constexpr T integral_constant<T, v>::value;

// 然后再定义 true_type 和 false_type
typedef integral_constant<bool, true>::type true_type;
typedef integral_constant<bool, false>::type false_type;

//======================================================================
// 然后可以基于 integral_constant 定义各种元编程的函数
template <bool cond, typename ifTrue, typename ifFalse>
struct conditional {
  using type = ifTrue;
};

template <typename ifTrue, typename ifFalse>
struct conditional<false, ifTrue, ifFalse> {
  using type = ifFalse;
};

template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<false, T> {
  using type = T;
};

};

#endif