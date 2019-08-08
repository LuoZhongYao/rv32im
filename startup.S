.global _start
.global main
.global hostapi_entry

_start:
	sw a0, hostapi_entry, t0
	la t0, _trap_handler
	csrw mtvec, t0
	j main

hostapi_entry:	.long  0x0
	
_trap_handler:
	mret
