#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h> 

using namespace System;
using namespace std;

//factorial recursividad
int factorial(int numero) {
    if (numero <= 1)
        return 1;
    else
        return numero * factorial(numero - 1);
}

//Factorial no recursivo
int factorial2(int numero) {
    int factorial = 1;
    for (int i = 2; i <= numero; i++)
    {
        factorial *= i;
    }
    return factorial;
}

//Funcion recursiva que cuenta digitos de un numero
int dig(int numero) {
    if (numero < 10)
        return 1;
    return 1 + dig(numero / 10);
}

//Funcion multiplicativa recursiva 
int etiope(int numero1, int numero2) {
    if (numero1 == 1) {
        return numero2;
    }
    else
        if (numero1 % 2 == 0)
            return etiope(numero1 / 2, numero2 * 2);
        else
            return numero2 + etiope(numero1 / 2, numero2 * 2);
}

//Punteros a funciones
float sum(float x, float y) { return x + y; }
float res(float x, float y) { return x - y; }
float pro(float x, float y) { return x * y; }
float div(float x, float y) { return y ? x / y : 0; }
//Vectores de punteros a funciones
float(*operacion[4])(float, float) = { sum,res,pro,div };
//Mostar Resultados
void mostrar() {
    float a, b;
    char opcion;
    float (*operacion2)(float, float);
    int i; 
    cout << "Primer operador: " << endl;
    cin >> a;
    cout << "Segundo operador: " << endl;
    cin >> b;
    cout << "Operacion ( + , - , * , / ) : " << endl;
    do {
        opcion = getchar();
    } while (opcion != '+' && opcion != '-' && opcion != '*' && opcion != '/');
    
   switch (opcion)
    {
    case '+': operacion2 = sum; break;
    case '-': operacion2 = res; break;
    case '*': operacion2 = pro; break;
    case '/': operacion2 = div;
    }
    printf("%f %c %f = %f", a, opcion, b, (*operacion2)(a, b));
    switch (opcion)
    {
    case '+': i = 0; break;
    case '-': i = 1; break;
    case '*': i = 2; break;
    case '/': i = 3; break;
    }
    cout << endl;
    printf("%f %c %f = %f", a, opcion, b, (*operacion[i])(a, b));

}
 

//Funciones como argumento
float sum2(float x, float y) { return x + y; }
float res2(float x, float y) { return x - y; }
float pro2(float x, float y) { return x * y; }
float div2(float x, float y) { return y ? x / y : 0; }
void mostrar2(float x, char c, float y, float(*f)(float, float))
    {
        if (c == '1') c = '+';
        else if (c == '2') c = '-';
        else if (c == '3') c = '*';
        else c = '/';
        printf("\n\n%f %c %f = ", x, c, y);
        printf("%f.", (*f)(x, y));
    }
//Mostar Resultados
void Resltados() {
    float a, b;
    char op;
    float (*operacion[4])(float, float) = { sum,res,pro,div };
    do
    {
        cout << endl;
        cout << "Primer operador: " << endl;
        cin >> a;
        cout << "Segundo operador: " << endl;
        cin >> b;
        cout << "Operacion ( 1.Suma , 2.Resta , 3.Multiplicacion , 4.Division ) : " << endl;
        do
            op = getche();
        while (op - '0' < 1 || op - '0' > 4);
        mostrar2(a, op, b, operacion[(short)(op - '1')]);
        cout << endl; 
        printf("Otra operacion ( Siguiente (s) / Ninguna (n) ) : ");
        do
            op = getche(); 
        while (op != 's' && op != 'n');
    } while (op == 's');
}

