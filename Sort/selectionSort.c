#include <stdio.h>

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

void print_list(int* A, int N)
{
  for (int i=0; i < N; i++)
  {
    printf("%d%1s", A[i], " ");
  }
  printf("\n");
}

int selectonSort(int* A, int N)
{
  int minj;
  int rep_times=0;
  for (int i=0; i<N; i++)
  {
    minj = i;
    for (int j=i; j<N; j++)
    {
      if (A[j] < A[minj])
      {
        minj = j;
      }
    }
    swap(A, N, i, minj);
    rep_times += 1;
  }
  return rep_times;
}

int main(void)
{
  int N, rep_times;
  int A[100];

  scanf("%d", &N);
  for (int i=0; i<N; i++)
  {
    scanf("%d", &A[i]);
  }

  rep_times=selectonSort(A, N);
  print_list(A, N);
  printf("%d\n", rep_times);
  return 0;
}
