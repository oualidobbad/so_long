# so_long

2D tile-based game with MiniLibX: load a `.ber` map, validate it, render the world, collect all items, and exit.

## Project Overview
- What it does: parses a custom map, ensures validity/reachability, renders tiles, and lets the player move to collect `C` before opening the exit `E`.
- Use cases: intro to graphics/event loops, map parsing, and flood-fill reachability.
- Problem solved: ensures maps are well-formed and winnable before play.

## Architecture & Design
- Data: linked list `t_node{ line, next }` holds map rows; `t_data` aggregates MLX handles, textures, counts, and player/exit coords (so_long.h).
- Validation pipeline (check_map.c):
  - `check_len`: all rows same length (rectangular).
  - `check_caracter`: counts `E/P/C` and forbids unknown chars.
  - `check_wall`: borders must be walls.
  - `flood_fill`: reachability of all collectibles/exit from player start (using a map copy).
- Rendering: `put_img` draws the map with MLX; textures for floor, walls, collectibles, exit states, and player facings.
- Input: `key_hook` handles WASD/ESC; updates map state, collectibles count, and opens the door when `C` is depleted.

## Core Concepts (with code)
- Extension guard:
```c
// so_long.c
int check_ber(char *str, char *ber) { /* scans for ".ber" suffix, else Error */ }
```
- Reachability via flood fill:
```c
// check_map.c
copy = map_copy(map);
return_coordinates(copy, data);
flood_fill(copy, data->row_player, data->colom_player);
if (check_caracter_after_flood_fill(copy) == 0) exit(0);
```
- Movement and collection:
```c
// hooks.c
if (ft_list_at(game->head, i)->line[j] == 'C') { game->c--; /* mark collected */ }
if (game->c <= 0) mlx_put_image_to_window(..., game->door_open, ...);
move_player_helper(...); // updates position + sprite
```

## Code Walkthrough
1) `main`: validate args + `.ber`, read map (get_next_line), build linked list.
2) `check_map`: copy map, run flood-fill, validate counts/walls/rectangularity.
3) Init MLX: window sized by rows/cols; load/draw sprites via `put_img`.
4) Event loop: `key_hook` for movement, `handle_close` for window X, render updates per move and print step count.

## Installation & Setup
- Requires MiniLibX (Linux X11 headers/libs). Adjust include path in so_long.h if needed.
- Build: `make` (mandatory build).
- Run: `./so_long maps/map.ber`.

## Usage Guide
- Controls: W/A/S/D to move, ESC to quit. Collect all `C` then step on `E` to win.
- Map charset: `1` wall, `0` floor, `C` collectible, `E` exit, `P` player start.

## Technical Deep Dive
- Flood fill ensures every `C`/`E` is reachable; uses list copy to avoid mutating the live map.
- Rendering updates only affected tiles when moving (overwrites old player tile with floor, redraws door state, then draws player orientation).
- Bounds/rect checks prevent segfaults from jagged rows; wall check ensures enclosure.

## Improvements & Future Work
- Add sprite loading error handling and central cleanup of MLX resources.
- Animate player/collectibles or add basic enemies.
- Add a bonus minimap and move counter overlay.

## Author
Oualid Obbad (@oualidobbad)