#include <iostream>
using namespace std;
#define ARRAY_SIZE 100000

int main()
{
  bool linear_search(int array[ARRAY_SIZE], int, int);
  int array[ARRAY_SIZE];
  int value, array_size;
  bool result;

  //test用のarrayを生成
  array_size=40;
  for (int n=0; n<array_size; n++)
  {
    array[n]=7*n;
  }

  //生成したarrayの出力
  cout << endl << "array: "<< endl;
  for (int n=0; n<array_size; n++)
  {
    cout << array[n] << " ";
  }
  cout << endl<<endl;

  value = 217;
  cout << "value: " << value << endl << endl;
  //217を探す
  result = linear_search(array, array_size, value);

  //結果報告
  if (result==1)
  {
    cout << "result:" << endl << value << " was found in the array!"<< endl << endl;
  }
  else
  {
    cout << "result:" << value << " was not found in the array." << endl << endl;
  }
}

bool linear_search(int array[ARRAY_SIZE], int array_size, int value)
{
  if (ARRAY_SIZE < array_size)
  {
    cout <<"error: Too long array." << endl;
    return false;
  }
  else
  {
    for (int i=0; i<array_size; i++)
    {
      if (array[i]==value)
      {
        return true;
      }
    }
    return false;
  }
}
