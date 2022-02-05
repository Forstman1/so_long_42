CFILES  = so_long.c so_long_utils.c movingfunc.c checkingwalls.c puttingimages.c
CBONUS  = so_long_utils_bonus.c moving.c moving_utils.c checkingwalls_bonus.c draw.c animations.c animations_utils.c draw_utils.c

OFILES	= $(CFILES:.c=.o)
OBONUS	= $(CBONUS:.c=.o)

CC	= gcc
Flags = -Wall -Werror -Wall
NAME = so_long.a


all : $(NAME)

$(NAME) : $(OFILES) so_long.h
	@ar -r $(NAME) $(OFILES)
	@$(CC) so_long.c so_long.a libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o so_long
	@echo "so_long been created"
	@./so_long fd_mandatory.ber

%.o:%.c so_long.h libft.a
	@$(CC) -o $@ -c $<
	@echo "$@ been created"

clean:
	@rm -f $(OFILES) $(OBONUS) 

fclean:	clean
	@rm -f  $(NAME) 

re : fclean all

bonus : $(OBONUS) so_long_bonus.h
	@ar -r $(NAME) $(OBONUS)
	@$(CC) $(Flags) so_long_bonus.c so_long.a libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o so_long_bonus
	@echo "executing bonus"
	@./so_long_bonus fd_bonus.ber