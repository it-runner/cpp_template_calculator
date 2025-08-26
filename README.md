... 

# 🧮 🖩 ___ Easy C++ Template Calculator ___ 🖩 🧮

A simple, console-based calculator written in **C++98** using
**templates**.
It supports basic arithmetic operations on multiple data types (`int`,
`float`, `double`) and includes some fun extras like ASCII art and a
lighthearted joke option.

...

## 🥳🥳🥳  I wrote this program for fun while learning templates in C++.  🥳🥳🥳
...

------------------------------------------------------------------------

## ✨ Features

-   Template-based calculator class (`Calculator<T>`) supporting:
    -   **Addition**
    -   **Subtraction**
    -   **Multiplication**
    -   **Division** (with error handling for division by zero /
        overflow)
-   Works with **integers**, **floats**, and **doubles**
-   Input validation (handles invalid user input gracefully)
-   Returns the result for float/double with 6 decimal places
-   **ANSI escape codes** for colored output and clear screen
    functionality
-   **Cross-platform support**
    -   ANSI codes are automatically enabled on Windows 10+
    -   Works on Linux/macOS terminals
-   Easter egg: *"How many programmers does it take to change a
    lightbulb?"* option prints ASCII art picture.

------------------------------------------------------------------------

## 📂 Project Structure

    ├── Calculator.hpp        # Template class declaration
    ├── Calculator.tpp        # Template class implementation
    ├── handleDataType.hpp    # Function template for handling calculations by type
    ├── handleDataType.tpp
    ├── helperFunctions.hpp   # Utility functions (menu, welcome screen, clear screen, etc.)
    ├── helperFunctions.cpp
    ├── printASCIIArt.hpp     # Fun ASCII art picture
    ├── printASCIIArt.cpp
    ├── main.cpp              # Entry point
    ├── Makefile              # Build configuration

------------------------------------------------------------------------

## ⚙️ Compilation

To build the project, simply run:

``` bash
make
```

This will compile the program with: - `g++` - Flags:
`-Wall -Wextra -Werror -std=c++98 -pedantic`

To clean up object files:

``` bash
make clean
```

To remove the executable:

``` bash
make fclean
```

To rebuild everything:

``` bash
make re
```

------------------------------------------------------------------------

## ▶️ Usage

Run the compiled program:

``` bash
./Calculator
```

You will see:

1.  **Welcome screen** with ASCII calculator.

2.  **Data type selection** menu:

    -   `1` → Integer
    -   `2` → Float
    -   `3` → Double
    -   `4` → Exit

3.  **Operation selection** menu:

    -   `1` → Add
    -   `2` → Subtract
    -   `3` → Multiply
    -   `4` → Divide
    -   `5` → Quit
    -   `6` → Joke (ASCII art)

4.  **Enter two numbers** → Result is displayed.

5.  **Prompt to continue** or quit.

------------------------------------------------------------------------

## 🔒 Error Handling

-   Invalid menu input → User is prompted again.
-   Invalid number input → User is asked to re-enter.
-   Integer division by zero → Displays an error message instead of crashing.
-   Overflow/underflow in arithmetic → Exception is caught and reported.

------------------------------------------------------------------------

## 📝 Example Run

     ____    ### Welcome to the easy C++ Template Calculator! ###    ____

     What type of data will be calculated?

     1. Integer
     2. Float
     3. Double
     4. Exit

     Enter your choice: 1

     ------------------------------------------
       ###    Operations menu:    ###
     ------------------------------------------

     1. ADD
     2. SUBTRACT
     3. MULTIPLY
     4. DIVIDE
     5. QUIT
     6. How many programmers does it take to change a lightbulb?

     Enter operation number (1-6): 1

     Enter the first integer: 7
     Enter the second integer: 5

    		Addition
	---- 

					7 + 5 = 12

	---- 


------------------------------------------------------------------------

## 🎉 Fun Fact

If you choose option `6` in the operations menu, the program prints an
ASCII art picture and a programmer joke.
