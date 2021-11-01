i=1
for i in range(100):
  n=i
  if i>=10 and n//10==n%10 and (n**2)//100==(n**2)%10:
      print(i)
  elif i<4:
      print(i)
  elif 4<=i and i<10 and (n**2)//10==(n**2)%10:
      print(i)
  i=i+1

