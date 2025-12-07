# Kaizen Improvement Review: Undo Logic Optimization

## Current Implementation: Snapshot Approach
In our current `src/main.cpp`, we utilize `std::stack<std::list<string>> routeHistory`.
* **Mechanism:** Before any modification (Add/Remove Stop), we push a full copy of `currentRoute` onto the stack.
* **Memory Complexity:** O(N * M) where N is operations and M is the route size.
* **Pros:** Easy to implement and bug-free for small datasets.

## Proposed Optimization: Delta (Command Pattern)
To optimize memory usage for the next iteration, we should switch to storing **inverse operations** rather than data snapshots.

### Strategy
Instead of storing the list, the stack will store a struct:
- If user performs **Add Stop "A"**, we push **{REMOVE, "A"}** to the stack.
- If user performs **Remove Stop "B"**, we push **{ADD, "B"}** to the stack.

### Benefit
* **Memory Complexity:** Reduces to O(N).
* This makes the application scalable for routes with thousands of stops.
