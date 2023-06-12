/*Realizado por Pérez Marcelo Cristopher - 3CV4

a) De que manera podrias representar los estados del juego (datos simples, arreglos, estructuras, listas, etc.)
	Los represetaria en una estructura de datos llamada persona, la cual tiene una velocidad y valores booleanos para
	indicar si ya cruzo y si tiene la lampara.
	
b) Indica cual seria el estado inicial del juego de forma grafica y en la representacion que propusiste.
	Graficamente al inicio la lampara esta a la derecha junto a todas las personas. En mi representacion de estructuras, al inicio
	todos tienen TRUE en la lampara y todos tienen FALSE en cruzar.
	
c) Indica cual seria el estado final del juego y en la representacion que propusiste.
	Graficamente, al final todos estarian del lado izquierdo del puente, y en mi representacion ganarias el juego cuando todos tengan 
	TRUE en cruzar.
	
d) Diseña una funcion generadora de estados (¿como generarias los movimientos?).

	if(canCross(people[a]) && canCross(people[b])){
			time=time-longerTime;
			
			people[a].crossed = !(people[a].crossed);
			people[b].crossed = !(people[b].crossed);
			
e) ¿Como verificas que tienes un estado valido?

	Solo podrian cruzar el puente si el tiempo no se ha acabado y si tienen la lampara. Esto es:
	
	bool canCross(person p){
	if(p.withLamp && (0<time<=30))
		return true;
	else
		return false;
	}
*/

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct{
	int speed;
	bool withLamp, crossed;
}person;

//Variable global.
int time = 30;

//Prototipos de funciones
bool canCross(person);

//Funcion Principal
int main(){
	
	//Se crea el estado inicial del juego, todos tienen la lampara, nadie ha cruzado y c/u tiene su velocidad. Ademas, el juego inicia con 30 segundos disponibles.
	person people[4];
	
	for(int i=0; i<5; i++)
		people[i].withLamp = true;
	
	people[0].speed= 1;
	people[1].speed= 3;
	people[2].speed= 6;
	people[3].speed= 8;
	people[4].speed= 12;
	
	cout<<"\t\tBienvenido al juego Family at the Bridge!\n"<<endl;
	cout<<"Es de noche y la familia (5 personas) tiene que cruzar el puente,"<<endl;
	cout<<"cada uno tiene su propia velocidad representada como los segundos que le toma cruzar el puente (1,3,6,8,10s)"<<endl;
	cout<<"Solo 2 personas como maximo pueden cruzar y tienen que llevar la lampara consigo"<<endl;
	cout<<"Ayuda a la familia a cruzar en 30 segundos o menos. Suerte!\n\n"<<endl;
	
	
	
	while(0<time<=30){
		int a,b;
		cout<<"(Quedan solo "<<time<<"segundos)"<<endl;
		cout<<"Que numero de persona quieres que cruce el puente? (Si solo quieres que cruce una persona para la segunda ingresa el mismo numero)"<<endl;
		cin>>a;
		cin>>b;
		
		int longerTime=people[a].speed;
		
		if(longerTime<people[b].speed)
			longerTime=people[b].speed;
			
		if(canCross(people[a]) && canCross(people[b])){
			time=time-longerTime;
			fflush(stdin);
			
			people[a].crossed = !(people[a].crossed);
			people[b].crossed = !(people[b].crossed);
			
		/*
			for(int i=0; i<5; i++)
				people[i].withLamp = false;
				
			people[a].withLamp = true;
			people[b].withLamp = true;
			
			if(people[a].crossed){
				for(int i=0; i<5; i++)
					if(people[i].crossed)
						people[i].withLamp = false;
					else{
						people[a].withLamp = true;
						people[i].withLamp = true;
					}
			}
			
			if(people[b].crossed){
				for(int i=0; i<5; i++)
					if(people[i].crossed)
						people[i].withLamp = false;
					else{
						people[b].withLamp = true;
						people[i].withLamp = true;
					}
			}
			*/
		
		}else cout<<"El tiempo se te ha acabado o las personas que elegiste no tienen la lampara.Intentalo de nuevo"<<endl;
		
		if(people[0].crossed&&people[1].crossed&&people[2].crossed&&people[3].crossed&&people[4].crossed)
			cout<<"Has ganado!!\n El tiempo restante fue: "<<time<<" segundos"<<endl;
	}
	return 0;
}

//Definicion de funciones
bool canCross(person p){
	if(p.withLamp && (0<time<=30))
		return true;
	else
		return false;
}
