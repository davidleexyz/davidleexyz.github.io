#include <iostream>

// 把创建工作放在 static 的 factory method 中
// 这样当添加type类型时只需要修改 create 函数
// 不需要修改client代码, 特别时作为library提供给其他人用的时候
enum VehicleType {
  TwoWheelsVehicleType = 0,
  ThreeWheelsVehicleType = 1,
  FourWheelsVehicleType = 2
};

class Vehicle {
public:
  virtual void print() = 0;
  // factory method
  static Vehicle* create(VehicleType type);
};

Vehicle* Vehicle::create(VehicleType type) {
  if (type == TwoWheelsVehicleType) {
    return new TwoWheelsVehicle();
  } else if (type == ThreeWheelsVehicleType) {
    return new ThreeWheelsVehicle();
  } else if (type == FourWheelsVehicleType) {
    return new FourWheelsVehicle();
  } else {
    return nullptr;
  }
}

class TwoWheelsVehicle : Vehicle {
public: 
  void print() {
    std::cout << "two wheels\n";
  }
};

class ThreeWheelsVehicle : Vehicle {
public:
  void print() {
    std::cout << "three wheels\n";
  }
};

class FourWheelsVehicle : Vehicle {
public:
  void print() {
    std::cout << "four wheels\n";
  }
};

// Client
class Client {
public:
  Client() {
    VehicleType type = FourWheelsVehicleType;
    ptr = Vehicle::create(type);
  }

  Vehicle* getVehicle() {
    return ptr;
  }

private:
  Vehicle* ptr;
};

int main() {
  Client* client = new Client();
  auto vehicle = client->getVehicle();
  vehicle->print();

  return 0;
}