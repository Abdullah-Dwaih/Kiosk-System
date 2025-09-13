# 🎟️ Kiosk System using Queue (C++)

This project is an implementation of a **Kiosk Ticketing System** using **Queues** in C++.  
It simulates how tickets are issued, served, and managed in real-world queue-based systems (e.g., banks, hospitals, or service centers).

---

## 📌 Features
- Issue tickets with **prefix** and **timestamp**.
- Track **waiting clients** and **served clients**.
- Estimate **expected service time** based on average serving time.
- Display tickets in:
  - **Right-to-Left (RTL)** order.
  - **Left-to-Right (LTR)** order.
- Show detailed **ticket information** (time, number, waiting clients).
- Print full queue line or all ticket details.

---

## ⚙️ How It Works
- The system maintains a **FIFO Queue** (`std::queue`) of issued tickets.
- Each ticket has:
  - Unique number (`Prefix + Number`).
  - Ticket issue time (`clsDate`).
  - Waiting clients count.
  - Expected serving time.
- Clients are served **in the order they arrive**.

---

## 🏗️ Project Structure
- `clsQueueLine`:  
  Handles the queue logic (issue, serve, display).
- `clsTicket` (inner class):  
  Represents an individual ticket with details.
- Uses `std::queue` and `std::stack` from C++ STL.

---

### Example Out : 
Queue Info
-------------------------
Prefix          = A
Total Tickets   = 5
Served Clients  = 2
Waiting Clients = 3
-------------------------

Tickets: A1 <-- A2 <-- A3 <-- A4 <-- A5 <--

       ---Tickets---
  _______________________
        A3
    2025-09-13 15:30:21
    Waiting Clients = 2
    Serve Time In
       10 Minutes.
  _______________________
