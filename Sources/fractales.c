/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 15:02:13 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/14 17:18:51 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_calc(t_param *param)
{
	float tmp;

	tmp = Z_R;
	Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
	Z_I = 2 * Z_I * tmp + C_I;
}

void		julia(int posx, int posy, t_param *param)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			C_R = 0.285;
			C_I = 0.01;
			Z_R = (x - posx) / ZOOM + X1;
			Z_I = (y - posy) / ZOOM + Y1;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0
							| i * COLOR));
		}
	}
}

void		mandelbrot(int posx, int posy, t_param *param)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			C_R = (x - posx) / ZOOM + X1;
			C_I = (y - posy) / ZOOM + Y1;
			Z_R = 0;
			Z_I = 0;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i == ITER)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 |
							i * COLOR));
		}
	}
}

void		inc_coord(t_param *param)
{
	if (!(X == WIDTH - 1 && Y == HEIGHT - 1))
	{
		if (X == WIDTH - 1)
		{
			X = 0;
			Y++;
		}
		else
			X++;
	}
}

void		mandelbrot_cl(int x, int y, t_param *param)
{
	cl_platform_id			id_pltfrm;
	cl_uint					nb_pltfrm;
	cl_int					code_error;
	cl_device_id			id_dev;
	cl_uint					nb_dev;
	cl_context				ctxt;
	cl_context_properties	pr[3];
	cl_command_queue		q_exe;
	cl_program				prog;
	const char				*mandelbrot_calc = {
		"__kernel void mandel(__global t_param *param)\n"
		"{\n"
		"	int	x = get_global_id(0);\n"
		"	int	y = get_global_id(1);\n"
		"	C_R = (x - P_X) / ZOOM + X1;\n"
		"	C_I = (y - P_Y) / ZOOM + Y1;\n"
		"	Z_R = 0;\n"
		"	Z_I = 0;\n"
		"	i = -1;\n"
		"	while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)\n"
		"		fract_calc(param);\n"
		"	if (i == ITER)\n"
		"		img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0));\n"
		"	else\n"
		"		img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0 | i * COLOR));\n"
		"	inc_coord(param);\n"
		"}\n"
	};
	cl_kernel				kern;
	t_param					*paramData;
	cl_mem					param_buff;
	
	x++;
	y++;
	paramData = param;
	code_error = clGetPlatformIDs(1, &id_pltfrm, &nb_pltfrm);
	code_error = clGetDeviceIDs(id_pltfrm, CL_DEVICE_TYPE_ALL, 1, &id_dev, &nb_dev);
	pr[0] = (cl_context_properties)CL_CONTEXT_PLATFORM;
	pr[1] = (cl_context_properties)id_pltfrm;
	pr[2] = 0;
	ctxt = clCreateContext(pr, nb_dev, &id_dev, NULL, NULL, &code_error);
	q_exe = clCreateCommandQueue(ctxt, id_dev, 0, &code_error);
	prog = clCreateProgramWithSource(ctxt, 1, (const char **)&mandelbrot_calc, NULL, &code_error);
	code_error = clBuildProgram(prog, nb_dev, &id_dev, NULL, NULL, NULL);
	if (code_error != CL_SUCCESS)
	{
		char	logErrors[4096];
		size_t	len_log;

		clGetProgramBuildInfo(prog, id_dev, CL_PROGRAM_BUILD_LOG, sizeof(logErrors), logErrors, &len_log);
		printf("\n[IMPRESSION DU JOURNAL DE COMPILATION]\n\n");
		printf("%s\n\n", logErrors);
		printf("[FIN DU JOURNAL]\n\n");
		exit(EXIT_FAILURE);
	}
	param_buff = clCreateBuffer(ctxt, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(*param), param, &code_error);
	kern = clCreateKernel(prog, "mandel", &code_error);
	code_error = clSetKernelArg(kern, 0, sizeof(param_buff), &param_buff);
	size_t	dim[] = {WIDTH, HEIGHT, 0};
	code_error = clEnqueueNDRangeKernel(q_exe, kern, 1, NULL, dim, NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(q_exe, param_buff, CL_TRUE, 0, sizeof(param_buff), param, 0, NULL, NULL);
	clReleaseMemObject(param_buff);
	clReleaseProgram(prog);
	clReleaseKernel(kern);
	clReleaseCommandQueue(q_exe);
	clReleaseContext(ctxt);
}
