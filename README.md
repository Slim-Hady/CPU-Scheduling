# CPU Scheduling Algorithms 

This project is a C implementation of common CPU scheduling algorithms used in Operating Systems. It calculates the Waiting Time and Turnaround Time for a set of processes based on the selected algorithm.

## Supported Algorithms

1. FCFS (First Come First Served)
   - Executes processes in the exact order they arrive.
   - Non-preemptive.

2. SJF (Shortest Job First)
   - Selects the process with the shortest burst time available.
   - Non-preemptive (once a process starts, it finishes).

3. RR (Round Robin)
   - Allocates a fixed time slice (Quantum) to each process.
   - Preemptive (switches between processes cyclically).

## Project Structure

- src/: Contains the source code files (.c).
- include/: Contains the header files (.h).
- main.c: The main entry point with the user menu.
- input.txt: The file containing process data.
- output.txt: The file where results are saved.
- Makefile: Script to compile the project easily.

## How to Build and Run

### Option 1: Using Make (Recommended)
1. Open your terminal in the project folder.
2. Compile the project:
   make
3. Run the executable:
   ./scheduler
4. To clean up build files:
   make clean

### Option 2: Manual Compilation
If you do not have Make installed, you can compile using gcc:
gcc main.c src/utils.c src/fcfs.c src/sjf.c src/rr.c -o scheduler -I./include

## Input File Format (input.txt)

The program reads process data from "input.txt".
IMPORTANT: The file must contain numbers only. Do not write text headers like "ID" or "Arrival".

The format for each line is:

[Process ID] [Arrival Time] [Burst Time]

Example content for input.txt:
```
1 0 7
2 2 4
3 4 1
4 5 4
```
## Usage

1. Fill "input.txt" with your process data.
2. Run the program.
3. Select an algorithm from the menu:
   - Enter 1 for FCFS.
   - Enter 2 for SJF.
   - Enter 3 for Round Robin (you will be asked to enter the Time Quantum).
4. The output table will be displayed in the terminal and saved to "output.txt".

