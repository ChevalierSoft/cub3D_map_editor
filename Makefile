NAME		= map_editor
FLAGS		= -g -Wextra -Wall -Werror
LIB_LINUX	= -lmlx -lXext -lX11
LIB_OSX_GPU	= libmlx.a -lmlx -framework OpenGL -framework AppKit -lz
INC			= ./includes/map_editor.h
GRN     	= \033[36m
RST     	= \033[0m

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    OS		= -D OSX
	LIB		= $(LIB_OSX_GPU)

else
	OS		= -D LINUX
	LIB		= $(LIB_LINUX)
endif

SRCS		= $(addprefix srcs/,\
main.c \
app_init.c \
quit.c \
default.c \
utils.c \
save_map.c \
get_char_from_key.c \
get_char_from_key_osx_rebind.c \
display.c \
default_mouse.c \
default_key.c \
)

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : make_lib $(OBJS)
	@gcc -O3 -o $(NAME) $(OBJS) $(FLAGS) -L. $(LIB)
	@echo "$(GRN)map_editor ready to use$(RST)"

%.o : %.c
	@gcc -O3 -o $(NAME) $(FLAGS) -c -o $@ $< -I.${INC}  $(OS)

make_lib :
	@if [ $(UNAME_S) = Darwin ]; then \
		make -C minilibx_opengl ; \
		cp ./minilibx_opengl/libmlx.a .; \
	else \
		make -C minilibx-linux ; \
		cp ./minilibx-linux/libmlx.a .; \
	fi

lib_mlx_linux :
	@echo "compiling  minilibx \c"
	@make -C minilibx-linux
	@cp ./minilibx-linux/libmlx_Linux.a .
	@echo "\t\t done"

lib_mlx_osx :
	@echo "compiling  minilibx \c"
	@make -C minilibx_opengl
	@cp ./minilibx_opengl/libmlx.a .
	@echo "\t\t done"

clean :
	@/bin/rm -rf $(OBJS)

fclean : clean
	@/bin/rm -rf $(NAME)

re : fclean all

.PHONY : re all $(NAME) clean fclean lib_mlx_linux lib_mlx_osx

# requirment to install minilibx on linux :
# sudo apt-get install gcc make xorg libxext-dev libbsd-dev
