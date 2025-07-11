# so_long

A simple 2D game built with [MLX42]

## 📋 Project Overview

**so_long** is a small graphical game where the player must collect all collectibles and reach the exit on a map defined in a `.ber` file.  
The project demonstrates file parsing, map validation, pathfinding, resource management, and basic graphics programming.

---

## 🚀 Features

- Reads and validates `.ber` map files
- Renders a tile-based map using MLX42
- Player movement with WASD keys
- Collectibles and exit logic
- Move counter displayed in the terminal
- Robust error handling and resource cleanup

## 🗺️ Map Format

- The map is a rectangular grid of characters:
  - `1` = Wall
  - `0` = Floor
  - `P` = Player start (exactly one)
  - `E` = Exit (exactly one)
  - `C` = Collectible (at least one)
- The map must be surrounded by walls and have a valid path from the player to all collectibles and the exit.

**Example:**
```
11111
1P0C1
100E1
11111
```

---

## 🕹️ Controls

- **W/A/S/D**: Move up/left/down/right
- **ESC**: Exit the game

---

**Build the project:**
   ```sh
   make
   ```

   This will also build the required `libft` and `MLX42` libraries.

**Run the game:**
   ```sh
   ./so_long maps/minimal_map.ber
   ```

---

## Authors

**lsurco-t
	