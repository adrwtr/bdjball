#ifndef PECAS_H
#define PECAS_H

#include "bolas.h"



/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organiza��o de c�digos 
e programa��o em C++

O arquivo pecas.h contem a classe pecas, que s�o 
as pe�as que aparecem no cenario para serem destruidas


Data de Cria��o
16/01/2008

Data �ltima modifica��o
22/02/2008
*/



class Pecas {
private:

	// contadores auxiliares
	int i;
	int c;

public:

	int tamanho_x;
	int tamanho_y;
	
	int posicao_x;
	int posicao_y;
	
	int poder;
	int cor;


	void iniciar( int x, int y, int vpoder );	 // inicia objeto
	void destrutor();							             // reinicia vari�veis do objeto
		
		
	void mostrar( BITMAP * fundo );  			     // mostra a pe�a
	int colisao_bola( Bolas * bola );   		   // verifica colisao com a bola
	
	
	// seleciona a cor para a pe�a de acordo com o poder
	void cria_cor();							
	

};

#endif
