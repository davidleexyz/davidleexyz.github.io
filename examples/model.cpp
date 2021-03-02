#include <iostream>

class A {
public:
  void func() { std::cout << "A::func, m_a: " << m_a << "\n"; }
  virtual void func_v() { std::cout << "A::func_v" << "\n"; }
  int m_a = 1;
protected:
  int m_b = 2;
private:
  int m_c = 3;
};

// A实例化后 对象占用内存 sizeof(a) = 16

class B {
public:
  virtual void func_v() { std::cout << "B::func_v" << "\n"; }
  void func() {}

public:
  int m_a;
};

// B实例化后 对象占用内存 sizeof(b) = 8, 对象的成员函数存放在代码段不占数据段空间

// b.func() 实际调用方式 B::func(&b) 其中 &b 就是this指针
// 每个实例化的对象地址不同

// 单一继承
/*
class C : public A {
public:
  void func() { std::cout << "C::func, m_a: " << m_a << "\n"; }
  int m_a = 4;
};

// 内存图
// A
// | vptr | -> | vtable | -> A::func_v
// | m_a  |
// | m_b  |
// | m_c  |

// C
// | vptr   | -> | vtable | -> A::func_v
// | A::m_a |
// | A::m_b |
// | A::m_c |
// | m_a    |
*/

class C : public A {
public:
  void func() { std::cout << "C::func, A::m_a: " << m_a << "\n"; }
  // override
  virtual void func_v() { std::cout << "C::func_v" << "\n"; }
  virtual void func_v_c() { std::cout << "C::func_v_c" << "\n"; }

  int m_a;
};

// C
// | vptrA  | -> | v_addr0 | -> C::func_v
// | vptrC  | -> | v_addr0 | -> C::func_v
// | A::m_a |    | v_addr1 | -> C::func_v_c
// | A::m_b |
// | A::m_c |
// | C::m_a |

// 总结: 继承内里可以找到直接使用, 否者沿着继承线向上查找

// 多重继承
class D: public A, public B {
public:
  virtual void func_v() { std::cout << "D::func_v" << "\n"; }
  virtual void func_v_d() { std::cout << "D::func_v_d" << "\n"; }
};

// D
// | vptrA  | -> | v_addr0 | -> D::func_v
// | vptrB  | -> | v_addr0 | -> D::func_v
//               | v_addr1 | -> B::func_v_b
// | vptrD  | -> | v_addr0 | -> D::func_v
// | A::m_a |    | v_addr1 | -> D::func_v_d
// | A::m_b |
// | A::m_c |
// | B::m_a |

// 初始化列表的执行顺序是和成员变量的声明顺序来执行的

int main() {
  A a;
  B b;
  std::cout << "A size: " << sizeof(a) << ", B size: " << sizeof(b) << "\n";

  C c;
  std::cout << "C size: " << sizeof(c) << "\n";
  std::cout << "A::m_a: " << c.A::m_a << "\n";
  std::cout << "m_a: " << c.m_a << "\n";

  c.func();
  c.A::func();
  c.func_v();

  A* ac = dynamic_cast<A*>(&c);
  ac->func_v();

  A* a_c = new C();
  a_c->func_v();
  a_c->A::func_v();

  D d;
  std::cout << "D size: " << sizeof(d) << "\n";

  return 0;
}