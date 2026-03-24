    # so_long

    2D tile game using MiniLibX: parse a `.ber` map, validate it, collect all items, then reach the exit.

    ## Architecture
    - Map: parser validates rectangle, walls, counts (1 exit, 1 player, >=1 collectible), and allowed chars.
    - Path check: flood-fill/BFS to ensure every collectible and the exit are reachable from the player start.
    - Render: MiniLibX window, sprites per tile; hooks for key input (WASD/arrow) and window close.
    - State: tracks player position, steps, remaining collectibles, and exits when win/lose.

    ## Build & Run
    - Requires MiniLibX dependencies (X11 on Linux, or macOS frameworks per 42 setup).
    - `make` → builds `so_long`.
    - Run: `./so_long maps/map.ber`.

    ## Technical Notes
    - Input handling uses event hooks; keep redraws minimal (only dirty tiles if optimized).
    - Ensure graceful cleanup: destroy images, window, and free map buffers on exit or errors.
    - Map charset typically: `01CEP` (wall, floor, collectible, exit, player).

    ## Testing Ideas
    - Invalid maps: holes in walls, multiple players/exits, unreachable collectibles, non-rectangular rows.
    - Movement: step counter increments once per valid move; win triggers only after all collectibles gathered.

    ## Author
    Oualid Obbad (@oualidobbad)