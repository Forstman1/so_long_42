CFILES  = so_long.c so_long_utils.c movingfunc.c checkingwalls.c puttingimages.c

OFILES	= $(CFILES:.c=.o)


CC	= gcc
NAME = so_long.a


all : $(NAME)

$(NAME) : $(OFILES) so_long.h
	@ar -r $(NAME) $(OFILES)
	@echo "solong.a been created"

%.o:%.c so_long.h libft.a
	@$(CC) -o $@ -c $<
	@echo "$@ been created"

execute : so_long.c so_long.a libft.a so_long.h
	@$(CC) so_long.c so_long.a libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o output
	@echo "executing"
	@./output fd.ber