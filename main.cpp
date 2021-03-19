#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include<sstream>
#include<fstream>


using namespace std;

string Codificador(string temp, map<string,int>& dic)
{
    stringstream entrada  ;
    entrada.clear();
    string t  = "";
    int codigo ;
    string previa ="";
    for(int i = 0 ; i <= temp.length() ; i++)
    {
        previa = t ;
        t+=temp[i];
        if(dic.find(t) == dic.end() && previa!="")
        {
            dic[t] = dic.size();
            codigo = dic[previa];
            entrada << codigo<<" ";
            previa.clear();
            t.clear();
            t += temp[i];
        }
    }
    return entrada.str();
}

void ImprimeDicionario (map<string,int>& dicionario)
{
    map<string,int>::iterator inc;
    for(inc=dicionario.begin(); inc!=dicionario.end(); inc++)
        cout<<inc->first<<" :: "<<inc->second<<endl;
}


int main(int argc, char* argv[])
{
    int s;
    cout<< "ATIVIDADE DE IMPLEMENTACAO 02 DA DISCIPLINA DE ESTRUTURA DE DADOS 2 - 2020.3" << endl;
    cout<< "DISCENTE: Maria Meiriele Dias da Silva" << endl;
    cout<< "MATRICULA: 201476009 "<< endl;
    cout<< "COMPRESSAO VIA LZW"<<endl<<endl;
    cout<< "IMPRIMIR EM TELA?(1 ou 0) ";
    cin >> s;
    cout<<endl<<endl;


    //INICIALIZA O DICIONARIO COM A TABELA ASCII
    map<string, int> dicionario;
    string aux;
    for(int i=0; i<256; i++)
    {
        aux = i;
        dicionario[aux] = i;
    }


    fstream arquivo;
    ofstream saida;
    string codificado = "";

    arquivo.open ("entrada.txt");
    if(arquivo.is_open())
    {
        while (!arquivo.eof())
        {
            string sout;
            getline(arquivo,sout);
            codificado += Codificador(sout,dicionario);
        }
    }
    else
        cerr<<"Erro ao abrir arquivo de saida!"<<endl;

    if(s == 1)
        cout<<codificado<<endl<<endl;
    else
    {
        saida.open("saida.txt");
        if(saida.is_open())
        {
            saida<<codificado;
        }
        else
            cerr<<"Erro ao abrir arquivo de saida!"<<endl;
    }


    arquivo.close();
    saida.close();


    return 0;
}


