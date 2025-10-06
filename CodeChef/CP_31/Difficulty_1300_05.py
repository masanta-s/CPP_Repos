# यदा यदा हि धर्मस्य ग्लानिर्भवति भारत।
# अभ्युत्थानमधर्मस्य तदात्मानं सृजाम्यहम्॥
# ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
# उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
# For printing an integer, instead of
#
# print(n)
# Use :-
#
# sys.stdout.write(str(n) + "\n")
# This is better for large outputs not for small outputs

# For printing a list of integers, instead of
#
# print(*list)
# Use :-
#
# sys.stdout.write(" ".join(map(str,list)) + "\n")
import bisect, itertools, math
# import numpy as np
from typing import List, Tuple
from collections import deque
from functools import reduce
from math import gcd, factorial
from itertools import accumulate, groupby
import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

MOD = 998244353


def bin_expo(x: int, n: int) -> int:
    ans = 1
    x %= MOD
    while n:
        if n & 1:
            ans = (ans * x) % MOD
        x = (x * x) % MOD
        n >>= 1
    return ans


def prime_numbers(N: int) -> List[bool]:
    is_prime = [True] * (N + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(N)) + 1):
        if is_prime[i]:
            for j in range(i * i, N + 1, i):
                is_prime[j] = False
    return is_prime


def nCr(n: int, r: int) -> int:
    if n - r < r:
        r = n - r
    p = k = 1
    while r:
        p *= n
        k *= r
        m = math.gcd(p, k)
        p //= m
        k //= m
        n -= 1
        r -= 1
    return p


def longest_common_substring(str1: str, str2: str) -> int:
    n, m = len(str1), len(str2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    max_len = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                max_len = max(max_len, dp[i][j])
    return max_len


def compute_xor(n: int) -> int:
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    return 0


def positions_0_1(s: str) -> List[int]:
    pos_0, pos_1 = [], []
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            pos_0.append(i)
        else:
            pos_1.append(i)
    return pos_1 if len(pos_1) <= len(pos_0) else pos_0


def subsequence_10_01_calculate(s: str) -> Tuple[int, Tuple[int, int]]:
    lst_idx = len(s) - 1
    pos = positions_0_1(s)
    total = sum(lst_idx - p - i for i, p in enumerate(pos))
    return total, (len(pos), int(s[pos[0]])) if pos else (0, 0)


def nos_01_10(s: str) -> Tuple[int, int]:
    total, (count, val) = subsequence_10_01_calculate(s)
    if val:
        return total, ((len(s) - count) * count - total)
    else:
        return ((len(s) - count) * count - total), total

def groupByFunc(str1):
    for char, group in groupby(str1):
        print(''.join(group))


def groupByList(str1):
    l1 = [''.join(group) for char, group in groupby(str1)]
    return l1

# -------------------------------
# Graph Algorithms (Commented Out)
# -------------------------------

# N = int(1e5 + 10)
# g = [[] for _ in range(N)]
# vis = [False] * N

# def dfs(vertex):
#     vis[vertex] = True
#     for child in g[vertex]:
#         if vis[child]:
#             continue
#         dfs(child)

# level = [0] * N

# def bfs(source):
#     q = deque()
#     q.append(source)
#     vis[source] = True
#     while q:
#         curr = q.popleft()
#         for child in g[curr]:
#             if not vis[child]:
#                 q.append(child)
#                 vis[child] = True
#                 level[child] = level[curr] + 1

# from heapq import heappop, heappush

# def dijkstra(source, graph):
#     dist = [float('inf')] * len(graph)
#     vis = [False] * len(graph)
#     dist[source] = 0
#     heap = [(0, source)]
#     while heap:
#         d, v = heappop(heap)
#         if vis[v]: continue
#         vis[v] = True
#         for child, weight in graph[v]:
#             if dist[v] + weight < dist[child]:
#                 dist[child] = dist[v] + weight
#                 heappush(heap, (dist[child], child))

# -------------------------------
# Main Logic Stub
# -------------------------------
def main():
    t = int(input())
    for _ in range(t):
        str1 = input().decode().strip()
        mul = 1; sum1 = 0
        l1 = groupByList(str1)
        for segment in l1:
            mul = (mul * len(segment)) % MOD
            sum1 += len(segment) - 1
        print(f"{sum1} {(mul * math.factorial(sum1)) % MOD}")

if __name__ == "__main__":
    main()
