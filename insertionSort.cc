#include <iostream>
using namespace std;

void print_list(int* A, int N)
{
  for (int i=0; i < N; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void insertionSort(int* A, int N)
{
  int j, v;
  for (int i=1; i < N; i++)
  {
    v = A[i];
    j = i - 1;
    while (j>=0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    print_list(A, N);
  }
}

int main()
{
  int N;
  cin >> N;

  int* A;
  for (int i=0; i < N; i++)
  {
   cin >> A[i];
  }
  print_list(A, N);
  insertionSort(A, N);

  return 0;
}
