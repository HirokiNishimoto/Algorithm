"""
ソートのアルゴリズム : クイックソート
O(nlog(n))
"""

def quick_sort(a, i, j):
  if i!=j:
    index=0
    b = [0 for i in range(len(a))]

    if a[i] > a[i+1]:
      pivot = a[i]
      pivot_index = i
    else:
      pivot = a[i+1]
      pivot_index = i+1
    #print("pivot_index: "+str(pivot_index))
    dele=0
    for n in range(i):
      b[index] = a[n]
      index+=1
      dele+=1
     #print(b)
    for n in range(j-i+1):
      if (pivot >= a[n+i])and(pivot_index!=n+i):
        b[index]=a[n+i]
        index+=1
     #print(b)
    k = index-dele
     #print("dele: "+str(dele)+ " index: " +str(index))
     #print("k:"+str(k))
    b[k+i]=pivot
    index+=1
     #print("index_<i: " +str(index))
    for n in range(j-i+1):
      if (pivot < a[n+i]):
        b[index]=a[n+i]
        index+=1
     #print("b:" +str(b))
    for n in range(len(a)-j-1):
      b[index]=a[n+j+1]
      index+=1
     #print("Index: "+str(index)+" len(a): "+str(len(a)))
    a = b
     #print("1"+str(a))
     #print("i: "+str(i)+" j: "+str(k-1))
    a = quick_sort(a, i,k+i-1)
     #print("2"+str(a))
     #print("i: "+str(k) + " j: "+str(j))
    a = quick_sort(a, k+i, j)
     #print("3"+str(a))
  return a

#a = [3,4,5,61,2,45,67,8,3,214,46,769,324,12,65,5423,345,435234,2346,-3,45,75,242,14,19,19,10,56,43,100, 2,2,2]
#a = [10,10,1]
#a=[2,1,3]
a = []
m = int(input("幾つの要素を入力しますか? "))
for j in range(m):
  x = int(input("要素を入力してください -> "))
  a.append(x)
print("ソート前: " + str(a))
a =quick_sort(a,0,len(a)-1)
print("ソート後: " +str(a))


"""
0<i<j<len(a)-1
quick_sort(a,i,j)で変わるのは[i,j]の部分だけであることに気づいてから自体が進展した
もっと簡潔に書けるはず
numpyを用いた実装もしてみたい
"""
