NAME = libft.a

SRC_DIR = srcs/
BONUS_DIR = bonus/

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -Iincludes
RM = rm -f

SRC = ft_isalpha.c\
      ft_isdigit.c\
      ft_isalnum.c\
      ft_isascii.c\
      ft_isprint.c\
      ft_strlen.c\
      ft_memset.c\
      ft_bzero.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_strlcpy.c\
      ft_strlcat.c\
      ft_toupper.c\
      ft_tolower.c\
      ft_strchr.c\
      ft_strrchr.c\
      ft_strncmp.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_strnstr.c\
      ft_atoi.c\
      ft_calloc.c\
      ft_strdup.c\
      ft_substr.c\
      ft_strjoin.c\
      ft_strtrim.c\
      ft_split.c\
      ft_itoa.c\
      ft_strmapi.c\
      ft_striteri.c\
      ft_putchar.c\
      ft_putstr.c\
      ft_putendl.c\
      ft_putnbr.c\
      ft_superatoi.c\
	  ft_printf.c\
	  print_c.c\
	  print_id.c\
	  print_p.c\
	  print_s.c\
	  print_u.c\
	  print_x.c\

BONUS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstadd_back.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

BONUS_OBJ = $(addprefix $(BONUS_DIR), $(BONUS:.c=.o))

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

all: $(NAME)

bonus : $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
