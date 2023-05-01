#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de oloca��o da string

int registro()//Fun��o de cadas os usuarios no sistemas. 
{
	//Inicio cria��o de variaveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Fim da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os da string
	
	FILE*file; //criar o arquivo
	file =fopen (arquivo, "w"); //cria o arquivo "w" significa esquever	
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//Abrindo o arquivo	
	fprintf(file,",");//Apenas um altera��o visual para separar os dados
	fclose(file);//Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //localiza��o para portugu�s
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Deleta os dados cadastrados
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);//remove o cpf do banco de daos
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo cpf
	
	if(file == NULL)
	{
		printf("O foi usuario deletado.\n");
		
	}
	system("pause");
}

int main()
{
	
	int opcao=0; //Define as vari�ves
	int laco=1; //La�o de repeti��
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //localiza��o para portugu�s
	
	//Definindo Linguagem
		printf("### Cart�rio da EBAC ###\n\n");
	//Inicio do Menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consulta nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu
	
	
		scanf("%d", &opcao); //aramazenamento a escolhad o usuario
	
		system("cls");//Responsavel por limpar a tela
	
			switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();	//chamada de fun��es
			break;
		
			case 2:
			consulta();
			break;	
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}
