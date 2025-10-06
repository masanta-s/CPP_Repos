# Mathematical Discoveries

## If question asks to find a and b such that a + b = n and LCM(a, b) is minimum possible:

1. **Identity Property**:
    - Find the largest divisor of n, let's say "d". The answer will be `(n - d) and d`

## If question asks to find no of maximum possible ribbon cuts in acceptable lengths of a, b and c, where ribbon length is n:

1. **Identity Property**:
    - Find the roots of `ax + by + cz = n`, To find those root, write the below code:
      int32_t main() {
         ios_base::sync_with_stdio(false);
         cin.tie(nullptr);
         cout.tie(nullptr);
         int n, ct1 = 0;
         vector<int> v1(3);
         cin >> n >> v1[0] >> v1[1] >> v1[2];
         sort(v1.begin(), v1.end());
         for (int i = 0; i * v1[0] <= n; i++) {
            for (int j = 0; i * v1[0] + j * v1[1] <= n; j++) {
               int k = n - (i * v1[0] + j * v1[1]);
               if (!(k % v1[2])) {
                  int ct2 = k / v1[2];
                  ct1 = max(ct1, i + j + ct2);
               }
            }
         }
         cout << ct1 << endl;
         return 0;
      }