#include <iostream>
#include <iomanip>

using namespace std;

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

int main() {
    const int NUM_ALUNOS = 5;
    
    char nomes[NUM_ALUNOS][50]; 
    float notas[NUM_ALUNOS][3];
    float medias[NUM_ALUNOS];
    const char* situacoes[NUM_ALUNOS];
    
    float maior_media = -1.0;
    int indice_melhor_aluno = 0; 

    cout << "=== CADASTRO DE ALUNOS ===\n";

    // Requisito: Estrutura de repetição para entrada de dados
    for (int i = 0; i < NUM_ALUNOS; ++i) {
        cout << "\n--- Aluno " << i + 1 << " ---\n";
        cout << "Nome: ";
        
        cin >> ws; // Limpa o buffer do teclado (evita que o 'Enter' pule a leitura do nome)
        cin.getline(nomes[i], 50); // Lê até 49 caracteres e aceita espaços

        // Estrutura de repetição para as 3 notas
        for (int j = 0; j < 3; ++j) {
            cout << "Nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }

        // Chama a função para calcular a média
        medias[i] = calcularMedia(notas[i][0], notas[i][1], notas[i][2]);

        // Requisito: Estrutura condicional (if/else) para determinar a situação
        if (medias[i] >= 7.0) {
            situacoes[i] = "Aprovado";
        } else {
            situacoes[i] = "Reprovado";
        }

        // Lógica para descobrir a maior média da turma
        if (medias[i] > maior_media) {
            maior_media = medias[i];
            indice_melhor_aluno = i; // Salva o índice de quem tirou a maior nota
        }
    }


    // Requisito: Exibição dos dados em formato de tabela
    cout << "\n==================================== TABELA DE ALUNOS ====================================\n";
    
    cout << left << setw(20) << "Nome" 
         << setw(10) << "Nota 1" 
         << setw(10) << "Nota 2" 
         << setw(10) << "Nota 3" 
         << setw(10) << "Media" 
         << "Situacao\n";
    cout << "------------------------------------------------------------------------------------------\n";

    cout << fixed << setprecision(2);

    // Estrutura de repetição para exibir os dados dos vetores paralelos
    for (int i = 0; i < NUM_ALUNOS; i++) {
        cout << left << setw(20) << nomes[i] 
             << setw(10) << notas[i][0] 
             << setw(10) << notas[i][1] 
             << setw(10) << notas[i][2] 
             << setw(10) << medias[i] 
             << situacoes[i] << "\n";
    }
    cout << "==========================================================================================\n";

    cout << "\n-> Destaque: O(a) aluno(a) com a maior media foi '" << nomes[indice_melhor_aluno] 
         << "' com a nota " << maior_media << ".\n\n";

    return 0;
}