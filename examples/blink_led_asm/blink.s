.data

reset_clear_base: .word 0x40023000 # RESET CLEAR IOBANK0
reset_done: .word 0x40023008 # RESET IOBANK0
gpio_base: .word 0x40028014 # GPIO 2
sio_base: .word 0xd0000000

.global _start_brad

_start_brad:
    la x5, reset_clear_base
    addi x6, x5, 32
    sw x6, 0(x5)
    
loop:
    la x5, reset_done
    beq x0, x5, loop

# Set function 5 of gpio 2, th
la x5, gpio_base
addi x6, x0, 5 # 5 tells the reg function 5 sio
sw x6, 0(x5)

# Store the value for setting the SIO to out
li x5, 1
slli x5, x5, 2

set_val:
    # Set the SIO to OUT
    la x6, sio_base
    sw x5, 0x38(x6) # Set the GPIO for outputs
    sw x5, 0x018(x6) # Set the GPIO to ON
