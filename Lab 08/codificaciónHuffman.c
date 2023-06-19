//Perez Marcelo Cristopher - 3CV4
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estrucutra parecida a la de un arbol binario
struct nodo{
    char letra;
    int frecuencia;
    struct nodo* izquierda;
    struct nodo* derecha;
};

// Estructura de un nodo en la lista enlazada
struct NodoLista{
    struct nodo* nodo;
    struct NodoLista* siguiente;
};

struct nodo* crearnodo(char letra, int frecuencia){
    struct nodo* nodo=(struct nodo*)malloc(sizeof(struct nodo));
    nodo->letra=letra;
    nodo->frecuencia=frecuencia;
    nodo->izquierda=NULL;
    nodo->derecha=NULL;
    return nodo;
}

//Crea un nuevo nodo de la lista enlazada
struct NodoLista* crearNodoLista(struct nodo* nodo){
    struct NodoLista* nuevoNodo=(struct NodoLista*)malloc(sizeof(struct NodoLista));
    nuevoNodo->nodo=nodo;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

//Tnserta un nodo en la lista enlazada de nodos del árbol binario
void insertarNodoLista(struct NodoLista** lista, struct NodoLista* nuevoNodo){
    if (*lista==NULL || nuevoNodo->nodo->frecuencia<(*lista)->nodo->frecuencia){
        nuevoNodo->siguiente = *lista;
        *lista=nuevoNodo;
    
    }
    else{
        struct NodoLista* actual=*lista;
        while (actual->siguiente!=NULL && nuevoNodo->nodo->frecuencia>=actual->siguiente->nodo->frecuencia){
            actual=actual->siguiente;
        }
        nuevoNodo->siguiente=actual->siguiente;
        actual->siguiente=nuevoNodo;
    }
}

//Se utiliza el histograma de las letras
struct nodo* construirArbolHuffman(char letras[], int frecuencias[], int numLetras){
    struct NodoLista* lista=NULL;

    // Crear nodos iniciales y agregarlos a la lista
    for(int i=0; i<numLetras; i++){
        struct nodo* nodo=crearnodo(letras[i], frecuencias[i]);
        struct NodoLista* nuevoNodoLista=crearNodoLista(nodo);
        insertarNodoLista(&lista, nuevoNodoLista);
    }

    // Construir el árbol de Huffman fusionando nodos de menor frecuencia
    while (lista->siguiente != NULL) {
        struct NodoLista* primerMenor=lista;
        struct NodoLista* segundoMenor=lista->siguiente;
        struct nodo* nuevoNodo=crearnodo('$', primerMenor->nodo->frecuencia+segundoMenor->nodo->frecuencia);
        nuevoNodo->izquierda=primerMenor->nodo;
        nuevoNodo->derecha=segundoMenor->nodo;
        struct NodoLista* nuevoNodoLista=crearNodoLista(nuevoNodo);
        lista = lista->siguiente->siguiente;
        insertarNodoLista(&lista, nuevoNodoLista);
    }

    return lista->nodo;
}

// Función para imprimir los códigos de Huffman para cada letra
void imprimirCodigosHuffman(struct nodo* raiz, char codigo[], int nivel) {
    if (raiz->izquierda==NULL && raiz->derecha==NULL) {
        codigo[nivel] = '\0';
        printf("%c: %s\n", raiz->letra, codigo);
    } else {
        codigo[nivel] = '0';
        imprimirCodigosHuffman(raiz->izquierda, codigo, nivel + 1);
        codigo[nivel] = '1';
        imprimirCodigosHuffman(raiz->derecha, codigo, nivel + 1);
    }
}

int main() {
    char frase[100];
    printf("Introduce una frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    int frecuencias[100] = {0};  // Array para almacenar las frecuencias de las letras del alfabeto
    int numLetras = 0;

    // Calcular el histograma de las letras en la frase
    for (int i=0; i<strlen(frase); i++) {
        char letra=frase[i];
        if (letra>= 'a' && letra<='z') {
            frecuencias[letra - 'a']++;
            if (frecuencias[letra - 'a'] == 1) {
                numLetras++;
            }
        }
    }

    char letras[numLetras];  // Array para almacenar las letras del alfabeto con frecuencia mayor a cero
    int index=0;

    // Construir el arreglo de letras y sus frecuencias correspondientes
    for (int i =0;i< 26; i++) {
        if (frecuencias[i]>0) {
            letras[index]='a' + i;
            index++;
        }
    }

    // Construir el árbol de Huffman
    struct nodo* raiz=construirArbolHuffman(letras, frecuencias, numLetras);

    printf("\nCodificacion de Huffman:\n");
    char codigo[100];
    imprimirCodigosHuffman(raiz, codigo, 0);

    // Codificar la frase original utilizando los códigos de Huffman
    
  
    
    return 0;
}
