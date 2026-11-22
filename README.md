# CacheForge

A Redis-inspired, in-memory key-value store built in C++.

CacheForge is a learning project focused on understanding how a
cache/storage engine works internally, while building a practical
foundation in C++ and backend development.

## Current Features

  ------------------------------------------------------------------------------------------
  Command                 Syntax                                     Description
  ----------------------- ------------------------------------------ -----------------------
  `SET`                   `SET <key> <value>`                        Stores a value. Values
                                                                     can contain spaces.

  `GET`                   `GET <key> [key ...]`                      Retrieves one or more
                                                                     values. Missing keys
                                                                     return `(nil)`.

  `DEL`                   `DEL <key> [key ...]`                      Deletes one or more
                                                                     keys and reports the
                                                                     number deleted.

  `MSET`                  `MSET <key> <value>, <key> <value>, ...`   Stores multiple
                                                                     key-value pairs in one
                                                                     command.
  ------------------------------------------------------------------------------------------

Example:

``` text
> SET name Karan Shandilya
OK
> MSET country India, age 22
OK
> GET name country age
Karan Shandilya, India, 22
> DEL country age
2
> GET country age
(nil), (nil)
```

## Project Progress

  ---------------------------------------------------------------------------
  Milestone               What we worked on           Status
  ----------------------- --------------------------- -----------------------
  **1. C++ Project        Created the project         Complete
  Setup**                 structure, initialized Git, 
                          configured C++17, and set   
                          up the CMake build.         

  **2. Understanding      Built the initial in-memory Complete
  Key-Value Storage**     key-value store using       
                          `std::unordered_map`, and   
                          explored how keys and       
                          values are stored and       
                          retrieved.                  

  **3. Object-Oriented    Encapsulated storage        Complete
  Refactoring**           operations in a             
                          `KeyValueStore` class with  
                          `set()`, `get()`, and       
                          `del()` methods.            

  **4. Separating Code    Separated the class         Complete
  into Multiple Files**   declaration into            
                          `include/KeyValueStore.h`   
                          and its implementation into 
                          `src/KeyValueStore.cpp`,    
                          keeping the application     
                          entry point in              
                          `src/main.cpp`.             

  **5. Better Command     Added multiword values,     Complete
  Parsing**               multi-key `GET` and `DEL`,  
                          `MSET`, input validation,   
                          empty-input handling,       
                          unknown-command handling,   
                          and graceful shutdown on    
                          `EXIT` or EOF.              

  **6. TTL and            Planned: add time-to-live   Planned
  Expiration**            support so keys can expire  
                          automatically or when       
                          accessed after expiry.      

  **7. Memory Management  Planned: introduce memory   Planned
  and Eviction**          limits and eviction         
                          policies such as LRU/LFU.   

  **8. Networking and TCP Planned: allow clients to   Planned
  Server**                communicate with CacheForge 
                          over TCP.                   

  **9. Concurrency,       Planned: explore concurrent Planned
  Persistence and         access,                     
  Distributed Storage**   persistence/recovery, and   
                          later distributed-storage   
                          concepts.                   
  ---------------------------------------------------------------------------

## Project Structure

``` text
CacheForge/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   └── KeyValueStore.h
├── src/
│   ├── main.cpp
│   └── KeyValueStore.cpp
└── build/
```

## Build and Run

Requirements: a C++17-compatible compiler and CMake.

``` bash
cmake -S . -B build
cmake --build build
./build/CacheForge
```

Re-run the CMake configuration command if `CMakeLists.txt` changes. For
changes limited to `.cpp` or header files, rebuilding is sufficient.

## Current Limitations

-   Data is stored in memory and is lost when the process exits.
-   There is no TTL, eviction policy, persistence, or network interface
    yet.
-   `MSET` uses commas to separate pairs, so commas are not currently
    supported inside values.
-   The current store is single-process and does not yet implement
    concurrent access.

## Direction

The goal is to evolve CacheForge incrementally into a more capable
in-memory key-value store, adding expiration, eviction, networking,
concurrency, and persistence as the project progresses.
