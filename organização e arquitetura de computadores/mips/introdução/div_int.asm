.text 
	li $t0, 32
	li $t1, 5
	
	srl $s2, $t0, 2 # shift left: 2^2 = 4 
	
	div $t0, $t1
	
	mflo $s0 # parte inteira em #s0
	
	mfhi $s1 # resto em #s1