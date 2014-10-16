#include <allegro.h>
#include <math.h>
#include <ctime> 


/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo efeitos.cpp contem os metodos da classe efeitos

Data de Criação
16/01/2008

Data última modificação
22/02/2008
*/


#include "efeitos.h"

Efeitos::Efeitos()
{
}

Efeitos::~Efeitos()
{    
}

void Efeitos::iniciar( int vx, int vy, int vid )
{
  x 		= vx;
  y 		= vy;
    
	id 		= vid;
        
	f 		= 20;
	dist 	= 1;    
}    

bool Efeitos::mostrar( BITMAP * fundo )
{
    switch( id )
    {
        case 1 :
            return efeito1( fundo );
        break;
    
        case 2:
            return efeito2( fundo );
        break;               
    }   
    
    return false;
} 

// Efeito de bola explodindo
bool Efeitos::efeito1( BITMAP * fundo )
{
    int tx = 0;
    int ty = 0;
    
    if ( f > 0 )
    {
        for ( i=0; i<=380; i++ )
        {
            if ( i % 20 == 0 )
            {

                for ( c=0; c<=dist; c++ )
                {
                    if ( c % 2 == 0 )
                    {                        
                        tx = (int)( dist * sin( GRAU_PARA_RADIANO(i) ) ); 
                        ty = (int)( dist * cos( GRAU_PARA_RADIANO(i) ) ); 
                
                        putpixel( fundo, (x+tx), (y+ty), makecol( 120, 120, 20 ) );	  
                        putpixel( fundo, (x+tx)+1, (y+ty)-5, makecol( 120, 120, 20 ) );	  
                        putpixel( fundo, (x+tx)+1, (y+ty)-3, makecol( 120, 120, 20 ) );	  
                        putpixel( fundo, (x+tx)+2, (y+ty)+2, makecol( 120, 120, 20 ) );	  
                        putpixel( fundo, (x+tx)+2, (y+ty)+5, makecol( 120, 120, 20 ) );	  
                    }
                }
            }  
        }
        
        dist++;       
     
        f--;
        return true;   
    }
    
    return false;
}

// Efeito bizarro
bool Efeitos::efeito2( BITMAP * fundo )
{
    int tx = 0;
    int ty = 0;
    int a = 0;
    
    if ( f > 0 )
    {
        for ( i=0; i<=30; i++ )
        {
            tx = x + rand() % x+dist;
            ty = y + rand() % y+dist;
            
            putpixel( fundo, (tx), (ty), makecol( 255, 100, i ) );	  
            putpixel( fundo, (tx)+1, (ty)+1, makecol( 255, 100, i ) );	  
        }
         
        dist++; 
        f--;
        
        return true;   
    }
    
    return false; 
    
}
