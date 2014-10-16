#include <allegro.h>
#include "pecas.h"
#include "bolas.h"

/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo pecas.cpp contem os metodos da classe pecas

Data de Criação
16/01/2008

Data última modificação
22/02/2008
*/


// inicia a peca
void Pecas::iniciar( int pos_x, int pos_y, int vpoder )
{
	// Tamanho estão constantes.. 
	// poderia ser alterado para receber valores tbm
	tamanho_x = 80;
	tamanho_y = 10;
	
	// recebe + 10 para ficar sempre dentro da tela
	posicao_x = pos_x + 10;
	posicao_y = pos_y + 10;
	
	// o poder determina a cor tbm..
	// cada peça tem um poder que interfere diretamente no jogo	
	poder = vpoder;
	
	// seleciona a cor para a peça de acordo com o poder
	this->cria_cor();
}


// reinicia variáveis do objeto
void Pecas::destrutor()
{
	i = 0;
	c = 0;
	
	tamanho_x = 0;
	tamanho_y = 0;
	
	posicao_x = 0;
	posicao_y = 0;     
	
	cor 	= 0;	
	poder 	= 0;
}


void Pecas::mostrar( BITMAP * fundo )
{
	rectfill( fundo, posicao_x, posicao_y, (posicao_x + tamanho_x), (posicao_y + tamanho_y), cor );
}


// Verifica colisao com a bola
int Pecas::colisao_bola( Bolas *bola )
{
	int bola_x = bola->posicao_x;
	int bola_y = bola->posicao_y;
	
	int px = bola->posicao_x + ( bola->velocidade_x * bola->direcao_x );
	int py = bola->posicao_y + ( bola->velocidade_x * bola->direcao_y );
	
	// verifica apenas a colisao  
	if ( 
	(  ( bola->posicao_x + bola->tamanho ) 	>  this->posicao_x  ) &&  
	( bola->posicao_x - bola->tamanho  		<  ( this->posicao_x + this->tamanho_x )  ) && 
	( ( bola->posicao_y + bola->tamanho ) 	>  this->posicao_y   ) && 
	( bola->posicao_y - bola->tamanho   	<  ( this->posicao_y + this->tamanho_y )  )
	)
	{
		
		// para cima 		bola->direcao_y = -1;
		// para esquerda 	bola->direcao_x = -1;
		
		// SE indo para esquerda
		if ( bola->direcao_x == -1 )
		{
			// SE subindo
			if ( bola->direcao_y == -1 )
			{
				// havendo colisao desce
				bola->direcao_y = 1; 				
				
				// vai bater na borda do lado esquerdo
				if ( 
				( bola->posicao_x - bola->tamanho ) <= ( this->posicao_x + this->tamanho_x ) 
				&&
				( bola->posicao_x - bola->tamanho ) >= ( this->posicao_x + this->tamanho_x - bola->tamanho ) 
				)
				{
					bola->direcao_x = 1;
					bola->direcao_y = -1;
				}						
				
			}	
			else
			{
				// descendo
				
				// havendo colisao sobe
				bola->direcao_y = -1; 
				
				
				// vai bater na borda do lado esquerdo
				if ( 
				( bola->posicao_x - bola->tamanho ) <= ( this->posicao_x + this->tamanho_x ) 
				&&
				( bola->posicao_x - bola->tamanho ) >= ( this->posicao_x + this->tamanho_x - bola->tamanho ) 
				)
				{
					bola->direcao_x = 1;
					bola->direcao_y = 1;
				}		
					
			}	

		}
		else
		{
		
			// indo para direita
	
			// subindo
			if ( bola->direcao_y == -1 )
			{
				// havendo colisao desce
				bola->direcao_y = 1; 
				
				// vai bater na borda do lado direito
				if ( 
				( bola->posicao_x + bola->tamanho ) >= ( this->posicao_x  ) 
				&&
				( bola->posicao_x + bola->tamanho ) <= ( this->posicao_x + bola->tamanho ) 
				)				
				{
					bola->direcao_x = -1;
					bola->direcao_y = -1;
				}			
			}
			else
			{
				
				// descendo
				
				// havendo colisao desce
				bola->direcao_y = -1; 
				
				// vai bater na borda do lado direito
				if ( 
				(bola->posicao_x + bola->tamanho) >= ( this->posicao_x  ) 
				&&
				(bola->posicao_x + bola->tamanho) <= ( this->posicao_x + bola->tamanho ) 
				)				
				{
					bola->direcao_x = -1;
					bola->direcao_y = 1;
				}			
					
			}
		}
	
	
		
		// caso haja colisao, 
		// retornamos o poder para executar a ação da peça
		
		return this->poder;
	}
	
	return 0;
}


// seleciona a cor correta de acordo com o poder
void Pecas::cria_cor()
{
	switch ( poder )
	{
		case 0 : cor = makecol( 255, 255, 255 );
		break;
		
		case 1 : cor = makecol( 255, 0, 0 );
		break;
		
		case 2 : cor = makecol( 0, 255, 0 );
		break;
		
		case 3 : cor = makecol( 0, 0, 255 );
		break;
		
		case 4 : cor = makecol( 255, 255, 0 );
		break;
		
		case 5 : cor = makecol( 0, 255, 255 );
		break;
		
		case 6 : cor = makecol( 255, 0, 255 );
		break;
		
		case 7 : cor = makecol( 150, 10, 100 );
		break;
		
	}
}
