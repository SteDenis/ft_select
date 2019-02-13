#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stdenis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:22:20 by stdenis           #+#    #+#              #
#    Updated: 2018/11/16 12:33:27 by stdenis          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
include include.mk
NAME	:=	$(LIBFT)

SRC=ft_putchar.c \
	ft_putstr.c \
	ft_tolower.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isprint.c \
	ft_isascii.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_strlen.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strncpy.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_strjoindir.c \
	ft_strcat_path.c \
	ft_lstmap.c \
	ft_swap_strings.c \
	ft_sort_table.c \
	ft_foreach.c

SRCDIR	:=	src
INCDIR	:=	inc
LIBDIR	:=	lib

BUILDDIR	:=	build
OBJDIR		:=	$(BUILDDIR)/obj

# File used as a command output buffer
TMP		:=	build/tmp.txt

#### COMPILER ####
CC		?=	cc

INCFLAG	:= -I $(INCDIR)
STDFLAG	?=	-ansi
WFLAGS	?=	-Wall -Wextra -Werror -pedantic
CFLAGS	=	$(WFLAGS) $(INCFLAG) $(STDFLAG)

LD		:=	ar
LDFLAG	:=	rcs

SRCLOCA	:=	$(shell find $(SRCDIR) -type d)
OBJLOCA	:=	$(subst $(SRCDIR), $(OBJDIR), $(SRCLOCA))

OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
SRC		:=	$(addprefix $(SRCDIR)/, $(SRC))

#### COLORS ####
ifdef TERM
# Ansi excape color sequences
RED			:=	"\033[1;31m"
GREEN		:=	"\033[0;32m"
BGREEN		:=	"\033[1;32m"
BLUE		:=	"\033[0;34m"
YELLOW		:=	"\033[0;33m"
PURPLE		:=	"\033[0;35m"
CYAN		:=	"\033[0;36m"
GREY		:=	"\033[0;37m"

# When printed reset the color
COLRESET	:=	"\033[0m"

# Move the cursor at the begining of the line
MOVELINE	:=	"\033[1A"
# Erase current line
CLEARLINE	:=	"\033[K"

COMPCOLOR	:=	$(GREEN)
LINKCOLOR	:=	$(PURPLE)
ONGOINGCOL	:=	$(YELLOW)
KOCOLOR		:=	$(RED)
RMCOLOR		:=	$(GREY)
DEBUGCOLOR	:=	$(YELLOW)
endif

#############################
#           RULES           #
#############################
#### COMPILE ####
# Standard rule used when just calling $> make
all:		$(NAME)

# Program linkage
$(NAME):	$(OBJ)
ifdef TERM
	@ echo $(ONGOINGCOL)[...]$(COLRESET)"	: "$@$(MOVELINE)
endif
	@ $(LD) $(LDFLAG) $(NAME) $(OBJ) 1> $(TMP) 2> $(TMP) \
		&& (echo $(CLEARLINE)$(LINKCOLOR)[libft]$(COLRESET)"	: created" \
			; cat $(TMP) \
			| sed -e "s/^/    /g" \
			; rm $(TMP)) \
		|| (echo $(CLEARLINE)$(KOCOLOR)[KO]$(COLRESET)"	: linkage fail" \
			; cat $(TMP) \
			| sed -e "s/^/    /g" \
			; rm $(TMP) \
			; exit 1)

# Compilation and .d generation
$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
ifdef TERM
	@ echo $(ONGOINGCOL)[...]$(COLRESET)"	: "$@$(MOVELINE)
endif
	@ $(CC) -c $< $(CFLAGS) -o  $@ 1> $(TMP) 2> $(TMP) \
		&& (echo $(CLEARLINE)$(COMPCOLOR)[OK]$(COLRESET)"	: "$@ \
			; cat $(TMP) \
			| sed -e "s/^/    /g") \
		|| (echo $(CLEARLINE)$(KOCOLOR)[KO]$(COLRESET)"	: "$@ \
			; cat $(TMP) \
			| sed -e "s/^/    /g" \
			; rm $(TMP) \
			; exit 1)

# Dir created to store build cache
$(OBJDIR):
	@ mkdir -p $(OBJLOCA)
$(BUILDDIR):
	@ mkdir -p $(BUILDDIR)

#### LOCAL (Don't recompile lib) ####
lclean:
	@ rm -r $(BUILDDIR) 1> /dev/null 2> /dev/null \
		&& echo $(RMCOLOR)[CLR]$(COLRESET)"	:" obj \
		; (exit 0)

lfclean: lclean
	@ rm -Rf *.dSYM 1> /dev/null 2> /dev/null
	@ rm $(NAME) 1> /dev/null 2> /dev/null \
		&& echo $(RMCOLOR)[CLR]$(COLRESET)"	:" $(NAME) \
		; (exit 0)

lre: lfclean all

#### MANDATORY ####
clean: lclean
	@ rm -f $(TMP)

fclean:	lfclean

re:		fclean all

#############################
#          SETTING          #
#############################
# Add rule to phony if they are not based on actual files.
.PHONY: all clean fclean re