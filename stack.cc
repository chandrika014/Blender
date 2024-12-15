#include <vector> 

class Stack {
 private:
  std::vector<void *> elements;
  size_t size;                  

 public:

  Stack() : size(0) {}

  ~Stack() {}

  void push(void *element)
  {
    elements.push_back(element);
    size++;
  }

  void *pop()
  {
    if (elements.empty())
      return nullptr;  
    void *top = elements.back();
    elements.pop_back();
    size--;
    return top;
  }

  bool isEmpty() const
  {
    return elements.empty();
  }

  size_t getSize() const
  {
    return size;
  }
};
extern "C" {

Stack *Stack_create()
{
  return new Stack();
}

void Stack_destroy(Stack *stack)
{
  delete stack;
}

void Stack_push(Stack *stack, void *element)
{
  stack->push(element);
}

void *Stack_pop(Stack *stack)
{
  return stack->pop();
}

bool Stack_isEmpty(const Stack *stack)
{
  return stack->isEmpty();
}

size_t Stack_getSize(const Stack *stack)
{
  return stack->getSize();
}
}
