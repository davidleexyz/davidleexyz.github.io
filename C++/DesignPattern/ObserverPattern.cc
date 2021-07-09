#include <iostream>
#include <vector>

// 关键点: Subject 用一个list来保存 Observers 
// 当状态改变时, 广播给所有Observers
class Observer {
public:
  virtual void update() = 0;
};

class Subject  {
public:
  Subject() = default;
  ~Subject() = default;

  void setState(int newState) {
    std::cout << "state changed\n";
    state =  newState;
    notifyAll();
  }

  int getState() {
    return state;
  }

  void attach(Observer* ob) {
    obList.push_back(ob);
  }

  void notifyAll() {
    for (auto ob : obList) {
      ob->update();
    }
  }

private:
  int state;
  std::vector<Observer*> obList;
};

class Concreteob1 : public Observer {
public:
  using Observer::Observer;
  Concreteob1(Subject* sub)
   : subject(sub) {
     subject->attach(this);
  }
  ~Concreteob1() {};

  void update() {
    std::cout << "concreteob1 receive update\n";
  }
private:
  Subject* subject;
};

class Concreteob2 : public Observer {
public:
  using Observer::Observer;
  Concreteob2(Subject* sub)
    : subject(sub) {
      subject->attach(this);
  }
  ~Concreteob2() {}

  void update() {
    std::cout << "concreteob2 receive update\n";
  }
private:
  Subject* subject;
};

int main() {
  Subject *sub = new Subject();

  Observer* ob1 = new Concreteob1(sub);
  sub->setState(1);

  Observer* ob2 = new Concreteob2(sub);
  sub->setState(2);

  return 0;
}