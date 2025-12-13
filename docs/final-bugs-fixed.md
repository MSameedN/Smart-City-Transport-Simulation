# Final Bugs Fixed (Week 4)

## 1. Global State Pollution
* **Issue:** The project relied on global variables (`stations`, `currentRoute`), making the state difficult to manage and prone to conflicts.
* **Fix:** Refactored all data into a `TransportSystem` class. Variables are now private members accessed through public methods.

## 2. Monolithic Simulation Logic
* **Issue:** The `simulateRun` function was overly complex and hard to read, handling iteration, boarding, and offloading simultaneously.
* **Fix:** Extracted logic into helper functions `boardPassengers()` and `offloadPassengers()`. The main simulation loop is now concise and readable.

## 3. Input Validation Failure
* **Issue:** Entering a character (non-integer) at the main menu caused an infinite loop and program crash.
* **Fix:** Added `cin` validation checks. The program now detects invalid input, clears the buffer, and prompts the user again without crashing.

## 4. Inefficient Queue Visualization
* **Issue:** Viewing queues required destructive copying or manual iteration constraints.
* **Fix:** Implemented a safe iteration method within the `TransportSystem` class to display passenger lists without modifying the underlying queue structure.
