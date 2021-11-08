/*******************************************************
 * This program calls an assembly program to read the 
 * array input and compute its sum. It prints the sum. 
 * The assembly program is in "hll_arraysum2a.asm" file.
 *******************************************************/
#include        <stdio.h>
#include        <ncurses.h>

void division();
void multiplicaciones();
void sumaDeDosValores();

#define  cantidad  10

//Función principal main()
int main(int argc, char * argv[])
{
	initscr();                          /*Inicia curses*/
	move(1,2);printw("PC:");
	move(2,2);printw("IR:");
	move(3,2);printw("0   0   0   0");
	move(4,2);printw("OF  CF  SF  ZF \n");
	move(5,2);printw("\n EAX: \n EBX: \n ECX: \n EDX: \n");
	move(5,53);printw("Instrucciones NASM");
	
    sumaDeDosValores();
    
    return 0;
}

void sumaDeValores()
{
	int        num[cantidad];
	extern int sumaNumeros(int*, int);
	move(6,0);printw("La suma de los valores es = %d\n",sumaNumeros(num,cantidad));
	
}

void sumaDeDosValores()
{
        int    x, y;
        extern int suma(int, int);
        move(15,0);printw("Se procederà a sumar 2 valores");
        move(16,0);printw("Ingrese el nùmero 1 = ");
        scanw("%d", &x);
        move(6,54);printw("segment .text");
        move(7,54);printw("global suma");
        move(8,54);printw("   suma:");
        move(9,54);printw("   enter   0,0");
        move(9,54);printw("   mov   EAX,[EBP+8]");
        move(1,2);printw("PC: 00111101");
        
        move(17,0);printw("Ingrese el nùmero 2 = ");
        scanw("%d", &y);
        move(1,2);printw("PC: 01000000");
        move(10,54);printw("   add   EAX,[EBP+12]");
        move(11,54);printw("   leave");
        move(12,54);printw("   ret");
        
        printf("Resultado = %d\n",suma(x, y));
        
        multiplicaciones();
}


void multiplicaciones()
{
        int    num1, num2;
        extern int multiplicacion (int, int);
        move(19,0);printw("Se procederà a multiplicar 2 valores");
        move(20,0);printw("Ingrese el nùmero 1 = ");
        scanw("%d", &num1);
        move(6,54);printw("segment .text");
        move(7,54);printw("global multiplicacion");
        move(7,54);printw("   enter  0,0");
        move(9,54);printw("   mov    AL,[EBP+8]");
        move(1,2);printw("PC: 01001101");
        move(21,0);printw("Ingrese el nùmero 2 = ");
        scanw("%d", &num2);
        move(7,54);printw("   mov    BL,[EBP+12]");
        move(9,54);printw("   mul    BL");
        move(9,54);printw("   leave");
        move(9,54);printw("   ret");
        move(1,2);printw("PC: 01010010");
        
        printf("Resultado = %d\n",multiplicacion(num1, num2));
        scanw("%d", &num1);
}
