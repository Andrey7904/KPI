x=float(input("Введіть x: "))
y=float(input("Введіть y: "))
if (x-1)**2+y**2<=4 and -1<=x and x<=1:
    print("Point (x,y) belongs to figure")
elif abs(y)<=3-x and 1<=x and x<=3:
    print("Point (x,y) belongs to figure")    
else:
    print("Point (x,y) DOESN`T belong to figure")