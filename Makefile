CFILES  = get_next_line.c get_next_line_utils.c

OFILES	= $(CFILES:.c=.o)


CC	= gcc
NAME = solong.a


all : $(NAME)

$(NAME) : $(OFILES) get_next_line.h solong.h
	@ar -r $(NAME) $(OFILES)
	@echo "solong.a been created"

%.o:%.c get_next_line.h solong.h
	@$(CC) -o $@ -c $<
	@echo "$@ been created"