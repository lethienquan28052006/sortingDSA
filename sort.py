import numpy as np
import time

n = int(1e6)  
total_n = 10 * n  


with open("data.inp", "r") as f:
    data = np.fromfile(f, sep=" ", count=total_n, dtype=np.float64)

if len(data) < total_n:
    print("Dữ liệu trong file không đủ 10 triệu phần tử!")
    exit()

tmp = 0

for it in range(10): 
    segment = data[it * n: (it + 1) * n] 
    
    print(f"\nTestcase {it + 1}:")

    start = time.time()
    segment.sort()  
    end = time.time()

    elapsed = (end - start) * 1000  
    tmp += elapsed
    print(f"Thời gian chạy: {elapsed:.6f} milliseconds")

print(f"\nThời gian trung bình: {tmp / 10:.6f} milliseconds")
