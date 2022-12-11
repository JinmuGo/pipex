# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:42:33 by jgo               #+#    #+#              #
#    Updated: 2022/11/23 14:10:09 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/config/Rules.mk
include $(TOPDIR)/config/color_rules.mk

LIBS = libft ft_printf

all bonus clean fclean re:
		$(Q)$(foreach lib, $(LIBS), $(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)

.PHONY: all clean fclean re bonus