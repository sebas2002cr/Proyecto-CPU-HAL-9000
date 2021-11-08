;--------------------------------------------------------
; This procedure receives an array pointer and its size 
; via the stack. It first reads the array input from the 
; user and then computes the array sum. 
; The sum is returned to the C program.
;--------------------------------------------------------
segment .data
scanw_format    db   "%d",0
printw_format  db   "Ingrese %d digitos a sumar:",10,13,0

segment .text
	
global  sumaNumeros
extern  printw,scanw
	
sumaNumeros:
      enter   0,0
      mov     ECX,[EBP+12]   ; copy array size to ECX
      push    ECX            ; push array size
      push    dword printw_format
      call    printw
      add     ESP,8          ; clear the stack 

      mov     EDX,[EBP+8]    ; copy array pointer to EDX
      mov     ECX,[EBP+12]   ; copy array size to ECX
read_loop:
      push    ECX            ; save loop count
      push    EDX            ; push array pointer
      push    dword scanw_format
      call    scanw
      add     ESP,4          ; clear stack of one argument
      pop     EDX            ; restore array pointer in EDX
      pop     ECX            ; restore loop count
      add     EDX,4          ; 
      dec     ECX
      jnz     read_loop

      mov     EDX,[EBP+8]    ; 
      mov     ECX,[EBP+12]   ; 
      sub     EAX,EAX        ; 
sumar_loop:
      add     EAX,[EDX]
      add     EDX,4          ; 
      dec     ECX
      jnz     sumar_loop
      leave	
      ret


;--------------------------------------------------------
; This procedure receives three integers via the stack.
; It adds the first two arguments and subtracts the 
; third one. It is called from the C program.
;--------------------------------------------------------
segment .text
	
global  test1
	
test1:
      enter   0,0
      mov     EAX,[EBP+8]        ; get argument1 (x)
      add     EAX,[EBP+12]       ; add argument 2 (y)
      leave	
      ret

;--------------------------------------------------------
; This procedure receives three integers via the stack.
; It adds the first two arguments and subtracts the 
; third one. It is called from the C program.
;--------------------------------------------------------
segment .text
	
global  multiplicacion
	
multiplicacion:
      enter   0,0
      mov     AL,[EBP+8]        ; get argument1 (x)
      mov     BL,[EBP+12]       ; add argument 2 (y)
      sub     AL,30h
      sub     BL,30h
      mul     BL
      MOV     AL,BL
      leave
      ret
