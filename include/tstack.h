// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  T arr[100];
  int top;

public:
  TStack():top(-1) {}
  T get()const {//взять
    return arr[top];
  }
  bool isEmpty() const {
    return top == -1;//пустота
  }
  bool isFull() const {
    return top == size-1;//полнота
  }
  void pop() {
  if (!isEmpty())
    top--;
  }
  T get() {
    if (isEmpty())
      throw "empty!";
    else
      return arr[top];
  }
  void push() {
  if (isFull())
    throw "full";
  else
    arr[++top] = value;
  }
};
#endif  // INCLUDE_TSTACK_H_
