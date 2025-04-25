# Task Scheduler

## Instructions on How to Run the Project

### Prerequisites

- Ensure you have a C++ compiler installed on your system that supports C++20 (e.g., `g++` or `clang++`).
- For macOS and Linux, ensure `make` is installed on your system.
- For Windows, use an alternative method as `make` is not available by default.

### Steps to Run on macOS and Linux

1. Open a terminal and navigate to the project directory:

   ```bash
   cd /path/to/task-scheduler
   ```

2. Clean any previous builds (optional):

   ```bash
   make clean
   ```

3. Build the project:

   ```bash
   make test
   ```

4. Run the testbench:
   ```bash
   ./bin/testbench
   ```

### Steps to Run on Windows

1. Open a terminal (e.g., Command Prompt or PowerShell) and navigate to the project directory:

   ```cmd
   cd \path\to\task-scheduler
   ```

2. Create the required directories for object files and binaries:

   ```cmd
   mkdir obj bin
   ```

3. Compile the source files manually using the following commands:

   ```cmd
   g++ -std=c++20 -Wall -g -c DHeap.cpp -o obj/DHeap.o
   g++ -std=c++20 -Wall -g -c Task.cpp -o obj/Task.o
   g++ -std=c++20 -Wall -g -c Testbench.cpp -o obj/Testbench.o
   g++ -std=c++20 -Wall -g -o bin/testbench obj/DHeap.o obj/Task.o obj/Testbench.o
   ```

4. Run the testbench:
   ```cmd
   .\bin\testbench.exe
   ```

### Notes

- The `make clean` command removes all previously compiled files and binaries (macOS/Linux only).
- The `make test` command compiles the project and generates the `testbench` binary in the `bin` directory (macOS/Linux only).
- Ensure the `tasks.csv` file is in the same directory as the executable to load and save tasks properly.

### Troubleshooting

- If you encounter issues with `make`, ensure it is installed and properly configured in your system's PATH (macOS/Linux).
- For Windows users, consider using a Unix-like environment such as Git Bash or WSL (Windows Subsystem for Linux) for better compatibility with `make`.

Enjoy using the Task Scheduler!
