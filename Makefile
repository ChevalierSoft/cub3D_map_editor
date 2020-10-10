NAME	= map_editor
FLAGS	= -Wextra -Wall -Werror
LIB		= -lmlx -lXext -lX11

SRCS	= $(addprefix srcs/,\
main.c \
app_init.c \
quit.c \
default.c \
utils.c \
ft_save_map.c \
)

OBJS	= ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -O3 -o $(NAME) $(OBJS) $(FLAGS) -L. $(LIB)

lib_mlx :
	@echo "compiling  minilibx \c"
	@make -C minilibx-linux
	@cp ./minilibx-linux/libmlx.a .
	@echo "\t\t done"

clean :
	/bin/rm -rf $(OBJS)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all

# requirment to install minilibx on linux :
# sudo apt-get install gcc make xorg libxext-dev libbsd-dev
