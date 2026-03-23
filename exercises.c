#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(int i = 1 ; i <= 10 ; i ++)
   {
      int *dato = malloc(sizeof(int));
      *dato = i;
      pushBack(L , dato);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0; //seria nuestro contador
   int *dato = (int*) first(L); // aqui obtengo el primero de la lista en entero

   while (dato != NULL){ //mientras existan elementos,seguimos no más
      suma += *dato; //suma el contenido
      dato = (int*) next(L); //avanzo al siguente dato
   
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int *dato = (int*) first(L); // me pongo en el primer elemento

   while (dato != NULL){ //mientras existan elementos, seguimos no más.
      if (*dato == elem){ //pregunto si son iguales.
         free(dato); //liberamos el dato, ya que hay que liberar memoria.
         popCurrent(L); // elimino el nodo actual.
         dato = (int*) next(L); // se vuelve a revisar el siguente dato.
      }
      else dato = (int*) next(L); // si no es igual, sigo no más
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack *auxiliar = create_stack(); //creo la pila auxiliar 
   void *dato; //aqui guardo un puntero general
   
   while ((dato = pop(P1)) != NULL){ // saco un elemento del original y lo guardo en el dato
      push(auxiliar, dato); // inserto en el auxiliar
   }
   while ((dato = pop(auxiliar)) != NULL){ //saco un elemento de auxiliar y lo guardo en el dato 
      push(P1, dato); 
      push(P2, dato); // copio los elementos de P2
      
   }
}


/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack *P = create_stack(); //creamos la pila vacia

   for (int i = 0; cadena[i] != '\0' ; i++){ //recorro la cadena.
      char c = cadena[i];
      if (c == '(' || c == '[' || c == '{'){
         push(P, &cadena[i]); // aqui lo insertamos a la pila.
            
      }
      else if (c == ')' || c == ']' || c == '}'){
         char *tope = (char*) top(P); //aqui veo el tope de la pila
         if (tope == NULL) return 0; // en esta parte del cierre si esta la pila vacia, error

         //aqui ya se compara el cierre con el tope
         if ((c == ')' && *tope == '(') || 
            (c == ']' && *tope == '[ ') || 
            (c == '}' && *tope == '{')){
            pop(P);
         }
         else return 0;
      }

   }
   if (top(P) == NULL) return 1; // si la pila quedo vacia y quedo todo ok, retornamos 1
   
   return 0; // retornamos si esta mal
}

