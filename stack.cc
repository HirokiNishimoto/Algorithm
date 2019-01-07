/*
スタックの実装
列の最後尾からのみ出し入れ可能なデータ構造
push: 最後尾にデータの挿入する
pop: 最後尾からデータを取り出す
*/

#include <iostream>
using namespace std;

#define STACK_SIZE 32

struct stack
{
  int arr[STACK_SIZE];
  int top;
};

int push(struct stack *stack, int input)
{
  if (stack->top <= STACK_SIZE)
  {
    stack->top++;
    stack->arr[stack->top] = input;
    return 0;
  }
  else
  {
    cout << "Push failed" << endl;
    return 1;
  }
}

int pop(struct stack *stack)
{
  if (stack->top != 0)
  {
    int temp_index = stack->top;
    int temp;
    stack->top--;
    temp = stack->arr[temp_index];
    stack->arr[temp_index] = 0;
    return temp;
  }
  else
  {
    cout << "No data found" << endl;
    return 1;
  }
}

void init_stack(struct stack *stack)
{
  int i;
  for (i = 0; i < STACK_SIZE; i++)
    stack->arr[i] = 0;
  stack->top = 0;
}

void show_stack(struct stack *stack)
{
  int i;
  for (i = 0; i < STACK_SIZE; i++)
    cout << stack->arr[i] << " ";
  cout << endl << "stack_top: " << stack->top << endl << endl;
}

int main(void)
{
  int pop_num;

  struct stack stack;
  init_stack(&stack);
  show_stack(&stack);

  for (int i=1; i<20;i++)
  {
    push(&stack, i*8);
  }
  show_stack(&stack);

  for (int i=0; i<2;i++)
  {
    pop(&stack);
    show_stack(&stack);
  }

  push(&stack, 100);
  show_stack(&stack);
  return 0;
}
