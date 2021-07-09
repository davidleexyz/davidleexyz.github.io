#include <iostream>

template <typename T>
class LinkedList {
  struct ListNode;
public:
  LinkedList() : head(nullptr), size(0) {}
  ~LinkedList();

  class Iterator {
  public:
    Iterator() : mNode(head) {};
    ~Iterator() = default;

    Iterator& operator=(ListNode* node) {
      mNode = node;
      return *this;
    }

    Iterator& operator++() {
      if (mNode) {
        mNode = mNode->next;
      }
      return *this;
    }

    bool operator!=(const Iterator& iter) {
      return mNode != iter.mNode;
    }

    const T operator*() const {
      return mNode->value;
    }

    ListNode* operator->() {
      return mNode;
    }

  private:
    ListNode* mNode;
  };

  Iterator begin() {
    return Iterator(head);
  }

  Iterator end() {
    return Iterator(nullptr);
  }

  void push_back(const T& value) {
    auto iter = begin();
    while (iter->mNode->next != nullptr) {
      ++iter;
    }
    ListNode* tmp = ListNode(value);
    iter.mNode->next = tmp;
    size++;
  }

  void pop_back() {
    auto iter = begin();
    while (iter.mNode->next->next != nullptr) {
      ++iter;
    }
    auto tmp = iter.mNode->next;
    iter.mNode->next = nullptr;
    delete tmp;
    size--;
  }

private:

  struct ListNode {
    T value;
    ListNode* next;
    ListNode(T value) : value(value), next(nullptr) {}
  };

  ListNode* head;
  size_t size;
};

int main() {
  LinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(5);
  list.push_back(8);

  for (auto iter = list.begin(); iter != list.end(); ++iter) {
    std::cout << *iter << ",";
  }
  std::cout << "\n";

  return 0;
}