# Uphold Coding Challenge — C++

## Problem
Given a string and an integer `x`, pad every group of consecutive digits 
with leading zeros so each group is exactly `x` digits long.

**Example:**
- `"James Bond 7", 3` → `"James Bond 007"`
- `"99UR1337", 6` → `"000099UR001337"`

## Solutions

### Solution 1 — Index Tracking (`solution1.cpp`)
The goal with this solution was to improve from the previous sliding 
window approach by thinking more in chunks with less branches. The 
problem with having too many branches is too many checks to corner a 
solution. With index tracking, I used a lastStart and lastEnd index to 
greedily track the beginning and ending values of digit groups. At the 
end of the loop, if indexStart != -1, I assumed I was in the middle of 
capturing digits, so I insert zeros on the temporary string and append 
it to the result string. This gave a much cleaner and more elegant 
approach to solving the problem with fewer logic branches.

**Time Complexity: O(n)**
Single pass through the string. `string.insert()` is O(n) in the worst 
case but is called at most once per digit group, keeping the overall 
complexity linear.

**Space Complexity: O(n)**
Output string grows linearly with input size. No additional data 
structures used.

---

### Solution 2 — Sliding Window (`solution2.cpp`)
This was the original solution. The approach was to scrape the 
characters including white spaces, and once a digit was hit, start 
counting up until either a null terminating character or something 
other than a digit was encountered. A boolean flag was used as a hint 
to track whether currently in the middle of a digit count. The left 
pointer marks where the digit group starts, and when a non-digit is 
encountered after digits, the padding is calculated using the distance 
between the left pointer and current position. This is the simplest 
possible logic of all four solutions which is reflected in it being the 
fastest in benchmarks.

**Time Complexity: O(n)**
Single pass through the string with two pointers and a boolean flag. 
Minimal overhead and minimal branches.

**Space Complexity: O(n)**
Output string grows linearly with input size. No additional data 
structures used.

---

### Solution 3 — Deque Buffer (`solution3.cpp`)
The thinking behind this solution was to collect characters linearly, 
seeing things one at a time. Once digits were encountered, the goal was 
to prepend zeros to the front of those digits. This reminded me of 
problems using a monotonic deque for tracking minimum and maximum 
values. Once a number is encountered it gets pushed back onto the deque, 
and once a non-digit is encountered that gets pushed back onto the deque 
too. The surprise with this solution was that despite using a deque 
which is designed for efficient front and back operations, it turned out 
to be the slowest solution. This is because of the `.insert` calls and 
the fact that every character touches multiple data structures — two 
deques running simultaneously — which creates a much higher constant 
factor even though the overall complexity is still linear.

**Time Complexity: O(n)**
Single pass through the string, however every character touches multiple 
data structures. This higher constant factor is visible in benchmarks 
where solution 3 is significantly slower than solutions 1 and 2.

**Space Complexity: O(n)**
Two deques running simultaneously plus the output string. Higher memory 
constant than solutions 1 and 2 due to the additional deque overhead.

---

### Solution 4 — Singly Linked List (`solution4.cpp`)
This was the final and most ambitious solution. The approach was a 
simple singly linked list using a fast pointer and prev pointer — 
inspired by the tortoise and hare algorithm. The idea was that prev 
trails fast the whole time through non-digit characters, and the moment 
fast lands on a digit, prev is sitting right before the digit group 
which is the perfect insertion point for zero nodes. This moves 
completely away from string manipulation and multiple data structures, 
inserting zeros directly in place into the list without any shifting. 
The result is collected by traversing the final list once at the end. 
On large inputs this solution scales significantly better than the deque 
solution, closing the gap with solutions 1 and 2, because linked list 
node insertion avoids the character shifting cost of string operations.

**Time Complexity: O(n)**
Three linear passes — one to build the list, one to insert zeros, one 
to collect the result. Scales better than string insert based solutions 
on large inputs because insertion does not require shifting.

**Space Complexity: O(n)**
Every character in the input becomes a heap allocated node. This carries 
a higher memory cost per character than string based solutions due to 
the pointer overhead of each node, but insertion is done in place 
without additional output structures.

---

## Benchmark Results

### Small Inputs (test case sized strings)
| Solution | Time |
|---|---|
| Solution 1 — Index Tracking | ~14,718 ns |
| Solution 2 — Sliding Window | ~11,967 ns |
| Solution 3 — Deque | ~75,592 ns |
| Solution 4 — Linked List | ~23,796 ns |

### Large Inputs (1000x repeated strings)
| Solution | Time |
|---|---|
| Solution 1 — Index Tracking | ~1,589,100 ns |
| Solution 2 — Sliding Window | ~1,141,261 ns |
| Solution 3 — Deque | ~20,477,241 ns |
| Solution 4 — Linked List | ~8,269,267 ns |

**Key takeaway:** Solution 2 is fastest across both input sizes due to 
its minimal overhead and simplest logic. Solution 4 scales significantly 
better than Solution 3 on large inputs because linked list node 
insertion avoids the character shifting cost of string operations.

---

## Unit Tests
Unit tests are written using Google Test:

| Input | x | Expected Output |
|---|---|---|
| `"James Bond 7"` | 3 | `"James Bond 007"` |
| `"PI=3.14"` | 2 | `"PI=03.14"` |
| `"It's 3:13pm"` | 2 | `"It's 03:13pm"` |
| `"It's 12:13pm"` | 2 | `"It's 12:13pm"` |
| `"99UR1337"` | 6 | `"000099UR001337"` |

---

## External Libraries
- Google Test 
- Google Benchmark