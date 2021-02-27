# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 14:54:11 by nayache           #+#    #+#              #
#    Updated: 2021/02/27 05:13:39 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern malloc
extern ft_strlen
extern ft_strcpy
extern __errno_location
global ft_strdup

section .text

ft_strdup:
		mov r12, rdi
		call ft_strlen
		add rax, 1
		mov rdi, rax
		call malloc
		cmp rax, 0
		je enomem_quit
		mov rdi, rax
		mov rsi, r12
		call ft_strcpy
		ret

enomem_quit:
		call __errno_location
		mov r12, 12
		mov [rax], r12
		mov rax, 0
		ret
