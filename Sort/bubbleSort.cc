#include <stdio.h>
using namespace std;

void print_list(int* A, int N)
{
  for (int i=0; i < N; i++)
  {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void swap(int* A, int N, int i, int j)
{
  int tmp;
  if (0 <= i && i < N && 0<= j && j < N)
  {
    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
  }
}

int bubbleSort(int* A, int N)
{
  bool flag = 1;
  int rep_counter = 0;
  for (int  i = 0; flag; i++)
  {
    flag = 0;
    for (int j = N-1; j > i; j--)
    {
      if (A[j] < A[j-1])
      {
        swap(A, N, j, j-1);
        flag = 1;
        rep_counter += 1;
      }
    }
  }
  return rep_counter;
}

int main()
{
  int* A;
  int N, rep_counter;
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  print_list(A, N);
  rep_counter = bubbleSort(A, N);
  print_list(A, N);
  printf("%d\n", rep_counter);

  return 0;
}
