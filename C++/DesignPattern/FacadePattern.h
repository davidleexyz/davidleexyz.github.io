// 一个系统由多个子系统组成, 把子系统封装在一个接口里
// 与外部交互都通过这个接口来进行通信
class SubSystem1 {
public:
  void operation();
};

class SubSystem2 {
public:
  void operation();
};

class Facade {
public:
  void WrapOperation() {
    sub1->operation();
    sub2->operation();
  }

private:
  SubSystem1* sub1;
  SubSystem2* sub2;
};