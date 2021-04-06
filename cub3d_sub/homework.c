#include <stdio.h>
#include <mlx.h>

# define IMG_HEIGHT 300
# define IMG_WIDTH 500

typedef struct  s_img
{
        void    *img_ptr;
        char    *addr;
        int     line_length;
        int     bits_per_pixel;
        int     endian;
}               t_img;

typedef struct  s_mlx
{
        void    *mlx_ptr;
        void    *win;
}                               t_mlx;

int     main(void)
{
        t_mlx   mlx;
        t_img   img;
        int     x;
        int     y;

        mlx.mlx_ptr = mlx_init();
        mlx.win = mlx_new_window(mlx.mlx_ptr, 1680, 997, "hyunwlee cub3d");
        img.img_ptr = mlx_new_image(mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
        img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
        // img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
        //여기서 (int *)를 안해주고 img.data가 void *이면 밑에 배열값들을 참조할 때 다 4를 곱해야한다.
        //그렇기 때문에 int *로 캐스팅해주는편이 좋다고 한다.

        // while (++count_h < IMG_HEIGHT)
        // x가로 y 높이
        char *dst;
        int color = 0xFF0000;
        y = -1;
        while (++y < IMG_HEIGHT)
        {
            // img.addr[y * img.line_length] = 0xFF0000;
            x = 200;
            *(unsigned int *)(img.addr + (y * img.line_length + img.bits_per_pixel / 8 * x)) = 0xFF0000;


            // printf("도는 거냐?");
            // while (++x < IMG_WIDTH)
            // {
            //     printf("빙글 ");
            //     dst = img.addr + (y * img.line_length + img.bits_per_pixel / 8 * x);
            //     *(unsigned int *)dst = color;
            // }
            // puts("");
        }
        mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
        mlx_loop(mlx.mlx_ptr);
        return (0);
}