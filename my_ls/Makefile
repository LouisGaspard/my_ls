##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

NAME	=	my_ls

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/main.c 			\
		./src/analyse_av.c 		\
		./src/check_av.c 		\
		./src/init_struct.c 		\
		./src/fill_arg.c 		\
		./src/print_group.c 		\
		./src/print_right.c 		\
		./src/print_size.c 		\
		./src/print_time.c 		\
		./src/print_type.c 		\
		./src/print_link.c 		\
		./src/print_user.c 		\
		./src/my_ls_option.c 		\
		./src/my_ls_utils.c 		\
		./src/my_ls_recursive.c 	\
		./src/my_ls_l_recursive.c	\
		./src/my_ls_inverse.c		\
		./src/my_ls_t.c			\
		./src/my_ls_d.c			\
		./src/my_total.c 		\
		./src/utils.c 			\
		./src/my_ls.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I ./include/

CFLAGS	+=	-W -Wall -Wextra

LIB	=	-L ./lib/ -lmy

all: $(NAME)

$(NAME): $(OBJS)
	 make -C ./lib/my/
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LIB)

clean:
	make clean -C ./lib/my/
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./lib/libmy.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
