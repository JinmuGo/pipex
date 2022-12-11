# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:49:09 by jgo               #+#    #+#              #
#    Updated: 2022/11/30 18:25:27 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

CPPFLAGS = -I$(TOPDIR)/includes

NAME = libftprintf.a

HEAD = ft_printf.h
SRCS = ft_printf.c \
		ft_printf_c.c \
		ft_printf_d.c \
		ft_printf_p.c \
		ft_printf_s.c \
		ft_printf_u.c \
		ft_printf_x.c \
		ft_putchar.c \
		ft_putstr.c \
		utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $@ $^
		$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib link_files
		$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/includes link_files

clean:
		$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib unlink_files
		$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
		$(RM) $(OBJS) $(DEPS)

fclean: clean
		$(RM) $(NAME)

re: fclean
		$(MAKE) all

.PHONY: all clean fclean re bonus