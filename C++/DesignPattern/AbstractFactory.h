#include <iostream>

// 抽象工厂是对一个类不同纬度(属性)的抽象
// abstract
class Human {
public:
  virtual void color() = 0;
  virtual void sex() = 0;
  virtual void language() = 0;
};

// abstract
class WhiteHuman : Human {
public:
  void color() {
    std::cout << "white human\n";
  }

  void language() {
    std::cout << "say one word\n";
  }
};

class BlackHuman: Human {
public:
  void color() {
    std::cout << "black human\n";
  }

  void language() {
    std::cout << "unknown word\n";
  }
};

class YellowHuman: Human {
public:
  void color() {
    std::cout << "yellow human\n";
  }

  void language() {
    std::cout << "say two word\n";
  }
};

// concrete human
class MaleWhiteHuman : WhiteHuman {
public:
  void sex() {
    std::cout << "male\n";
  }
};

class FemaleWhiteHuman : WhiteHuman {
public:
  void sex() {
    std::cout << "female\n";
  }
};

// abstract
class HumanFactory {
public:
  virtual Human* createWhiteHuman() = 0;
  virtual Human* createBlackHuman() = 0;
  virtual Human* createYellowHuman() = 0;
};

// concrete
class MaleFactory : HumanFactory {
public:
  Human* createWhiteHuman() {
    return new MaleWhiteHuman(); 
  }

  Human* createBlackHuman() {
    //return new MaleBlackHuman();
  }

  Human* createYellowHuman() {
    //return new MaleYellowHuman();
  }
};

class FemaleFactory : HumanFactory {
public:
  Human* createWhiteHuman() {
    
  }

  Human* createBlackHuman() {

  }

  Human* createYellowHuman() {

  }
};

int main() {
  MaleFactory* male = new MaleFactory();
  Human* whiteMale = male->createWhiteHuman();
  Human* blackMale = male->createBlackHuman();
  Human* yellowMale = male->createYellowHuman();

  FemaleFactory* female = new FemaleFactory();
  Human* whiteFemale = female->createWhiteHuman();
  Human* blackFemale = female->createBlackHuman();
  Human* yellowFemale = female->createYellowHuman();
}