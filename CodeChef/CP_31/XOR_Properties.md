# XOR Properties and Applications in Competitive Programming

## Basic Properties
1. **Identity Property**:  
   - `a ⊕ 0 = a` (XOR with zero leaves the number unchanged)

2. **Self-Canceling Property**:  
   - `a ⊕ a = 0` (XOR of a number with itself is always zero)

3. **Commutative Property**:  
   - `a ⊕ b = b ⊕ a` (Order does not matter)

4. **Associative Property**:  
   - `(a ⊕ b) ⊕ c = a ⊕ (b ⊕ c)` (Grouping does not change the result)

---

## Useful Applications

### 1. XOR with Power of 2
- If `x` is a power of 2, then:
  - `x ⊕ y = x + y` if `x` and `y` have no common set bits.

### 2. Finding a Unique Element (Single Number Problem)
- If every element appears twice except one:
  ```cpp
  int unique = 0;
  for (int num : arr) unique ^= num;
  ```

### 3. Swapping Two Numbers Without Extra Space
  ```cpp
  a = a ^ b;
  b = a ^ b;  // Now b = a
  a = a ^ b;  // Now a = b
  ```

### 4. XOR from 1 to N (Prefix XOR Trick)
  ```cpp
  int xorUptoN(int n) {
      if (n % 4 == 0) return n;
      if (n % 4 == 1) return 1;
      if (n % 4 == 2) return n + 1;
      return 0;
  }
  ```

### 5. Finding Missing Number in an Array
  ```cpp
  int missingNumber(vector<int>& nums) {
      int n = nums.size();
      int xorAll = 0, xorArr = 0;
      for (int i = 1; i <= n; i++) xorAll ^= i;
      for (int num : nums) xorArr ^= num;
      return xorAll ^ xorArr;
  }
  ```

### 6. Checking if a Number is a Power of Two
  ```cpp
  bool isPowerOfTwo(int x) {
      return (x > 0) && ((x & (x - 1)) == 0);
  }
  ```

### 7. Finding the Rightmost Set Bit
  ```cpp
  int rightmostSetBit = x & -x;
  ```

### 8. Checking if Two Numbers Have Opposite Signs
  ```cpp
  bool hasOppositeSigns(int x, int y) {
      return (x ^ y) < 0;
  }
  ```

### 9. XOR of Two Consecutive Numbers
- If `n` is a power of 2 minus 1:
  - `n ⊕ (n + 1) = 2n + 1`

### 10. General XOR of a Range [L, R]
  ```cpp
  XOR(L to R) = XOR(0 to R) ⊕ XOR(0 to L-1);
  ```

### 11. AND > XOR
  ```cpp
  Conclusion: Because a & b is guaranteed to be ≥ 2^k 
  and a ^ b is guaranteed to be < 2^k, the inequality a & b > a ^ b will always hold true when their most significant bits align.
  ```

### 12. XOR-Based Graph and Trie Applications
- **Finding Maximum XOR Pair in an Array using Trie**
- **Efficient path XOR queries on trees using Binary Lifting**
- **Bitwise DP problems**

### 13. Checking if a Binary String has All Length-k Substrings (XOR Rolling Hash)
- Efficiently check if a binary string contains all possible substrings of length `k`.

---

## Conclusion
- XOR is highly useful in **parity checking, encryption, bit manipulation, range queries, and DP problems**.
- It allows **fast swaps, missing number detection, efficient hashing, and graph operations**.

