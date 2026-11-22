<div align="center">

# ⚡ CacheForge

**A Redis-inspired in-memory key-value store, built from scratch in C++17.**

*Learn C++, storage engines, and backend systems by building a cache from the ground up.*

<br>

![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-build-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Status](https://img.shields.io/badge/status-in%20development-F59E0B?style=for-the-badge)
![Progress](https://img.shields.io/badge/milestones-5%20of%209-10B981?style=for-the-badge)

[Features](#-features) · [Quick Start](#-quick-start) · [Roadmap](#-roadmap) · [Structure](#-project-structure) · [Limitations](#-current-limitations)

</div>

---

## ✨ Features

| Command | Syntax | Description |
|:--------|:-------|:------------|
| 🟢 `SET`  | `SET <key> <value>` | Stores a value. Values may contain spaces. |
| 🔵 `GET`  | `GET <key> [key ...]` | Retrieves one or more values. Missing keys return `(nil)`. |
| 🔴 `DEL`  | `DEL <key> [key ...]` | Deletes keys and returns the number removed. |
| 🟣 `MSET` | `MSET <key> <value>, <key> <value>, ...` | Stores multiple key-value pairs in a single command. |

### Example session

```text
> SET name Karan Shandilya
OK
> MSET country India, age 22
OK
> GET name country age
Karan Shandilya, India, 22
> DEL country age
2
```

---

## 🚀 Quick Start

**Requirements:** CMake and a C++17-compatible compiler.

```bash
# Configure
cmake -S . -B build

# Build
cmake --build build

# Run
./build/CacheForge
```

> [!TIP]
> Re-run the configure step only when `CMakeLists.txt` changes. For source-code changes, rebuilding is enough.

---

## 🗺️ Roadmap

| # | Milestone | Scope | Status |
|:-:|:----------|:------|:------:|
| 1 | **Project Setup** | Project structure, Git, C++17, CMake | ✅ Complete |
| 2 | **Key-Value Storage** | Initial in-memory store on `std::unordered_map` | ✅ Complete |
| 3 | **Object-Oriented Refactor** | `KeyValueStore` class with `set()`, `get()`, `del()` | ✅ Complete |
| 4 | **Multiple Source Files** | Declarations, implementation, and entry point split across `include/` and `src/` | ✅ Complete |
| 5 | **Command Parsing** | Multiword values, multi-key `GET`/`DEL`, `MSET`, validation, empty-input handling, graceful shutdown | ✅ Complete |
| 6 | **TTL & Expiration** | Time-to-live and key expiration | 🚧 Next |
| 7 | **Memory Management & Eviction** | Memory limits, LRU/LFU eviction policies | 📋 Planned |
| 8 | **Networking & TCP Server** | Client communication with CacheForge over TCP | 📋 Planned |
| 9 | **Concurrency, Persistence & Distribution** | Concurrent access, persistence/recovery, distributed-storage concepts | 📋 Planned |

```mermaid
flowchart LR
    A[1 Setup] --> B[2 Storage] --> C[3 OOP] --> D[4 Files] --> E[5 Parsing]
    E --> F[6 TTL]:::next --> G[7 Eviction] --> H[8 TCP] --> I[9 Persistence]
    classDef next fill:#F59E0B,stroke:#B45309,color:#000
    style A fill:#10B981,color:#fff
    style B fill:#10B981,color:#fff
    style C fill:#10B981,color:#fff
    style D fill:#10B981,color:#fff
    style E fill:#10B981,color:#fff
```

---

## 📁 Project Structure

```text
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

---

## ⚠️ Current Limitations

- **No persistence:** data lives in memory only and is lost on exit.
- **Not yet implemented:** TTL, eviction, networking, concurrency, and persistence.
- **`MSET` and commas:** commas separate pairs, so commas inside values are unsupported.

---

## 🎯 What's Next

The next milestone is **TTL and Expiration**, followed by memory management, networking, concurrency, and persistence.

<div align="center">

<sub>Built as a hands-on learning project · Crafted in C++17</sub>

</div>