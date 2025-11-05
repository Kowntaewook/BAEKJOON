a = int(input())  

for i in range(1, a + 1):
    num, num2 = map(int, input().split())  
    result = num + num2  
    print(f"Case #{i}: {result}")  