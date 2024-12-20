#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>

void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
int  end(int grille[7][6],int player);
void  ia(int grille[7][6]);

int main(){
    int grille[7][6] = {};
    std::string choix;

    int player = 1;
    int c = 0;
    int var = 0;
    int mj;

    bool continuer = true;

    int  change = 1;
    

    drawGrid(grille);

    

        

        while (change == 1){

            std::cout << "Quelle methode de jeu utiliser: " << std::endl;
            std::cout << "j1 VS j2 (1)" << std::endl;
            std::cout << "j1 VS IA (2)" << std::endl;
            std::cin >> mj;
            continuer = true;

            if (mj == 1){
            while (continuer == true){
                std::cout << "player_" << player << " -> col :";
                std::cin >> choix;
            
                if (choix == "exit"){
                    break;
                }   

                bool success = false;

                if (choix.size() == 1){
                    if (choix[0] >= '0' && choix[0] <= '7'){
                        int col = choix[0]  - '0';

                        success = playTurn(grille, col, player);
                    }
                }

                system("CLS");

                if (!success){
                    std::cout << "votre choix est incorrect\n";
                } else{
                    if (player == 1) player = 2;
                    else player = 1;
                }

                drawGrid(grille);
                c = end(grille,player);
                if(c == 1){
                    std::cout << "Le joueur 1 a gagne"<< std::endl;
                    std::cout << "continuer ? oui(1)/non(2) :  ";
                    std::cin >> var;
                    if(var == 1){
                        for(int i=0; i<=5; i++){
                            for(int j=0; j<=6; j++){
                                grille[i][j] = 0;
                            }
                        }
                        player = 1;
                        c = 0;
                        std::cout << "Changer de mode ? oui(1) / non (2):  ";
                        std::cin >> change;
                        if(change == 1)
                            continuer = false;
                        else
                            continuer = true;
                    }else{
                        continuer = false;
                        change = 0;
                    }
                }else if (c == 2){
                    std::cout << "Le joueur 2 a gagne"<< std::endl;
                    std::cout << "continuer ? oui(1)/non(2) :  ";
                    std::cin >> var;
                    if(var == 1){
                        for(int i=0; i<=5; i++){
                            for(int j=0; j<=6; j++){
                                grille[i][j] = 0;
                            }
                        }
                        player = 1;
                        c = 0;
                        std::cout << "Changer de mode ? oui(1) / non (2):  ";
                        std::cin >> change;
                        if(change == 1)
                            continuer = false;
                        else
                            continuer = true;
                    }else{
                        continuer = false;
                        change = 0;
                    }
                }else continuer = true;
            }
            

            // IA player
        

            }else if(mj == 2){
                while(continuer){

                    player = 1;
                    std::cout << "player" << " -> col :";
                    std::cin >> choix;
                
                    if (choix == "exit"){
                        break;
                    }   

                    bool success = false;
                

                    if (choix.size() == 1){
                        if (choix[0] >= '0' && choix[0] <= '7'){
                            int col = choix[0]  - '0';

                            success = playTurn(grille, col, player);
                        }
                    }

                    system("CLS");

                    if (!success){
                        std::cout << "votre choix est incorrect\n";
                    }else{
                        if (player == 1){
                            ia(grille);
                            player = 1;
                        } 
                    }

                    drawGrid(grille);
                    c = end(grille,player);
                    if(c == 1){
                        std::cout << "Le joueur a gagne"<< std::endl;
                        std::cout << "continuer ? oui(1) / non(2) :  ";
                        std::cin >> var;
                        if(var == 1){
                            for(int i=0; i<=5; i++){
                                for(int j=0; j<=6; j++){
                                    grille[i][j] = 0;
                                }
                            }
                            player = 1;
                            c = 0;
                            std::cout << "Changer de mode ? oui(1) / non (2):  ";
                            std::cin >> change;
                            if(change == 1)
                                continuer = false;
                            else
                                continuer = true;
                        }else{
                            continuer = false;
                            change = 0;
                        }
                    }else if (c == 2){
                        std::cout << "L'IA a gagne"<< std::endl;
                        std::cout << "continuer ? oui(1) / non(2) :  ";
                        std::cin >> var;
                        if(var == 1){
                            for(int i=0; i<=5; i++){
                                for(int j=0; j<=6; j++){
                                    grille[i][j] = 0;
                                }
                            }
                            player = 1;
                            c = 0;
                            std::cout << "Changer de mode ? oui(1) / non (2):  ";
                            std::cin >> change;
                            if(change == 1)
                                continuer = false;
                            else
                                continuer = true;
                        }else{
                            continuer = false;
                            change = 0;
                        }
                    }else continuer = true;
                }
            
            }
            
        }
        
    return 0;
}



void drawGrid(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}

int end(int grille[7][6], int player){
    int g = 0, r = 0, g1=0, r1 =0, t = 0, s = 0,t1= 0, s1 = 0, i, j;
    for(int ligne = 0; ligne < 6; ligne++){
        g = 0, r = 0, g1=0, r1 =0;
        for(int col = 0; col < 7; col++){

            if(grille[col][ligne] == 1){
                if (grille[col+1][ligne] == 1)
                    g++;
                if(g > 0 && grille[col-1][ligne] != 1)
                    g = 0;


            }else if(grille[col][ligne] == 2){
                if (grille[col+1][ligne] == 2)
                    r++;
                if(r > 0 && grille[col-1][ligne] != 2)
                    r = 0;

            } 
            

            if(grille[ligne][col] == 1){
                if (grille[ligne][col +1] == 1)
                    g1++ ;
                if(g1 > 0 && grille[ligne][col-1] != 1)
                    g1 = 0;


            }else if(grille[ligne][col] == 2){
                if (grille[ligne][col +1] == 2)
                    r1++;
                if(r1 > 0 && grille[ligne][col-1] != 2)
                    r1 = 0;

            } 


            
        }

        
        
        if(g1 >= 2 || g >= 2){
            return 1;
        }else if(r1 >= 2 || r >= 2){
            return 2;
        }
            
             
    }
    for(int ligne = 0; ligne<= 7; ligne++){
        t = 0, s = 0,t1= 0, s1 = 0;
        for(int col = 0; col <= 6; col++){
            if(grille[ligne][col] == 1){
                for(i = 0; i < 3; i++){
                    if(grille[ligne +i][col +i] == grille[ligne +i+1][col +i+1])
                        t++;
                    if(grille[ligne +i][col +i] != grille[ligne +i+1][col +i+1]) t=0;
                }

                for(i = 0; i <= 2; i++){
                    if(grille[ligne +i][col -i] == grille[ligne +i+1][col -i-1])
                        t1++;
                    if(grille[ligne +i][col -i] != grille[ligne +i+1][col -i-1]) t1 = 0;
                }
            }
            if(grille[ligne][col] == 2){
                for(i = 0; i <= 2; i++){
                    if(grille[ligne +i][col +i] == grille[ligne +i+1][col +i+1])
                        s++;
                    if(s < 4 && grille[ligne +i][col +i] != grille[ligne +i+1][col +i+1]) s=0;
                }

                for(i = 0; i <= 2; i++){
                    if(grille[ligne +i][col -i] == grille[ligne +i+1][col -i-1])
                        s1++;
                    if(s < 4 && grille[ligne +i][col -i] != grille[ligne +i+1][col -i-1]) s1=0;
                }
            }
        }
        if(t >= 4 || t1 >= 4){
            return 1;
        }else if(s >= 4 || s1 >= 4){
            return 2;
        }
    }

        

    return 0;

}

   

void ia(int grille[7][6]){

    srand(static_cast<unsigned int>(time(0)));

    int random;

    bool success = false;

    while(!success){
        random = rand() % 7;
        int col = random;
        success = playTurn(grille, col, 2);
    }

} 