"""
クイックソート
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
    dele=0
    for n in range(i):
      b[index] = a[n]
      index+=1
      dele+=1
    for n in range(j-i+1):
      if (pivot >= a[n+i])and(pivot_index!=n+i):
        b[index]=a[n+i]
        index+=1
    k = index-dele
    b[k+i]=pivot
    index+=1
    for n in range(j-i+1):
      if (pivot < a[n+i]):
        b[index]=a[n+i]
        index+=1
    for n in range(len(a)-j-1):
      b[index]=a[n+j+1]
      index+=1
    a = b
    a = quick_sort(a, i,k+i-1)
    a = quick_sort(a, k+i, j)
  return a


a = []
m = int(input("幾つの要素を入力しますか?"))
for j in range(m):
  x = int(input("要素を入力してください->"))
  a.append(x)
print("ソート前: " + str(a))
a =quick_sort(a,0,len(a)-1)
print("ソート後: " +str(a))
