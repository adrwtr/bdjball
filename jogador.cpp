#include <allegro.h>
#include "jogador.h"
#include "bolas.h"


/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo jogador.cpp contem os metodos da classe jogador

Data de Criação
16/01/2008

Data última modificação
22/02/2008
*/


///#####################################
// PASSO 4 - Continuação 2
///#####################################

// construtor padrão do C++
Jogador::Jogador() 
{
	i = 0;
	c = 0;
	
	tamanho_x 	= 0;
	tamanho_y 	= 0;
	
	cor = 0;
	
	posicao_x 	= 0;
	posicao_y 	= 0;
	
	limite_x1 	= 0;
	limite_x2 	= 0;
	
	velocidade 	= 0;
}

Jogador::~Jogador()
{
	destrutor();
}

// inicia o jogador
void Jogador::iniciar( int posx, int posy, int vlimite1, int vlimite2 )
{
	tamanho_x = 60;
	tamanho_y = 10;
	
	posicao_x = posx;
	posicao_y = posy;
	
	limite_x1 = vlimite1;
	limite_x2 = vlimite2;
	
	velocidade = 10;
	
	cor = makecol( 0,0,255 );    
	
	bateu = 0;
}

// destroi
void Jogador::destrutor()
{
	i = 0;
	c = 0;
	
	tamanho_x = 0;
	tamanho_y = 0;
	
	cor = 0;
	
	posicao_x 	= 0;
	posicao_y 	= 0;       
	
	limite_x1 	= 0;
	limite_x2 	= 0;
	
	velocidade	= 0;  
}

// imprime o jogador
void Jogador::mostrar( BITMAP * fundo )
{
	rectfill( fundo, posicao_x, posicao_y, ( tamanho_x + posicao_x ), ( tamanho_y + posicao_y ), cor );
}

// verifica novas posições
void Jogador::refresh()
{
	// se apertar para a esquerda
	// ler http://www.bdjogos.com/biblioteca_conteudo.php?id=17
	if ( key[KEY_LEFT] && posicao_x > limite_x1 )
	{
		posicao_x -= velocidade;
	}
	
	// se apertar para a direta
	if ( key[KEY_RIGHT] && posicao_x < ( limite_x2 - tamanho_x ) )
	{
		posicao_x += velocidade;
	}
	
	// Atenção: 
	// os testes de teclado acima não irão funcionar 
	// caso os testes de mouse não estiverem em comentários
	
	// para jogar com o teclado, é preciso comentar as instruções abaixo

	// se posicao do mouse for mario que X	
	// ler em http://www.bdjogos.com/biblioteca_conteudo.php?id=15
	if ( mouse_x > posicao_x )
	{
		posicao_x += velocidade;	
	}
	
	if ( mouse_x < posicao_x )
	{
		posicao_x -= velocidade;	
	}
	
	if ( posicao_x < limite_x1 )
	{
		posicao_x = limite_x1;
	}
	
	if ( posicao_x > ( limite_x2 - tamanho_x ) )
	{
		posicao_x = limite_x2 - tamanho_x;
	}
}

// Verifica a colisão com a bola 
// ler em http://www.bdjogos.com/conteudo.php?link=capitulo_27.php
void Jogador::colisao_bola( Bolas *bola )
{
	// var auxiliar
	int divisao = 0;
	
	// verifica apenas a colisao  
	if ( 
	(  ( bola->posicao_x + bola->tamanho ) > this->posicao_x  ) &&  
	(  ( bola->posicao_y + bola->tamanho ) > this->posicao_y   ) && 	
	( bola->posicao_x < ( this->posicao_x + this->tamanho_x )  ) && 	
	( bola->posicao_y < ( this->posicao_y + this->tamanho_y )  )
	)
	{
		// caso tenha colisao, dividimos o jogador por 6 partes 
		// (int)( .. ) transforma a divisao fracionario para um número inteiro
		divisao = (int)( ( this->tamanho_x ) / 6 );
		
		// testa se a bola pegou no primeiro pedaço do jogador
		// joga sempre a bola para a esquerda
		// aumenta a velocidade xy
		if ( bola->posicao_x > this->posicao_x && bola->posicao_x < this->posicao_x + ( divisao * 1 ) )
		{
			if ( bola->posicao_x < ( bola->posicao_x  + ( bola->velocidade_x * bola->direcao_x ) ) )
			{
				bola->direcao_x = -1;   
			}        
		
			bola->adiciona_velocidade_x();
			bola->adiciona_velocidade_y();
			
			// locao aonde bateu
			bateu = 1;
		}
		
		// joga para a esquerda
		// remove velocidade em x
		// amenta velocidade em y
		if ( bola->posicao_x > ( this->posicao_x + ( divisao * 1 ) ) && bola->posicao_x < this->posicao_x + ( divisao * 2 ) )
		{
			if ( bola->posicao_x < ( bola->posicao_x  + ( bola->velocidade_x * bola->direcao_x ) ) )
			{
				bola->direcao_x = -1;   
			} 
			
			bola->remove_velocidade_x();
			bola->adiciona_velocidade_y();
			
			// locao aonde bateu
			bateu = 2;
		}
		
		// joga para a esquerda
		// diminui velocidade
		if ( bola->posicao_x > ( this->posicao_x + ( divisao * 2 ) ) && bola->posicao_x < this->posicao_x + ( divisao * 3 ) )
		{
			if ( bola->posicao_x < ( bola->posicao_x  + ( bola->velocidade_x * bola->direcao_x ) ) )
			{
				bola->direcao_x = -1;   
			} 
			
			bola->remove_velocidade_x();
			bola->remove_velocidade_y();
			
			// locao aonde bateu
			bateu = 3;
		}
		
		// joga para direita
		// diminui velocidade

		if ( bola->posicao_x > ( this->posicao_x + ( divisao * 3 ) ) && bola->posicao_x < this->posicao_x + ( divisao * 4 ) )
		{
			if ( bola->posicao_x > ( bola->posicao_x  + ( bola->velocidade_x * bola->direcao_x ) ) )
			{
				bola->direcao_x = bola->direcao_x * -1;   
			} 
			
			bola->remove_velocidade_x();
			bola->remove_velocidade_y();
			
			bateu = 4;
		}
		
		// joga para a direita
		// remove velocidade em x
		// aumenta em y
		if ( bola->posicao_x > ( this->posicao_x + ( divisao * 4 ) ) && bola->posicao_x < this->posicao_x + ( divisao * 5 ) )
		{
			if ( bola->posicao_x > ( bola->posicao_x  + ( bola->velocidade_x * bola->direcao_x ) ) )
			{
				bola->direcao_x = bola->direcao_x * -1;   
			}     
			
			bola->remove_velocidade_x(); 
			bola->adiciona_velocidade_y();      
			
			bateu = 5;
		}
		
		// joga para a direita
		// aumenta velocidade xy
		if ( bola->posicao_x > ( this->posicao_x + ( divisao * 5 ) ) && bola->posicao_x < this->posicao_x + ( divisao * 6 ) )
		{
			if ( bola->posicao_x > ( bola->posicao_x  + ( bola->velocidade_x * bola->direcao_x ) ) )
			{
				bola->direcao_x = bola->direcao_x * -1;   
			} 
			
			bola->adiciona_velocidade_x();
			bola->adiciona_velocidade_y();
			
			bateu = 6;
		}
		
		
		
		// joga bola para cima
		//bola->direcao_y *= -1;
		bola->direcao_y = -1;
	}     


}

void Jogador::adiciona_tamanho()
{
	( tamanho_x < limite_x2 ? tamanho_x+=10 : tamanho_x );
}

void Jogador::remove_tamanho()
{
	( tamanho_x > 20 ? tamanho_x-=10 : tamanho_x );
}

void Jogador::adiciona_velocidade()
{
	( velocidade < 50 ? velocidade+=10 : velocidade );
}

void Jogador::remove_velocidade()
{
	( velocidade > 10 ? velocidade-=30 : velocidade );
	( velocidade <= 0 ? velocidade=1 : velocidade );
}

///#####################################
// PASSO 4 - FIM
///#####################################


///#####################################
// PASSO 5 
///#####################################

///#####################################
// Abra o arquivo bolas.h
///#####################################

