// Headers
// el .h es como crearnos nuestra propia libreria y lo que procede luego en el main es llamar a nuestra propia libreria creada
// definiciones de funciones, no procesos, solo prototipos por asi decirlo

#ifndef  Calculadora_h //empezar con un archivo de cabecera
//verifica que este archivo no haya sido incluido anteriormente, y comprime
#define Calculadora_h
//que ese mismo archivo no sea repetido en otro lado

// funciones con parametros de tipo void
void sumar(double num1, double num2);
void restar(double num1, double num2);

// funciones con parametros de retorno
double multiplicar(double num1, double num2);
double dividir(double num1, double num2);


#endif // !Calculadora_h