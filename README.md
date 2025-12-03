# NamitGarg-C-Assignment.2
## About This Project

This is my version of the console game we had to modify for Assignment 2.  
The original game was very simple with only one obstacle, no score, no lives, and no restart option.  
I improved it and added features to make it more fun and playable.  

Now it feels like a small, interactive console game with proper gameplay mechanics.

---

## What the Game Has Now

Here are the improvements I made:

### ✔ Player Movement
The player (`Y`) can move left and right using:
- Left Arrow / `A` → move left  
- Right Arrow / `D` → move right  

### ✔ Score System
Each obstacle successfully avoided increases your **score** by 1.

### ✔ Lives System
The player starts with **3 lives**.  
Colliding with an obstacle reduces lives by 1.  
The game ends when all lives are lost.

### ✔ Restart Option
After Game Over, the player can:
- Press `R, r` → Restart the game without closing the program  
- Press any other key → Exit the game  

### ✔ Continuous Obstacles
Obstacles (`#`) appear continuously in random lanes, increasing the challenge.

### ✔ Sound Effects
- Background music plays during gameplay (`bg.wav`)  
- Collision sound plays when the player hits an obstacle (`impact.wav`)  

---

## How to Play

Controls:

| Action | Keys |
|--------|------|
| Move Left | Left Arrow / `A` |
| Move Right | Right Arrow / `D` |
| Restart Game (after Game Over) | `R` |
| Exit Game (after Game Over) | Any other key |

Gameplay:

1. Move your player left and right to avoid falling obstacles.  
2. Each obstacle avoided increases your score.  
3. Colliding with an obstacle decreases your lives.  
4. When all lives are lost, the Game Over screen appears:  

5. You can restart or exit as desired.

---

## Modifications I Added (as per assignment)

1. Score system for tracking performance.  
2. 3 lives system for extended gameplay.  
3. Restart option after Game Over without closing the program.  
4. Continuous obstacle movement with random lanes.  
5. Clean Game Over screen showing only final score and options.  

---

## What I Learned

While making this game, I learned and practiced:

- Handling keyboard input using `_kbhit()` and `getch()`  
- Using Windows console functions to move the cursor (`SetConsoleCursorPosition`)  
- Playing background and collision sounds with `PlaySound()`  
- Implementing a game loop with real-time input and updates  
- Collision detection and game state management  
- Resetting game state for restart without exiting the program  
- Improving console visuals using ASCII characters  

---

### Made by: Namit Garg
### Section: AD
### Roll no.: 12515001002 (38)
### B.Tech CSE – Assignment 2
