#include <iostream>

template <typename T>
struct PointerOf {
  using result = T*;
};

#define pointer(...) typename PointerOf<__VA_ARGS__>::result

// 非类型参数, 类型参数, 模板参数, 模板递归
template <int N, typename T, template <typename> class Func>
struct Times {
  using result = typename Func<typename Times<N-1, T, Func>::result>::result;
};

// 类模板的偏特化
template <typename T, template <typename> class Func>
struct Times<1, T, Func> {
  using result = typename Func<T>::result;
};

#define times(...) typename Times<__VA_ARGS__>::result

// currying 柯里化
// 意义: 柯里化可以将多参函数变成单参函数
// 好处: 让函数粒度更小, 方便组合
/*
template <int N>
struct CharPointer {
  using result = times(N, const char, PointerOf);
};
*/

// 元函数转发 (类模板继承)
/*
template <int N>
struct CharPointer : Times<N, const char, PointerOf> {
};
*/
template <int N>
using CharPointer = Times<N, const char, PointerOf>;

template <bool v> struct Bool;

template <>
struct Bool<true> {
  static const bool value = true;
  using result = Bool<true>;
};

template <>
struct Bool<false> {
  static const bool value = false;
  using result = Bool<false>;
};

using trueType = Bool<true>;
using falseType = Bool<false>;

#define boolean(v) typename Bool<v>::result

template <int N>
struct Integer {
  static const int value = N;
  using result = Integer<N>;
};

#define integer(v) typename Integer<v>::result

template <typename T, typename U>
struct IsEqual {
  using result = boolean(false);
};

template <typename T>
struct IsEqual<T, T> {
  using result = boolean(true);
};

#define isEqual(...) typename IsEqual<__VA_ARGS__>::result

template <typename T, typename U> struct Add;

template <int T, int U>
struct Add<Integer<T>, Integer<U>> {
  using result = Integer<T+U>;
};

#define add(...) typename Add<__VA_ARGS__>::result

template <typename T>
struct Value {
  static const int value = T::value;
};

#define eval(t) Value<t>::value

// 变长参数模板 形参...在前  实参...在后
// 参数解包也需要使用递归
// 需要特化参数为空时候的情形
template <typename ...args> struct Sum;

template <typename number, typename ...leftNumbers>
struct Sum<number, leftNumbers...> {
  using result = typename Add<number, typename Sum<leftNumbers...>::result>::result;
};

template <>
struct Sum<> {
  using result = Integer<0>;
};

#define sum(...) Sum<__VA_ARGS__>::result

// 模式匹配 通过特化和偏特化
template <typename expr, typename T, typename U>
struct IfThenElse {
};

template <typename T, typename U>
struct IfThenElse<trueType, T, U> {
  using result = T;
};

template <typename T, typename U>
struct IfThenElse<falseType, T, U> {
  using result = U;
};

#define ifThenElse(...) typename IfThenElse<__VA_ARGS__>::result

// 不可变性 -- 没有中间变量, 没有副作用, 纯函数式

// lazy computation
// 只有对模板内部的成员访问时, 编译器才会对其生成定义
template <typename T>
struct CloneCreator {
  static T* create(T* obj) {
    return obj->clone();
  }
};

template <typename T>
struct UncloneCreator {
  static T* create(T* obj) {
    return new T(*obj);
  }
};

template <typename T, bool clonable>
using Creator = ifThenElse(boolean(clonable), CloneCreator<T>, UncloneCreator<T>);

// duck typing

// visitor 设计模式
// 如果某一个类的继承类种类修改比较少, 但是其接口改变比较频繁就可以使用访问者模式
// Animal 下有 cat, mouse 两种动物类, Animal 接口有 run, jump 等, 当需要添加 eat 方法时, 那么所有的子类都要去实现这个接口
/*
class AnimalVisitor {
  virtual void visit(Cat &cat) = 0;
  virtual void visit(Mouse &mouse) = 0;
};

class RunVisitor : AnimalVisitor {
  virtual void visit(Cat &cat);
  virtual void visit(Mouse &mouse);
};

class JumpVisitor : AnimalVisitor {
  virtual void visit(Cat &cat);
  virtual void visit(Mouse &mouse);
};


class Animal {
  virtual accept(AnimalVisitor &av);
};

class Cat {
  virtual accept(AnimalVisitor &av) {
    av.visit(*this);
  }
};
*/

// 1.6.1
template <typename T>
struct SizeOf {
  constexpr static size_t value = sizeof(T);
};

// 1.6.2
template <typename T, size_t N>
struct IsEqualSize {
  constexpr static bool value = sizeof(T) == N;
};

// 1.6.4
template <typename T>
struct Outer_ {

  template <typename U>
  struct Middle_ {

    template <typename V>
    struct Inner_ {
    };

    using inner_type = Inner_;
  };

  using middle_type = Middle_;
};

// 1.6.6


template <int V>
struct Print {
  operator char() {
    return V + 0xFFFF;
  }
};

int main()
{
  CharPointer<1>::result test = "template meta programming";
  std::cout << test << "\n";

  std::cout << eval(isEqual(integer(3), integer(4))) << "\n";

  std::cout << eval(add(integer(3), integer(4))) << "\n";

  std::cout << eval(ifThenElse(isEqual(integer(3), integer(4)), trueType, falseType)) << "\n";
  std::cout << eval(ifThenElse(isEqual(integer(3), integer(3)), trueType, falseType)) << "\n";

  std::cout << eval(sum(integer(3), integer(4), integer(5))) << "\n";

  //char v = Print<SizeOf<int>::value>();
  //char v = Print<IsEqualSize<int, 8>::value>();
  std::cout << "Int type size: " << SizeOf<int>::value << "\n";
  std::cout << "IsEqualSize: " << IsEqualSize<int, 4>::value << "\n";

  return 0;
}