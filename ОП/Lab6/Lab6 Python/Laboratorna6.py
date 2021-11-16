def sqrt(a,k,n):
    y_n=a
    for i in range(1,n):
        y_n=(1/k)*(a/(y_n**(k-1))+(k-1)*y_n)
        i=i+1
    return y_n
a=float(input("Enter (a>0) a="))
n=int(input("Enter n="))
print("Result is:"+str((sqrt(a,3,n)-sqrt(a*a+1,6,n))/(1+sqrt(3+a,7,n))))