# Clumsy Factorial (C)

This is a C implementation of the "Clumsy Factorial" problem from LeetCode.

Instead of the normal factorial (N × N-1 × ... × 1), we follow a pattern of operations:  
**Multiply → Divide → Add → Subtract**, applied from left to right, repeating until we reach 1.

---

## ⚙️ How It Works

We loop from N down to 1, and:

1. Start with `last = N`
2. For each next number `k`, we:
   - Multiply (`last = last * k`)
   - Divide (`last = last / k`)
   - Add (`res += last`, then `last = k`)
   - Subtract (`res += last`, then `last = -k`)

3. Keep updating `op` (0 to 3) to cycle through `* / + -`.

At the end, we add whatever is left in `last` to the final result.

---

## 🧪 Examples

```c
clumsy(4);  // 4 * 3 / 2 + 1 = 6 + 1 = 7
clumsy(10); // 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1 = 12
