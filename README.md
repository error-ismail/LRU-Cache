# LRU Cache

A simple LRU (Least Recently Used) Cache implementation in C++.

## Data Structures

* **`unordered_map`** – used for fast key lookup.
* **Doubly Linked List** – used to maintain the LRU order.

The most recently used item is kept near the tail, while the least recently used item stays near the head.

## Complexity

* `get()` — **O(1) average**
* `put()` — **O(1) average**
* Space — **O(capacity)**

## Input

First enter the cache capacity, then enter operations until EOF.

```text
2
put A 10
put B 20
get A
put C 30
get B
get C
```

## Compile and Run

```bash
g++ -std=c++17 LRU_Cache.cpp -o LRU_Cache
```

Windows:

```bash
.\LRU_Cache.exe
```

Linux/macOS:

```bash
./LRU_Cache
```
