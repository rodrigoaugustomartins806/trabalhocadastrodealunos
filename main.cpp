#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 70

typedef struct
{
	char nome[50];
	int idade[50];
	char sexo[50];
	char curso[50];
	char rua[50];
	int numero;
	int cep;
	float notas[4];
	int ativo;
		
	
}Aluno;
//Constante definida
Aluno alunos[MAX_ALUNOS];
//Prototipo de Todas as Funções
void menu();
void cadastrar();
void remover();
void aprovados();
void reprovados();
void pesquisar();
void listar();

int main(int argc, char** argv)
{

	menu();
	return 0;
}

void menu()
{
	// system("clear"); Comando para Linux
	 //Comando para Windows
	//Variavel que ira receber a opção do menu
	
	int op;
	do{
	system("cls");

	printf("\n ************************************\n");
	printf(" * Bem vindo a o cadastro de Alunos *\n");
	printf(" * Desenvolvido por:                *\n");
	printf(" * Sarah Ketlen                     *\n");
	printf(" * Rodrigo Martins                  *\n");
	printf(" ************************************\n");
	printf("\n");
	printf( "Selecione: \n" );
	printf("\n");
	printf( "1 - Cadastrar Aluno\n");
	printf( "2 - Listar Alunos\n" );
	printf( "3 - Atualizar cadastro\n");
	printf( "4 - Deletar Aluno\n");
	printf( "5 - Pesquisar Aluno\n");
	printf( "6 - Alunos Reprovados\n");
	printf( "7 - Alunos Aprovados\n");
	printf( "0 - Sair\n" );
	printf( "\nEscolha uma opção(0-4):\n ");
	scanf("%d",&op);
	//limpando o buffer 
	getchar();
	switch(op){

		case 1:
				
				cadastrar();
		break;

		case 2:
				
				listar();
		break;


		case 4:

				remover();
		break;

		case 5:

				pesquisar();
		break;

		case 6:

				reprovados();
		break;

		case 7:

				aprovados();
		break;

	}
			getchar();
	} while(op!=0);
	
}
void cadastrar()
{
	
	char nome[50];
	float notas[4];
	int idade;
	char sexo;
	char curso[50];
	char rua[50];
	int numero;
	int cep;
	int op;

	do{
		system("cls");
		printf("\n********************CADASTRO DE ALUNOS********************\n");
		printf("\nNome: ");
		//Usando o fgets e o sizeof para ele calcular automanticamente
		//com base no tamanho da minha variavel
		fgets(nome,sizeof(nome),stdin);
		
		printf("\nIdade: ");
		scanf("%d",&idade);
		getchar();
		printf("\nSexo: ");
		scanf("%c",&sexo);
			getchar();
		printf("\nCurso: ");
	fgets(curso,sizeof(curso),stdin);	
	//	scanf("%c",&curso);
	//		getchar();
		printf("\nRua: ");
		fgets(rua,sizeof(rua),stdin);
	//	scanf("%c",&rua);
		printf("\nNumero: ");
		scanf("%d",&numero);
			getchar();
		printf("\nCep: ");
		scanf("%d",&cep);
			getchar();
		printf("\n1 Bimestre: ");
		//Cadastrando as Notas e passando o indice [0]
		scanf("%f",&notas[0]);
		printf("\n2 Bimestre: ");
		scanf("%f",&notas[1]);
		printf("\n3 Bimestre: ");
		scanf("%f",&notas[2]);
		printf("\n4 Bimestre: ");
		scanf("%f",&notas[3]);
		//um laço para cadastro dos alunos conforme tamanho estabelecido
		for (int i = 0 ;i< MAX_ALUNOS; i++)
		{
			//Neste caso se tiver alguma cadastro igual a zero 
			//podemos substituir o mesmo
			if(alunos[i].ativo==0)
			{
    			
				alunos[i].notas[0] = notas[0];
				alunos[i].notas[1] = notas[1];
				alunos[i].notas[2] = notas[2];
				alunos[i].notas[3] = notas[3];
				//para cadastrar o nome nao podemos usar a mesma estrutura acima
				//neste caso vamos usar a funcao strcpy 
				strcpy(alunos[i].nome,nome);
				alunos[i].idade[i]=idade;
				alunos[i].sexo[i]=sexo;
				strcpy(alunos[i].curso,curso);
				strcpy(alunos[i].rua,rua);
				alunos[i].numero=numero;
				alunos[i].cep=cep;
				//tenho que colocar um break para ele parar 
				//senao vai cadastrar diversas vezes
				alunos[i].ativo=1;
				break;



			}

		}


		printf("\n1 - Continuar\n0 - Para Sair\n");
		scanf("%d",&op);
		//usando o comando getchar para  limpar o que tiver guardado 
	getchar();
	}while(op!=0);

	
}
void remover()
{
	int matricula;
	listar();
	printf("\nDigite a matricula para ser Removida\n");
	scanf("%d",&matricula);
	--matricula;
	alunos[matricula].ativo=0;
	getchar();
	printf("\nAluno Excluido Com Sucesso!!!!\n");

	
	
	
}
void reprovados()
{
	system("cls");
float media;

printf("\n LISTA DE ALUNOS REPROVADOS\n");

for (int i = 0; i < MAX_ALUNOS; ++i)
{
if (alunos[i].ativo ==1)
{
	media = 0;
	media = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3] ;
	media = media / 4;
	if (media < 7.0)
	{
	printf("\nMatricula: %d\n", i+1);
	printf("Nome: %s \n",alunos[i].nome);
	printf("1 Bim: %.2f \n",alunos[i].notas[0]);
	printf("2 Bim: %.2f \n",alunos[i].notas[1]);
	printf("3 Bim: %.2f \n",alunos[i].notas[2]);
	printf("4 Bim: %.2f \n",alunos[i].notas[3]);
    printf("\n-------------------------------");
	}
	
}

}


	
}
void pesquisar()
{	system("cls");

	char nome[50];
	int op;
	do{system("cls");
	printf("\nDigite o nome do Aluno para Pesquisar: ");
	//scanf("%c",&nome);
	fgets(nome,sizeof(nome),stdin);

for (int i = 0; i < MAX_ALUNOS; ++i)
{
if (alunos[i].ativo ==1)
{
	printf("\n\n--------Dados do Aluno--------\n");
	printf("\nMatricula:  %d\n", i+1);
	printf("Nome:  %s",alunos[i].nome);
	printf("idade:  %d \n",alunos[i].idade[i]);
	printf("Sexo:  %c \n",alunos[i].sexo[i]);
	printf("\n--------Dados do Curso--------\n");
	printf("\nCurso:  %s \n",alunos[i].curso);
	
	printf("\n----------Endereço-------------\n");
	printf("\nRua: %sN: %d \n",alunos[i].rua,alunos[i].numero);
	printf("Bairro: Cruzeiro\nCidade: Belo Horizonte\n");
	printf("Estado: Minas Gerais\n");
	printf("Cep: %d\n",alunos[i].cep);
	printf("\n-----------Notas---------------\n");
	printf("1 Bim: %.2f \n",alunos[i].notas[0]);
	printf("2 Bim: %.2f \n",alunos[i].notas[1]);
	printf("3 Bim: %.2f \n",alunos[i].notas[2]);
	printf("4 Bim: %.2f \n",alunos[i].notas[3]);
    printf("\n-------------------------------");
}

}
	printf("\n---------------------------------------------\n");
	printf("\nDigite 0 para Sair  ou 1 para Nova Pesquisa\n");
	scanf("%d",&op);
	getchar();
	}while(op!=0);
	
}

void listar()
{	system("cls");

printf("\n LISTA DE ALUNOS\n");
for (int i = 0; i < MAX_ALUNOS; ++i)
{
if (alunos[i].ativo ==1)
{
	printf("\n\n--------Dados do Aluno--------\n");
	printf("\nMatricula:  %d\n", i+1);
	printf("Nome:  %s",alunos[i].nome);
	printf("idade:  %d \n",alunos[i].idade[i]);
	printf("Sexo:  %c \n",alunos[i].sexo[i]);
	printf("\n--------Dados do Curso--------\n");
	printf("\nCurso:  %s \n",alunos[i].curso);
	
	printf("\n----------Endereço-------------\n");
	printf("\nRua: %sN: %d \n",alunos[i].rua,alunos[i].numero);
	printf("Bairro: Cruzeiro\nCidade: Belo Horizonte\n");
	printf("Estado: Minas Gerais\n");
	printf("Cep: %d\n",alunos[i].cep);
	printf("\n-----------Notas---------------\n");
	printf("1 Bim: %.2f \n",alunos[i].notas[0]);
	printf("2 Bim: %.2f \n",alunos[i].notas[1]);
	printf("3 Bim: %.2f \n",alunos[i].notas[2]);
	printf("4 Bim: %.2f \n",alunos[i].notas[3]);
    printf("\n-------------------------------");
}

}


}
void aprovados()
{
system("cls");
float media;

printf("\n LISTA DE ALUNOS APROVADOS\n");

for (int i = 0; i < MAX_ALUNOS; ++i)
{
if (alunos[i].ativo ==1)
{
	media = 0;
	media = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2] + alunos[i].notas[3] ;
	media = media / 4;
	if (media > 7.0)
	{
	printf("\nMatricula: %d\n", i+1);
	printf("Nome: %s \n",alunos[i].nome);
	printf("1 Bim: %.2f \n",alunos[i].notas[0]);
	printf("2 Bim: %.2f \n",alunos[i].notas[1]);
	printf("3 Bim: %.2f \n",alunos[i].notas[2]);
	printf("4 Bim: %.2f \n",alunos[i].notas[3]);
    printf("\n-------------------------------");
	}
	
}

}

}
