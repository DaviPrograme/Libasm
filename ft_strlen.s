bits 64

section .text:
		global ft_strlen

		ft_strlen:
			xor rcx, rcx
			.while:
				cmp [rdi+rcx], byte 0
				je .return
				inc rcx
				jmp .while
			.return:
				mov rax, rcx
				ret
