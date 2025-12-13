# Smart City Transport Simulation

## Project Summary
A C++ console-based application designed to simulate a city bus transit system. The program allows users to manage bus routes, stations, and passengers dynamically. It features a simulation engine that processes passenger boarding and drop-offs based on the defined route and station queues.

## Data Structures Used
* **`std::map` (Stations):** Used to store station data with station names as keys for $O(\log N)$ lookup efficiency.
* **`std::queue` (Passenger Lines):** Models real-world waiting lines at stations (FIFO - First In, First Out).
* **`std::list` (Bus Route):** Allows efficient insertion and deletion of stops at any point in the route without shifting memory.
* **`std::stack` (Undo History):** Stores snapshots of the route to enable "Undo" functionality (LIFO - Last In, First Out).
* **`std::vector` (Time Table):** Stores fixed schedule data.

## Key Features
1.  **Route Management:** Add or remove stops dynamically from the active route.
2.  **Undo System:** Revert the last change made to the route.
3.  **Passenger Simulation:** Board and drop off passengers automatically as the bus traverses the route.
4.  **Station Management:** Create new stations and view current passenger queues.
5.  **Search:** Quickly find station details and waiting counts.

## How to Run
1.  Ensure you have a C++ compiler installed (e.g., G++).
2.  Compile the source code:
    ```bash
    g++ -o transport_sim src/main.cpp
    ```
3.  Run the executable:
    ```bash
    ./transport_sim
    ```
