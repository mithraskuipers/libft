NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

srcs = ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strchr.c \
ft_strrchr.c \
ft_strnstr.c \
ft_strncmp.c \
ft_atoi.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_split.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

#onder ft_split.c
#ft_itoa.c \
#boven ft_strmapi.c

#onder ft_substr.c
#ft_strjoin.c \
#ft_strtrim.c \
#boven ft_split.c

srcs_objectfiles = $(srcs:.c=.o)

#bonus = ft_lstnew.c \
#ft_lstadd_front.c \
#ft_lstsize.c \
#ft_lstlast.c \
#ft_lstadd_back.c \
#ft_lstdelone.c \
#ft_lstclear.c \
#ft_lstiter.c \
#ft_lstmap.c

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	
%.o: %.c $(HEADER)
	$(CC) -c $(CCFLAGS) -o $@ $<

# 'make' creates .o files for each function as well as the main library file, libft.a
# 'make re' removes all .o & .a files then remakes them
# 'make clean' removes the .o files used to create the library
# 'make fclean' removes the .o & .a files used to create the library

re: fclean all

clean:
	rm -f $(srcs_objectfiles)

fclean: clean
	rm -f $(NAME)

.PHONY: bonus re clean fclean
