// #include <iostream>
// #include <string>
// #include <vector>     // For Time Table
// #include <list>       // For Route & Bus
// #include <queue>      // For Passenger Queues
// #include <map>        // For Stations (BST)
// #include <stack>      // For Undo History
// #include <algorithm>  // For std::find
// using namespace std;
//
// // --- 1. DATA STRUCTURES ---
// struct Passenger {
//     string name;
//     string startStation;
//     string destinationStation;
// };
//
// list<string> currentRoute;
// stack<list<string>> routeHistory;
// vector<string> timeTable = {"08:00", "10:00", "12:00", "14:00", "16:00"};
// map<string, queue<Passenger>> stations;
//
//
// // --- 2. CORE LOGIC FUNCTIONS ---
//
// void addStop(const string& stop) {
//     routeHistory.push(currentRoute);
//     currentRoute.push_back(stop);
//     cout << "Added stop: " << stop << endl;
// }
//
// void removeStop(const string& stop) {
//     auto it = find(currentRoute.begin(), currentRoute.end(), stop);
//     if (it != currentRoute.end()) {
//         routeHistory.push(currentRoute);
//         currentRoute.erase(it);
//         cout << "Removed stop: " << stop << endl;
//     } else {
//         cout << "Stop not found in the route.\n";
//     }
// }
//
// void undoLastRouteUpdate() {
//     if (!routeHistory.empty()) {
//         currentRoute = routeHistory.top();
//         routeHistory.pop();
//         cout << "Last route update undone.\n";
//     } else {
//         cout << "No route updates to undo.\n";
//     }
// }
//
// void displayRoute() {
//     cout << "Current Route: ";
//     for (const string& stop : currentRoute) {
//         cout << stop << " -> ";
//     }
//     cout << "END\n";
// }
//
// void showTimeTable() {
//     cout << "Time Table: ";
//     for (const string& time : timeTable) {
//         cout << time << " ";
//     }
//     cout << endl;
// }
//
// void simulateRun() {
//     cout << "\n--- STARTING BUS SIMULATION ---" << endl;
//     list<Passenger> bus;
//     int busCapacity = 10;
//
//     for (const string& stop : currentRoute) {
//         cout << "\n>>> Arriving at station: " << stop << endl;
//         auto it = bus.begin();
//         while (it != bus.end()) {
//             if (it->destinationStation == stop) {
//                 cout << "  (-) Dropping off: " << it->name << endl;
//                 it = bus.erase(it);
//             } else {
//                 ++it;
//             }
//         }
//         if (stations.find(stop) != stations.end()) {
//             queue<Passenger>& stationQueue = stations[stop];
//             cout << "  (" << stationQueue.size() << " passengers waiting)" << endl;
//             while (!stationQueue.empty() && bus.size() < busCapacity) {
//                 Passenger p = stationQueue.front();
//                 stationQueue.pop();
//                 bus.push_back(p);
//                 cout << "  (+) Boarding: " << p.name << endl;
//             }
//         } else {
//             cout << "  (This stop is not a registered station)" << endl;
//         }
//         cout << "  Departing " << stop << ". (Bus has " << bus.size() << " passengers)" << endl;
//     }
//     cout << "\n--- SIMULATION COMPLETE ---" << endl;
// }
//
// void loadDefaultData() {
//     cout << "Loading default simulation data..." << endl;
//     stations["Central Station"] = queue<Passenger>();
//     stations["Library"] = queue<Passenger>();
//     stations["Market"] = queue<Passenger>();
//     stations["University"] = queue<Passenger>();
//     addStop("Central Station");
//     addStop("Market");
//     addStop("Library");
//     addStop("University");
//     addStop("Central Station");
//     stations["Central Station"].push({"Saad", "Central Station", "University"});
//     stations["Central Station"].push({"Ali", "Central Station", "Library"});
//     stations["Market"].push({"Ayesha", "Market", "University"});
//     cout << "Default data loaded." << endl;
//     while(!routeHistory.empty()) routeHistory.pop();
//     routeHistory.push(currentRoute);
// }
//
// // --- 3. NEW: UI "HANDLER" FUNCTIONS ---
// // These simple functions just get input from the user
//
// void handle_addStop() {
//     string input;
//     cout << "Enter stop name: ";
//     getline(cin, input);
//     addStop(input);
// }
//
// void handle_removeStop() {
//     string input;
//     cout << "Enter stop name to remove: ";
//     getline(cin, input);
//     removeStop(input);
// }
//
// void handle_addPassenger() {
//     string name, start, dest;
//     cout << "Enter passenger name: ";
//     getline(cin, name);
//     cout << "Enter start station: ";
//     getline(cin, start);
//     cout << "Enter destination: ";
//     getline(cin, dest);
//
//     if (stations.find(start) != stations.end()) {
//         stations[start].push({name, start, dest});
//         cout << "Passenger " << name << " added to queue at " << start << ".\n";
//     } else {
//         cout << "Error: Start station not found. Add the station first.\n";
//     }
// }
//
// void handle_showQueues() {
//     cout << "--- All Passenger Queues ---" << endl;
//     if (stations.empty()) {
//         cout << "No stations have been added yet." << endl;
//     }
//     for (auto it = stations.begin(); it != stations.end(); ++it) {
//         string stationName = it->first;
//         queue<Passenger> q = it->second; // Copy queue to show it
//
//         cout << "Station: " << stationName << " (";
//         if (q.empty()) {
//             cout << "empty)" << endl;
//         } else {
//             cout << q.size() << " waiting)" << endl;
//             while (!q.empty()) {
//                 cout << "  - " << q.front().name << endl;
//                 q.pop();
//             }
//         }
//     }
// }
//
// void handle_addStation() {
//     string input;
//     cout << "Enter station name: ";
//     getline(cin, input);
//     if (stations.find(input) == stations.end()) {
//         stations[input] = queue<Passenger>();
//         cout << "Added station: " << input << endl;
//     } else {
//         cout << "Station " << input << " already exists." << endl;
//     }
// }
//
// void handle_searchStation() {
//     string input;
//     cout << "Enter station name to search: ";
//     getline(cin, input);
//     if (stations.find(input) != stations.end()) {
//         cout << "Station found: " << input << endl;
//         cout << "  Passengers waiting: " << stations[input].size() << endl;
//     } else {
//         cout << "Station not found.\n";
//     }
// }
//
// void displayMenu() {
//     cout << "\n=== Smart City Transport Simulation (v2) ===\n";
//     cout << "1. Add Stop to Route\n";
//     cout << "2. Display Route\n";
//     cout << "3. Remove Stop from Route\n";
//     cout << "4. Undo Last Route Update\n";
//     cout << "5. Add Passenger\n";
//     cout << "6. Show Passenger Queues\n";
//     cout << "7. Show Time Table\n";
//     cout << "8. Add Station\n";
//     cout << "9. Search Station\n";
//     cout << "10. *** RUN SIMULATION ***\n";
//     cout << "11. Exit\n";
//     cout << "Enter your choice: ";
// }
//
//
// // --- 4. MAIN FUNCTION (Now much shorter!) ---
//
// int main() {
//     int choice;
//     routeHistory.push(currentRoute);
//     loadDefaultData();
//
//     do {
//         displayMenu();
//         cin >> choice;
//         cin.ignore(); // Clears the input buffer
//
//         switch (choice) {
//             case 1:  handle_addStop();         break;
//             case 2:  displayRoute();           break;
//             case 3:  handle_removeStop();      break;
//             case 4:  undoLastRouteUpdate();    break;
//             case 5:  handle_addPassenger();    break;
//             case 6:  handle_showQueues();      break;
//             case 7:  showTimeTable();          break;
//             case 8:  handle_addStation();      break;
//             case 9:  handle_searchStation();   break;
//             case 10: simulateRun();            break;
//             case 11: cout << "Exiting...\n";   break;
//             default: cout << "Invalid choice!\n";
//         }
//     } while (choice != 11);
//
//     return 0;
// }