num1,num2=map(int, input().split())
num3=list(map(int, input().split()))[:num1]

for i in range(num1):
    if(num3[i] < num2):
        print(num3[i], end=" ")