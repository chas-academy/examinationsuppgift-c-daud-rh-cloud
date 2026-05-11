#include <stdio.h>

//variabler
char elevensnamn[5][11];
int Poang[5][13];

double total_klass_medel = 0;
double klassmedel = 0;
double singelelev_medel[5];

int main() {

    //// Inmatning för elevnsnamn och deras betyg -->
    
    for (int i = 0; i < 5; i++) { 
        scanf("%s", elevensnamn[i]); 

        /// kollar ascii nummer
        if (elevensnamn[i][0] >= 'a' && elevensnamn[i][0] <= 'z') { 
            elevensnamn[i][0] = elevensnamn[i][0] - 32;} 

        int summan = 0; 
        for (int j = 0; j < 13; j++) { 
            scanf("%d", &Poang[i][j]); 
            summan = summan + Poang[i][j];
        } 
    
        singelelev_medel[i] = summan / 13.0;
        total_klass_medel = total_klass_medel + singelelev_medel[i];
    }

    klassmedel = total_klass_medel / 5.0;




    // Hitta eleven med högst medelvärde -->
    double vinnar_index = 0;
    char vinnares_namn[11];

    for ( int g = 0; g < 5; g++) {
        if (singelelev_medel[g] > vinnar_index) {
            vinnar_index = singelelev_medel[g];

            //  namnet till vinnar-variabeln
            for (int n = 0; n < 11; n++) {
                vinnares_namn[n] = elevensnamn[g][n];
            }
        }  
    } 

             printf("%s\n", vinnares_namn);


    ///  under klassens medelvärde!! -->

    for (int i = 0; i < 5; i++) {
        if (singelelev_medel[i] < klassmedel) {
            printf("%s\n", elevensnamn[i]);
        }
    }  
 
    return 0;
}