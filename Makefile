SRCS = push_swap.c \
       stack_methods_1.c \
	   stack_methods_2.c \
	   stack_methods_3.c \
       find_min.c \
	   parser.c \
	   check_sorted.c \
	   linked_list.c \
	   sort_stack.c \
	   big_sort.c \
	   algo_in.c \
	   optimise_out_1.c \
	   optimise_out_2.c \
	   index_cost.c \
	   convert_av.c \
	   help_sort_3.c \
	   calculate_target.c \
	   calc_cost.c \
	   move_nodes.c \
	   stack_methods_4.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = make -C libft

PRINTF = make -C libft/printf

NAME = push_swap

LIBFT_PATH = -Llibft
LIBFT_NAME = -lft  #-l adds lib to the beginning of the library name !

LIBFTPRINTF_PATH = -Llibft/printf
LIBFTPRINTF_NAME = -lftprintf

all: libs $(NAME)

$(NAME): $(OBJS) ./libft/libft.a ./libft/printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH) $(LIBFT_NAME) $(LIBFTPRINTF_PATH) $(LIBFTPRINTF_NAME)

libs:
	$(LIBFT)
	$(PRINTF)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(LIBFT) clean
	$(PRINTF) clean

fclean: clean
	$(RM) $(NAME)
	$(LIBFT) fclean
	$(PRINTF) fclean

re: fclean all

.PHONY: clean