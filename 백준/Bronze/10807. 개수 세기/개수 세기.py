num1=int(input())
num2=list(map(int, input().split()))[:num1]
num3=int(input())
result=0

for i in range(num1):
    if num2[i] == num3:
        result+=1
print(result)