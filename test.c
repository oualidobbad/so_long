// #include "so_long.h"
// #include <unistd.h>

// typedef struct s_vars {
//     void *mlx;
//     void *win;
// } t_vars;
// void handl_close(int keycode, t_vars *vars) {
	
//     mlx_destroy_window(vars->mlx, vars->win);
// 	exit (0);
// }

// int key(int key_code, t_vars *vars)
// {
// 	if (key_code == 65307)
// 		handl_close(key_code, vars);
//     else if (key_code)
// 	return (printf ("%d\n", key_code));
// }


// int main(void) {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 900, 800, "Hello world!"); 
//     mlx_hook(vars.win, 2, 1L<<0, key, &vars);
//     mlx_loop(vars.mlx); 

//     return (0);
// }

