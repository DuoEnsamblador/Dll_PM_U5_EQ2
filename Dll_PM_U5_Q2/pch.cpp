// pch.cpp: el archivo de código fuente correspondiente al encabezado precompilado

#include "pch.h"

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