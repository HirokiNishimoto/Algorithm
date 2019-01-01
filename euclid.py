def euclid(m, n):
    while True:
        r = m%n
        if r==0:
            return n
        else:
            m=n
            n=r

print(euclid(20,5))
