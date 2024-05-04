.text
	li $t0, 12
	addi $t1, $zero, 10
	
	sll $s1, $t1, 10 # multiplicar por 2 ^ 10 = 1024 - shift left é muito mais "barato" para o computador processar do que mul
	mul $s0, $t0, $t1 # $s0 terá o resultado da multiplicação
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	
	