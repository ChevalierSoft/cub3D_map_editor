GRN     = \033[32;01m
RST     = \033[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "Deleting libmlx objects\c"
	@rm -f $(OBJ) *~
	@rm -f mlx_app
	@echo "\t\t$(GRN)[OK]$(RST)"

fclean: clean
	@echo "Deleting libmlx.a\c"
	@rm -f $(NOM)
	@echo "\t\t$(GRN)[OK]$(RST)"

re: clean all
