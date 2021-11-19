#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h> // strcmp -- Biblioteca de comparação de strings !!!!


typedef struct  cadastro cad;
  
  struct cadastro{
  	char nome [30];
  	char comando;
  	int quantidade;
  	int codigo;
  	float preco;
  	float valor_caixa;
  };

typedef struct estoque estq;

  struct estoque{
  	char nome[30];
  	int quantidade_restante;
  	int codigo;
  };

typedef struct caixa cx;

  struct caixa{
  	float valor_total;
  	float valor_vendido;
  	float lucro;
  };

      void cabecalho ();
      void getch ();
      void insprod(); 
      void list();
      void pesquisar();
      void lucro();
      void venda();
      float valor_tot(float aux);
      float x;



int main (){
	fflush(stdin);
	setlocale(LC_ALL,"portuguese.h");
	int op;
	char comando;
	cx c;
	
    do{
        cabecalho ();
    	printf("\tMENU PRINCIPAL: \n1-Inserir novo produto \n2-Venda de produto \n3-Pesquisar produto \n4-Listar todos os produtos \n5-Valor do caixa \n6-Lucro atual \n7-Sair \nInsira a opcao desejada:  ");
    	scanf("%i", &op);
    	
    	switch (op){
    		
    		case 1:
    			insprod();
    		break;
    		
			case 2:
				venda();
    		break;
    		
    		case 3:
    			pesquisar();
    		break;
    		
    		case 4:
    			list();
    		break;
    		
    		case 5:
    			FILE *file;
    			file = fopen("filepredutos.txt", "wb"); 
    	if (file == NULL){
	
		printf("Desculpe, foram encontrados problemas na abertudo do arquivo!");

	}
	    else{
	    	float vt;
	    	cabecalho();
	    	printf("Insira o valor atual do caixa: ");
	    	scanf("%f", &c.valor_total);
	    	x = valor_tot(c.valor_total);
	    	printf("\nEste e o valor do caixa: R$ %.2f\n\n", x);
			getch();
		fclose(file);
		
		}
    			
    		break;
    		
    		case 6:
    		break;
    		
    		case 7:
    			cabecalho();
    			printf(" \nObrigado pela sua visita!\n\n ");
    			getch();
    			break;
    			
    			default: 
    			cabecalho ();
    			printf("\nNumero invalido, por favor insire um numero valido! \n\n");
    			getch();
    			break;

		}
    	
    	
    	
	}while (op != 7);

	
	
	return 0;
}
cx c;


int aux;

void cabecalho (){
	system("cls");
	printf("-------------------------------------------------\n");
    printf("\tBem vindo ao seu caixa !\n");
    printf("-------------------------------------------------\n\n");
}

void getch (){
	system ("pause");
}

void insprod (){
	FILE *file;
	file = fopen("fileprodutos.txt", "ab");
	cad c;
	if (file == NULL){
		printf("Desculpe, foram encontrados problemas na abertudo do arquivo!");
	}
	else {
		do{
			cabecalho();
			
			fflush(stdin);
			
		printf("Insira o nome do produto: ");
		gets(c.nome);
		    fflush(stdin);
		    
		printf("Insira o codigo deste produto: ");
		scanf("%i", &c.codigo);
		
		    fflush(stdin);
		    
		printf("Insira a quantidade deste produto no estoque: ");
		scanf("%i", &c.quantidade);
		
		    fflush(stdin);
		    
		printf("Insira o preco deste produto: ");
		scanf("%f", &c.preco);
		
		    fflush(stdin);
		    
		fwrite(&c, sizeof(cad), 1, file);    
		printf("Deseja continuar ? (s/n) : ");
		scanf("%c", &c.comando);
		
	} while (c.comando == 's');
	fclose(file);
}
}

void list (){
	FILE *file;
	file = fopen("fileprodutos.txt", "rb");
	cad c;
	if (file == NULL){
		printf("Desculpe, foram encontrados problemas na abertudo do arquivo!");
	}
	else{
		cabecalho ();
		while (fread (&c, sizeof(cad), 1,file) == 1 ){
			printf("--------------------------------------------------------\n");
			printf("Nome do produto: %s \nCodigo do produto: %i \nQuantidade: %i \nPreco do produto: %f\n", c.nome, c.codigo, c.quantidade, c.preco);
			printf("--------------------------------------------------------\n\n");
		}
		
	}
	fclose(file);
	getch();
}

void pesquisar (){
	cabecalho();
	FILE *file;
	file = fopen ("fileprodutos.txt", "rb");
	cad c;
	estq e;
	char nome [30];
	
	if (file == NULL){
		printf("Desculpe, foram encontrados problemas na abertudo do arquivo!");
	}
	else{
		printf("Insira o nome do produto a ser pesquisado: ");
		scanf("%s", &nome);
		
		while(fread (&c, sizeof(cad), 1, file) == 1){
			if (strcmp(c.nome , nome) == 0){
				
			    printf("-------------------------------------------------\n");
				printf("Nome do produto: %s \nCodigo do produto: %i \nQuantidade no estoque: %i \nPreco do produto: %f\n ", c.nome, c.codigo,aux, c.preco);
			    printf("-------------------------------------------------\n\n");
			}
		}
	
	fclose(file);
	getch();
}
}

void venda(){
	cabecalho ();
	 
	 int i;
	 int venda;
	 char nome[30]; 
	 cad c;
	 cx x;
	 estq e;
	 
     FILE *file;	
     
	 file = fopen("fileprodutos.txt", "rb");		
	
		
	if (file == NULL){
		printf("Desculpe, foram encontrados problemas na abertura do arquivo! ");
	}
		
   	else{
   		
		printf("Insira o nome do produto a ser vendido: ");
		scanf("%s", &nome);	
		
		while(fread (&c, sizeof(cad), 1, file) == 1){


			if (strcmp(c.nome , nome) == 0){
				
				do{
				for(int i=1;i<2;i++){
					
				fflush(stdin);
				fwrite(&c, sizeof(cad),1,file);
				c.quantidade-=i;
				e.quantidade_restante = c.quantidade;
				aux = c.quantidade;
				fflush(stdin);
			    printf("-------------------------------------------------\n");
  				printf("Produto vendido! \nNome do produto: %s \nCodigo do produto: %i \nQuantidade no estoque: %i \nPreco do produto: %f\n ", c.nome, c.codigo,e.quantidade_restante, c.preco);
				x.valor_vendido = c.preco * i;
			    fflush(stdin);
				x.valor_total -=x.valor_vendido;    
				printf("Saldo atual do caixa: %f\n",x.valor_total);
				printf("-------------------------------------------------\n\n");
			
		fflush(stdin);
        printf("Deseja continuar vendendo este produto? (s/n)");
        scanf("%c", &c.comando);
		}
		
			}while(c.comando == 's');	
			fflush(stdin);
getch();
system("exit");
fclose(file);

	 }
}
}
}

float valor_tot(float aux){
	cx c;
	return(aux+=0);
}
