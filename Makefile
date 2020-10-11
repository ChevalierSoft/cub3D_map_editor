NAME	= map_editor
FLAGS	= -Wextra -Wall -Werror
LIB		= -lmlx -lXext -lX11
INC		= ./includes/map_editor.h

ifeq ($(UNAME_S),Darwin)
    OS = -D OSX
else
	OS = -D LINUX
endif

SRCS	= $(addprefix srcs/,\
main.c \
app_init.c \
quit.c \
default.c \
utils.c \
save_map.c \
azerty_to_qwerty_linux.c \
)

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -O3 -o $(NAME) $(OBJS) $(FLAGS) -L. $(LIB)

%.o : %.c
	gcc -O3 -o $(NAME) $(FLAGS) -c -o $@ $< -I.${INC} -L. $(LIB) $(OS)

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
