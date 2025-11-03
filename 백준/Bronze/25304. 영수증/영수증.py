num = int(input())  
num2 = int(input())  

result = 0  

for i in range(num2):  
    a, b = map(int, input().split())  
    result += a * b  

if result == num:  
    print("Yes")  
else:  
    print("No")  
