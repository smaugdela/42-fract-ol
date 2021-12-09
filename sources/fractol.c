/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:27:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/12/09 16:52:55 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void ft_error(const char* ft_name)
{
    ft_putstr_fd("Error: ", 2);
    perror(ft_name);
    exit(EXIT_FAILURE);
}

int main(void)
{
    void    *server_ptr;
    void    *win_ptr;

    server_ptr = mlx_init();
    if (server_ptr == NULL)
        ft_error("mlx_init");
    win_ptr = mlx_new_window(server_ptr, 
        WIN_WIDTH, WIN_HEIGHT, "Hello World!");
    if (win_ptr == NULL)
    {
        free(server_ptr);
        ft_error("mlx_new_window");
    }


    mlx_destroy_window(server_ptr, win_ptr);
    mlx_destroy_display(server_ptr);
    free(server_ptr);
    return (0);
}
