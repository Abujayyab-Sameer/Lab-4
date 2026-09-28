.global sum_array

.text
sum_array:
    mov $0, %eax     
    xor %rcx, %rcx      

loop_start:
    cmp %rsi, %rcx     
    jge loop_end 

    mov (%rdi, %rcx, 4), %edx
    
    add %edx, %eax    

    inc %rcx            
    jmp loop_start     

loop_end:
    ret                 