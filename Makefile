SRCS = ./libft/printf/ft_printf.c \
       ./libft/printf/ft_printf_hex.c \
       ./libft/printf/ft_printf_pointer.c \
       ./libft/printf/ft_printf_nbr.c \
       ./libft/printf/ft_printf_parser.c \
       ./libft/printf/ft_printf_str.c \
       push_swap.c \
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
       ./libft/ft_isalpha.c ./libft/ft_isprint.c ./libft/ft_memcmp.c  ./libft/ft_putchar_fd.c ./libft/ft_split.c \
	./libft/ft_strlcat.c ./libft/ft_strncmp.c ./libft/ft_substr.c ./libft/ft_atoi.c ./libft/ft_isalnum.c \
	./libft/ft_itoa.c ./libft/ft_memcpy.c  ./libft/ft_putendl_fd.c ./libft/ft_strchr.c  ./libft/ft_strlcpy.c \
	./libft/ft_strnstr.c ./libft/ft_tolower.c ./libft/ft_bzero.c   ./libft/ft_isascii.c \
	./libft/ft_memmove.c ./libft/ft_putnbr_fd.c  ./libft/ft_strdup.c  ./libft/ft_strlen.c  ./libft/ft_strrchr.c \
	./libft/ft_toupper.c ./libft/ft_calloc.c  ./libft/ft_isdigit.c ./libft/ft_memchr.c  ./libft/ft_memset.c  \
	./libft/ft_putstr_fd.c  ./libft/ft_strjoin.c ./libft/ft_strmapi.c ./libft/ft_strtrim.c ./libft/ft_striteri.c \
	./libft/ft_lstadd_back_bonus.c ./libft/ft_lstadd_front_bonus.c ./libft/ft_lstclear_bonus.c \
	./libft/ft_lstdelone_bonus.c ./libft/ft_lstiter_bonus.c ./libft/ft_lstlast_bonus.c \
	./libft/ft_lstmap_bonus.c ./libft/ft_lstnew_bonus.c ./libft/ft_lstsize_bonus.c ./libft/ft_atol.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = make -C libft

PRINTF = make -C libft/printf

NAME = push_swap

all: $(NAME)

libs:
	$(LIBFT)
	$(PRINTF)

$(NAME): $(OBJS) libs 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft -Llibft/printf -lftprintf

%.o: %.c push_swap.h ./libft/libft.h ./libft/printf/ft_printf.h
	echo "Building $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	echo "Removing all object files..."
	$(RM) $(OBJS)
	$(LIBFT) clean
	$(PRINTF) clean

fclean: clean
	@echo "Removing executable and libs..."
	$(RM) $(NAME)
	$(LIBFT) fclean
	$(PRINTF) fclean

re: fclean all

.PHONY: clean

.SILENT: