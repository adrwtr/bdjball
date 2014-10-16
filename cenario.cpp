#include <allegro.h>

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <cstdlib>
#include <iomanip>

using std::ios;


#include "cenario.h"
#include "pecas.h"


/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo cenario.cpp contem os metodos da classe cenario

Data de Criação
16/01/2008

Data última modificação
20/02/2008
*/


///#####################################
// PASSO 3 continuação
///#####################################
Cenario::Cenario() 
{
  i = 0;
	c = 0;

	cor = 0;

	tamanho_x = 0;
	tamanho_y = 0;
    
	buffer 		   = NULL;    
	fase_atual 	 = 0;
  vtotal_fases = 0;
	
	
	vidas = 3;  
}
    
Cenario::~Cenario()
{
    
}
    
// inicia o cenario
void Cenario::iniciar( int vtamanho_x, int vtamanho_y )
{
    tamanho_x = ( vtamanho_x > 0 && vtamanho_x < 640 ? vtamanho_x : 100 );
    tamanho_y = ( vtamanho_y > 0 && vtamanho_y < 480 ? vtamanho_y : 100 );
    
    // cria o buffer para as imagens do cenario
	  buffer = create_bitmap( 640, 480 );
	
	  // este é o buffer da imagem lida do txt
    img_fundo = create_bitmap( 640, 480 );
	
	  // cor nao está sendo usada se a imagem lida do txt for != NULL
    cor    = makecol( 255, 255, 0 );
	
	
	
	  // inicia com 3 vidas
    vidas = 3;
    		
    fase_atual = 0;
    
	  // ATENÇÃO>
	  // Lembre sempre de iniciar seus arrays 
		
    // inicia array
    for ( i=0; i<(::total_pecas); i++ )
    {
        pecas[i] = NULL;
    }
	
    for ( i=0; i<(::total_fases ); i++ )
    {
		    nome_fases[ i ] = NULL;	
	  }
    
    for ( i=0; i< (::total_bolas ); i++ )
    {
        bolas[i] = NULL;
    }
        
	  // cria a primeira bola
    bolas[0] = new Bolas();
    bolas[0]->iniciar( ((tamanho_x/2) + 10), (tamanho_y - 35) );
    
	
	
	
    // iniciar efeitos
    for ( i=0; i< (::total_efeitos ); i++ )
    {
        efeitos[i] = NULL;
    }    
}
    
// Reinicia o objeto
void Cenario::destrutor()
{
  i = 0;
	c = 0;
	
	tamanho_x = 0;
	tamanho_y = 0;
	
	cor 	= 0;
  vidas 	= 0;
    
    
	// função da allegro muito importante para os BITMAPS
	destroy_bitmap( buffer );
  destroy_bitmap( img_fundo );
    
	buffer 		= NULL; 
  img_fundo 	= NULL;
	
	
    
  // inicia array  
	// Observe como apagamos as alocações da memoria  
  for ( i=0; i<(::total_pecas); i++ )
  {
      if ( pecas[i] != NULL )
      {
          delete pecas[i];
          pecas[i] = NULL;
      }
  } 
	
	for ( i=0; i<(::total_fases ); i++ )
  {
		delete nome_fases[ i ];
		nome_fases[i] = NULL;	
	}        
	
	
	// destroi as bolas
  for ( i=0; i< (::total_bolas ); i++ )
  {
    if (  bolas[i] != NULL )
    {
      // executa o destrutor dos objetos pode limpar os BITMAPS
			bolas[i]->destrutor();
			
      delete bolas[i];
      bolas[i] = NULL;
		}
  }
    
  // efeitos
  for ( i=0; i< (::total_efeitos ); i++ )
  {
    if (  efeitos[i] != NULL )
    {
      delete efeitos[i];
      efeitos[i] = NULL;
		}        
  }	
	
}
    
// imprime todo o cenario
BITMAP * Cenario::mostrar()
{
  // limpa o buffer
	clear( buffer );  
	
	// fundo
  rectfill( buffer, 10, 10, ( tamanho_x + 10 ), ( tamanho_y + 10 ), cor );
	
	// imagem de fundo
	if ( img_fundo != NULL )
	{
    	blit( img_fundo, buffer, 0, 0, 10, 10, ( tamanho_x + 10 ), ( tamanho_y + 10 ) );
	}
    
  // imprime as pecas     
  for ( i=0; i<(::total_pecas); i++ )
  {
      if ( pecas[i] != NULL )
      {
        pecas[i]->mostrar( buffer );
      }
  }    
    
	// imprime e atualiza as posições das bolas
  for ( i=0; i< (::total_bolas ); i++ )
  {
    if (  bolas[i] != NULL )
    {
      bolas[i]->mostrar( buffer );
      bolas[i]->refresh();
		}
	}
	
	bool temp1 = false;
	for ( i=0; i< (::total_efeitos ); i++ )
  {
    if (  efeitos[i] != NULL )
    {
      temp1 = efeitos[i]->mostrar( buffer );
			
			// caso o efeito não exista mais
      if ( temp1 == false )
      {
        delete efeitos[i];
        efeitos[i] = NULL;
      }
		}        
  }	
    
    
  return buffer;        
}
    
// Verifica colisoes    
void Cenario::colisao_bola( BITMAP * fundo, Jogador *jogador )
{	
	
	int proxima_bola = -1;
	
	// Controles das bolas
  for ( i=0; i< (::total_bolas ); i++ )
  {
    if (  bolas[i] != NULL )
    {
                                                
      jogador->colisao_bola( bolas[i] );
			
            
      ///////////////////
      // Colisoes cenario
      if ( bolas[i]->posicao_x < ( 10 ) )
		  {
		    bolas[i]->posicao_x = bolas[i]->tamanho + 20;
		  }
		    
			if ( bolas[i]->posicao_x > ( this->tamanho_x + bolas[i]->tamanho ) )
		  {
		    bolas[i]->posicao_x = this->tamanho_x - bolas[i]->tamanho - 20;		    	
		  }
		    
			// bateu em alguma das laterais
		  if ( 
			bolas[i]->posicao_x <= ( 10 + bolas[i]->tamanho ) || 
			bolas[i]->posicao_x >= ( this->tamanho_x - bolas[i]->tamanho ) 
			)
		  {
		    	bolas[i]->direcao_x *= -1;
		    	
          adiciona_efeito( 1 );
		  }
		    
			// bateu em cima
		  if ( bolas[i]->posicao_y <= ( 10 + bolas[i]->tamanho ) )
		  {		    	
				bolas[i]->direcao_y *= -1;
				
				adiciona_efeito( 1 );
		  }		    
		    
			// bateu no fundo do cenario.. precisa destruir a bola
		  if ( bolas[i]->posicao_y >= ( this->tamanho_y - bolas[i]->tamanho ) )
		  {
				if ( DEBUG_MODE )
		    {
					bolas[i]->direcao_y *= -1;
				}
				
				bolas[i]->destrutor();
				delete bolas[i];
				bolas[i] = NULL;	
			}
		    
      // Colisoes cenario
      ///////////////////
		    
		    
		  ///////////////////
		  // colisao peças com a bola
		    
		  int acao = 0;
        	
      if ( bolas[i] != NULL )
      {
        	
    		for ( c=0; c<(::total_pecas); c++ )
    		{
		        if ( pecas[c] != NULL )
		        {
		            acao = pecas[c]->colisao_bola( bolas[i] );
			            			            
			            
    						////////////
		            // ACOES
		            if ( acao != 0 )
			    		  {					
                  adiciona_efeito( 2 );
                            
      						// destroi pedra 
      						pecas[c]->destrutor();
      						delete pecas[c];							
      						pecas[c] = NULL;
							
					        
  			    			// aumenta velocidade
  			    			if ( acao == 1 )
  			    			{
  			    			  bolas[i]->adiciona_velocidade_x();    			
  			    			} 
  			    			
  			    			// cria nova bola
  			    			if ( acao == 2 )
  			    			{   
    								proxima_bola = -1;	
    								
    								for ( int b=0; b< (::total_bolas ); b++ )
    							  {
    							    if (  bolas[b] == NULL )
    							    {
    										proxima_bola = b;
    										b = (::total_bolas );
    									}
    								}
  								
  								     
                    if ( proxima_bola != -1 )
                    {
                      bolas[proxima_bola] = new Bolas();
    				          bolas[proxima_bola]->iniciar(  jogador->posicao_x + 10, jogador->posicao_y - 5  );
                    } 
			    			}
			    			
			    			// aumenta jogador
			    			if ( acao == 3 )
			    			{
			    				jogador->adiciona_tamanho();
			    			}
			    			

			    			if ( acao == 4 )
			    			{
								  jogador->remove_tamanho();			    				
			    			}	
			    			
			    			if ( acao == 5 )
			    			{
								  jogador->adiciona_velocidade();
							  }
			    			
			    			if ( acao == 6 )
			    			{
			            jogador->remove_velocidade();
			          }
			                

			    			if ( acao == 7 )
			    			{
			    			  bolas[i]->remove_velocidade_x();    			
			    			} 

			    			if ( acao == 8 )
			    			{
			    			  bolas[i]->adiciona_velocidade_x();    			
								  bolas[i]->adiciona_velocidade_x();    			
								  bolas[i]->adiciona_velocidade_y();    			
			    			}
							
							  if ( acao == 9 )
			    			{
			    			  bolas[i]->adiciona_velocidade_y();    			
								  bolas[i]->adiciona_velocidade_y();    			
								  bolas[i]->adiciona_velocidade_x();    			
			    			} 
							
							  if ( acao == 10 )
			    			{
			    			  bolas[i]->remove_velocidade_x();  
								  bolas[i]->remove_velocidade_y();    			
			    			}														
									                
			    			
			    			
			    			acao = 0;
			    		}    		
			        // FIM ACOES
			        ////////////
					  }
						    
			    
	            
	        }
	        //  FOR Controles das bolas
			  }
        	
    	} 
    	
	
	}
	  
    
    
    
    
}


///#####################################
// PASSO 3 FIM
///#####################################


///#####################################
// PASSO 4 
///#####################################

///#####################################
// Abra o arquivo jogador.h
///#####################################





  ///#####################################
  // PASSO 6 - Continuação
  ///#####################################

    
// leitor das fases
bool Cenario::le_fases()
{
	// abre o arquivo para leitura
	// ler em http://bdjogos.com/adrw/c/arquivos_acesso_sequencial.html
	ifstream leitor( "fases.txt", ios::in );

	if ( !leitor )
	{		
		return false;
	}
	
	char temp[30];
	char * nome_fase;
	int contador = 0;
	
		
	while ( leitor >> temp )
	{
		nome_fase = new char[30];
		
		// copia o que tem em temp para nome_fase
		strcpy( nome_fase, temp );

		
		// aponta
		this->nome_fases[contador] = nome_fase;
		
		contador++;  
		vtotal_fases++;
		
	}
	
	// se lembre sempre de fechar o leitor
	leitor.close();
	
	return true;	
}

bool Cenario::cria_fase()
{
	  // já é ultima fase ???
    if ( vtotal_fases == fase_atual )
    {
        return false;   
    }
    else
    {
    	// le proxima fase	
    	ifstream leitor( nome_fases[fase_atual], ios::in );
    	
    	int vposx = 0;
    	int vposy = 0;
    	int poder = 0;
    	
    	char temp[1];
    
      if ( leitor >> this->tamanho_x >> this->tamanho_y >> this->bitmap_fase )
      {
        img_fundo = load_bitmap( bitmap_fase, NULL );           
      }
    	
    	while ( leitor >> vposx >> vposy >> poder )
    	{
    		for ( i=0; i<(::total_pecas); i++ )
    		{
    			if ( pecas[i] == NULL )
    			{
    				pecas[i] = new Pecas();
    				pecas[i]->iniciar( vposx, vposy, poder );
    				i = (::total_pecas);
    			}
    		}
    	}
    	
    	leitor.close();
    	
    	fase_atual++;
    	return true;	
    }
}


///#####################################
// PASSO 6 - FIM 
///#####################################


///#####################################
// PASSO 7 
///#####################################

///#####################################
// abra o arquivo main.cpp
///#####################################



bool Cenario::verifica_vidas()
{
	int num_bolas = 0;
	
  for ( i=0; i< (::total_bolas ); i++ )
  {
    if (  bolas[i] != NULL )
    {	
		  num_bolas++;
			i = ::total_bolas;
		}
  }
	
	// se nao tem nenhuma bola no cenario
	// tira uma vida e cria nova bola
	if ( num_bolas == 0 )
	{
		vidas--;
		
		if ( bolas[0] == NULL )
		{
		  bolas[0] = new Bolas();
	    bolas[0]->iniciar( (this->tamanho_x / 2) + 10, this->tamanho_y - 35  );
    }
		
	}	
	
	// acabou o jogo
	if ( vidas == 0 )
	{
		return false;	
	}
	
	// jogo continua
	return true;
}

void Cenario::adiciona_efeito( int id )
{  		    	
    for ( e=0; e<(::total_efeitos); e++ )
    {
        if ( efeitos[e] == NULL )
        {
            efeitos[e] = new Efeitos();
            efeitos[e]->iniciar( bolas[i]->posicao_x, bolas[i]->posicao_y, id  );
            e = ::total_efeitos;
        }   
    }  
}
    
    
// verifica pecas do cenario
bool Cenario::verifica_pecas()
{
  for ( c=0; c<(::total_pecas); c++ )
	{
	   if ( pecas[c] != NULL )
	   {
        c = (::total_pecas);
        return true;
     }
  }
    
  return false;
}
    
// fase de teste
void Cenario::teste()
{
    pecas[0] = new Pecas();
    pecas[0]->iniciar( 50, 200, 1 );
    
    pecas[1] = new Pecas();
    pecas[1]->iniciar( 210, 200, 2 );        
     
    pecas[2] = new Pecas();
    pecas[2]->iniciar( 110, 10, 3 );     
    
    pecas[3] = new Pecas();
    pecas[3]->iniciar( 10, 150, 4 );         
}
    
    
    
