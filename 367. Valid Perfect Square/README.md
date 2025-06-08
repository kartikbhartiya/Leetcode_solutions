# Check if a Number is a Perfect Square (C)

This is a simple C program that checks whether a given non-negative integer is a perfect square or not.

## What it Does

It takes an integer `x` and returns:

- `true` if `x` is a perfect square (like 4, 9, 16...)
- `false` if it’s not (like 3, 10, 14...)

Pretty straightforward.

## How it Works

Instead of using `sqrt()` or any float math, this solution uses a loop to check if there's any integer `i` such that `i * i == x`.

To avoid overflow (and unnecessary loops), it stops the loop at `x / i`. (and avoids error)

It also keeps track of the closest square less than or equal to `x` using a variable `b`, and finally checks if `b * b == x`.

## Example

```c
isPerfectSquare(25);  // returns true
isPerfectSquare(14);  // returns false
