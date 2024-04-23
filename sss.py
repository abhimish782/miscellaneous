#default 
#def add(a,b=5,c=10):
 #   return (a+b+c)
#print(add(10));

#keyword arguments
#def add(a,b,c):
#    return (a+b+c)
#print(add(b=10,a=10,c=10))

# write a python code to show method overloading using default method in keyword argument?

def add(a=0, b=0, c=0):
    return a + b + c

print(add())

print(add(1))


print(add(1, 2))


print(add(1, 2, 3))