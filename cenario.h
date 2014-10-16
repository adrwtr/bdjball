#ifndef CENARIO_H
#define CENARIO_H

#include "pecas.h"
#include "bolas.h"
#include "jogador.h"
#include "efeitos.h"


/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organiza��o de c�digos 
e programa��o em C++

O arquivo cenario.h contem a classe cenario

A classe cenario praticamente controla o jogo todo.
Ela indica quantas pe�as, bolas podemos ter..

Ela controla as colis�es e a��es


Data de Cria��o
16/01/2008

Data �ltima modifica��o
20/02/2008
*/


///#####################################
// PASSO 2 continua��o
///#####################################


//  ver http://bdjogos.com/adrw/c/classes_const.htm
const int total_pecas 	= 50;					// quantidade m�xima de pecas
const int total_fases 	= 10;					// quantidade m�xima de fases
const int total_efeitos = 50;					// quantidade m�xima de efeitos

const int total_bolas	= 100;					// quantidade m�xima de bolas

const bool DEBUG_MODE	= true;				// sistema para manuten��o de c�digo

// ver http://bdjogos.com/adrw/c/classes_implementacao.htm

class Cenario {

private:

	// contadores auxiliares
	int i;
	int c;
	int e;

	// ATEN��O:
	// Este � um Array de Ponteiros para caracteres.
	// Este array vai armazenar at� "10" ponteiros para caracteres que ser�o os nomes das fases lidos
	// ver http://bdjogos.com/adrw/c/ponteiros.htm
	char * nome_fases[ total_fases ];
	
	// guarda o n�mero da fase atual
	int fase_atual;
	
	// indica o numero total de fases lidas do txt
	int vtotal_fases;
	
	// n�mero total de vidas do jogador
	int vidas;
	
	// ATEN��O:
	// Est� � um array de caracteres que ir� guardar o nome do bitmap lido no txt das fases
	// ver http://bdjogos.com/adrw/c/array1.htm
	// ver http://bdjogos.com/adrw/c/mani_strings.htm
	char bitmap_fase[30];


public:

	int tamanho_x;
	int tamanho_y;
	
	int cor;
	
		
	BITMAP * buffer;
	
	// BITMAP da imagem de fundo do cenario ( lido do bitmap_fase[30] );
	BITMAP * img_fundo;
	
	// Array de ponteiros para pecas, 
	// com este array iremos criar as pe�as por aloca��o dinamica
	Pecas *pecas[ ::total_pecas ];
	
	// Array de Ponteiros para bolas
	// com este array iremos criar as bolas por aloca��o dinamica
	Bolas *bolas[ ::total_bolas ];
	
	// Array de ponteiros para efeitos
	// com este array iremos criar os efeitos por aloca��o dinamica 
	Efeitos *efeitos[ ::total_efeitos ];
	
	
	// Construtor e destrutor padr�o
	// ver http://bdjogos.com/adrw/c/construtores_destruidores.htm
	Cenario();
	~Cenario();
	
	
	// inicia o objeto
	void iniciar( int tamanho_x, int tamanho_y );
	
	// reinicia vari�veis do objeto
	void destrutor();
	
	
	// Mostra o cenario na tela
	BITMAP * mostrar();   
	
	// Verifica colis�o com a bola
	void colisao_bola( BITMAP * fundo, Jogador *jogador );      
	
	
	///#####################################
  // PASSO 2 FIM
  ///#####################################
	
	///#####################################
  // PASSO 3
  ///#####################################
	
	///#####################################
  // Abra o arquivo cenario.pp
  ///#####################################
  
  
  
  
	
	// Le o txt fases.txt que possui o nome de outros txt que est�o as fases	
	bool le_fases();
	
	// Ap�s a execu��o da fun��o le_fases,
	// cria a fase de acordo com as coordenadas do txt
	bool cria_fase();
		
	// essa fun��o verifica as vidas do jogador	
	bool verifica_vidas();	
	
	// adiciona um efeito na tela
	void adiciona_efeito( int vid );
	
	// verifica situa��o das pe�as
	bool verifica_pecas();
	
	// cenario de testes ( cria pe�as no cenario )
	void teste();

};

#endif
