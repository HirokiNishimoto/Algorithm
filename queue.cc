/*
待ち行列の実装
列の最後尾からデータを入れ、先頭からデータを取り出す
enquence: 最後尾へデータの挿入する
dequence: 先頭からデータを取り出す
*/

#include <iostream>
using namespace std;

#define QUEUE_SIZE 32

struct queue {
  int arr[QUEUE_SIZE];
  int first, last;
};

int enquence(struct queue *queue, int input) {
  if (queue->last <= QUEUE_SIZE)
{
    queue->arr[queue->last] = input;
    queue->last++;
    return 0;
  }
  else
  {
    cout << "enquence failed" << endl;
    return 1;
  }
}

int denquence(struct queue *queue)
{
  if (queue->first != queue->last)
  {
    int temp_index = queue->first;
    int temp;
    queue->first++;
    temp = queue->arr[temp_index];
    queue->arr[temp_index] = 0;
    return temp;
  }
  else
  {
    cout << "No data found" << endl;
    return 1;
  }
}

void init_queue(struct queue *queue)
{
  int i;
  for (i = 0; i < QUEUE_SIZE; i++)
    queue->arr[i] = 0;
  queue->first = 0;
  queue->last = 0;
}

void show_queue(struct queue *queue)
{
  int i;
  for (i = 0; i < QUEUE_SIZE; i++)
    cout << queue->arr[i] << " ";
  cout << endl << "queue_first: " << queue->first << endl << "queue_last: " << queue->last << endl << endl;
}

int main(void)
{
  int denquence_num;

  struct queue queue;
  init_queue(&queue);
  show_queue(&queue);

  for (int i=1; i<20;i++)
  {
    enquence(&queue, i*8);
  }
  show_queue(&queue);

  for (int i=0; i<2;i++)
  {
    denquence(&queue);
    show_queue(&queue);
  }

  enquence(&queue, 100);
  show_queue(&queue);
  return 0;
}
