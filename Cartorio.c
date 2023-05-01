#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de olocação da string

int registro()//Função de cadas os usuarios no sistemas. 
{
	//Inicio criação de variaveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Fim da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os da string
	
	FILE*file; //criar o arquivo
	file =fopen (arquivo, "w"); //cria o arquivo "w" significa esquever	
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen (arquivo, "a");//Abrindo o arquivo	
	fprintf(file,",");//Apenas um alteração visual para separar os dados
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
	setlocale(LC_ALL, "Portuguese"); //localização para português
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
		{
			printf("Não foi possivel abrir o arquivo, não localizado!.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Deleta os dados cadastrados
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
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
	
	int opcao=0; //Define as variáves
	int laco=1; //Laço de repetiçã
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //localização para português
	
	//Definindo Linguagem
		printf("### Cartório da EBAC ###\n\n");
	//Inicio do Menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consulta nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
	
		scanf("%d", &opcao); //aramazenamento a escolhad o usuario
	
		system("cls");//Responsavel por limpar a tela
	
			switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();	//chamada de funções
			break;
		
			case 2:
			consulta();
			break;	
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
