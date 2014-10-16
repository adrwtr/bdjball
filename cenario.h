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
Use para estudar organização de códigos 
e programação em C++

O arquivo cenario.h contem a classe cenario

A classe cenario praticamente controla o jogo todo.
Ela indica quantas peças, bolas podemos ter..

Ela controla as colisões e ações


Data de Criação
16/01/2008

Data última modificação
20/02/2008
*/


///#####################################
// PASSO 2 continuação
///#####################################


//  ver http://bdjogos.com/adrw/c/classes_const.htm
const int total_pecas 	= 50;					// quantidade máxima de pecas
const int total_fases 	= 10;					// quantidade máxima de fases
const int total_efeitos = 50;					// quantidade máxima de efeitos

const int total_bolas	= 100;					// quantidade máxima de bolas

const bool DEBUG_MODE	= true;				// sistema para manutenção de código

// ver http://bdjogos.com/adrw/c/classes_implementacao.htm

class Cenario {

private:

	// contadores auxiliares
	int i;
	int c;
	int e;

	// ATENÇÃO:
	// Este é um Array de Ponteiros para caracteres.
	// Este array vai armazenar até "10" ponteiros para caracteres que serão os nomes das fases lidos
	// ver http://bdjogos.com/adrw/c/ponteiros.htm
	char * nome_fases[ total_fases ];
	
	// guarda o número da fase atual
	int fase_atual;
	
	// indica o numero total de fases lidas do txt
	int vtotal_fases;
	
	// número total de vidas do jogador
	int vidas;
	
	// ATENÇÃO:
	// Esté é um array de caracteres que irá guardar o nome do bitmap lido no txt das fases
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
	// com este array iremos criar as peças por alocação dinamica
	Pecas *pecas[ ::total_pecas ];
	
	// Array de Ponteiros para bolas
	// com este array iremos criar as bolas por alocação dinamica
	Bolas *bolas[ ::total_bolas ];
	
	// Array de ponteiros para efeitos
	// com este array iremos criar os efeitos por alocação dinamica 
	Efeitos *efeitos[ ::total_efeitos ];
	
	
	// Construtor e destrutor padrão
	// ver http://bdjogos.com/adrw/c/construtores_destruidores.htm
	Cenario();
	~Cenario();
	
	
	// inicia o objeto
	void iniciar( int tamanho_x, int tamanho_y );
	
	// reinicia variáveis do objeto
	void destrutor();
	
	
	// Mostra o cenario na tela
	BITMAP * mostrar();   
	
	// Verifica colisão com a bola
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
  
  
  
  
	
	// Le o txt fases.txt que possui o nome de outros txt que estão as fases	
	bool le_fases();
	
	// Após a execução da função le_fases,
	// cria a fase de acordo com as coordenadas do txt
	bool cria_fase();
		
	// essa função verifica as vidas do jogador	
	bool verifica_vidas();	
	
	// adiciona um efeito na tela
	void adiciona_efeito( int vid );
	
	// verifica situação das peças
	bool verifica_pecas();
	
	// cenario de testes ( cria peças no cenario )
	void teste();

};

#endif
