# ATM

This is a simple **ATM Simulation** program written in C. It simulates basic functionalities of an ATM such as checking balance, withdrawing money, depositing money, and exiting. The program is designed for educational purposes, allowing users to interact with a simulated ATM using basic command-line inputs.

## Features

- **Check Balance**: Users can view their current balance at any time.
- **Deposit Money**: Allows users to add money to their account.
- **Withdraw Money**: Users can withdraw money if they have sufficient balance.
- **Exit**: Safely exits the program after finishing operations.

## Usage

**ATM Menu**: 
   - After launching, the program will display a menu with options:
     ```
     Welcome to MB ATM
     1. Check Balance
     2. Deposit Money
     3. Withdraw Money
     4. Exit
     ```
**Interacting with the ATM**:
   - The user will be prompted to select an option by entering the corresponding number (e.g., "1" for checking balance).
   - The program will perform the requested action (like updating balance after a deposit) and then return to the main menu until the user selects "Exit."

## Code Structure

- **atm.c**: The main source code file that includes all functionalities such as user input, balance checking, deposits, and withdrawals.

The user can enter their choice (1, 2, 3, or 4) to perform actions. After each action, the menu will be shown again until the user chooses to exit.

## Personal Reflection

### Why I Built This Application
I created this ATM Simulation program as part of a learning project to strengthen my understanding of C programming, especially working with user input and implementing control flow. It provided a hands-on way to practice essential programming concepts like loops, conditionals, and functions, while mimicking a real-world use case.

### What I Learned
Through building this program, I gained a better grasp of modular code structure by dividing the program into clear, distinct functions like checking balance, depositing, and withdrawing. I also learned how to handle user inputs and how to avoid common errors such as entering invalid amounts or handling negative balances. Debugging and managing edge cases (e.g., trying to withdraw more than the available balance) was an important lesson in attention to detail.
