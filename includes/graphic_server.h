/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_server.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:17:37 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:39:49 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_SERVER_H
# define GRAPHIC_SERVER_H

# include <so_long.h>

# define WIN_TITLE			"so_long"
# define KEY_ESC			53
# define KEY_ARROW_TOP		126
# define KEY_ARROW_BOT		125
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define KEY_NUM_PAD_1		83
# define KEY_NUM_PAD_0		82
# define KEY_TILD			50
# define KEY_MINUS			27
# define KEY_PLUS			24
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				22
# define KEY_6				23
# define KEY_7				24
# define KEY_8				25
# define KEY_9				26
# define KEY_0				27
# define KEY_OUI			41
# define KEY_NON			39
# define RED_BUTTON			17
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_O				31
# define KEY_L				37
# define KEY_SHIFT			257
# define KEY_SPACE			49
# define KEY_TAB			48

/*
** # define MAX_SCREEN_X		1024
** # define MAX_SCREEN_Y		780
*/

# define MAX_SCREEN_X		3072
# define MAX_SCREEN_Y		1920
# define SIZE_SCREEN_X		1536
# define SIZE_SCREEN_Y		960

# define CHECK_STR			"01PCE"
# define CHAR_EMPTY			'0'
# define CHAR_WALL			'1'
# define CHAR_PLAYER		'P'
# define CHAR_COLLECT		'C'
# define CHAR_EXIT			'E'

# define COLOR_EMPTY		0x00636D83
# define COLOR_WALL			0x00101010
# define COLOR_COLLECT		0x00D19A66
# define COLOR_PLAYER		0x0000F000
# define COLOR_EXIT			0x00F00000

typedef struct s_img
{
	void			*id;
	unsigned int	*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_img;
typedef struct s_tile
{
	char			type;
	unsigned int	color;
	int				sx;
	int				sy;
	int				x;
	int				y;
	t_img			img;
}					t_tile;
typedef struct s_win
{
	void			*id;
	int				sx;
	int				sy;
}					t_win;
typedef struct s_mlx
{
	void			*id;
	t_win			win;
	int				bmp_on;
}					t_mlx;
extern t_mlx		g_mlx;
#endif
