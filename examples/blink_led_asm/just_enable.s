.data

sio_base: .word 0xd0000000

.global _start_brad

_start_brad:
    # Load the value at the address in sio_base
    # which in our case is the address of the
    # SIO base registers
    la x5, sio_base

    # Add 0x18 to the sio_base address to get the
    # address of the GPIO_OUT_SET register
    addi x5, x5, 0x18

    # Set 1 to x6 and then shift it across 25 times
    # This will let us set the 25th pin to on
    li x6, 1
    slli x6, x6, 25

    # Now write the value back to the register
    sw x6, 0(x5)
