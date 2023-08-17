# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cstaats <cstaats@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/29 08:30:46 by cstaats       #+#    #+#                  #
#    Updated: 2022/11/08 15:13:17 by cstaats       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Wunreachable-code -g -fsanitize=address
LIBMLX	:= ./MLX42

HEADERS	:= -I ./ -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
SRCS	:= main.c errorchecks.c utils.c get_next_line.c get_next_line_utils.c utilscont.c images.c utilscont1.c validpath.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -g -fsanitize=address

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx