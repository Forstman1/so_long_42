CFILES  = so_long.c so_long_utils.c moving.c checkingwalls.c draw.c animations.c animations_utils.c draw_utils.c

OFILES	= $(CFILES:.c=.o)


CC	= gcc
Flags = -Wall -Werror -Wall
NAME = so_long.a


all : $(NAME)

$(NAME) : $(OFILES) so_long.h
	@ar -r $(NAME) $(OFILES)
	@echo "solong.a been created"

%.o:%.c so_long.h libft.a
	@$(CC) $(Flags) -o $@ -c $<
	@echo "$@ been created"

execute : so_long.c so_long.a libft.a so_long.h
	@$(CC) $(Flags) so_long.c so_long.a libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o output
	@echo "executing"
	@./output fd.ber