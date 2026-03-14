# Stacks and Queues Assignment

## Task 1: Stack Operations on Array S[1..6] (3 pts)

We illustrate the state of the stack after each operation in the sequence:  
PUSH(S,4), PUSH(S,1), PUSH(S,3), POP(S), PUSH(S,8), POP(S)  
on an initially empty stack S stored in array S[1..6].

Assume a standard array-based stack implementation:
- Indices run from 1 to 6.
- A variable `top` tracks the index of the top element (top = 0 means empty).
- PUSH increments top and places the element at S[top].
- POP returns/removes the element at S[top] and decrements top.

**Initial state (empty stack):**  
top = 0  
S = [ , , , , , ]   (positions 1 to 6 empty)

1. **PUSH(S,4)**  
   top = 1  
   S = [4, , , , , ]

2. **PUSH(S,1)**  
   top = 2  
   S = [4, 1, , , , ]

3. **PUSH(S,3)**  
   top = 3  
   S = [4, 1, 3, , , ]

4. **POP(S)** → removes 3  
   top = 2  
   S = [4, 1, , , , ]   (3 is removed; position 3 logically empty)

5. **PUSH(S,8)**  
   top = 3  
   S = [4, 1, 8, , , ]

6. **POP(S)** → removes 8  
   top = 2  
   S = [4, 1, , , , ]   (8 is removed; position 3 logically empty)

**Final state:** top = 2, elements from bottom to top: 4, 1

This follows the LIFO (Last In, First Out) principle. The illustrations match typical textbook Figure 17 style, showing array contents and top pointer after each step.

## Task 2: Queue Operations on Array Q[1..6] (3 pts)

We illustrate the state of the queue after each operation in the sequence:  
ENQUEUE(Q,4), ENQUEUE(Q,1), ENQUEUE(Q,3), DEQUEUE(Q), ENQUEUE(Q,8), DEQUEUE(Q)  
on an initially empty queue Q stored in array Q[1..6].

Assume a standard array-based (non-circular) queue implementation:
- Indices run from 1 to 6.
- Variables `front` and `rear` track the positions (front = 0 and rear = 0 means empty).
- ENQUEUE increments rear and places the element at Q[rear].
- DEQUEUE returns/removes the element at Q[front] and increments front.

**Initial state (empty queue):**  
front = 0, rear = 0  
Q = [ , , , , , ]

1. **ENQUEUE(Q,4)**  
   rear = 1, front = 1  
   Q = [4, , , , , ]

2. **ENQUEUE(Q,1)**  
   rear = 2  
   Q = [4, 1, , , , ]

3. **ENQUEUE(Q,3)**  
   rear = 3  
   Q = [4, 1, 3, , , ]

4. **DEQUEUE(Q)** → removes 4  
   front = 2  
   Q = [ , 1, 3, , , ]   (position 1 logically empty)

5. **ENQUEUE(Q,8)**  
   rear = 4  
   Q = [ , 1, 3, 8, , ]

6. **DEQUEUE(Q)** → removes 1  
   front = 3  
   Q = [ , , 3, 8, , ]   (positions 1–2 logically empty)

**Final state:** front = 3, rear = 4, elements from front to rear: 3, 8

This follows the FIFO (First In, First Out) principle. The illustrations match typical textbook Figure 18 style, showing array contents with front and rear pointers after each step.

## Task 3: Rewrite ENQUEUE and DEQUEUE to detect underflow and overflow (1 pt)

In a fixed-size array-based queue (size 6), we must check boundaries before operations.

**ENQUEUE(Q, x):**
- If rear == 6, then **overflow** → report error ("Queue is full") and do not insert.
- Else increment rear, set Q[rear] = x.

**DEQUEUE(Q):**
- If front == 0 and rear == 0 (or front > rear), then **underflow** → report error ("Queue is empty") and return nothing/error value.
- Else return Q[front], then increment front.
- (Optionally, if front > rear after increment, reset front = rear = 0 for empty queue.)

These checks prevent invalid operations and match the intent of Listings 4 & 5 in typical textbooks (adding condition checks before modifying front/rear).

## Task 4: O(1)-time procedures for deque using array (3 pts)

A deque (double-ended queue) allows insertion and deletion at both ends in O(1) time. Using a fixed-size array D[1..n] (here n=6 for consistency), we maintain two pointers:

- `left`: index of the leftmost (front) element
- `right`: index of the rightmost (rear) element
- Initially: left = 1, right = 0 (empty deque)

(For simplicity, we use 1-based indexing and allow wrap-around logic only if implementing circular; here we describe linear version with checks.)

Four O(1) procedures:

1. **Insert at front (push_left / insertLeft(x)):**
   - If deque is full (right - left + 1 == n), report overflow.
   - Else decrement left, set D[left] = x.

2. **Insert at rear (push_right / insertRight(x)):**
   - If deque is full (right - left + 1 == n), report overflow.
   - Else increment right, set D[right] = x.

3. **Delete from front (pop_left / deleteLeft):**
   - If deque is empty (left > right), report underflow.
   - Else return D[left], then increment left.

4. **Delete from rear (pop_right / deleteRight):**
   - If deque is empty (left > right), report underflow.
   - Else return D[right], then decrement right.

These operations are all O(1) because they only involve constant-time pointer updates and array access. (Note: a circular array deque avoids wasting space after many deletes, but the linear version above is sufficient for O(1) time per operation as long as overflow is handled.)
