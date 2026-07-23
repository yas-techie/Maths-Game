# Math Quiz Game

A console-based Math Quiz game written in C++.

## Features

- Choose the number of questions
- Multiple difficulty levels:
  - Easy
  - Medium
  - Hard
  - Mixed
- Multiple operation types:
  - Addition
  - Subtraction
  - Multiplication
  - Division
  - Mixed operations
- Random question generation
- Answer checking
- Score tracking
- Pass/fail result display
- Console color feedback
- Replay option

## How It Works

The player chooses:

1. Number of questions
2. Question difficulty:
   - Easy
   - Medium
   - Hard
   - Mixed
3. Operation type:
   - Add
   - Subtract
   - Multiply
   - Divide
   - Mixed

The game generates random math questions based on the selected settings.

After each answer:
- A correct answer increases the score.
- A wrong answer displays the correct answer.
- The final result is calculated based on the player's score.

## Technologies Used

- C++
- Standard Library (`iostream`, `cstdlib`, `ctime`)

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/yas-techie/Maths-Game.git
cd Maths-game
```

### 2. Compile the program

```bash
g++ MathsGame.cpp -o MathsGame
```

### 3. Run the executable

**Windows:**
```bash
MathsGame.exe
```

**Linux/macOS:**
```bash
./MathsGame
```

## Download

If you don't want to compile the project yourself, you can download the latest Windows executable from the **Releases** page.
