CFILES  = ./so_long_mandatory/so_long.c ./so_long_mandatory/so_long_utils.c ./so_long_mandatory/movingfunc.c ./so_long_mandatory/checkingwalls.c ./so_long_mandatory/puttingimages.c ./so_long_mandatory/so_long_utils2.c

CBONUS = ./so_long_bonus/so_long_bonus.c ./so_long_bonus/so_long_utils_bonus.c ./so_long_bonus/moving_bonus.c ./so_long_bonus/moving_utils_bonus.c ./so_long_mandatory/checkingwalls.c ./so_long_bonus/animations_bonus.c ./so_long_bonus/animations_utils_bonus.c ./so_long_bonus/draw_bonus.c ./so_long_bonus/draw_utils_bonus.c ./so_long_bonus/so_long_utils2_bonus.c

OFILES	= $(CFILES:%.c=%.o)

OBONUS = $(CBONUS:%.c=%.o)

CC	= gcc
Flags = -Wall -Werror -Wextra
NAME = so_long.a


all: $(NAME)

$(NAME) : $(OFILES)
	@ar -r $(NAME) $(OFILES)
	@echo "solong.a been created"

%.o:%.c ./so_long_mandatory/so_long.h ./so_long_bonus/so_long_bonus.h
	@$(CC) $(Flags) -o $@ -c $<
	@echo "$@ been created"

clean:
	@rm -f $(OFILES) $(OBONUS) 

fclean:	clean
	@rm -f  $(NAME) 

re : fclean all

bonus : $(OBONUS)
	@ar -r $(NAME) $(OBONUS)

execute : so_long.a
	@$(CC) $(Flags) -g ./so_long_mandatory/so_long.c so_long.a ./so_long_mandatory/libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o so_long
	@echo "executing"
	@./so_long fd.ber

executebonus : so_long.a
	@$(CC) $(Flags) ./so_long_bonus/so_long_bonus.c so_long.a ./so_long_bonus/libft.a -L /Users/sahafid/Desktop/minilibx_mms_20200219 -lmlx -framework OpenGl -framework AppKit -o so_long
	@echo "executing"
	@./so_long fd.ber