NAME = minirt.a
AR = ar rcs
LMLX_FLAG= -L ./minilibx_opengl_20191021 libmlx.a -L ./minilibx_mms_20200219 libmlx.dylib -framework OpenGL -framework AppKit
FLAGS =  
SRC  =	srcs/intersection.c\
		srcs/ray.c\
		srcs/plan.c\
		srcs/sphere.c\
		srcs/triangle.c\
		srcs/square.c\
		srcs/cylinder.c\
		srcs/vectors.c\
		srcs/operations.c\
		srcs/camera.c_and_ray.c\
		srcs/color.c\
		srcs/light_intensity.c\
		srcs/main_sphere.c\
		srcs/shadow_intersection.c\
		srcs/draw.c\
		srcs/keyboard_mouse.c\
		srcs/bmp.c\
		srcs/ft_atof.c\
		\
		parsing/fill_ambiant.c\
		parsing/fill_light.c \
		parsing/list_of_element.c\
		parsing/fill_camera.c\
		parsing/fill_resolution.c\
		parsing/fill_struct.c\
		parsing/fill_plan.c\
		parsing/fill_sphere.c\
		parsing/fill_square.c\
		parsing/fill_cylindre.c\
		parsing/fill_triangle.c\
		parsing/get_next_line_utils_bonus.c\
		parsing/get_next_line_bonus.c\
		parsing/ft_split.c\
		parsing/parsing.c\
		parsing/ft_white_spaces.c\
		parsing/ft_isdigit.c\
		parsing/coordinate_checkers.c\
		parsing/parsing_check.c\
		parsing/check_struct1.c\
		parsing/check_struct2.c\
		parsing/check_struct3.c\
		parsing/error_message.c\
		parsing/general_check.c\
		parsing/parse_translation.c\
		parsing/parse_rotation.c\



HEADERS = ./includes/
OBJECT = $(SRC:.c=.o)
MLX_MMS = ./minilibx_mms_20200219
MLX_OGL = ./minilibx_opengl_20191021 

$(NAME): $(OBJECT)
	make -sC $(MLX_MMS) 
	make -sC $(MLX_OGL) 
	@$(AR) $(NAME) $(OBJECT)
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@gcc $(FLAGS)  -I /usr/local/include -L ./minilibx_opengl_20191021 libmlx.dylib -lmlx -framework OpenGl -framework AppKit  minirt.a

%.o: %.c
	@gcc $(FLAGS) -I $(HEADERS)  -o $@ -c $<

all: $(NAME) 
	
clean:
	@rm -f $(OBJECT)
	@make clean -sC $(MLX_MMS) 
	@make clean -sC $(MLX_OGL) 
	@rm -f libmlx.dylib
fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)