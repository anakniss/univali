.data # especificação de algumas variáveis. lida com os dados na memória principal
	msg: .asciiz "Olá, mundo!" # mensagem a ser exibida para o usuário

.text # instruções em si
	li $v0, 4 # instrução para a impressão da string
	la $a0, msg # indica o endereço em que está a mensagem
	syscall # faça! imprima :)