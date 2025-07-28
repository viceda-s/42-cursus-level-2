# 🕹️ so_long

![Score Badge](https://img.shields.io/badge/Score-125%2F100-brightgreen)

## Description

**so_long** is a 2D game project developed for the 42 curriculum, which I was inspired by classic Bomberman (without bombs or destructible objects—yet!) and with 16-bit graphics reminiscent of the Super Nintendo era. The project’s goal is to collect all collectibles on a map and reach the exit, while avoiding enemies and obstacles. The focus is on event-driven graphics programming with **MiniLibX**, careful memory management and creating a rewarding retro gameplay experience.

## Installation / Usage

1. Clone the repository:

```bash
git clone https://github.com/viceda-s/42-cursus-level-2.git
cd so_long
```

2. Compile:

```bash
make
```

3. Run the game with your chosen map:

```bash
./so_long [map_file.ber]
```

Example:

```bash
./so_long maps/42.ber
```


## How It Works

The game takes a `.ber` map file as input and creates a colorful, tile-based world:

- **Player Controls**: Move up, down, left, or right (WASD/Arrow keys).
- **Objectives**: Collect all collectibles to open the exit, avoid enemies, and reach the exit to win.
- **Enemies**: Patrolling AI can end your game upon contact.
- **Visuals**: 16-bit styled graphics inspired by the SNES, featuring custom sprites and animated tiles.
- **UI**: Current movement count is shown in real time on screen.

| Key | Action |
| :-- | :-- |
| W / ↑ Arrow | Move Up |
| S / ↓ Arrow | Move Down |
| A / ← Arrow | Move Left |
| D / → Arrow | Move Right |
| ESC | Exit the game |

*Maps must be surrounded by walls, contain at least one player, exit and collectible for validity.*

## Extras / Bonus

- Animated tiles, sprite-based enemies, and particle effects for retro ambiance.
- Enemy patrol routes and enhanced game-over logic.
- Smooth movement and dynamic UI updates.
- Highly modular code and strict memory leak prevention.
- Custom map loader and validator.
- Optimized for larger, complex maps.
- Easily modifiable assets for new levels and visuals.


## Testing

- Run existing maps or create your own in the `maps/` folder.
- Example:

```bash
./so_long maps/level_!.ber
```

- Ensure maps are rectangular, bordered by walls, and meet requirements (one player, one exit, at least one collectible).
- Failure and edge states (invalid map, collisions) are handled with clear error messages or game-over screens.


## Notes

- Developed in C using **MiniLibX** for graphics (42's school library).
- 16-bit graphics inspired by the Super Nintendo (SNES) era.
- No bombs or destructible objects in this version (extensible for future updates).
