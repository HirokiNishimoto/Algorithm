#include <iostream>
using namespace std;
#define ARRAY_SIZE 100000

void mergesort(int arr[], int i, int j)
{
  int temp[ARRAY_SIZE], left[ARRAY_SIZE], right[ARRAY_SIZE];
  int index=0,right_index=0, left_index=0;
  /*配列の分割*/
  double median = (i+j)/2;
  mergesort(arr, i, median);
  mergesort(arr, median+1, j);

  /*A[i]~A[median]とA[median+1]~A[j]をマージ*/
  for (int n=0; n<(median-i+1);n++)
  {
    left[n]=arr[n];
  }
  for (int n=0; n<(j-median);n++)
  {
    right[n]=arr[n];
  }
  while (left_index<median-i+1&&right_index<j-median)
  {
    if (left[left_index]<=right[right_index])
    {
      arr[index]=left[left_index];
      index++;left_index++;
    }
    else
    {
      arr[index]=right[right_index];
      index++;right_index++;
    }
  }
  while (left_index>=median-i+1&&right_index<j-median)
  {
    arr[index]=right[right_index];
    index++;right_index++;
  }
  while (left_index<median-i+1&&right_index>=j-median)
  {
    arr[index]=left[left_index];
    index++;left_index++;
  }
}

int main()
{
  int arr_size, n;
  int arr[ARRAY_SIZE];
  cout << "何個のデータを入力しますか->" ; cin >> arr_size;
  for (int i=0; i<arr_size; i++)
  {
    cout << "データを入力->";cin >> n;
    arr[i] = n;
  }
  mergesort(arr, 0, arr_size-1);
}
