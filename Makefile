CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
NAME    = libft.a

SRC_PATH    = srcs/
OBJS_PATH   = objs/
LIBFT_PATH  = libft/
GNL_PATH    = get_next_line/

LIBFT_SRCS  = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c
GNL_SRCS    = get_next_line.c \
			get_next_line_utils.c
LIBFT_OBJS  = $(addprefix $(OBJS_PATH)$(LIBFT_PATH), $(LIBFT_SRCS:.c=.o))
GNL_OBJS    = $(addprefix $(OBJS_PATH)$(GNL_PATH), $(GNL_SRCS:.c=.o))

GNL_H     = $(addprefix $(SRC_PATH), $(GNL_PATH))
GNL_ARGS  = -I./$(GNL_H)
INCS_ARGS = -I./includes

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: $(NAME)
	@echo "$(GREEN)$(NAME) DONE$(NONE)"

$(OBJS_PATH):
	@mkdir $@

$(OBJS_PATH)$(LIBFT_PATH): | $(OBJS_PATH)
	@mkdir $@

$(OBJS_PATH)$(GNL_PATH): | $(OBJS_PATH)
	@mkdir $@

$(NAME): $(OBJS_PATH)$(LIBFT_PATH) $(LIBFT_OBJS) $(OBJS_PATH)$(GNL_PATH) $(GNL_OBJS)
	@ar rc $(NAME) $(LIBFT_OBJS) $(GNL_OBJS)
	@echo "Creating $@..."

$(OBJS_PATH)$(LIBFT_PATH)%.o: $(SRC_PATH)$(LIBFT_PATH)%.c
	@gcc $(CFLAGS) $(INCS_ARGS) -o $@ -c $<
	@echo "Creating $@..."

$(OBJS_PATH)$(GNL_PATH)%.o: $(SRC_PATH)$(GNL_PATH)%.c
	@gcc $(CFLAGS) $(GNL_ARGS) -o $@ -c $<
	@echo "Creating $@..."

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Deleting $(OBJS_PATH)...$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Deleting $(NAME)...$(NONE)"

re: fclean all

.PHONY: all clean fclean re
