# Parallel Execution Algorithms in C++

This document provides an overview of various C++ Standard Library algorithms that support **parallel execution** using `std::execution::par_unseq`. This execution policy allows algorithms to run **in parallel** while utilizing **SIMD (Single Instruction Multiple Data) optimizations**, making them significantly faster for large datasets.
Use `std::execution::par_unseq` for n > 10^6 and `std::execution::unseq` for n <= 10^5

---

## 🚀 Sorting Algorithms

### **1️⃣ std::sort - Sorting a Range of Elements**

Sorts the elements in a given range.

```cpp
#include <bits/stdc++.h>
#include <execution>
using namespace std;

int main() {
    vector<int> v = {5, 3, 8, 1, 4};
    sort(std::execution::par_unseq, v.begin(), v.end());
    for (int x : v) cout << x << " "; // Output: 1 3 4 5 8
}
```

---

### **2️⃣ std::stable_sort - Stable Sorting**

Preserves the order of equal elements while sorting.

```cpp
#include <bits/stdc++.h>
#include <execution>
using namespace std;

int main() {
    vector<pair<int, char>> v = {{3, 'a'}, {1, 'b'}, {3, 'c'}, {2, 'd'}};
    stable_sort(std::execution::par_unseq, v.begin(), v.end());
    for (auto p : v) cout << p.first << " " << p.second << "\n";
}
```

---

### **3️⃣ std::partial_sort - Partially Sorting**

Sorts only the **top-k elements** in order.

```cpp
#include <bits/stdc++.h>
#include <execution>
using namespace std;

int main() {
    vector<int> v = {7, 3, 9, 1, 5};
    partial_sort(std::execution::par_unseq, v.begin(), v.begin() + 3, v.end());
    for (int x : v) cout << x << " "; // Output: 1 3 5 ...
}
```

---

### **4️⃣ std::nth_element - Finding the Nth Smallest Element**

Partitions the array such that the nth element is at its correct position.

```cpp
#include <bits/stdc++.h>
#include <execution>
using namespace std;

int main() {
    vector<int> v = {7, 3, 9, 1, 5};
    nth_element(std::execution::par_unseq, v.begin(), v.begin() + 2, v.end());
    cout << v[2]; // Output: 5 (3 smallest elements are in front)
}
```

---

## 🔄 Transformations & Iterations

### **5️⃣ std::for_each - Applying a Function**

Applies a function to each element.

```cpp
vector<int> v = {1, 2, 3};
for_each(std::execution::par_unseq, v.begin(), v.end(), [](int &x) { x *= 2; });
```

---

### **6️⃣ std::transform - Element-wise Transformation**

Transforms each element using a function.

```cpp
vector<int> v = {1, 2, 3}, res(3);
transform(std::execution::par_unseq, v.begin(), v.end(), res.begin(), [](int x) { return x * x; });
```

---

## 🔍 Searching & Counting

### **7️⃣ std::find - Finding an Element**

Finds the first occurrence of an element.

```cpp
auto it = find(std::execution::par_unseq, v.begin(), v.end(), 3);
```

---

### **8️⃣ std::count / std::count_if - Counting Elements**

Counts occurrences of a value or based on a condition.

```cpp
int count = count(std::execution::par_unseq, v.begin(), v.end(), 3);
int even_count = count_if(std::execution::par_unseq, v.begin(), v.end(), [](int x) { return x % 2 == 0; });
```

---

## 🔀 Merging & Set Operations

### **9️⃣ std::merge - Merging Two Sorted Ranges**

Merges two sorted ranges into a single sorted range.

```cpp
vector<int> a = {1, 3, 5}, b = {2, 4, 6}, res(6);
merge(std::execution::par_unseq, a.begin(), a.end(), b.begin(), b.end(), res.begin());
```

---

### **🔟 std::set_union - Union of Two Sorted Sets**

Combines unique elements from both sorted sets.

```cpp
vector<int> a = {1, 2, 3}, b = {2, 3, 4}, res(6);
auto it = set_union(std::execution::par_unseq, a.begin(), a.end(), b.begin(), b.end(), res.begin());
res.resize(it - res.begin());
```

---

### **1️⃣1️⃣ std::set_intersection - Finding Common Elements**

Finds the common elements between two sorted sets.

```cpp
vector<int> a = {1, 2, 3}, b = {2, 3, 4}, res(3);
auto it = set_intersection(std::execution::par_unseq, a.begin(), a.end(), b.begin(), b.end(), res.begin());
res.resize(it - res.begin());
```

---

## 🔥 Summary Table

| Algorithm | Purpose | Example |
|-----------|---------|---------|
| **std::sort** | Sorts elements | `sort(std::execution::par_unseq, v.begin(), v.end());` |
| **std::stable_sort** | Stable sorting | `stable_sort(std::execution::par_unseq, v.begin(), v.end());` |
| **std::partial_sort** | Sorts top-K elements | `partial_sort(std::execution::par_unseq, v.begin(), v.begin() + k, v.end());` |
| **std::nth_element** | Finds the Nth smallest element | `nth_element(std::execution::par_unseq, v.begin(), v.begin() + k, v.end());` |
| **std::for_each** | Applies a function | `for_each(std::execution::par_unseq, v.begin(), v.end(), f);` |
| **std::transform** | Transforms elements | `transform(std::execution::par_unseq, v.begin(), v.end(), res.begin(), f);` |
| **std::find** | Finds an element | `find(std::execution::par_unseq, v.begin(), v.end(), x);` |
| **std::count_if** | Counts elements by condition | `count_if(std::execution::par_unseq, v.begin(), v.end(), pred);` |
| **std::merge** | Merges sorted sequences | `merge(std::execution::par_unseq, a.begin(), a.end(), b.begin(), b.end(), res.begin());` |
| **std::set_union** | Union of two sorted sets | `set_union(std::execution::par_unseq, a.begin(), a.end(), b.begin(), b.end(), res.begin());` |
| **std::set_intersection** | Intersection of two sets | `set_intersection(std::execution::par_unseq, a.begin(), a.end(), b.begin(), b.end(), res.begin());` |

---

These functions make use of **parallel execution** to enhance performance. 🚀 Happy Coding! 😊
