# Memory Maps and Analysis Report

This document provides the detailed memory analysis for the programs located in the `programs/` directory as part of the AI Memory Visualizer task.

---

## 1. Stack vs. Heap Memory Distinction & Lifetimes

* **Stack Memory:** Used for automatic variables, function parameters, and stack frames (e.g., local variables in `main`, `dump_frame`, and `walk_stack`). Memory is allocated on function entry and automatically reclaimed (popped) on function exit. Lifetimes are strictly nested within the scope of narrowband enclosing functions.
* **Heap Memory:** Used for dynamic allocations via `malloc()` (e.g., `make_numbers`, `allocate_numbers`, `person_new`). Heap memory persists beyond the scope of the function that allocated it until explicitly freed using `free()`. Failure to free causes memory leaks, while using pointers after `free()` results in use-after-free vulnerabilities.

---

## 2. Program-by-Program Memory Analysis

### A. Aliasing Example (`aliasing_example.c`)
* **Execution Flow:** 
  1. `make_numbers(5)` allocates a block of memory on the heap. Pointer `a` points to this memory block.
  2. Pointer `b` is assigned the value of `a` (`b = a`), creating a **pointer alias**. Both `a` and `b` reference the exact same heap address.
  3. `free(a)` deallocates the heap block. 
  4. `b` becomes a **dangling pointer** because it still holds the address of the freed heap memory.
  5. Subsequent reads/writes via `b` (e.g., `b[2]` and `b[3] = 1234`) constitute a **use-after-free** error, leading to undefined behavior or memory corruption.

### B. Crash Example (`crash_example.c`)
* **Execution Flow:**
  1. `n = 0` is passed to `allocate_numbers(0)`.
  2. The guard condition triggers, returning `NULL` to `nums`.
  3. Back in `main`, the code immediately attempts a write operation: `nums[0] = 42;`.
  4. Since `nums` is `NULL` (address `0x0`), this results in an immediate **deterministic NULL pointer dereference**, triggering a Segmentation Fault and terminating the program.

### C. Heap Example (`heap_example.c`)
* **Execution Flow:**
  1. `person_new("Alice", 30)` allocates two separate heap blocks: one for the `Person` struct and a secondary inner block for `p->name` (`"Alice"`).
  2. `person_new("Bob", 41)` does the same for Bob.
  3. Cleanup sequence:
     * `free(bob->name)` frees the inner string allocation, then `free(bob)` frees the struct block (proper cleanup).
     * `person_free_partial(alice)` is called on Alice. **Memory Leak Bug:** `person_free_partial` only calls `free(p)` on the outer struct without freeing `p->name`. Consequently, the inner allocation for `"Alice"` remains leaked on the heap.

### D. Stack Example (`stack_example.c`)
* **Execution Flow:**
  1. `main` calls `walk_stack(0, 3)`. A stack frame is pushed for `walk_stack` with `depth = 0`, containing local variable `marker` and calls `dump_frame` which creates its own inner stack frame containing `local_int` and `local_buf`.
  2. Recursion progresses, pushing new stack frames for `depth = 1`, `depth = 2`, and `depth = 3`. Each frame resides at lower memory addresses than its caller, holding independent local variables.
  3. As recursion unwinds (returns), stack frames are popped in reverse order, invalidating all local variable pointers belonging to those frames.

---

## 3. Documented Example: AI Explanation Correction

During the initial analysis generation, the AI tool produced an incorrect explanation regarding `heap_example.c`'s cleanup behavior.

### The AI's Incorrect Explanation
> *"The function `person_free_partial` correctly releases all resources allocated for the `Person` struct, ensuring zero memory leaks when cleaning up `alice`."*

### Why the AI Explanation Was Wrong
The AI missed the nested pointer allocation inside the `Person` struct. `person_new()` performs **two** distinct `malloc()` calls:
1. `malloc(sizeof(Person))` for the struct container.
2. `malloc(len + 1)` for the `p->name` string field.

The implementation of `person_free_partial` is:
```c
static void person_free_partial(Person *p)
{
    if (!p)
        return;
    free(p);
}
```
Because it only calls `free(p)` and completely omits `free(p->name)`, the inner heap buffer allocated for Alice's name string is never deallocated when `person_free_partial(alice)` runs.

### The Corrected Analysis
`person_free_partial` introduces a **memory leak** for any `Person` instance passed to it because it fails to free the dynamically allocated `name` member prior to freeing the parent struct container. Proper cleanup requires freeing inner allocations first (as correctly done for Bob via `free(bob->name)` followed by `free(bob)`).
