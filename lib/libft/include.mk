LIBFT		:=	libft.a

LIBFT_PATH	?=	.

LIBFT_LINK	:= -L $(LIBFT_PATH) -l ft
LIBFT_INC	:= -I $(LIBFT_PATH)/inc

ifndef LIB_LINK
LIB_LINK	:=
LIB_INC		:=
endif

LIB_LINK	+= $(LIBFT_LINK)
LIB_INC		+= $(LIBFT_INC)