#include <iostream>

using namespace std;

int main()
{
    //Vetores com as informações dos animais escolhidos.
    float metanoAnimal[] = {250, 270, 270, 560, 285, 285, 285};
    float biogasAnimal[] = {5, 4.5, 4, 8, 9, 10, 4.9};
    //Variáveis de verificação.
    int x = 0, c, vT = 0, vP = 0;
    //Variáveis de entrada do usuário.
    float tempBio, presBio, pesoTan;
    int animalEsc;
    
    //Interface para explicar ao usuário.
    cout << "*******************************************************************************************\n";
    cout << "                        Programa de automação do Biodigestor\n";
    cout << "*******************************************************************************************\n";
    cout << "\n--------------------------Por favor insira os dados pedidos---------------------------\n";
    cout << "\n";
    cout << "\n";
    
    while(x == 0){
        //Entrada do tipo de animal 
        cout << "*******************************************************************************************\n";
        cout << "Digite o número correspondente ao tipo de dejeto de animal que vai abastecer o tanque.\n";
        cout << "                               Caprino/ovino: 1\n";
        cout << "                              Bovinos de Leite: 2\n";
        cout << "                              Bovinos de corte: 3\n";
        cout << "                                  Suínos: 4\n";
        cout << "                               Frango de corte: 5\n";
        cout << "                                 Poedeiras: 6\n";
        cout << "                                  Codornas: 7\n";
        cout << "*******************************************************************************************\n";
        cout << "Tipo Escolhido: ";
        cin >> animalEsc;
        system("clear");
        
        //Tratativa de erros caso o usuário digite errado.
        if(animalEsc >= 1 && animalEsc <= 7){
            x = 1;
        }
        if(animalEsc < 1 || animalEsc > 7){
            cout << "*******************************************************************************************\n";
            cout << "       ATENÇÃO: Por favor digite um número que esteja na lista a baixo.\n";
            cout << "*******************************************************************************************\n";
            cout << "\n--------------------------Por favor insira os dados novamente---------------------------\n";
            cout << "\n";
            cout << "\n";
        }
    }
    
    x = 0;
    
    //While para deixar a verificação de cada etapa em loop até que todas as etapas estejão corretas.
    while(x == 0){
        //Entradas da situação atual do Biodigestor.
        cout << "Para iniciar o biodigestor o tanque de entrada precisa estar cheio com 325Kg de dejetos.\n";
        cout << "Peso dos dejetos presentes no tanque: ";
        cin >> pesoTan;
        system("clear");
        
        //começo das verificações das entradas e respostas de acordo com as mesmas.
        
        //vericação do tanque de entrada.
        if(pesoTan < 325){
            cout << "*******************************************************************************************\n";
            cout << "       ATENÇÃO: O tanque de entrada precisa estar cheio para iniciar o processo.\n";
            cout << "*******************************************************************************************\n";
            cout << "\n--------------------------Por favor insira os dados novamente---------------------------\n";
            cout << "\n";
            cout << "\n";
        }else if(pesoTan > 325){
            cout << "*******************************************************************************************\n";
            cout << "       ATENÇÃO: O peso dos dejetos presentes no tanque ultrapassa o peso limite.\n";
            cout << "*******************************************************************************************\n";
            cout << "\n--------------------------Por favor insira os dados novamente---------------------------\n";
            cout << "\n";
            cout << "\n";
        }else{
            //Output fase01.
            cout << "*******************************************************************************************\n";
            cout << "                        Fase 01 - Abastecimento do tanque de entrada concluída\n";
            cout << "*******************************************************************************************\n";
            cout << "\n";
            cout << "\n";
            cout << "\n--------------------------Abrindo portas do tanque de entrada---------------------------\n";
            cout << "\n";
            cout << "\n";
            cout << "\nFase 01 concluida, digite 1 para continuar e 0 para parar do sistema: ";
            cin >> c;
            if(c == 0){
                return 0;
            }else{
                system("clear");
                x = 1;
            }
        }
    }
    
    x = 0;
    
    while(x == 0){
        //Output fase02.
        cout << "*******************************************************************************************\n";
        cout << "                        Fase 02 - Controle do Biodigestor\n";
        cout << "*******************************************************************************************\n";
        cout << "\n";
        cout << "\n";
        cout << "\n--------------------------Fechando portas do tanque de entrada---------------------------\n";
        cout << "\n";
        cout << "\n";
        cout << "\n--------------------------Ligando o misturador do tanque---------------------------\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        //Input da temperatura.
        cout << "A temperatura do Biodigestor deve estar entre 30ºC e 35ºC para iniciar a fase de mistura.\n"; 
        cout << "Temperatura atual do Biodigestor: "; 
        cin >> tempBio; 
        cout << "\n";
        //Input da pressão.
        cout << "A pressão dentro do Biodigestor deve ser mantida entre 0,4 a 0,58mca (Metro de coluna d'água) durante todo o processo.\n";
        cout << "Pressão atual no Biodigestor: ";
        cin >> presBio;
        cout << "\n";
        system("clear");
        //verificação da temperatura.
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "*******************************************************************************************\n";
        cout << "                        Resultado da verificação da temperatura:\n";
        //Caso a temperatura do input esteja baixa.
        if(tempBio < 30){
            //Caso a temperatura já estivesse baixa antes.
            if(vT == 1){
                cout << "\n                        A temperatura continua baixa.\n";
                cout << "\n";
                cout << "\n--------------------------Aquecedor continua ligado---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 1;
            }
            //Caso a temperatura estivesse alta antes.
            else if(vT == 2){
                cout << "\n                        A temperatura está baixa agora.\n";
                cout << "\n";
                cout << "\n-------------------------- Desligando resfriador e ligando aquecedor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 1;
            }
            //Caso seja a primeira vez que a temperatura está baixa.
            else if(vT == 0){
                cout << "\n                        A temperatura está baixa.\n";
                cout << "\n";
                cout << "\n--------------------------Ligando o aquecedor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 1;
            }
        //Caso a temperatura do input esteja alta.    
        }else if(tempBio > 35){
            //Caso a temperatura estivesse baixa antes.
            if(vT == 1){
                cout << "\n                        A temperatura está alta agora.\n";
                cout << "\n";
                cout << "\n-------------------------- Desligando aquecedor e ligando resfriador---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 2;
            }
            //Caso a temperatura já estivesse alta antes.
            else if(vT == 2){
                cout << "\n                        A temperatura continua alta.\n";
                cout << "\n";
                cout << "\n--------------------------Resfriador continua ligado---------------------------\n";
                cout << "\n";
            cout << "\n";
                vT = 2;
            }
            //Caso seja a primeira vez que a temperatura está alta.
            else if(vT == 0){
                cout << "\n                        A temperatura está alta.\n";
                cout << "\n";
                cout << "\n--------------------------Ligando o resfriador---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 2;
            }
        //Caso a temperatura do input esteja normal.
        }else{
            //Caso a temperatura estivesse baixa e normalizou.
            if(vT == 1){
                cout << "\n                        A temperatura está normal agora.\n";
                cout << "\n";
                cout << "\n-------------------------- Desligando aquecedor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 0;
            }
            //Caso a temperatura estivesse alta e normalizou.
            else if(vT == 2){
                cout << "\n                        A temperatura está normal agora.\n";
                cout << "\n";
                cout << "\n--------------------------Desligando resfriador---------------------------\n";
                cout << "\n";
                cout << "\n";
                vT = 0;
            }
            //Caso a temperatura esteja adequada.
            else if(vT == 0){
                cout << "\n                        Temperatura adequada.\n";
                cout << "\n";
                cout << "\n";
                vT = 0;
            }
        }
        cout << "\n";
        cout << "\n";
        //verificação da pressão.
        cout << "*******************************************************************************************\n";
        cout << "                        Resultado da verificação da pressão:\n";
        //Caso a pressão do input esteja baixa.
        if(presBio < 0.4){
            //Caso a pressão já estivesse baixa antes.
            if(vP == 1){
                cout << "\n                      A pressão interna continua baixa\n";
                cout << "\n";
                cout << "\n--------------------------A velociadade do misturardor continua maior do que o normal---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 1;
            }
            //Caso a pressão estivesse alta antes.
            else if(vP == 2){
                cout << "\n                      A pressão interna está baixa agora\n";
                cout << "\n";
                cout << "\n--------------------------Aumentando a velociadade do misturardor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 1;
            }
            //Caso seja a primeira vez que a pressão está baixa. 
            else if(vP == 0){
                cout << "\n                      A pressão interna está baixa\n";
                cout << "\n";
                cout << "\n--------------------------Aumentando a velociadade do misturardor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 1;
            }
        }else if(presBio > 0.58){
            //Caso a pressão estivesse baixa antes.
            if(vP == 1){
                cout << "\n                      A pressão interna está alta agora\n";
                cout << "\n";
                cout << "\n--------------------------Diminuindo a velocidade do misturador---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 2;
            }
            //Caso a pressão já estivesse alta antes.
            else if(vP == 2){
                cout << "\n                      A pressão interna continua alta\n";
                cout << "\n";
                cout << "\n--------------------------A velociadade do misturardor continua menor do que o normal---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 2;
            }
            //Caso seja a primeira vez que a pressão está alta.
            else if(vP == 0){
                cout << "\n                      A pressão interna está alta\n";
                cout << "\n";
                cout << "\n--------------------------Diminuindo a velociadade do misturardor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 2;
            }
        }else{
            //Caso a pressão estivesse baixa antes. 
            if(vP == 1){
                cout << "\n                      A pressão interna está dentro da faixa correta\n";
                cout << "\n";
                cout << "\n--------------------------Diminuindo a velocidade do misturador para a velocidade normal---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 0;
            }
            //Caso a pressão estivesse alta antes.
            else if(vP == 2){
                cout << "\n                      A pressão interna está dentro da faixa correta\n";
                cout << "\n";
                cout << "\n--------------------------Aumentando a velocidade do misturador para a velocidade normal---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 0;
            }
            //Caso a pressão esteja adequada.
            else if(vP == 0){
                cout << "\n                      A pressão interna está dentro da faixa correta\n";
                cout << "\n";
                cout << "\n--------------------------Mantendo a velociadade normal do misturardor---------------------------\n";
                cout << "\n";
                cout << "\n";
                vP = 0;
            }
        }
        //Caso a temperatura e pressão estejam corretas.    
        if(vT == 0 && vP == 0){
            cout << "\n";
            cout << "\n";
            cout << "*******************************************************************************************\n";
            cout << "                        Fase 02 - Controle de Temperatura e Pressão concluída\n";
            cout << "*******************************************************************************************\n";
            cout << "\n";
            cout << "\n";
            cout << "\n--------------------------Parando misturador---------------------------\n";
            cout << "\n";
            cout << "\n";
            cout << "\n--------------------------Abrindo portas de saída---------------------------\n";
            cout << "\nFase 02 concluida, digite 1 para continuar e 0 para parar do sistema: ";
            cin >> c;
            
            if(c == 1){
                x = 1;
            }else{
                return 0;
            }
            system("clear");
        }
        //Caso a temperatura ou pressão não estejam corretas.
        else{
            cout << "\nFase 02 ainda em processo, digite 1 para verificar novamente a temperatura e pressão ou 0 para parar do sistema: ";
            cin >> c;
            if(c == 1){
                x = 0;
            }else{
                return 0;
            }
            system("clear");
        }
    }
    
    //Fase de saída do biogas e biofertilizante. 
    cout << "*******************************************************************************************\n";
    cout << "               Fase 03 - Controle do esvaziamento de materiais do tanque\n";
    cout << "*******************************************************************************************\n";
    cout << "\n";
    cout << "\n";
    //Tela de informação sobre matéria gerada.
    cout << "*******************************************************************************************\n";
    cout << "\n";
    cout << "\n";
    cout << "\nM³ de biogás gerado: " << biogasAnimal[animalEsc - 1] * 325 << "\n";
    cout << "\nM³ de gás metano gerado: " << (metanoAnimal[animalEsc - 1] * 5) * 0.5 << "\n";
    cout << "\nM³ de gás carbônico gerado: " << metanoAnimal[animalEsc - 1] * 0.3 << "\n";
    cout << "\nQuantidade de biofertilizantes gerado: " << 325 * 0.8 << "\n";
    cout << "\n";
    cout << "\n";
    cout << "*******************************************************************************************\n";
    cout << "\n";
    cout << "\n";
    cout << "\n--------------------------Cálculo sobre o biogás gerado---------------------------\n";
    cout << "\n";
    cout << "\n";
    cout << "O biogás gerado equivale a: .\n";
    cout << "Gasolina: " << (biogasAnimal[animalEsc - 1] * 325)* 0.321 << "L\n";
    cout << "Querosene: "<< (biogasAnimal[animalEsc - 1] * 325)* 0.341 << "L\n";
    cout << "Óleo Diesel: "<< (biogasAnimal[animalEsc - 1] * 325)* 0.358 << "L\n";
    cout << "Gás de Cozinha (GLP): "<< (biogasAnimal[animalEsc - 1] * 325)* 0.396 << "Kg\n";
    cout << "Lenha: "<< (biogasAnimal[animalEsc - 1] * 325)* 1.450 << "Kg\n";
    
    return 0;
}
