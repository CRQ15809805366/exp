# (1) 计算斐波那契数列中小于参数 n 的所有值
def fibonacci_less_than(n):
    fib_sequence = []
    a, b = 0, 1
    while a < n:
        fib_sequence.append(a)
        a, b = b, a + b
    return fib_sequence

# 示例调用
print(fibonacci_less_than(10))  # 输出: [0, 1, 1, 2, 3, 5, 8]
print("-----------------------")

# (2) 利用列表实现筛选法求素数
def sieve_of_eratosthenes(n):
    if n < 2:
        return []
    primes = [True] * n
    primes[0] = primes[1] = False  # 0 和 1 不是素数
    for i in range(2, int(n**0.5) + 1):
        if primes[i]:
            for j in range(i * i, n, i):
                primes[j] = False
    return [i for i in range(n) if primes[i]]

# 示例调用
print(sieve_of_eratosthenes(20))  # 输出: [2, 3, 5, 7, 11, 13, 17, 19]
print("-----------------------")

# (3) 判断回文字符串
def is_palindrome(s):
    return s == s[::-1]

# 示例调用
print(is_palindrome("abcba"))  # 输出: True
print(is_palindrome("hello"))  # 输出: False
print("-----------------------")

# (4) 随机生成包含 n 个整数的列表，返回元组
import random

def random_list_and_average(n):
    random_list = [random.randint(1, 100) for _ in range(n)]
    avg = sum(random_list) / n
    greater_than_avg = [x for x in random_list if x > avg]
    return (avg, *greater_than_avg)

# 示例调用
print(random_list_and_average(3))  # 示例输出: (50.0, 60, 70)
print("-----------------------")

# (5) 计算工作日努力程度
def work_effort():
    target = 37.78
    rest_decay = 0.99  # 休息日水平下降
    work_days = 5
    rest_days = 2

    effort = 1.0
    daily_increase = 1.0
    while True:
        for _ in range(365):
            for _ in range(work_days):
                effort *= daily_increase
            for _ in range(rest_days):
                effort *= rest_decay
        if effort >= target:
            return daily_increase
        effort = 1.0
        daily_increase += 0.001

# 示例调用
print(work_effort())  # 输出: 1.019