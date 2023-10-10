#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

// Struct para Alunos
struct Alunos {
	int cpf;
	char nome[30];
	char dataNascimento[15];
	float peso;
	float altura;
	int status;
};

// Struct para Professores
struct Professores {
	int cod_prof;
	char nome[50];
	char endereco[50];
	int telefone;
	int status;
};

// Struct para Modalidades
struct Modalidades {
	int cod_modalidade;
	char descricao[30];
	int cod_prof;
	float valor_aula;
	int limite_alunos;
	int total_alunos;
	int status;
};

// Struct para Matriculas
struct Matriculas {
	int cod_matricula;
	int cpf_aluno;
	int cod_modalidade;
	int qtde_aulas;
};

// indice

struct indice_aluno {
        int codigo;
        int ender;
};

struct indice_professor {
        int codigo;
        int ender;
}; 

struct indice_modalidade {
 		int codigo;
 		int ender;
 };


/* 1) O programa deverá possuir funções específicas para a inclusão de novos dados nas tabelas, exclusão de dados, 
leitura exaustiva e reorganização das tabelas. */

/*// Função para leitura de novo aluno
void leitura_alunos(struct Alunos a[], int &contadoraluno){
	int i = 0;
	for(; i < contadoraluno; i++) {
		cout << "CPF Aluno: \n\n";
		cin >> a[i].cpf;
		cout<< "Nome: \n\n";
		cin >> a[i].nome;
		cout << "CPF \n\n";
		cin >> a[i].cpf;
		cout<< "Data de Nascimento \n\n";
		cin>> a[i].dataNascimento;
		cout << "Peso \n\n";
		cin >> a[i].peso;
		cout << "Altura \n\n";
		cin >> a[i].altura;
	}
	
}

// Função para leitura de novos Professores
void leitura_professor(struct Professores p[], int &contadorprofessor) {
	int i = 0;
	for (; i < contadorprofessor; i++){
		cout << "Codigo Professor: \n\n";
		cin >> p[i].cod_prof;
		cout << "Nome: \n\n";
		cin >> p[i].nome;
		cout << "Enderço: \n\n";
		cin >> p[i].endereco;
		cout << "Telefone: \n\n";
		cin >> p[i].telefone;
	}
}

 Função para leitura de novas modalidades
void leitura_modalidades(struct Modalidades m[], int &contadormodalidade) {
	int i = 0;
	for(; i < contadormodalidade; i++) {
		cout << "Codigo Modalidade: \n\n";
		cin >> m[i].cod_modalidade;
		cout << "Descricao: \n\n";
		cin >> m[i].descricao;
		cout << "Codigo Professor: \n\n";
		cin >> m[i].cod_prof;
		cout << "Valor da Aula: \n\n";
		cin >> m[i].valor_aula;
		cout << "Limite de Alunos: \n\n";
		cin >> m[i].limite_alunos;
		cout << "Total de Alunos: \n\n";
		cin >> m[i].total_alunos;
	}
}

void leitura_matriculas(struct Matriculas m[], int &contadormatricula ) {
	int i = 0;
	for(; i < contadormatricula; i++) {
		cout << "Codigo Matricula: \n\n";
		cin >> m[i].cod_matricula;
		cout << "CPF Aluno: \n\n";
		cin >> m[i].cpf_aluno;
		cout << "Codigo Modalidade: \n\n";
		cin >> m[i].cod_modalidade;
		cout << "Quantidade de Aulas: \n\n";
		cin >> m[i].qtde_aulas;
	}
}
*/
// Leitura Indice

/*
leitura_indice_aluno (struct indice_aluno idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].cpf;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}

leitura_indice_professor (struct indice_professor idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice " << (i+1) << ": ";
        cin >> idx[i].codigo;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].ender;
    }
}
*/

// Inclusão de novos dados nas tabelas

void inclusao_aluno (struct indice_aluno idx[], struct Alunos a[], int &cont, int cod){
    cont++;
    // busca binaria verificar se ja esta cadastrado
    int i = 0, f = cont, x = 0;
     int m =(i + f) / 2;
     while (x == 0) {
     for(; f >= i && cod != idx[m].codigo; m = (i + f)/ 2) {
		if (cod > idx[m].codigo)	
     		i = m + 1;
		else 
			f = m - 1;
	}
	
	if ((cod == idx[m].codigo)) {
		cout << "\nAluno ja existe";
		cout << "\nCodigo: ";
			cin>> cod;
	}
	else{
		x = 1;
	}
}
    // inclusao do novo registro na area de dados
    	a[cont].cpf = cod;
    	cout << "Nome: ";
    	cin >> a[cont].nome;
    	cout << "Data Nascimento: ";
    	cin >> a[cont].dataNascimento;
    	cout << "Peso: ";
    	cin >> a[cont].peso;
    	cout << "Altura: ";
	cin >> a[cont].altura;
    // inclusao na area de indices
	if (cont == 0){
		idx[0].codigo = cod;
		idx[0].ender = cont;
	}
	else{
		for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = cod;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
    getch();
	}
    
}

void buscaaleat_aluno (struct indice_aluno idx[], struct Alunos a[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
        cout << "\n\n Aluno ja? Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCPF do Aluno: " << a[i].cpf;
        cout << "\tNome: " << a[i].nome;
        cout << "\tData Nascimento: " << a[i].dataNascimento;
        cout << "\tPeso: " << a[i].peso;
        cout << "\Altura: " << a[i].altura;
        
    }
    else
        inclusao_aluno (idx, a, cont, cod);
    getch();
}

void excluir_aluno (struct indice_aluno idx[], struct Alunos a[], int &cont, int cod) {
	int i = 0, f = cont;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
		if (cod > idx[m].codigo)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].ender;
	if ((cod == idx[m].codigo) && a[i].status == 0) {
		a[i].status = 1;
		cout <<"\n\n Aluno excluido com Sucesso";
	}
	else 
		cout <<"Aluno não cadastrado";
	getch();
}

void exaustiva_aluno (struct indice_aluno idx[], struct Alunos a[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (a[i].status == 0){
            cout << "\nCPF do Aluno: " << a[i].cpf;
            cout << "\tNome: " << a[i].nome;
            cout << "\tData Nascimento: " << a[i].dataNascimento;
            cout << "\tPeso: " << a[i].peso;
            cout << "\tAltura: " << a[i].altura;
        }
    }
}

void reorganizacao (struct indice_aluno idx[], struct indice_aluno novoidx[], struct Alunos a[], struct Alunos novoal[], int &cont){
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (a[i].status == 0){
            j++;
            novoal[j].cpf = a[i].cpf;
            strcpy (novoal[j].nome,a[i].nome);
            strcpy (novoal[j].dataNascimento,a[i].dataNascimento);
            novoal[j].peso = a[i].peso;
            novoal[j].altura = a[i].altura;
            novoal[j].status = 0;
            novoidx[j].codigo = novoal[j].cpf;
            novoidx[j].ender = j;
        }
    }
    cont = j+1;
}

void inclusao_professor (struct indice_professor idx[], struct Professores p[], int &cont, int codigo){
    cont++;
    // inclusao do novo registro na area de dados
    p[cont].cod_prof = codigo;
    cout << "Nome: ";
    cin >> p[cont].nome;
    cout << "Endereco: ";
    cin >> p[cont].endereco;
    cout << "Telefone: ";
    cin >> p[cont].telefone;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].codigo > codigo; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = codigo;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void buscaaleat_professor (struct indice_professor idx[], struct Professores p[], int &cont, int codigo){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && codigo != idx[m].codigo; m = (i + f) / 2){
        if (codigo > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codigo == idx[m].codigo){
        cout << "\n\n Professor ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo do Professor: " << p[i].cod_prof;
        cout << "\tNome: " << p[i].nome;
        cout << "\tEndereco: " << p[i].endereco;
        cout << "\nTelefone: " << p[i].telefone;
    }
    else
        inclusao_professor(idx, p, cont, codigo);
    getch();
}

void excluir_professor (struct indice_professor idx[], struct Professores p[], int &cont, int cod) {
	int i = 0, f = cont;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
		if (cod > idx[m].codigo)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].ender;
	if ((cod == idx[m].codigo) && p[i].status == 0) {
		p[i].status = 1;
		cout <<"\n\n Professor excluido com Sucesso";
	}
	else 
		cout <<"Professor não cadastrado";
	getch();
}

void exaustiva_professor (struct indice_professor idx[], struct Professores p[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (p[i].status == 0){
            cout << "\nCodigo do Professor: " << p[i].cod_prof;
            cout << "\tNome: " << p[i].nome;
            cout << "\tEndereco: " << p[i].endereco;;
            cout <<"\nTelefone: " << p[i].telefone;
        }
    }
}

void inclusao_modalidade (struct indice_modalidade idx[], struct Modalidades m[], int &cont, int codigo){
    cont++;
    // inclusao do novo registro na area de dados
    m[cont].cod_prof = codigo;
    cout << "Codigo: ";
    cin >> m[cont].cod_modalidade;
    cout << "Descricao: ";
    cin >> m[cont].descricao;
    cout << "Valor da Aula: ";
    cin >> m[cont].valor_aula;
    cout << "Limite de alunos:";
    cin >> m[cont].limite_alunos;
    cout << "Total de alunos: ";
    cin >> m[cont].total_alunos;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].codigo > codigo; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].ender = idx[i].ender;
    }
    idx[i+1].codigo = codigo;
    idx[i+1].ender = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void buscaaleat_modalidade (struct indice_modalidade idx[], struct Modalidades md[], int &cont, int codigo){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && codigo != idx[m].codigo; m = (i + f) / 2){
        if (codigo > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codigo == idx[m].codigo){
        cout << "\n\n Professor ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].ender;
        cout << "\nCodigo da Modalidade: " << md[i].cod_modalidade;
        cout << "\tDescricao: " << md[i].descricao;
        cout << "\tValor da Aula: " << md[i].valor_aula;
        cout << "\nLimite de alunos: " << md[i].limite_alunos;
        cout << "Total de alunos: "  << md[i].total_alunos;
    }
    else
        inclusao_modalidade(idx, md, cont, codigo);
    getch();
}

void excluir_modalidade (struct indice_modalidade idx[], struct Modalidades md[], int &cont, int cod) {
	int i = 0, f = cont;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
		if (cod > idx[m].codigo)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].ender;
	if ((cod == idx[m].codigo) && md[i].status == 0) {
		md[i].status = 1;
		cout <<"\n\n Professor excluido com Sucesso";
	}
	else 
		cout <<"Professor não cadastrado";
	getch();
}

void exaustiva_modalidade (struct indice_modalidade idx[], struct Modalidades md[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].ender;
        if (md[i].status == 0){
           cout << "\nCodigo da Modalidade: " << md[i].cod_modalidade;
            cout << "\tDescricao: " << md[i].descricao;
            cout << "\tValor da Aula: " << md[i].valor_aula;
            cout << "\nLimite de alunos: " << md[i].limite_alunos;
            cout << "Total de alunos: "  << md[i].total_alunos;
        }
    }
}

/*Menu Principal*/
void mainMenu (){
	system("cls");
	cout<<"\t\t============ MENU ========\n\n";
	cout<<"\t\t\t[1] - Aluno\n\n";;
	cout<<"\t\t\t[2] - Professor\n\n";
	cout<<"\t\t\t[3] - Modalidade\n\n";
	cout<<"\t\t\t[4] - Matriculas\n\n";
	cout << "\t\t\t[0] - Sair\n\n";
}

void menuAlunos (struct Alunos tabela_alunos[], struct indice_aluno idx_aluno[], int &cont_aluno){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout<<"\t\t============ MENU ALUNOS ========\n\n";
	cout << "\t\t\t[1] - Incluir Alunos\n\n";
	cout << "\t\t\t[2] - Excluir Alunos\n\n";
	cout << "\t\t\t[3] - Mostrar Alunos\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			for (int codpesq = 9; codpesq != 0;) {
				cout << "\n\nInforme o Codigo do Aluno a ser Incluido (0 para Encerrar): ";
        		     cin >> codpesq;
        		if (codpesq != 0)
                  	buscaaleat_aluno(idx_aluno, tabela_alunos, cont_aluno, codpesq);
          }
			break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o Codigo do Cliente a ser Exclu?do (0 para Encerrar): ";
        			cin >> codpesq;
        		if (codpesq != 0)
            		excluir_aluno(idx_aluno, tabela_alunos, cont_aluno, codpesq);
               }
               
               cout << "Leitura Exaustiva dos Registros Alunos";
    			exaustiva_aluno (idx_aluno,tabela_alunos,cont_aluno);
    			
    			getch();
			break;
		case 3:
		
			break;
		case 4:
			
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuProfessores (struct Professores tabela_professores[], struct indice_professor idx_professores[], int &cont_professor){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout<<"\t\t============ MENU ALUNOS ========\n\n";
	cout << "\t\t\t[1] - Incluir Professores\n\n";
	cout << "\t\t\t[2] - Excluir Professores\n\n";
	cout << "\t\t\t[3] - Mostrar Professores\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			for (int codpesq = 4; codpesq != 0;) {
				cout << "\n\nInforme o Codigo do Professor a ser Incluido (0 para Encerrar): ";
        			cin >> codpesq;
        		if (codpesq != 0)
          		buscaaleat_professor(idx_professores, tabela_professores, cont_professor, codpesq);
			}
			break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o Codigo do Cliente a ser Exclu?do (0 para Encerrar): ";
        			cin >> codpesq;
     		if (codpesq != 0)
            		excluir_professor(idx_professores, tabela_professores, cont_professor, codpesq);
          	}
          	
          	cout << "Leitura Exaustiva dos Registros Professor";
    			exaustiva_professor (idx_professores, tabela_professores, cont_professor);
			break;
		case 3:
		
			break;
		case 4:
			
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuModalidades (struct 	Modalidades tabela_modalidade[], struct	indice_modalidade idx_modalidade[], int &cont_modalidade){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout<<"\t\t============ MENU ALUNOS ========\n\n";
	cout << "\t\t\t[1] - Incluir Modalidade\n\n";
	cout << "\t\t\t[2] - Excluir Modalidade\n\n";
	cout << "\t\t\t[3] - Mostrar Modadelidade\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			for (int codpesq = 9; codpesq != 0;) {
				cout << "\n\nInforme o Codigo do Modalidade a ser Incluido (0 para Encerrar): ";
        			cin >> codpesq;
        		if (codpesq != 0) 
                  buscaaleat_modalidade(idx_modalidade, tabela_modalidade, cont_modalidade, codpesq);
			}
			break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o Codigo do Professor a ser Excluido (0 para Encerrar): ";
        			cin >> codpesq;
     		if (codpesq != 0)
            		excluir_modalidade (idx_modalidade, tabela_modalidade, cont_modalidade, codpesq);
          	}
          	
          	cout << "Leitura Exaustiva dos Registros Modalidade";
    			exaustiva_modalidade (idx_modalidade, tabela_modalidade, cont_modalidade);
    			
			break;
		case 3:
		
			break;
		case 4:
			
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

int main() {
	
	int cont_aluno;
	int cont_professor;
	int cont_modalidade;
	
	Alunos tabela_alunos[100] = {
		{ 23445, "Caua", "24/06/2003", 78.01, 1.86}, 
	     { 68911, "Joao", "02/04/2006", 71.01, 1.76},
		{ 65234, "Otavio", "17/08/2001", 81.05, 1.88},
		{ 18901, "Gustavo", "09/12/2002", 85.01, 1.79},
		{ 12385, "Gabriel", "24/06/2003", 80.77, 1.75}
	};
					  	
	indice_aluno idx_aluno [50] = { 
		{01, 000},
		{02, 001},
		{03, 002},
		{04, 003},
		{05, 004}
	};
							  
	Professores tabela_professores[100] = {
		{ 50, "Thiago", "Jardim Parana,301", 18997653440},
		{ 51, "Rodrigo", "Senhor do Bonfin,451", 18996674130}
	};
	
	indice_professor idx_professores[100] = {
		{06, 005},
		{07, 006}
	};
	
	Modalidades tabela_modalidade[100] = {
	{ 10, "Musculacao", 01, 50.00, 20, 15},
	{ 11, "Cross-fit", 02, 70.00, 25, 17}
	};
	
	indice_modalidade idx_modalidade[100] = {
	{24, 012},
	{25, 013}
	};
	
	int x = 1, opcao = 0;
	
	 	while (x == 1) {
			mainMenu();
				cout << "\n\nDigite sua opcao: ";
				cin >> opcao;
		switch (opcao) {
				case 1: 
					menuAlunos(tabela_alunos, idx_aluno, cont_aluno);

					break;
				case 2:
					menuProfessores(tabela_professores, idx_professores, cont_professor);
					
					break;
				case 3: 
                		menuModalidades(tabela_modalidade, idx_modalidade, cont_modalidade);
                		
                		break;
            		case 4:
                	
                		
                		break;
                	case 5:
                	
                		break;
                		
                	default:
                		cout << "Opcao invalida. Tente novamente." << endl;
                		
                		 getch();	
		
		}
	}
}




