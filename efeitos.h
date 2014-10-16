#ifndef EFEITOS_H
#define EFEITOS_H
	
#include <allegro.h>
#include <math.h>


/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo efeitos.h contem a classe efeitos, 
que fazem aquelas explosões pelo cenario


Data de Criação
16/01/2008

Data última modificação
22/02/2008
*/


// Ler em 
// http://bdjogos.com/biblioteca_conteudo.php?id=24

#define GRAU_PARA_RADIANO( GRAU )    ( ((GRAU) * (M_PI))   / (180)  ) // graus para radianos 
#define RADIANO_PARA_GRAU( RADIANO ) ( ((RADIANO) * (180)) / (M_PI) ) // radianos para graus 

class Efeitos {

private:
     
	// contadores auxiliares    
	int i;
	int c;
	int f;	
	
	// posição do efeito
	int x, y;	
	
	// 
	int dist;
	
	// Tipo de Efeito
	int id;
	
public:    
    
    Efeitos();
    ~Efeitos();
    
    void iniciar( int x, int y, int vid );		// inicia objeto
    
    bool mostrar( BITMAP * fundo );   			// mostra efeito
	 
    bool efeito1( BITMAP * fundo );				
    bool efeito2( BITMAP * fundo );
        
    
};


#endif
