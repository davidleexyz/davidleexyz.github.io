#include <vector>
#include <iostream>

// 关键点: 由visitor来统一访问的方式，object将自身实列传到visitor中

class Part1;
class Part2;
class Total;

class Visitor {
public:
  virtual void visit(Part1* part1) = 0;
  virtual void visit(Part2* part2) = 0;
  virtual void visit(Total* total) = 0;
};

class Object {
public:
  virtual void accept(Visitor* visitor) = 0;
};

class Part1 : public Object {
public:
  Part1() = default;
  void accept(Visitor* visitor) {
    visitor->visit(this);
  }
private:
  int attr{1};
};

class Part2 : public Object {
public:
  Part2() = default;
  void accept(Visitor* visitor) {
    visitor->visit(this);
  }
private:
  int attr{2};
};

class Total : public Object {
public:
  Total() {
    part1 = new Part1();
    part2 = new Part2();
  }

  void accept(Visitor* visitor) {
    part1->accept(visitor);
    part2->accept(visitor);

    visitor->visit(this);
  }
private:
  Part1* part1;
  Part2* part2;
};

class ObjectVisitor : public Visitor {
public:
  void visit(Part1 *part1) {
    std::cout << "visit part1\n";
  }

  void visit(Part2 *part2) {
    std::cout << "visit part2\n";
  }

  void visit(Total* total) {
    std::cout << "visit total\n";
  }
};

int main() {
  ObjectVisitor* visitor = new ObjectVisitor();
  Total* total = new Total();
  total->accept(visitor);

  return 0;
}