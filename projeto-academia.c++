#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

// STRUCTS
struct Alunos {
	int cpf;
	char nome[30];
	char dataNascimento[15];
	float peso;
	float altura;
	int status;
	float imc;
};


struct Professores {
	int cod_prof;
	char nome[50];
	char endereco[80];
	int telefone;
	int status;
};


struct Modalidades {
	int cod_modalidade;
	char descricao[30];
	int cod_prof;
	float valor_aula;
	int limite_alunos;
	int total_alunos;
	int status;
};


struct Matriculas {
	int cod_matricula;
	int cpf_aluno;
	int cod_modalidade;
	int qtde_aulas;
	int status;
};

/*--------------------------------------------------------------------------------------*/


//INDICES

struct indice_Aluno {
        int codigoCpf;
        int enderAluno;
};

struct indice_Professor {
        int codigoProfessor;
        int enderProfessor;
}; 

struct indice_Modalidade {
 		int codigoModalidade;
 		int enderModalidade;
 };

struct indice_Matricula {
 		int codigoMatricula;
 		int enderMatricula;
 };
 
/*-----------------------------------------------------------------------------------------*/

//BUSCA

int buscaaleat_Aluno (struct indice_Aluno idxAluno[], int contador, int cpfDoAluno) {
    int i = 0, f = contador - 1;
    int m = (i + f) / 2;
    for (; f >= i && cpfDoAluno != idxAluno[m].codigoCpf; m = (i + f) / 2) {
        if (cpfDoAluno > idxAluno[m].codigoCpf) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    if (cpfDoAluno == idxAluno[m].codigoCpf) {
        return idxAluno[m].enderAluno;
    } else {
        return -1;
    }
}

int buscaaleat_Professor (struct indice_Professor idxProfessor[], int contador, int codigo) {
    int i = 0, f = contador - 1;
    int m = (i + f) / 2;
    for (; f >= i && codigo != idxProfessor[m].codigoProfessor; m = (i + f) / 2) {
        if (codigo > idxProfessor[m].codigoProfessor) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    if (codigo == idxProfessor[m].codigoProfessor) {
        return idxProfessor[m].enderProfessor;
    } else {
        return -1;
    }
}

int buscaaleat_Modalidade (struct indice_Modalidade idxModalidade[], int contador, int codigo) {
    int i = 0, f = contador - 1;
    int m = (i + f) / 2;
    for (; f >= i && codigo != idxModalidade[m].codigoModalidade; m = (i + f) / 2) {
        if (codigo > idxModalidade[m].codigoModalidade) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    if (codigo == idxModalidade[m].codigoModalidade) {
        return idxModalidade[m].enderModalidade;
    } else {
        return -1;
    }
}

int buscaaleat_Matricula (struct indice_Matricula idxMatricula[], int contador, int codigo) {
    int i = 0, f = contador - 1;
    int m = (i + f) / 2;
    for (; f >= i && codigo != idxMatricula[m].codigoMatricula; m = (i + f) / 2) {
        if (codigo > idxMatricula[m].codigoMatricula) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }
    if (codigo == idxMatricula[m].codigoMatricula) {
        return idxMatricula[m].enderMatricula;
    } else {
        return -1;
    }
}

/*--------------------------------------------------------------------------------------------------*/

// INCLUSÕES 

void inclusao_aluno (struct Alunos aluno[],struct indice_Aluno idxaluno[], int &cont_aluno){
    
    system("cls");
    cout << "--------------- CADASTRAR ALUNOS NOVOS-----------------";
    const int tamanhovetor = 10;
 
 	// tomanho maximo no meu vetor
 	for (int i = 5; i < tamanhovetor; ) {
	
	// verifica se cpf existi
    	bool verificandoCpf = false;
        while (!verificandoCpf) {

            cout << "\n\n - Digite o CPF do aluno: " << "(digite 0 para sair): ";
            cin >> aluno[i].cpf;

     if (aluno[i].cpf == 0) {
                break;
      }
	
     int validarCpf = buscaaleat_Aluno(idxaluno, cont_aluno, aluno[i].cpf);
     if (validarCpf != -1) {
          cout << "CPF ja cadastrado: " << aluno[validarCpf].nome;
	} else {
                verificandoCpf  = true;
     	}
     }
	if (aluno[i].cpf == 0) {
            break;
     }
     cin.ignore();
     // verifica se nome esta vazio
     bool verificandonome = false;
     while (!verificandonome) {
          cout << "\nNome do Aluno: ";
          gets(aluno[i].nome);
     if (aluno[i].nome != "") {
          verificandonome = true;
     } else {
          cout << "Insira nome do Aluno!" << endl;
          cin.ignore();
          }
     }
     cin.ignore();
	   cout << "Data de Nascimento: ";
	   cin >> aluno[i].dataNascimento;
	   cin.ignore();
        cout << "Peso: ";
        cin >> aluno[i].peso;
        cin.ignore();
        cout << "Altura: ";
        cin >> aluno[i].altura;
        cin.ignore();
        

        aluno[i].imc = aluno[i].peso / (aluno[i].altura * aluno[i].altura);
		
        cout << "\nIMC: " << aluno[i].imc;
        cin.ignore();

        if (aluno[i].imc < 18.5)
      
            cout << "\tDiagnostico: Abaixo do peso";
        else if (aluno[i].imc >= 18.5 && aluno[i].imc < 24.9)
            cout << "\tDiagnostico: Peso normal";
        else if (aluno[i].imc >= 25 && aluno[i].imc < 29.9)
            cout << "\tDiagnostico: Acima do peso";
        else
            cout << "\tDiagnostico: Obesidade";
            
        int j;
        for (j = cont_aluno - 1; j >= 0 && aluno[i].cpf < idxaluno[j].codigoCpf; j--) {
            idxaluno[j + 1] =idxaluno[j];
        }
        idxaluno[j + 1].codigoCpf = aluno[i].cpf;
        idxaluno[j + 1].enderAluno = i;
        cout << "\n------Aluno cadastrado com Sucesso------" << endl;
        cont_aluno++;
        i++;
    }

    cout << "\n\nSaindo..." << endl;
    cin.ignore();
};

void inclusao_professor(struct Professores professor[], struct indice_Professor idxProf[], int &contador) {
	system("cls");
    cout << "\n\n\n------------- CADASTRAR NOVOS PROFESSORES -----------------";
    const int tamanhoVetor = 10;
    for (int i = 5; i < tamanhoVetor;) {
     

        bool verificandocodigo = false;
        while (!verificandocodigo) {
            cout << "\n\nDigite o codigo do professor " << "(digite 0 para sair): ";
            cin >> professor[i].cod_prof;
            if (professor[i].cod_prof == 0) {
                break;
            }
            int validaCodigo = buscaaleat_Professor(idxProf, contador, professor[i].cod_prof);
            if (validaCodigo != -1) {
                cout << "Codigo ja cadastrado: " << professor[validaCodigo].nome;
            } else {
                verificandocodigo = true;
            }
        }
        if (professor[i].cod_prof == 0) {
            break;
        }

        bool vericandonomeProfessor = false;
        while (!vericandonomeProfessor) {
            cout << "\nNome do Professor: ";
            cin.ignore();
            gets(professor[i].nome);
            if (professor[i].nome != "") {
                vericandonomeProfessor = true;
            } else {
                cout << "Nome do professor nao estar vazio!" << endl;
            }
        }

        bool verificandoendereco = false;
        while (!verificandoendereco) {
            cout << "Endereco do professor: ";
            gets(professor[i].endereco);
            if (professor[i].endereco != "") {
                verificandoendereco = true;
            } else {
                cout << "Endereço nao pode ser vazio" << endl;
            }
        }

        bool verificandotelefone = false;
        while (!verificandotelefone) {
            cout << "Telefone do professor(a): ";
            cin >> professor[i].telefone;
            if (professor[i].telefone != 0) {
                verificandotelefone = true;
            } else {
                cout << "Telefone nao pode ser vazio" << endl;
            }
        }

        int j;
        for (j = contador - 1; j >= 0 && professor[i].cod_prof < idxProf[j].codigoProfessor; j--) {
           idxProf[j + 1] = idxProf[j];
        }
        idxProf[j + 1].codigoProfessor = professor[i].cod_prof;
        idxProf[j + 1].enderProfessor = i;
        cout << "\n---------- Professor cadastrado com Sucesso -------" << endl;
        contador++;
        i++;
    }
    cout << "\n\nSaindo...." << endl;
    cin.ignore();
}

void inclusao_modalidade(struct Modalidades modalidades[], struct indice_Modalidade indiceModalidade[], int &cont_modalidade,
                           struct Professores professores[], struct indice_Professor indiceProfessor[],
                           int &contadorProfessor) {
	system("cls");
    cout << "\n\n\n--------------- CADASTRAR NOVAS MODALIDADES --------------------";

    const int tamanhoMaximoVetor = 10;

    for (int i = 5; i < tamanhoMaximoVetor;) {

        bool validandocodigo = false;
        while (!validandocodigo) {
            cout << "\n\nDigite o codigo da Modalidade " << "(digite 0 para sair): ";
            cin >> modalidades[i].cod_modalidade;
            if (modalidades[i].cod_modalidade == 0) {
                break;
            }
            int validarcodigo = buscaaleat_Modalidade(indiceModalidade, cont_modalidade, modalidades[i].cod_modalidade);
            if (validarcodigo != -1) {
                cout << "Codigo ja cadastrado para Modalidade: " << modalidades[validarcodigo].descricao;
            } else {
                validandocodigo = true;
            }
        }
        if (modalidades[i].cod_modalidade == 0) {
            break;
        }
        cin.ignore();
        bool descricaoNaoVazia = false;
        while (!descricaoNaoVazia) {
            cout << "\nDescricao da Modalidade: ";
//            cin.ignore();
            gets(modalidades[i].descricao);
            if (modalidades[i].descricao != "") {
                descricaoNaoVazia = true;
            } else {
                cout << "Descricao nao pode ser vazia" << endl;
            }
        }

        cout << "\nTotal de alunos cadastrados: ";
        cin >> modalidades[i].total_alunos;
        cin.ignore();

        bool maiorQue0 = false;
        while (!maiorQue0) {
            cout << "\nLimite de alunos: ";
            cin >> modalidades[i].limite_alunos;
            cin.ignore();
            if (modalidades[i].limite_alunos <= 0) {
                cout << "Limite deve ser maior que 0" << endl;
            } else if(modalidades[i].total_alunos > modalidades[i].limite_alunos){
                cout <<"O limite de aluno esgotado"<<endl;
            } else {
                maiorQue0 = true;
            }
        }
        cout << "\nValor da aula da Modalidade: ";
        cin >> modalidades[i].valor_aula;
        cin.ignore();

        bool encontrouProfessor = false;
        while (!encontrouProfessor) {
            cout << "\nCodigo do professor da Modalidade: ";
            cin >> modalidades[i].cod_prof;
            cin.ignore();
            int codigoASerProcurado = modalidades[i].cod_prof;
            int resultadoBuscarProfessor = buscaaleat_Professor(indiceProfessor, contadorProfessor, codigoASerProcurado);
            if (resultadoBuscarProfessor == -1) {
                cout << "Professor nao encontrado, digite um codigo existente";
            } else {
                cout << "Professor: " << professores[resultadoBuscarProfessor].nome << endl;
                encontrouProfessor = true;
            }
        }

        int j;
        for (j = cont_modalidade - 1;
             j >= 0 && modalidades[i].cod_modalidade < indiceModalidade[j].codigoModalidade; j--) {
            indiceModalidade[j + 1] = indiceModalidade[j];
        }
        indiceModalidade[j + 1].codigoModalidade = modalidades[i].cod_modalidade;
        indiceModalidade[j + 1].enderModalidade = i;
        cout << "\n---------- Modalidade cadastrada com Sucesso ---------" << endl;
        cont_modalidade++;
        i++;
    }
    cout << "\n\nSaindo....";
    cin.ignore();
}

void  inclusao_matricula(struct Matriculas matriculas[], struct indice_Matricula indiceMatricula[], int &contador,
                          struct Alunos aluno[], struct indice_Aluno indiceAluno[], int &contadorAluno,
                          struct Modalidades modalidades[], struct indice_Modalidade indiceModalidade[],
                          int &contadorModalidade) {
    system("cls");
    cout << "\n\n\n------------------------ CADASTRAR NOVAS MATRICULAS -----------------------";
    const int tamanhoVetor = 10;

    for(int i = 5; i < tamanhoVetor;){

        bool verificaCodigo = false;
        while(!verificaCodigo) {
            cout << "\n\nDigite o codigo da Matricula" << "(digite 0 para sair): ";
            cin >> matriculas[i].cod_matricula;
            if (matriculas[i].cod_matricula == 0) {
                break;
            }
            int validarCodigo = buscaaleat_Matricula(indiceMatricula, contador, matriculas[i].cod_matricula);
            if (validarCodigo != -1) {
                cout << "Codigo da matricula ja cadastrada: " << matriculas[validarCodigo].cod_matricula << endl;
            } else {
                verificaCodigo = true;
            }
        }
        if (matriculas[i].cod_matricula == 0) {
            break;
        }

        bool verificaCPF = false;
        while(!verificaCPF){
            cout << "Digite o CPF do aluno: ";
            cin >> matriculas[i].cpf_aluno;
            int cpfProcurado = matriculas[i].cpf_aluno;
            int resultadoBuscaCpf = buscaaleat_Aluno(indiceAluno, contadorAluno, cpfProcurado);
            if (resultadoBuscaCpf != -1) {
                cout << "Nome: " << aluno[resultadoBuscaCpf].nome << endl;
                verificaCPF = true;
            } else {
                cout << "Aluno nao encontrado." << endl;
            }
        }

        bool verificaModalidade = false;
        while(!verificaModalidade){
            cout << "Digite o código da modalidade: ";
            cin >> matriculas[i].cod_modalidade;
            int modalidadeProcurada = matriculas[i].cod_modalidade;
            int resultadoBuscaModalidade = buscaaleat_Modalidade(indiceModalidade, contadorModalidade, modalidadeProcurada);
            if(resultadoBuscaModalidade != -1){
                cout << "Modalidade: " << modalidades[resultadoBuscaModalidade].descricao << endl;
            } else {
                cout <<"Modalidade nao encontrada." <<endl;
                continue;
            }
            int pessoasCadastradasNaModalidade = modalidades[resultadoBuscaModalidade].total_alunos;
            int limiteDePessoasNaModalidade = modalidades[resultadoBuscaModalidade].limite_alunos;

            if (pessoasCadastradasNaModalidade < limiteDePessoasNaModalidade) {
                cout << "\nHa vagas disponiveis nessa modalidade" << endl;
                modalidades[resultadoBuscaModalidade].total_alunos = modalidades[resultadoBuscaModalidade].total_alunos + 1;
                cout << "\n--------Aluno matriculado com sucesso!----------" << endl;
                cout << "\nAlunos cadastrados: " << modalidades[resultadoBuscaModalidade].total_alunos << endl;
                cout << "Limite de alunos da modalidade: " << limiteDePessoasNaModalidade << endl;
                verificaModalidade = true;
            } else {
                cout << "\nNao ha vagas nessa modalidade." << endl;
            }
        }
        bool maiorque0 = false;
        while(!maiorque0){
            cout << "Quantidade de aulas: ";
            cin >> matriculas[i].qtde_aulas;

            if(matriculas[i].qtde_aulas <= 0){
                cout << "O numero de aulas nao pode ser igual ou menor que 0" <<endl;
            } else {
                maiorque0 = true;
            }
        }
        int j;
        for (j = contador - 1; j >= 0 && matriculas[i].cod_matricula < indiceMatricula[j].codigoMatricula; j--) {
            indiceMatricula[j + 1] = indiceMatricula[j];
        }
        indiceMatricula[j + 1].codigoMatricula = matriculas[i].cod_matricula;
        indiceMatricula[j + 1].enderMatricula = i;
        cout << "\n---------Matricula cadastrada com Sucesso----------" << endl;
        contador++;
        i++;
    }
	cout << "\n\nSaindo....";
   	cin.ignore();
}


/*------------------------------------------------------------------------------*/

// EXCLUSAO

void excluir_aluno (struct Alunos aluno[], struct indice_Aluno idx[], int &cont_aluno, int cod) {
	system("cls");
	cout<<"\n\t\t------EXCLUIR ALUNOS---------";
	int i = 0, f = cont_aluno;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigoCpf; m = (i + f) / 2){
		if (cod > idx[m].codigoCpf)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].enderAluno;
	if ((cod == idx[m].codigoCpf) && aluno[i].status == 0) {
		aluno[i].status = 1;
		cout<<"\n\t-----------------------------------------------------------------------------------------------";
		cout <<"\n\n Aluno excluido com Sucesso";
		cout << "\n\t| CPF: " << aluno[i].cpf<< " | Nome: " << aluno[i].nome;
	}
	else 
		cout <<"Aluno nao cadastrado";
	getch();
}


void excluir_professor (struct Professores professor[], struct indice_Professor idx[], int &cont_professor, int cod) {
	system("cls");
	cout<<"\n\t\t----------EXCLUIR PROFESSORES--------";
	int i = 0, f = cont_professor;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigoProfessor; m = (i + f) / 2){
		if (cod > idx[m].codigoProfessor)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].enderProfessor;
	if ((cod == idx[m].codigoProfessor) && professor[i].status == 0) {
		professor[i].status = 1;
	cout<<"\n\t-----------------------------------------------------------------------------------------------";
		cout <<"\n\n Professor excluido com Sucesso";
		cout << "\n\t| Codigo: " << professor[i].cod_prof<< " | Nome: " << professor[i].nome<< " | Endereco: " << professor[i].endereco<< " | Telefone: " << professor[i].telefone;
	}
	else 
		cout <<"Professor nao cadastrado";
	getch();
}

void excluir_modalidade (struct Modalidades tabela[], struct indice_Modalidade idx[], int &cont_modalidade, int cod) {
	system("cls");
	cout<<"\n\t\t---------EXCLUIR MODALIDADES---------";
	int i = 0, f = cont_modalidade;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigoModalidade; m = (i + f) / 2){
		if (cod > idx[m].codigoModalidade)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].enderModalidade;
	if ((cod == idx[m].codigoModalidade) && tabela[i].status == 0) {
		tabela[i].status = 1;
		cout<<"\n\t-----------------------------------------------------------------------------------------------";
		cout <<"\n\n Modalidade excluida com Sucesso";
		cout << "\n\t| Codigo: " << tabela[i].cod_modalidade<< " | Descricao: " << tabela[i].descricao<< " | Professor: " << tabela[i].cod_prof<< " | Valor Aula: " << tabela[i].valor_aula<<" | Alunos: "<<tabela[i].total_alunos<<" / "<<tabela[i].limite_alunos<<" |";
	}
	else 
		cout <<"Modalidade nao cadastrado";
	getch();
}

void excluir_matricula ( struct Matriculas mat[], struct indice_Matricula idx[], int &cont, int cod,  struct indice_Modalidade idxmod[], struct Modalidades modalidade[], int &cont_modalidade) {
	system("cls");
	int i = 0, f = cont;
	int m = (i + f) / 2;
   	for(; f >= i && cod != idx[m].codigoMatricula; m = (i + f) / 2){
		if (cod > idx[m].codigoMatricula)
			i = m + 1;
		else 
			f = m - 1;
	}
	i = idx[m].enderMatricula;
	if ((cod == idx[m].codigoMatricula) && mat[i].status == 0) {
		mat[i].status = 1;
		cout <<"\n\n Matricula excluida com Sucesso";
		int modalidadeProcurada = mat[i].cod_modalidade;
          int resultadoBuscaModalidade = buscaaleat_Modalidade(idxmod, cont_modalidade, modalidadeProcurada);
          cout<<"\n\t-----------------------------------------------------------------------------------------------";
		cout <<"\n\n Matricula excluida com Sucesso";
		cout << "\n\t| Codigo: " << mat[i].cod_matricula << " | CPF do Aluno: " << mat[i].cpf_aluno<< " | Codigo da Modalidade: " << mat[i].cod_modalidade;
	}
	else 
		cout <<"Matricula nao cadastrado";
	getch();
}

/*--------------------------------------------------------------------------------------------*/

//EXAUTIVAS

void exaustiva_aluno (struct indice_Aluno idx[], struct Alunos aluno[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].enderAluno;
        if (aluno[i].status == 0){
            cout << "\nCPF do Aluno: " << aluno[i].cpf;
            cout << "\tNome: " << aluno[i].nome;
            cout << "\tData Nascimento: " << aluno[i].dataNascimento;
            cout << "\tPeso: " << aluno[i].peso;
            cout << "\tAltura: " << aluno[i].altura;
        }
    }
}

void exaustiva_professor (struct indice_Professor idx[], struct Professores professor[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].enderProfessor;
        if (professor[i].status == 0){
            cout << "\nCodigo do Professor: " << professor[i].cod_prof;
            cout << "\tNome: " << professor[i].nome;
            cout << "\tEndereco: " << professor[i].endereco;;
            cout <<"\nTelefone: " << professor[i].telefone;
        }
    }
}

void exaustiva_modalidade (struct indice_Modalidade idx[], struct Modalidades md[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].enderModalidade;
        if (md[i].status == 0){
           cout << "\nCodigo da Modalidade: " << md[i].cod_modalidade;
            cout << "\tDescricao: " << md[i].descricao;
            cout << "\tValor da Aula: " << md[i].valor_aula;
            cout << "\nLimite de alunos: " << md[i].limite_alunos;
            cout << "Total de alunos: "  << md[i].total_alunos;
        }
    }
}

void exaustiva_matricula (struct indice_Matricula idx[], struct Matriculas mat[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].enderMatricula;
        if (mat[i].status == 0){
           cout << "\nCodigo da Maticula: " << mat[i].cod_matricula;
            cout << "\tCPF da aluno: " << mat[i].cpf_aluno;
            cout << "\tCodigo da matricula: " << mat[i].cod_modalidade;
            cout << "\nQuantidade de aulas: " << mat[i].qtde_aulas;
        }
    }
}

/*-----------------------------------------------------------------------------------*/

//REORGANIZAOCAO

void reorganizacao_aluno (struct indice_Aluno idx[], struct Alunos aluno[], int &cont_aluno){
    
	Alunos novoal[100];
	indice_Aluno novoidx[50];
	
	int j=-1;
    for (int k=0; k < cont_aluno; k++){
        int i = idx[k].enderAluno;
        if (aluno[i].status == 0){
            j++;
            novoal[j].cpf = aluno[i].cpf;
            strcpy (novoal[j].nome,aluno[i].nome);
            strcpy (novoal[j].dataNascimento,aluno[i].dataNascimento);
            novoal[j].peso = aluno[i].peso;
            novoal[j].altura = aluno[i].altura;
            novoal[j].status = 0;
            
            novoidx[j].codigoCpf = novoal[j].cpf;
            novoidx[j].enderAluno = j;
        }
    }
    cont_aluno = j+1;
    
    
    for(int y = 0; y < cont_aluno; y++ ){
    	aluno[y].cpf = novoal[y].cpf;
		//strcpy(alunos[y].cpf,novoAlunos[y].cpf);
		strcpy(aluno[y].nome,novoal[y].nome); 
		strcpy(aluno[y].dataNascimento,novoal[y].dataNascimento);
		aluno[y].peso = novoal[y].peso;
		aluno[y].altura = novoal[y].altura;
		aluno[y].status = novoal[y].status;
		aluno[y].imc = novoal[y].imc;
		
		idx[y].codigoCpf = novoidx[y].codigoCpf;
		idx[y].enderAluno = novoidx[y].enderAluno;
		
	}
}

void reorganizacao_professores (struct indice_Professor idx[], struct Professores p[], int &cont_professor){
    
    	Professores novoprof[100];
	indice_Professor novoidx[100]; 
    
    int j=-1;
    for (int k=0; k < cont_professor; k++){
        int i = idx[k].enderProfessor;
        if (p[i].status == 0){
            j++;
            novoprof[j].cod_prof = p[i].cod_prof;
            strcpy (novoprof[j].nome,p[i].nome);
            strcpy (novoprof[j].endereco,p[i].endereco);
            novoprof[j].telefone = p[i].telefone;
            novoprof[j].status = 0;
            novoidx[j].codigoProfessor = novoprof[j].cod_prof;
            novoidx[j].enderProfessor = j;
        }
    }
    cont_professor = j+1;
    
    for(int y = 0; y < cont_professor; y++ ){
    	p[y].cod_prof = novoprof[y].cod_prof;
		//strcpy(alunos[y].cpf,novoAlunos[y].cpf);
		strcpy(p[y].nome,novoprof[y].nome); 
		strcpy(p[y].endereco,novoprof[y].endereco);
		p[y].telefone = novoprof[y].telefone;
		p[y].status = novoprof[y].status;
		
		idx[y].codigoProfessor = novoidx[y].codigoProfessor;
		idx[y].enderProfessor = novoidx[y].enderProfessor;
		
	}
}


void reorganizacao_modalidade (struct indice_Modalidade idx[], struct Modalidades mod[], int &cont_modalidade){
    
   	Modalidades novomod[100];
	indice_Modalidade novoidx[100];
    
    int j=-1;
    for (int k=0; k < cont_modalidade; k++){
        int i = idx[k].enderModalidade;
        if (mod[i].status == 0){
            j++;
            novomod[j].cod_modalidade = mod[i].cod_modalidade;
            strcpy (novomod[j].descricao,mod[i].descricao);
            novomod[j].valor_aula = mod[i].valor_aula;
            novomod[j].limite_alunos = mod[i].limite_alunos;
            novomod[j].total_alunos = mod[i].total_alunos;
            novomod[j].status = 0;
            novoidx[j].codigoModalidade = novomod[j].cod_modalidade;
            novoidx[j].enderModalidade = j;
        }
    }
    cont_modalidade = j+1;
    
    for(int y = 0; y < cont_modalidade; y++ ){
    		mod[y].cod_modalidade = novomod[y].cod_modalidade;
		
		strcpy(mod[y].descricao,novomod[y].descricao); 
		mod[y].valor_aula = novomod[y].valor_aula;
		mod[y].limite_alunos = novomod[y].limite_alunos;
		mod[j].total_alunos = novomod[y].total_alunos;
		mod[y].status = novomod[y].status;
		
		idx[y].codigoModalidade = novoidx[y].codigoModalidade;
		idx[y].enderModalidade = novoidx[y].enderModalidade;
		
	}
}


void reorganizacao_matriculas (struct indice_Matricula idx[], struct Matriculas mat[], int &cont){
    
    Matriculas novomat[100];
    indice_Matricula novoidx[100];
	
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].enderMatricula;
        if (mat[i].status == 0){
            j++;
            novomat[j].cod_matricula = mat[i].cod_matricula;
            novomat[j].cpf_aluno = mat[i].cpf_aluno;
            novomat[j].cod_matricula = mat[i].cod_matricula;
            novomat[j].qtde_aulas = mat[i].qtde_aulas;
            novomat[j].status = 0;
            novoidx[j].codigoMatricula = novomat[j].cod_matricula;
            novoidx[j].enderMatricula = j;
        }
    }
    cont = j+1;
    
    for(int y = 0; y < cont; y++ ){
    		mat[y].cod_matricula = novomat[y].cod_matricula;
		
		mat[y].cpf_aluno = novomat[y].cpf_aluno;
		mat[y].cod_matricula = novomat[y].cod_matricula;
		mat[j].qtde_aulas = novomat[y].qtde_aulas;
		mat[y].status = novomat[y].status;
		
		idx[y].codigoMatricula = novoidx[y].codigoMatricula;
		idx[y].enderMatricula = novoidx[y].enderMatricula;
		
	}
    
}

/*-----------------------------------------------------------------------------*/

//MOSTRAR DADOS

void mostrarAluno(struct Alunos tabela[],struct indice_Aluno idx[], int &cont_aluno){
	system("cls");
	cout<<"\n\t\t------------------ Exibindo lista de alunos --------------";
	
	if(cont_aluno ==0){
		cout<<"\nTabela vazia";
		
	} else{
		for(int i = 0; i < cont_aluno; i++){
		cout<<"\nCPF: "<<tabela[i].cpf<<" | NOME: "<<tabela[i].nome<<" | NASCIMENTO: "<<tabela[i].dataNascimento<<" | PESO: "<<tabela[i].peso<<" | ALTURA: "<<tabela[i].altura<<" | IMC: "<<tabela[i].imc<<" | STATUS:"<<tabela[i].status;
		
		}
		
		cout<<"\n\nAREA DE INDEX";
		for(int k = 0; k < cont_aluno; k++){
			
			cout<<"\nCodigo: "<<idx[k].codigoCpf<<" | Endereco: "<<idx[k].enderAluno;
		}
		
	}
	getch();
	
}


void mostrarProfessor(struct Professores tabela[],struct indice_Professor idx[], int &cont_professor){
	system("cls");
	cout<<"\n\t\tExibindo lista de Professores";
	
	if(cont_professor ==0){
		cout<<"\nTabela vazia";
		
	} else{
		for(int i = 0; i < cont_professor; i++){
		cout<<"\nCodigo do Professor: "<<tabela[i].cod_prof<<" | NOME: "<<tabela[i].nome<<" | ENDERECO: "<<tabela[i].endereco<<" | TELEFONE: "<<tabela[i].telefone<<" | STATUS:"<<tabela[i].status;
		
		}
		
		cout<<"\n\nAREA DE INDEX";
		for(int k = 0; k < cont_professor; k++){
			
			cout<<"\nCodigo: "<<idx[k].codigoProfessor<<" | Endereco: "<<idx[k].enderProfessor;
		}
		
	}
	getch();
}


void mostrarModalidade(struct Modalidades tabela[],struct indice_Modalidade idx[], int &cont_modalidade, struct Professores tabelaprof[]){
	system("cls");
	cout<<"\n\t\t====LISTA DE MODALIDADES====";
	
	if(cont_modalidade ==0){
		cout<<"\nTABELA VAZIA";
		
	} else{
		for(int i = 0; i < cont_modalidade; i++){
		cout<<"\nCODIGO DA MODALIDADE: "<<tabela[i].cod_modalidade<<" | DESCRICAO: "<<tabela[i].descricao<<" | VALOR DA AULA: "<<tabela[i].valor_aula<<" | LIMTE DE ALUNOS: "<<tabela[i].limite_alunos<<" | TOTAL DE ALUNOS:"<<tabela[i].total_alunos<< " \n " << " | STATUS: "<< tabela[i].status;
		cout<< " | CODIGO DO PROFESSOR: "<< tabelaprof[i].cod_prof<< " | NOME DO PROFESSOR: "<< tabelaprof[i].nome;
		}
		
		cout<<"\n\nAREA DE INDEX";
		for(int k = 0; k < cont_modalidade; k++){
			
			cout<<"\nCodigo: "<<idx[k].codigoModalidade<<" | Endereco: "<<idx[k].enderModalidade;
		}
		
	}
	getch();
}


void mostrarMatricula(struct Matriculas tabela[],struct indice_Matricula idx[], int &cont_matricula){
	system("cls");
	cout<<"\n\t\t====LISTA DE MATRICULAS====";
	
	if(cont_matricula ==0){
		cout<<"\nTABELA VAZIA";
		
	} else{
		for(int i = 0; i < cont_matricula; i++){
		cout<<"\nCODIGO DA MATRICULA: "<<tabela[i].cod_matricula <<" | CPF do aluno: "<<tabela[i].cpf_aluno<<" | CODIGO DA MATRICULA: "<<tabela[i].cod_modalidade<<" | QUANTIDADE DE AULAS: "<<tabela[i].qtde_aulas;
		
		}
		
		cout<<"\n\nAREA DE INDEX";
		for(int k = 0; k < cont_matricula; k++){
			
			cout<<"\nCodigo: "<<idx[k].codigoMatricula<<" | Endereco: "<<idx[k].enderMatricula;
		}
		
	}
	getch();
}

/*----------------------------------------------------------------------------------------------*/

// CALUCULAR LUCRO

void calcularFaturamento(struct indice_Modalidade idxModalidade[], struct Modalidades modalidades[], 
					struct indice_Matricula idxMatricula[], struct Matriculas matricula[], 
					struct indice_Professor idxProfessor[], struct Professores professores[], 
					int &cont_modalidade, int &cont_matricula, int &cont_professor){
						
						
    int codigoDaModalidade;
    cout << "Digite o codigo da modalidade: ";
    cin >> codigoDaModalidade;

     int BuscaDaModalidade = buscaaleat_Modalidade(idxModalidade, cont_modalidade, codigoDaModalidade);
     float valorDaAula = modalidades[BuscaDaModalidade].valor_aula;
     int codigoDoProfessor = modalidades[BuscaDaModalidade].cod_prof;
     int resultadobuscaProfessor = buscaaleat_Professor(idxProfessor, cont_professor, codigoDoProfessor);
     cout << "\nDescricao: " << modalidades[BuscaDaModalidade].descricao;
     cout << "\nProfessor: " << professores[BuscaDaModalidade].nome;

     int quantidadeDeAula = 0;
     for(int i = 0; i < cont_matricula; i++){
         if(codigoDaModalidade == modalidades[i].cod_modalidade){
             quantidadeDeAula = matricula[i].qtde_aulas;
         }
     }
     cout <<"\nQuantidade de aula: " << quantidadeDeAula;
     float lucro = quantidadeDeAula * valorDaAula;
     cout << "\nLucro: " << lucro;
     
     getch();
}


/*Menu Principal*/
void mainMenu (){
	system("cls");
	cout<<"\t\t============ MENU ========\n\n";
	cout<<"\t\t\t[1] - Aluno\n\n";;
	cout<<"\t\t\t[2] - Professor\n\n";
	cout<<"\t\t\t[3] - Modalidade\n\n";
	cout<<"\t\t\t[4] - Matriculas\n\n";
	cout<<"\t\t\t[5] - Faturamento\n\n";
	cout << "\t\t\t[0] - Sair\n\n";
}

void menuAlunos (struct Alunos tabela_alunos[], struct indice_Aluno idx_aluno[], int &cont_aluno){
	
	
	
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout<<"\t\t============ MENU ALUNOS ========\n\n";
	cout << "\t\t\t[1] - Incluir Alunos\n\n";
	cout << "\t\t\t[2] - Excluir Alunos\n\n";
	cout << "\t\t\t[3] - Mostrar Alunos\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opcao: ";
	cin >> option;
	
	switch(option){
		case 1:
			cout << "Cadastre até 4 alunos"<<endl;
                inclusao_aluno(tabela_alunos, idx_aluno, cont_aluno);
                getch();
                system("cls");
                break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o Codigo do Aluno a ser Excluido (0 para Encerrar): ";
        			cin >> codpesq;
        			cin.ignore();
        		if (codpesq != 0)
            		excluir_aluno(tabela_alunos, idx_aluno, cont_aluno, codpesq);
               }
               
    			reorganizacao_aluno (idx_aluno, tabela_alunos, cont_aluno);
               
               cout << "Leitura Exaustiva dos Registros Alunos";
                
    			exaustiva_aluno (idx_aluno,tabela_alunos,cont_aluno);
    			
    			getch();
			break;
		case 3:
			 mostrarAluno(tabela_alunos, idx_aluno, cont_aluno);
			break;
		case 4:
			
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

menuProfessores (struct Professores tabela_professores[], struct indice_Professor idx_professores[], int &cont_professor){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	system("cls");
	cout<<"\t\t============ MENU PROFESSORES ========\n\n";
	cout << "\t\t\t[1] - Incluir Professores\n\n";
	cout << "\t\t\t[2] - Excluir Professores\n\n";
	cout << "\t\t\t[3] - Mostrar Professores\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opcao: ";
	cin >> option;
	
	switch(option){
		case 1:
			 cout << "Digite ate 5 professores"<<endl;
                inclusao_professor(tabela_professores, idx_professores, cont_professor);
                getch();
                system("cls");
                break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo do professor a ser excluido (0 para Encerrar): ";
        			cin >> codpesq;
     		if (codpesq != 0)
            		excluir_professor(tabela_professores, idx_professores, cont_professor, codpesq);
          	}
          	
          	reorganizacao_professores (idx_professores, tabela_professores, cont_professor);
          	
          	cout << "LEITURA EXAUTIVA DOS REGISTROS PROFESSOR";
    			exaustiva_professor (idx_professores, tabela_professores, cont_professor);
    			getch();
			break;
		case 3:
			mostrarProfessor(tabela_professores, idx_professores, cont_professor);
			break;
		case 4:
			
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuModalidades (struct Modalidades tabela_modalidade[], struct indice_Modalidade idx_modalidade[],int &cont_modalidade, struct indice_Professor idxp[], int contpro, struct Professores tabela[],  struct indice_Aluno idxal[], struct Alunos a[], int contAl){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout<<"\t\t============ MENU MODALIDADE ========\n\n";
	cout << "\t\t\t[1] - Incluir Modalidade\n\n";
	cout << "\t\t\t[2] - Excluir Modalidade\n\n";
	cout << "\t\t\t[3] - Mostrar Modadelidade\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			cout << "Cadastre ate 5 modalidades: "<<endl;
                inclusao_modalidade(tabela_modalidade, idx_modalidade, cont_modalidade, tabela, idxp, contpro);
                getch();
                system("cls");
                break;
			break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o Codigo do Professor a ser Excluido (0 para Encerrar): ";
        			cin >> codpesq;
     		if (codpesq != 0)
            		excluir_modalidade (tabela_modalidade, idx_modalidade, cont_modalidade, codpesq);
          	}
          	
          	reorganizacao_modalidade (idx_modalidade, tabela_modalidade, cont_modalidade);
          	
          	cout << "Leitura Exaustiva dos Registros Modalidade";
    			exaustiva_modalidade (idx_modalidade, tabela_modalidade, cont_modalidade);
    			getch();
			break;
		case 3:
			mostrarModalidade(tabela_modalidade, idx_modalidade, cont_modalidade, tabela);
			break;
		case 4:
			
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuMatricula (struct Matriculas tabela_matriculas[],  struct indice_Matricula idx_matricula[], int &cont_matricula, struct Alunos tabela_aluno[], struct indice_Aluno idxal[], int contal, struct Modalidades tabelamod[], struct indice_Modalidade idxmod[], int contmod){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	fflush(stdin);
	system("cls");
	cout<<"\t\t============ MENU MATRICULA ========\n\n";
	cout << "\t\t\t[1] - Incluir Matricula\n\n";
	cout << "\t\t\t[2] - Excluir Matricula\n\n";
	cout << "\t\t\t[3] - Mostrar Matricula\n\n";
	cout << "\t\t\t[0] - Voltar\n\n";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			cout <<"Cadastre até 4 matriculas"<<endl;
                inclusao_matricula(tabela_matriculas, idx_matricula, cont_matricula, tabela_aluno, idxal, contal, tabelamod, idxmod, contmod);
                getch();
                system("cls");
                break;
			break;
		case 2:
			for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o Codigo do Matricula a ser Excluido (0 para Encerrar): ";
        			cin >> codpesq;
     		if (codpesq != 0)
            		excluir_matricula(tabela_matriculas, idx_matricula, cont_matricula, codpesq, idxmod, tabelamod, contmod);
          	}
          	
          	reorganizacao_matriculas (idx_matricula, tabela_matriculas, cont_matricula);
          	
          	cout << "Leitura Exaustiva dos Registros Matriculas";
    			exaustiva_matricula (idx_matricula, tabela_matriculas, cont_matricula);
    			getch();
			break;
		case 3:
			mostrarMatricula(tabela_matriculas, idx_matricula, cont_matricula);
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
	
	
	Alunos tabela_alunos[100] = {
		{ 12345, "Caua", "24/06/2003", 78.01, 1.86, 0, 78.01/(1.86 * 1.86)}, 
	     { 23456, "Joao", "02/04/2006", 71.01, 1.76, 0, 71.01/(1.76 * 1.76)},
		{ 34567, "Otavio", "17/08/2001", 81.05, 1.88, 0, 81.05/(1.88 * 1.88)},
		{ 45678, "Gustavo", "09/12/2002", 85.01, 1.79, 0, 85.01/(1.79 * 1.79)},
		{ 56789, "Gabriel", "24/06/2003", 80.77, 1.75, 0, 78.01/(1.86 * 1.86)}
	};
					  	
	indice_Aluno idx_aluno [50] = { 
		{12345, 0},
		{23456, 1},
		{34567, 2},
		{45678, 3},
		{56789, 4}
	};
	
						  
	Professores tabela_professores[10] = {
		{ 10, "Thiago",   "Jardim Parana,301", 189983637, 0},
		{ 20, "Rodrigo",  "Senhor do Bonfin,451", 189960677, 0},
		{ 30, "Augusto",  "Jose A. Soares,531", 189976687, 0},
		{ 40, "Fernando", "Sete de Setembro,765", 189960656, 0},
		{ 50, "Rafael",   "Jose Zibordi,245", 189960689, 0}
	};
	

	indice_Professor idx_professores[10] = {
		{10, 0},
		{20, 1},
		{30, 2},
		{40, 3},
		{50, 4}
	};
	
	
	Modalidades tabela_modalidade[10] = {
	{ 100, "Muay-thay",  10, 50.00, 20, 15, 0},
	{ 200, "Cross-fit",  20, 70.00, 25, 17, 0},
	{ 300, "Musculacao", 30, 100.00, 40, 30, 0},
	{ 400, "Pilates",    40, 65.00, 20, 15, 0},
	{ 500, "Luta livre", 50, 80.00, 30, 15, 0}
	};
	

	
	indice_Modalidade idx_modalidade[10] = {
	{100, 0},
	{200, 1},
	{300, 2},
	{400, 3},
	{500, 4}
	};
	
	
	
	
	Matriculas tabela_matriculas[10] = {
	{ 1000, 12345, 300, 30, 0},
    	{ 2000, 23456, 300, 12, 0},
    	{ 3000, 34567, 100, 15, 0},
    	{ 4000, 45678, 200, 22, 0},
    	{ 5000, 56789, 200, 10, 0}
	};
	
	indice_Matricula idx_matricula[10] = {
	{1000, 0},
	{2000, 1},
	{3000, 2},
	{4000, 3},
	{5000, 4}
	};
	
	int cont_aluno = 5 ;
	int cont_professor = 5;
	int cont_modalidade = 5;
	int cont_matricula = 5;
	
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
                		menuModalidades(tabela_modalidade, idx_modalidade, cont_modalidade, idx_professores, cont_professor, tabela_professores, idx_aluno, tabela_alunos, cont_aluno);
                		
                	break;
            	case 4:
               		menuMatricula(tabela_matriculas, idx_matricula, cont_matricula, tabela_alunos, idx_aluno, cont_aluno, tabela_modalidade, idx_modalidade, cont_matricula);
                		
               		break;
               	case 5:
                		calcularFaturamento(idx_modalidade, tabela_modalidade, idx_matricula, tabela_matriculas, idx_professores, tabela_professores, cont_modalidade, cont_matricula, cont_professor);
                	
               		break;
                		
               	default:
               		cout << "Opcao invalida. Tente novamente." << endl;
                		
               		 getch();	
		
		}
	}
}