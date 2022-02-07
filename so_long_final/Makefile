CFILES  = so_long.c so_long_utils.c movingfunc.c checkingwalls.c puttingimages.c so_long_utils2.c

CBONUS = so_long_bonus.c so_long_utils_bonus.c moving_bonus.c moving_utils_bonus.c checkingwallsbonus.c animations_bonus.c animations_utils_bonus.c draw_bonus.c draw_utils_bonus.c so_long_utils2_bonus.c

OFILES	= $(CFILES:%.c=%.o)

OBONUS = $(CBONUS:%.c=%.o)

CC	= gcc
Flags = -Wall -Werror -Wextra
NAME = so_long.a


all: $(NAME)

$(NAME) : $(OFILES)
	@ar -r $(NAME) $(OFILES)
	@$(CC) $(Flags) -g so_long.c so_long.a libft1/libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o so_long
	@echo "so_long.a been created"

%.o:%.c so_long.h so_long_bonus.h
	@$(CC) $(Flags) -o $@ -c $<

clean:
	@rm -f $(OFILES) $(OBONUS)

fclean:	clean
	@rm -f  $(NAME)

re : fclean all

bonus : fclean $(OBONUS)
	@ar -r $(NAME) $(OBONUS)
	@$(CC) $(Flags) so_long_bonus.c so_long.a libft1/libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o so_long_bonus

execute :
	@echo "executing mandatory"
	@./so_long fd.ber

executebonus :
	@echo "executing bonus"
	@./so_long_bonus fd_bonus.ber