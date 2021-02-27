# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 14:34:19 by nayache           #+#    #+#              #
#    Updated: 2021/02/27 06:56:46 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcpy

section .text

ft_strcpy:
		mov rdx, rdi

cpy:
		cmp byte [rsi], 0
		je null_terminate
		mov cl, [rsi]
		mov [rdx], cl
		inc rsi
		inc rdx
		jmp cpy

null_terminate:
		mov byte [rdx], 0

return_value:
		mov rax, rdi
		ret
