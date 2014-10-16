#ifndef JOGADOR_H
#define JOGADOR_H

#include "bolas.h"


/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organiza��o de c�digos 
e programa��o em C++

O arquivo jogador.h contem a classe jogador, que � a raquete 
que rebate a bola, controlada pelo usuario


Data de Cria��o
16/01/2008

Data �ltima modifica��o
22/02/2008
*/


///#####################################
// PASSO 4 - Continua��o
///#####################################




class Jogador {
private:

	// contadores auxiliares
	int i;
	int c;

public:

	int posicao_x;
	int posicao_y;
	
	int tamanho_x;
	int tamanho_y;
	
	int cor;
	
	
	int limite_x1;		// limite de movimento para o jogador a esquerda
	int limite_x2;		// limite de movimento para o jogador a direita
	
	int velocidade;
	
	// variavel auxiliar que indica aonde a bola bateu no jogador... 
	int bateu;
	
	
	
	Jogador();			// fun��o construtor
	~Jogador();			// fun��o destrutor
	
	// inicia objeto corretamente
	void iniciar( int posx, int posy, int limite_x1, int limite_x2 );

	// reinicia vari�veis do objeto
	void destrutor();


	// imprime o jogador
	void mostrar( BITMAP * fundo );
	
	// atualiza posi��o do jogador na tela
	void refresh();
	
	// verifica colis�es com as bolas
	void colisao_bola( Bolas * ); 
	
	
	
	void adiciona_tamanho();			  // adiciona tamanho
	void remove_tamanho();		      // remove tamanho
	void adiciona_velocidade();		  // adiciona velocidade
	void remove_velocidade();	      // remove velocidade
	
};

///#####################################
// Abra o arquivo jogador.cpp
///#####################################

#endif
