🛠️ Low Level Messing: 1 Billion Ints vs. Arrow Lake

I’m experimenting with how to actually saturate a modern CPU. I’ve built a C/C++ hybrid that sorts 1,000,000,000 unsigned integers, but I’m seeing some "fat" in the performance stats that I don't fully understand yet, and yes this is my first low level attempts at stuff... original approach but hey.

## 📊 Current Performance (The Reality)
Running `/usr/bin/time -v`:
- **User Time:** 137.81s (This feels high)
- **Wall Clock:** 12.85s
- **CPU Usage:** 1095%
- **Max RSS:** 7.45 GB
- **Minor Page Faults:** ~2 Million

## 🏗️ What i think is happening Under the Hood
1. **The Generation:** I'm using a single-threaded Xorshift loop to fill the array.
2. **The Bridge:** Passing the raw pointer to a C++ parallel sort.
3. **The Goal:** I want to reduce the "User Time" and understand why I'm hitting 2 million page faults even with a simple `malloc`.

## 🧠 What I'm Trying to Learn
I’m still early in a low level journy but i'm looking for the "Old School" wisdom that the docs don't cover:
- How can I parallelize the Xorshift generation without causing race conditions on the state?
- Is there a way to "pre-warm" the memory to avoid that massive page fault spike?
- Does this 1095% CPU usage suggest I'm hitting "False Sharing" in the C++ bridge?

If you have a "90-page manifesto" on why my cache alignment is a disaster, **i want to read it.**; i’m looking for the "why" behind the silicon.
