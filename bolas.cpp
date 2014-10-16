#include <allegro.h>
#include "bolas.h"

/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo bolas.cpp contem os metodos da classe bolas

Data de Criação
16/01/2008

Data última modificação
22/02/2008
*/


///#####################################
// PASSO 5 - continuação
///#####################################




// construtor
Bolas::Bolas()
{
}

// destrutor
Bolas::~Bolas()
{
	//destrutor();
}

// inicia o objeto
// foi criado essa função por que funções da Allegro não podem ser chamadas 
// em contrutores e destrutores
void Bolas::iniciar( int pos_x, int pos_y )
{
	posicao_x = pos_x;
	posicao_y = pos_y;
	
	direcao_x = 1;
	direcao_y = -1;
	
	velocidade_x = 2;
	velocidade_y = 2;
	
	tamanho = 5;
	cor 	  = makecol( 10, 10, 255 );


	// contadores e auxiliares
	i = 0;
	c = 0;		
}

// reinicia o objeto bolas
void Bolas::destrutor()
{
	i = 0;
	c = 0;
	
	tamanho = 0;
	cor 	= 0;
	
	posicao_x = 0;
	posicao_y = 0;
	
	direcao_x = 0;
	direcao_y = 0;
	
	velocidade_x = 0;  
	velocidade_y = 0;	
}

// imprime a bola
void Bolas::mostrar( BITMAP * fundo )
{
	bola_normal( fundo );	
}

// atualiza posição da bola
void Bolas::refresh()
{
	posicao_x += ( velocidade_x * direcao_x );
	posicao_y += ( velocidade_y * direcao_y );
}

void Bolas::adiciona_velocidade_x()
{
	if ( velocidade_x < 5 )
	{
		velocidade_x++;
	}
}

void Bolas::remove_velocidade_x()
{
	if ( velocidade_x > 2 )
	{
		velocidade_x --;
	}
}

void Bolas::adiciona_velocidade_y()
{
	if ( velocidade_y < 5 )
	{
		velocidade_y++;
	}
}

void Bolas::remove_velocidade_y()
{
	if ( velocidade_y > 2 )
	{
		velocidade_y --;
	}
}

// imprime o desenho de uma bola personalizada
void Bolas::bola_normal( BITMAP * fundo )
{	
	circlefill( fundo, posicao_x, posicao_y, tamanho,   makecol( 110, 110, 110 ) );
	circlefill( fundo, posicao_x, posicao_y, tamanho-3, makecol( 60, 60, 60 ) );
	circlefill( fundo, posicao_x, posicao_y, tamanho-5, makecol( 30, 30, 30 ) );
	putpixel  ( fundo, posicao_x, posicao_y, makecol( 20, 20, 20 ) );	
}


///#####################################
// PASSO 5 - FIM
///#####################################


///#####################################
// PASSO 6 
///#####################################

///#####################################
// abra o arquivo main.cpp e inicie lendo pelo passo 6
///#####################################


