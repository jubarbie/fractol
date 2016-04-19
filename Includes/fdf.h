/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 10:48:32 by jubarbie          #+#    #+#             */
/*   Updated: 2016/04/19 09:12:33 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MLX param->mlx
# define WIN param->win
# define POSX param->pos_x
# define POSY param->pos_y
# define WIN_X param->win_x
# define WIN_Y param->win_y
# define WIDTH param->width
# define HEIGHT param->height
# define BPP param->bpp
# define SIZELINE param->sizeline
# define ENDIAN param->endian
# define IMG param->img
# define IMG_ADDR param->img_addr
# define ZOOM param->zoom

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_x;
	int		win_y;
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*img_addr;
	float	zoom;
}				t_param;

typedef	struct	s_pix
{
	int				x;
	int				y;
	unsigned int	color;
}				t_pix;

t_param			*init_param(int size_x, int size_y, char *title);
void			white_screen(t_param *param);
void			init_pos(t_param *param);
void			img_put_pixel(t_param *param, int x, int y, unsigned int color);
int				create_img(t_param *param);

#endif
