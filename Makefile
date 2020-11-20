NAME = minirt.a
AR = ar rcs
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
		srcs/translation.c\
		srcs/keyboard_mouse.c\
		srcs/rotation.c\
		srcs/bmp.c\
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
		parsing/check_struct.c\
		parsing/error_message.c\
		parsing/general_check.c\
		parsing/parse_translation.c\
		parsing/parse_rotation.c\

	#gcc -Wall -Werror -Wextra -std=gnu99 -I. -g -lm -lGLEW -lglfw -lGL ${OBJS} minilibx/libmlx_Linux.a -o ${NAME}


HEADERS = ./includes/
OBJECT = $(SRC:.c=.o)

$(NAME): $(OBJECT)
	@$(AR) $(NAME) $(OBJECT)

%.o: %.c
	@gcc $(FLAGS) -I $(HEADERS)  -o $@ -c $<

all: $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)