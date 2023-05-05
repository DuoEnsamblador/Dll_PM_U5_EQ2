// pch.cpp: el archivo de código fuente correspondiente al encabezado precompilado

#include "pch.h"
#include <stdio.h>

// Cuando se utilizan encabezados precompilados, se requiere este archivo de código fuente para que la compilación se realice correctamente.

int __stdcall suma(int a, int b) {
	//data
	int resultado;


	_asm { //ensamblador inline
		mov eax , a 
		add eax , b

		mov resultado , eax
	}
	return resultado;
}

	int __stdcall multiplicacion(int a, int b) {
		//data
		int resultado;

		_asm { //ensamblador inline
			mov eax, a
			mul b

			mov resultado, eax
		}
		return resultado;
}

	int __stdcall resta(int a, int b) {

		//data
		int resultado2;

		_asm { //ensamblador inline
			mov eax, 0
			mov eax, a
			mov ebx, b
			sub eax, ebx

			mov resultado2, eax
		}
		return resultado2;
	}

	int __stdcall division(int a, int b) {

		//data
		int resultado2;

		_asm { //ensamblador inline
	
			mov eax, a
			mov ecx, b
			div ecx
			mov resultado2, eax
		}
		return resultado2;
	}

	int __stdcall largo_cadena(const char* str) {
		int len = strlen(str);
		return len;
	}


	//Reescribir el contenido de una cadena que se obtuvo desde c#


	int __stdcall escribir_cadena(char* str , int len_buffer) {

		const char* aux = "GARUCO Te MATARA"; //debe ser menor que len_buffer
		int len = strlen(aux);
		for (int i = 0; i < len; i++) {
			str[i] = aux[i];
		}
		return len;
	}


#pragma enregion

#pragma region PROGRAMAS 2023 1


	
	int __stdcall promedioDeUsuario(char* nombre, int cal1, int cal2, int cal3) {
		//a nombre no se le hara ningun cambio en este programa...

		int prom;
		int pDecimal;
		//ensamblador
		_asm {
			mov eax , 0
			add eax , cal1
			add eax , cal2
			add eax , cal3

			mov edx , 0
			mov ecx , 3 
			div ecx 

			mov pDecimal , edx
			mov prom , eax
		}

		prom += pDecimal / 3;

		return prom;
	}

#pragma endregion

	int __stdcall promUsuario(char* cadRes, char* nombre, int cal1, int cal2, int cal3) {
		//a nombre no se le hara ningun cambio en este programa...
		int prom;
		int pDecimal;
		//ensamblador
		_asm {
			mov eax, 0
			add eax, cal1
			add eax, cal2
			add eax, cal3

			mov edx, 0
			mov ecx, 3
			div ecx

			mov pDecimal, edx
			mov prom, eax
		}

		prom += pDecimal / 3;

		int c = 0;
		const char* aux = "tienes un promedio de: ";
		int len = strlen(nombre);
		for (int i = 0; i < len; i++)
		{
			cadRes[c] = nombre[i];
			c++;
		}
		len = strlen(aux);
		for (int i = 0; i < len; i++)
		{
			cadRes[c] = aux[i];
			c++;
		}
		if (prom == 10) {
			cadRes[c] = 49;
			c++;
			cadRes[c] = 48;

		}
		else {
			cadRes[c] = prom + 48;
		}
		c++;
		return c;
	}

	int __stdcall Calculartiempo(char* cadRes, int velocidad, int distancia) {
		//a nombre no se le hara ningun cambio en este programa...
		int ms;
		int dana = 1000;
		int rayo = 3600;
		double resultF;
		//ensamblador
		//eax = 90
		// eax(f) = eax(90)*1000
		//90,000
		 // 75000 / 3600 = 20
		_asm {

			mov eax, velocidad
			mul dana

			mov edx, 0
			div rayo

			mov ms , eax
		}
		resultF = distancia / ms;
		return resultF;

		}
	
	int __stdcall velocidad(char* cadRes, char* nombre ,int distancia, int tiempo) {
		//a nombre no se le hara ningun cambio en este programa...
 //a nombre no se le hara ningun cambio en este programa ...

	//velocidad = distancia / tiempo
		int velocidad;
		int pDecimal;
		_asm {
			mov eax, distancia
			mov ebx, tiempo
			mov edx, 0
			div ebx // eax / ebx  => distancia / tiempo
			mov pDecimal, edx
			mov velocidad, eax
		}
		//velocidad += pDecimal / tiempo;
		int c = 0; //inicio de la cadena resultado     
		c += addCadena2Cadena(cadRes, c, nombre);
		const char* aux = " tiene una velociad de: "; //debe ser menor que len_buffer
		c += addCadena2Cadena(cadRes, c, aux);
		//Params: cadena en la que se concatenara, posicion de inicio del numero, numero a concatenar 
		c += addNum2Cadena(cadRes, c, velocidad);
		//retorna la cantidad de caracteres en la palabra ...
		return c;
	}

	int __stdcall addCadena2Cadena(char* cadRes, int indice, const char* cadena) {

		int len = strlen(cadena);
		for (int i = 0; i < len; i++) //recorre cada caracter del nombre del carrito
		{
			cadRes[indice] = cadena[i];
			indice++;
		}
		return len;
	}

	int __stdcall addNum2Cadena(char* cadRes, int indice, int numero) {
		//buscar cuantos digitos tiene la variables
		int tempNumero = numero;
		int cont = 0; //almacena el total de digitos-1
		while (tempNumero >= 10) {
			tempNumero /= 10;
			cont++;
		}
		//X  = 1
		//XX =  10
		//XXX = 100
		//XXXX = 1000
		if (cont >= 1) { //se entra solo cuando son dos o mas digitos los que componen al numero
			int div = 10;
			for (int i = 0; i < cont - 1; i++) { //busca encontrar al divisor
				div = div * 10;
			}
			while (numero > 0) { //obtener el digito mas a la izquierda ... 
				int t = numero / div;
				cadRes[indice] = t + 48;
				indice++;
				numero = numero % div;
				div = div / 10;
			}
		}
		else { //con  = 0
			cadRes[indice] = numero + 48;
			indice++;
		}
		return cont + 1;
	}


