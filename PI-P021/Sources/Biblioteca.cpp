#include "../Headers/Biblioteca.hpp"
#include <fstream>

vector<Livro> *Biblioteca::getLivros()
{
    return &(this->listaLivros);
}

vector<Usuario> *Biblioteca::getUsuarios()
{
    return &(this->listaUsuario);
}

vector<Aluguel> *Biblioteca::getAlugueis()
{
    return &(this->listaAlugueis);
}

void Biblioteca::mostraMenuPrincipal()
{
    limpaTela();
    cout << "\t======MENU PRINCIPAL======";
    cout << "\n\t[1] - GERENCIA USUARIO:";
    cout << "\n\t[2] - GERENCIA LIVROS:";
    cout << "\n\t[3] - GERENCIA ALUGUEIS:";
    cout << "\n\t[0] - SAIR";
    cout << "\n\tENTRADA ->  ";
}

void Biblioteca::mostraMenuAluguel()
{
    system("clear || cls");
    cout << "-------MENU-------" << endl;
    cout << "[1] INSERIR :" << endl;
    cout << "[2] ESCONTRAR :" << endl;
    cout << "[3] FINALIZAR :" << endl;
    cout << "[4] LISTAR ATIVOS :" << endl;
    cout << "[5] LISTAR INATIVOS: " << endl;
    cout << "[5] LISTAR POR CLIENTE: " << endl;
    cout << "[0] SAIR" << endl;
    cout << "Escolha : ";
}

void Biblioteca::mostraMenuSecundario()
{
    limpaTela();
    cout << "\t===========MENU===========";
    cout << "\n\t[1] - INSERIR:";
    cout << "\n\t[2] - ENCONTRAR:";
    cout << "\n\t[3] - EXCLUIR:";
    cout << "\n\t[4] - LISTAR:";
    cout << "\n\t[5] - EDITAR:";
    cout << "\n\t[0] - SAIR";
    cout << "\n\tENTRADA ->  ";
}

void Biblioteca::menuPrincipal(vector<Aluguel> alugueis, vector<Usuario> usuarios, vector<Livro> livros)
{

    int escolha;

    do
    {
        Biblioteca::mostraMenuPrincipal();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {

        case 1:

            Biblioteca::menuUsuarios(usuarios);

            break;

        case 2:

            Biblioteca::menuLivros(livros);

            break;

        case 3:

            Biblioteca::menuAluguel(alugueis, usuarios, livros);

            break;

        default:
            break;
        }
    } while (escolha != 0);
}

void Biblioteca::menuAluguel(vector<Aluguel> &alugueis, vector<Usuario> &usuarios, vector<Livro> &livros)
{
    int escolha;
    do
    {
        Biblioteca::mostraMenuAluguel();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            insereAluguel(usuarios, livros, alugueis);
            break;
        case 2:
            encontrarAluguel(alugueis);
            break;
        case 3:
            finalizarAluguel(alugueis);
            break;
        case 4:
            listarAlugueisAtivos(alugueis);
            break;
        case 5:
            listarAlugueisInativos(alugueis);
            break;
        case 6:
            listarAluguelPorCliente(alugueis);
            break;
        default:
            break;
        }
    } while (escolha != 0);
}

void Biblioteca::limpaTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Biblioteca::pause()
{
    cout << "\n\tDigite enter para continuar!...\n";
    cin.get();
    limpaTela();
}

// PERSISTENCIA DE DADOS

void Biblioteca::recuperaUsuarios(vector<Usuario> &usuarios)
{
    ifstream usuariosFile;
    usuariosFile.open("../BancoDeDados/usuarios.txt");

    if (usuariosFile.is_open())
    {
        string id, nome, cpf, endereco, telefone;
        int idd;
        while (usuariosFile.eof() == false)
        {
            getline(usuariosFile, id);
            getline(usuariosFile, nome);
            getline(usuariosFile, cpf);
            getline(usuariosFile, endereco);
            getline(usuariosFile, telefone);

            if (id != "")
            {
                Usuario usuario(nome, cpf, endereco, telefone);
                idd = stoi(id);
                usuario.setId(idd);

                if (idd > Usuario::getQuantidadeDeIdentificadores())
                {
                    Usuario::setQuantidadeDeIdentificadores(idd);
                }
                usuarios.push_back(usuario);
            }
        }
        usuariosFile.close();
    }
    else
    {
        cout << "\n\tErro ao abrir o arquivo de usuarios!";
    }
}

void Biblioteca::recuperaLivros(vector<Livro> &livros)
{
    ifstream livrosFile;
    livrosFile.open("../BancoDeDados/livros.txt");

    if (livrosFile.is_open())
    {
        string id, titulo, autor, numPaginas, numDeCopiasDisponiveis;
        int idd, numPag, numDeCopias;
        while (livrosFile.eof() == false)
        {
            getline(livrosFile, id);
            getline(livrosFile, titulo);
            getline(livrosFile, autor);
            getline(livrosFile, numPaginas);
            getline(livrosFile, numDeCopiasDisponiveis);

            if (id != "")
            {
                numDeCopias = stoi(numDeCopiasDisponiveis);
                idd = stoi(id);
                numPag = stoi(numPaginas);
                Livro livro(titulo, autor, numPag, numDeCopias);
                livro.setId(idd);

                if (idd > Livro::getQuantidadeDeIdentificadores())
                {
                    Livro::setQuantidadeDeIdentificadores(idd);
                }
                livros.push_back(livro);
            }
        }
        livrosFile.close();
    }
    else
    {
        cout << "\n\tErro ao abrir o arquivo de livros!";
    }
}

void Biblioteca::recuperaAlugueis(vector<Aluguel> &alugueis, vector<Usuario> &usuarios, vector<Livro> &livros)
{
    ifstream inAlugueis;
    inAlugueis.open("../BancoDeDados/Alugueis.txt", ios_base::in);
    string idAluguel, idUsuario, idLivro, diaAluguel, mesAluguel, anoAluguel, ativo;
    int idAluguelINT, idUsuarioINT, idLivroINT, diaAluguelINT, mesAluguelINT, anoAluguelINT, ativoINT;
    Usuario *usuario;
    Livro *livro;
    if (inAlugueis.is_open())
    {
        while (inAlugueis.eof() == false)
        {
            getline(inAlugueis, idAluguel);
            getline(inAlugueis, idUsuario);
            getline(inAlugueis, idLivro);
            getline(inAlugueis, diaAluguel);
            getline(inAlugueis, mesAluguel);
            getline(inAlugueis, anoAluguel);
            getline(inAlugueis, ativo);
            if (!idAluguel.empty())
            {
                idAluguelINT = stoi(idAluguel);
                idUsuarioINT = stoi(idUsuario);
                idLivroINT = stoi(idLivro);
                diaAluguelINT = stoi(diaAluguel);
                mesAluguelINT = stoi(mesAluguel);
                anoAluguelINT = stoi(anoAluguel);
                ativoINT = stoi(ativo);

                for (auto it = usuarios.begin(); it != usuarios.end(); it++)
                {
                    if (it->getId() == idUsuarioINT)
                    {
                        usuario = &(*it);
                        break;
                    }
                }

                for (auto it = livros.begin(); it != livros.end(); it++)
                {
                    if (it->getId() == idLivroINT)
                    {
                        livro = &(*it);
                        break;
                    }
                }

                Data data;
                data.tm_mday = diaAluguelINT;
                data.tm_mon = mesAluguelINT;
                data.tm_year = anoAluguelINT;

                Aluguel aluguel(true, usuario, livro, data);
                if (ativoINT == 0)
                {
                    aluguel.setAtivo(false);
                }
                alugueis.push_back(aluguel);
            }
        }
        inAlugueis.close();
    }
}

// USUARIOS

void Biblioteca::menuUsuarios(vector<Usuario> &usuarios)
{
    int escolha;
    do
    {
        Biblioteca::mostraMenuSecundario();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            Biblioteca::insereUsuario(usuarios);
            break;

        case 2:
            Biblioteca::encontraUsuario(usuarios);
            break;

        case 3:
            Biblioteca::excluirUsuario(usuarios);
            break;

        case 4:
            Biblioteca::listarUsuarios(usuarios);
            break;

        case 5:
            Biblioteca::modificarUsuario(usuarios);
            break;

        default:

            break;
        }

    } while (escolha != 0);
}

void Biblioteca::insereUsuario(vector<Usuario> &usuarios)
{
    limpaTela();
    string nome, cpf, endereco, telefone;

    cout << "\n\tInforme o nome: ";
    getline(cin, nome);

    cout << "\n\tInforme o cpf:";
    getline(cin, cpf);

    cout << "\n\tInforme o endereço: ";
    getline(cin, endereco);

    cout << "\n\tInforme o telefone: ";
    getline(cin, telefone);

    Usuario usuario(nome, cpf, endereco, telefone);
    usuarios.push_back(usuario);

    ofstream usuariosFile;
    usuariosFile.open("../BancoDeDados/usuarios.txt", ios_base::app);

    if (usuariosFile.is_open())
    {
        usuariosFile << usuario.getId() << endl;
        usuariosFile << usuario.getNome() << endl;
        usuariosFile << usuario.getCPF() << endl;
        usuariosFile << usuario.getEndereco() << endl;
        usuariosFile << usuario.getTelefone() << endl;
        usuariosFile.close();
    }
    else
    {
        cout << "\n\tErro ao abrir o arquivo de usuarios!";
        pause();
    }
}

void Biblioteca::encontraUsuario(vector<Usuario> &usuarios)
{
    limpaTela();
    int id;
    cout << "\n\tInforme o número identificador do usuario: ";
    cin >> id;

    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {

        if (id == it->getId())
        {
            it->mostrarUsuario();
            return;
        }
    }

    cout << "\n\tUsuario não encontrado na base de dados!";
    pause();
}

void Biblioteca::listarUsuarios(vector<Usuario> &usuarios)
{
    limpaTela();
    cout << "\n\t==========LISTA DE USUARIOS==========\n";
    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        it->mostrarUsuario();
    }

    cout << "\n\t============FIM DA LISTA============\n";
    pause();
}

void Biblioteca::excluirUsuario(vector<Usuario> &usuarios)
{

    int id;
    bool usuarioExcluido = false;
    bool usuarioEncontrado = false;

    limpaTela();
    cout << "\n\tInforme o identificador do usuario que deseja excluir: ";
    cin >> id;
    cin.get();

    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        if (id == it->getId())
        {
            usuarios.erase(it);
            usuarioExcluido = true;
            usuarioEncontrado = true;
            break;
        }
    }

    if (usuarioExcluido)
    {
        cout << "\n\tUsuario excluido com sucesso!";
        pause();

        ofstream usuariosFile;
        usuariosFile.open("../BancoDeDados/usuarios.txt", ios_base::out);

        if (usuariosFile.is_open())
        {
            for (auto it = usuarios.begin(); it != usuarios.end(); it++)
            {
                usuariosFile << it->getId() << endl;
                usuariosFile << it->getNome() << endl;
                usuariosFile << it->getCPF() << endl;
                usuariosFile << it->getEndereco() << endl;
                usuariosFile << it->getTelefone() << endl;
            }
            usuariosFile.close();
        }
        else
        {
            cout << "\n\tErro ao abrir o arquivo de usuarios!";
            pause();
        }
    }
    if (!usuarioEncontrado)
    {
        cout << "\n\tUsuario não encontrado, na base de dados!";
        pause();
    }
}

void Biblioteca::modificarUsuario(vector<Usuario> &usuarios)
{

    int id;
    int escolha;
    string nome;
    string cpf;
    string endereco;
    string telefone;
    bool usuarioEncontrado = false;
    bool usuarioModificado = false;

    limpaTela();
    cout << "\n\tInforme o identificador do usuario: ";
    cin >> id;

    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        if (id == it->getId())
        {
            usuarioEncontrado = true;
            do
            {
                cout << "\n\tO QUE DESEJA ALTERAR?";
                cout << "\n\t[1] - NOME";
                cout << "\n\t[2] - CPF";
                cout << "\n\t[3] - ENDEREÇO";
                cout << "\n\t[4] - TELEFONE";
                cout << "\n\t[0] - SAIR";
                cout << "\n\tENTRADA -> ";
                cin >> escolha;
                cin.get();

                switch (escolha)
                {

                case 1:
                    limpaTela();
                    cout << "\n\tInforme o novo nome: ";
                    getline(cin, nome);
                    it->setNome(nome);
                    usuarioModificado = true;
                    break;

                case 2:
                    limpaTela();
                    cout << "\n\tInforme o novo cpf: ";
                    getline(cin, cpf);
                    it->setCPF(cpf);
                    usuarioModificado = true;
                    break;

                case 3:
                    limpaTela();
                    cout << "\n\tInforme o novo endereço: ";
                    getline(cin, endereco);
                    it->setEndereco(endereco);
                    usuarioModificado = true;
                    break;

                case 4:
                    limpaTela();
                    cout << "\n\tInforme o novo telefone: ";
                    getline(cin, telefone);
                    it->setTelefone(telefone);
                    usuarioModificado = true;
                    break;

                default:
                    break;
                }

            } while (escolha != 0);

            return;
        }
    }

    if (usuarioModificado)
    {
        ofstream usuariosFile;
        usuariosFile.open("../BancoDeDados/usuarios.txt", ios_base::out);
        if (usuariosFile.is_open())
        {
            for (auto it = usuarios.begin(); it != usuarios.end(); it++)
            {
                usuariosFile << it->getId() << endl;
                usuariosFile << it->getNome() << endl;
                usuariosFile << it->getCPF() << endl;
                usuariosFile << it->getEndereco() << endl;
                usuariosFile << it->getTelefone() << endl;
            }
            usuariosFile.close();
        }
    }
    else
    {
        if (!usuarioEncontrado)
        {
            cout << "\n\tUsuario não encontrado, na base de dados!";
            pause();
        }
    }
}

// LIVROS

void Biblioteca::menuLivros(vector<Livro> &livros)
{
    int escolha;

    do
    {
        Biblioteca::mostraMenuSecundario();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            Biblioteca::insereLivros(livros);
            break;

        case 2:
            Biblioteca::encontraLivros(livros);
            break;

        case 3:
            Biblioteca::excluirLivros(livros);
            break;

        case 4:
            Biblioteca::listarLivros(livros);
            break;

        case 5:
            Biblioteca::modificarLivros(livros);
            break;

        default:

            break;
        }

    } while (escolha != 0);
}

void Biblioteca::insereLivros(vector<Livro> &livros)
{
    limpaTela();
    string titulo, autor;
    int numPaginas, numDeCopiasDisponiveis;

    cout << "\n\tInforme o titulo do livro: ";
    getline(cin, titulo);

    cout << "\n\tInforme o autor do livro: ";
    getline(cin, autor);

    cout << "\n\tInforme o número de páginas do livro: ";
    cin >> numPaginas;

    cout << "\n\tInforme o número de cópias disponíveis: ";
    cin >> numDeCopiasDisponiveis;

    Livro livro(titulo, autor, numPaginas, numDeCopiasDisponiveis);
    livros.push_back(livro);

    ofstream livrosFile;
    livrosFile.open("../BancoDeDados/livros.txt", ios_base::app);

    if (livrosFile.is_open())
    {
        livrosFile << livro.getId() << endl;
        livrosFile << livro.getTitulo() << endl;
        livrosFile << livro.getAuthor() << endl;
        livrosFile << livro.getNumPaginas() << endl;
        livrosFile << livro.getNumDeCopiasDisponiveis() << endl;
        livrosFile.close();
    }
    else
    {
        cout << "\n\tErro ao abrir o arquivo de livros!";
        pause();
    }
}

void Biblioteca::encontraLivros(vector<Livro> &livros)
{
    limpaTela();
    int id;
    cout << "\n\tInforme o número identificador do livro: ";
    cin >> id;

    for (auto it = livros.begin(); it != livros.end(); it++)
    {

        if (id == it->getId())
        {
            it->mostrarLivro();
            return;
        }
    }
    cout << "\n\tLivro não encontrado na base de dados!";
    pause();
}

void Biblioteca::listarLivros(vector<Livro> &livros)
{
    limpaTela();
    cout << "\n\t==========LISTA DE LIVROS==========\n";
    for (auto it = livros.begin(); it != livros.end(); it++)
    {
        it->mostrarLivro();
    }

    cout << "\n\t============FIM DA LISTA============\n";
    pause();
}

void Biblioteca::excluirLivros(vector<Livro> &livros)
{
    limpaTela();
    int id;
    bool usuarioExcluido = false;
    bool usuarioEncontrado = false;
    cout << "\n\tInforme o identificador do livro: ";
    cin >> id;
    cin.get();

    for (auto it = livros.begin(); it != livros.end(); it++)
    {
        if (id == it->getId())
        {
            livros.erase(it);
            usuarioExcluido = true;
            usuarioEncontrado = true;
            break;
        }
    }

    if (usuarioExcluido)
    {
        cout << "\n\tLivro excluido com sucesso!";
        pause();
        ofstream livrosFile;
        livrosFile.open("../BancoDeDados/livros.txt", ios_base::out);

        if (livrosFile.is_open())
        {
            for (auto it = livros.begin(); it != livros.end(); it++)
            {
                livrosFile << it->getId() << endl;
                livrosFile << it->getTitulo() << endl;
                livrosFile << it->getAuthor() << endl;
                livrosFile << it->getNumPaginas() << endl;
                livrosFile << it->getNumDeCopiasDisponiveis() << endl;
            }
            livrosFile.close();
        }
        else
        {
            cout << "\n\tErro ao abrir o arquivo de livros!";
            pause();
        }
    }
    if (!usuarioEncontrado)
    {
        cout << "\n\tLivro não encontrado, na base de dados!";
        pause();
    }
}

void Biblioteca::modificarLivros(vector<Livro> &livros)
{
    limpaTela();
    int id;
    int escolha;
    string titulo;
    string autor;
    int numPaginas;
    int numDeCopiasDisponiveis;
    bool livroEncontrado = false;

    cout << "\n\tInforme o identificador do livro: ";
    cin >> id;

    for (auto it = livros.begin(); it != livros.end(); it++)
    {

        if (id == it->getId())
        {

            do
            {
                limpaTela();
                cout << "\n\tO QUE DESEJA ALTERAR?";
                cout << "\n\t[1] - TITULO";
                cout << "\n\t[2] - AUTOR";
                cout << "\n\t[3] - NÚMEROS DE PÁGINAS";
                cout << "\n\t[4] - NÚMERO DE CÓPIAS DISPONÍVEIS";
                cout << "\n\t[0] - SAIR";
                cout << "\n\tENTRADA -> ";
                cin >> escolha;
                cin.get();

                switch (escolha)
                {
                case 1:
                    limpaTela();
                    cout << "\n\tInforme o novo titulo: ";
                    getline(cin, titulo);
                    it->setTitulo(titulo);
                    livroEncontrado = true;
                    break;

                case 2:
                    limpaTela();
                    cout << "\n\tInforme o novo autor: ";
                    getline(cin, autor);
                    it->setAuthor(autor);
                    livroEncontrado = true;
                    break;

                case 3:
                    limpaTela();
                    cout << "\n\tInforme o novo número de páginas: ";
                    cin >> numPaginas;
                    it->setNumPaginas(numPaginas);
                    livroEncontrado = true;
                    break;

                case 4:
                    limpaTela();
                    cout << "\n\tInforme o novo número de cópias disponíveis: ";
                    cin >> numDeCopiasDisponiveis;
                    it->setNumDeCopiasDisponiveis(numDeCopiasDisponiveis);
                    livroEncontrado = true;
                    break;

                default:

                    break;
                }

            } while (escolha != 0);
        }
    }

    if (livroEncontrado)
    {
        ofstream livrosFile;
        livrosFile.open("../BancoDeDados/livros.txt", ios_base::out);
        if (livrosFile.is_open())
        {
            for (auto it = livros.begin(); it != livros.end(); it++)
            {
                livrosFile << it->getId() << endl;
                livrosFile << it->getTitulo() << endl;
                livrosFile << it->getAuthor() << endl;
                livrosFile << it->getNumPaginas() << endl;
                livrosFile << it->getNumDeCopiasDisponiveis() << endl;
            }
            livrosFile.close();
        }
    }
    else
    {
        if (!livroEncontrado)
        {
            cout << "\n\tLivro não encontrado, na base de dados!";
            pause();
        }
    }
}

// ALUGUEIS

void Biblioteca::insereAluguel(vector<Usuario> &usuarios, vector<Livro> &livros, vector<Aluguel> &alugueis)
{

    int usuarioId;
    bool encontrouUsuario = false;

    // Busca o usuario
    Usuario *usuario;
    cout << "\n\tInforme o id do usuario: ";
    cin >> usuarioId;
    cin.get();

    for (auto it = usuarios.begin(); it != usuarios.end(); it++)
    {
        if (usuarioId == it->getId())
        {
            usuario = &(*it);
            encontrouUsuario = true;
            break;
        }
    }

    if (!encontrouUsuario)
    {
        cout << "\n\tUsuario não encontrado, na base de dados!";
        pause();
        return;
    }

    // Busca o livro
    bool encontrouLivro = false;
    Livro *livro;
    int livroId;

    cout << "\n\tInforme o id do livro: ";
    cin >> livroId;
    cin.get();

    for (auto it = livros.begin(); it != livros.end(); it++)
    {
        if (livroId == it->getId())
        {
            livro = &(*it);
            encontrouLivro = true;
            break;
        }
    }

    if (!encontrouLivro)
    {
        cout << "\n\tLivro não encontrado, na base de dados!";
        pause();
        return;
    }

    if (livro->getNumDeCopiasDisponiveis() == 0)
    {
        cout << "\n\tLivro não disponível para aluguel!";
        pause();
        return;
    }
    else
    {
        livro->setNumDeCopiasDisponiveis(livro->getNumDeCopiasDisponiveis() - 1);

        ofstream livrosFile;
        livrosFile.open("../BancoDeDados/livros.txt", ios_base::out);
        if (livrosFile.is_open())
        {
            for (auto it = livros.begin(); it != livros.end(); it++)
            {
                livrosFile << it->getId() << endl;
                livrosFile << it->getTitulo() << endl;
                livrosFile << it->getAuthor() << endl;
                livrosFile << it->getNumPaginas() << endl;
                livrosFile << it->getNumDeCopiasDisponiveis() << endl;
            }
            livrosFile.close();
        }
    }

    time_t tempoAtual = time(nullptr);
    Data *dataInicio = localtime(&tempoAtual);
    dataInicio->tm_year += 1900;
    dataInicio->tm_mon += 1;

    Aluguel aluguel(true, usuario, livro, *dataInicio);
    alugueis.push_back(aluguel);

    ofstream alugueisFile;
    alugueisFile.open("../BancoDeDados/alugueis.txt", ios_base::app);

    if (alugueisFile.is_open())
    {
        alugueisFile << aluguel.getId() << endl;
        alugueisFile << aluguel.getUsuario()->getId() << endl;
        alugueisFile << aluguel.getLivro()->getId() << endl;
        alugueisFile << aluguel.getDataDeAluguel().tm_mday << endl;
        alugueisFile << aluguel.getDataDeAluguel().tm_mon << endl;
        alugueisFile << aluguel.getDataDeAluguel().tm_year << endl;
        alugueisFile << aluguel.getAtivo() << endl;
        alugueisFile.close();
    }
    else
    {
        cout << "\n\tErro ao abrir o arquivo de alugueis!";
        pause();
    }
}

void Biblioteca ::finalizarAluguel(vector<Aluguel> &alugueis)
{
    int idUsuario;
    int idLivro;

    cout << "\n\tInforme o id do usuario: ";
    cin >> idUsuario;
    cin.get();

    cout << "\n\tInforme o id do livro: ";
    cin >> idLivro;
    cin.get();

    for (auto it = alugueis.begin(); it != alugueis.end(); it++)
    {
        if (idUsuario == it->getUsuario()->getId() && idLivro == it->getLivro()->getId() && it->getAtivo())
        {
            it->setAtivo(false);
            cout << "\n\tAluguel finalizado com sucesso!";
            pause();

            ofstream alugueisFile;
            alugueisFile.open("../BancoDeDados/alugueis.txt", ios_base::out);
            if (alugueisFile.is_open())
            {
                for (auto it = alugueis.begin(); it != alugueis.end(); it++)
                {
                    alugueisFile << it->getId() << endl;
                    alugueisFile << it->getUsuario()->getId() << endl;
                    alugueisFile << it->getLivro()->getId() << endl;
                    alugueisFile << it->getDataDeAluguel().tm_mday << endl;
                    alugueisFile << it->getDataDeAluguel().tm_mon << endl;
                    alugueisFile << it->getDataDeAluguel().tm_year << endl;
                    alugueisFile << it->getAtivo() << endl;
                }
                alugueisFile.close();
            }
            else
            {
                cout << "\n\tErro ao abrir o arquivo de alugueis!";
                pause();
            }
            pause();
            return;
        }
    }
    cout << "\n\tAluguel não encontrado, na base de dados!";
}

void Biblioteca::encontrarAluguel(vector<Aluguel> &alugueis)
{
    int idUsuario;
    int idLivro;

    cout << "\n\tInforme o id do usuario: ";
    cin >> idUsuario;
    cin.get();

    cout << "\n\tInforme o id do livro: ";
    cin >> idLivro;
    cin.get();

    for (auto it = alugueis.begin(); it != alugueis.end(); it++)
    {
        if (idUsuario == it->getUsuario()->getId() && idLivro == it->getLivro()->getId() && it->getAtivo())
        {
            it->mostrarAluguel();
            pause();
            return;
        }
    }
    cout << "\n\tAluguel não encontrado, na base de dados!";
}

void Biblioteca::listarAlugueisAtivos(vector<Aluguel> &alugueis)
{
    limpaTela();
    cout << "\n\t==========LISTA DE ALUGUEIS ATIVOS==========\n";
    for (auto it = alugueis.begin(); it != alugueis.end(); it++)
    {
        if (it->getAtivo())
        {
            it->mostrarAluguel();
        }
    }

    cout << "\n\t============FIM DA LISTA============\n";
    pause();
}

void Biblioteca::listarAlugueisInativos(vector<Aluguel> &alugueis)
{
    limpaTela();
    cout << "\n\t==========LISTA DE ALUGUEIS INATIVOS==========\n";
    for (auto it = alugueis.begin(); it != alugueis.end(); it++)
    {
        if (!it->getAtivo())
        {
            it->mostrarAluguel();
        }
    }

    cout << "\n\t============FIM DA LISTA============\n";
    pause();
}

void Biblioteca::listarAluguelPorCliente(vector<Aluguel> &alugueis)
{
    int idUsuario;
    bool clienteEncontrado = false;

    cout << "\n\tInforme o id do usuario: ";
    cin >> idUsuario;
    cin.get();

    limpaTela();
    cout << "\n\t==========LISTA DE ALUGUEIS==========\n";
    for (auto it = alugueis.begin(); it != alugueis.end(); it++)
    {
        if (it->getUsuario()->getId() == idUsuario && it->getAtivo())
        {
            clienteEncontrado = true;
            it->mostrarAluguel();
        }
    }

    cout << "\n\t============FIM DA LISTA============\n";
    pause();

    if (!clienteEncontrado)
    {
        cout << "\n\tCliente não encontrado, na base de dados!";
        pause();
    }
}
