bits 64

global ft_strcmp

section .text:
		ft_strcmp:
			xor rax, rax
			push rbx
			xor rbx, rbx
			mov rcx, 0
			.while:
			mov al, byte[rdi + rcx]
			mov bl, byte[rsi + rcx]
			cmp al, bl
			jne .return
			cmp al, 0
			je .return
			inc rcx
			jmp .while
			.return:
				sub rax, rbx
				cmp rax, 0
				pop rbx
				ret
