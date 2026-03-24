# so_long

## Description
2D tile-based game built with MiniLibX for the 42 curriculum.

## Features
- Map parsing/validation; collectibles and exit conditions.
- Player movement with simple rendering.

## Technologies Used
- C, MiniLibX, Makefile.

## Installation
- Ensure MiniLibX deps, then run `make`.

## Usage
- `./so_long maps/map.ber` to play a provided map.

## Example
- Move with arrow/WASD keys to collect items and exit.

## Technical Notes
- Map loader validates rectangular shape, walls, collectibles, exit, and player start; floods invalid maps.
- Rendering via MiniLibX 2D blits; key hooks drive player moves with step counting.
- Keep textures path-correct in .ber; maps must use only allowed characters (1/0/E/C/P).   

## Author
- Oualid Obbad (@oualidobbad)