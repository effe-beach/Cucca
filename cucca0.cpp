#include <iostream>
#include <fstream>   
#include <string> 
#include <stdio.h>
#include <stdlib.h> //rand(), srand()
#include <ctime> //time value
using namespace std;

struct nodo{string carta; nodo*next; nodo(string a=0, nodo*b=0){carta=a; next=b;} };

void ins_nome(string &C, int u)
{
	cout<<"ins nome giocatore" <<u <<": "; cin>>C;
}

void stampa_mazzo(string* M)
{
	for(int i=0; i<40; i++)
	{
		cout<<M[i]<<'\n';
		if(i==19) cout<<endl;
		if(i==39) cout<<"\tfine";
	}
}

nodo* append(nodo* L, string* M, int i)
{
	if(!L) return new nodo(M[i],0);
	//else
	L->next= append(L->next,M,i);
	return L;
}

void stampa_lista(nodo*L)
{
	//se il nodo esiste, stampo e passo al prossimo
	if(L)
	{
		cout<<L->carta<<'\n';
		stampa_lista(L->next);
	}
	return;
}

void mischia_mazzo(string* M)
{
	srand(time(0));
	
	//mischia
	//scambio ogni carta del mazzo con un altra presa a caso
	//malus: le prime carte avranno piu` probabi di essere scambiate piu` volte
	/*SOL: algoritmo Yates-fisher:
		Anziche` scambiare carte nello stesso mazzo, prendo a caso una carta dal primo, e la impilo nel secondo
		Serve una lista di nodi per scegliere a caso.
	*/
	
	//crea lista 40 nodi==mazzo
	nodo*L=0;
	for(int i=0; i<40; i++)
	{
		L=append(L,M,i);
	}
	
	// stampa_lista(L);
	
	// SHUFFLE:
	// scegli val da lista, mettilo nel mazzo && toglilo dalla lista, ripeti fino a esaurimento lista	
	nodo* T=0; // puntatore a nodo temp scelto a caso
	for(int i=0; i<40; i++)
	{
		int val= rand()%(40-i);
		
		// punto il nodo val-esimo e lo copio in M[i];
		T= scorri_lista(L,val); //DA FARE
		M[i]= T->carta;
		//canc nodo
		canc_nodo(L,val) // DA FARE
		
	}
}

main(){

	string N1, N2, N3, N4;
	
	ins_nome(N1,1); ins_nome(N2,2); ins_nome(N3,3); ins_nome(N4,4);
	
	string M[40];
	
	//input mazzo
	ifstream IN;
	IN.open("mazzo");
	if(IN)
	{
		for(int i=0; i<40; i++){
			// prendi stringa da file: IN e` lo stream di input, M[i] e` dove metto il val preso
			getline(IN, M[i]);
		}
	}
	IN.close();
	
	
	// mischia mazzo
	mischia_mazzo(M);
	
	
	
	
}	
