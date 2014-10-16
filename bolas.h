#ifndef BOLAS_H
#define BOLAS_H
	
#include <allegro.h>

/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo bolas.h contem a classe bolas

Data de Criação
16/01/2008

Data última modificação
22/02/2008
*/

///#####################################
// PASSO 5 
///#####################################
	
class Bolas {
      
private:
        
	// contadores auxiliares
	int i;
	int c;
		
	
public:
	
	int posicao_x;
	int posicao_y;
	
	int tamanho;    
	int cor;
	
	// controlam a velocidade da bola em x e em y
	// desta forma ela pode ir para lugares diferentes na tela
	int velocidade_x;	
	int velocidade_y;
	
	// informam a direção de movimentação da bola
	// pelo cenario
	
	// para esquerda 	bola->direcao_x = -1;
	// para cima 		  bola->direcao_y = -1;	
	int direcao_x;
	int direcao_y;
	

	Bolas();								// função construtor
	~Bolas();								// função destrutor
	
	void iniciar( int pos_x, int pos_y );	// inicia objeto
	void destrutor();						          // reinicia variáveis do objeto
	
	void mostrar( BITMAP * fundo );    		// imprime a bola no vetor fundo
	void refresh();							          // atualiza posição da bola
	
	void adiciona_velocidade_x();
	void remove_velocidade_x();
	
	void adiciona_velocidade_y();
	void remove_velocidade_y();
	
	
	void bola_normal( BITMAP * fundo );		// imprime o desenho de uma bola personalizada
	
		
};

///#####################################
// abra o arquivo bolas.cpp
///#####################################
	
#endif
