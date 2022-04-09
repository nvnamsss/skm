# Coding
The explaination for 4 questions is write below for further information about the implementation
## Question 1
This problem can be solved by moving forward until it can't then change the direction by turning 90 degrees. This approach time complexity and space complexity is O(n^2) where we use extra space to determine when we need to turn.

But we can improve the space complexity to O(1) by simulating the traversel, in other words, we know exactly where we need to go next by traversing layer by layer. After all, the layers traversel form a spiral traversel.

## Question 2
Intuitively, we can see that the data structure contains both characteristic of `queue` and `stack` thus I decided to implement a `dequeue` which I use `DoublyLinkedList` as internal unit for efficiency in `pop_back()` and `pop_front()`.

This data structure has O(1) time complexity in all methods because we can pointing out which node will be popped immediately thus the time complexity for `pop` is O(1). And for the push, due to the characteristic of `LinkedList`, it is obviously O(1).
## Question 3
We can solve this problem in O(n) time complexity and O(n) space complexity. Concretely, we need extra space for the answer and two passes for calculating the product. In the first pass, we iterate from 0 -> n, at each step we got the product from 0 -> i then we store it to the `ans` (I term the product as `dp`). In the second pass, we do the same but in a revert flow thus at every step, we got the product from i -> n thus ans[i] * dp means product(0, i) * (product, i + 1, n).

## Question 4
This problem can be solved with O(n^2) time complexity and O(1) space complexity by modifying it in-place if this constraint is applied:
- the range of matrix[i][j] is restricted in range [x, y], e.g matrix[i][j] >= 0

When modifying in-place, we set matrix[i][j] = v where v < x or v > y thus in the second pass, we can recognize that the element at `i`, `j` is modified

Otherwise, space complexity would be O(n^2) where we use extra space for storing the modified matrix

