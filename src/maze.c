#include "../include/maze.h"
#include "../include/generate.h"
#include "../include/util.h"
#include "../include/display.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void free_maze(struct t_maze *m){
    int i;
    for(i = 0; i < m->height; i++){
        free(m->cells[i]);
    }
    free(m->cells);
}

void ask_user(struct t_instance *inst){
    int temp;
    printf("Welcome.\n");

    //Width
    printf("Please tell me the width of the maze you want (an odd number between 9 and 309) : ");
    scanf("%d", &temp);
    while((temp < 9) || (temp > 3009) || (temp%2==0)){
        printf("Wrong value. Please tell me the width of the maze you want (an odd number between 9 and 309) : ");
        scanf("%d", &temp);
    }
    inst->m.width = temp+4;
    
    //Height
    printf("Please tell me the height of the maze you want (an odd number between 9 and 309) : ");
    scanf("%d", &temp);
    while((temp < 9) || (temp > 3009) || (temp%2==0)){
        printf("Wrong value. Please tell me the height of the maze you want (an odd number between 9 and 309) : ");
        scanf("%d", &temp);
    }
    inst->m.height = temp+4;

    //Type of maze
    printf("\nWhich type of maze do you want (0 : Island, 1 : Arborescent) : ");
    scanf("%d", &temp);
    while((temp < 0) || (temp > 1)){
        printf("Wrong value. Which type of maze do you want (0 : Island, 1 : Arborescent) : ");
        scanf("%d", &temp);
    }
    inst->m.maze_type = temp;

    //Type of display
    printf("\nWhich type of display do you want (0 : Unresolved, 1 : Resolved, 2 : Binary (dev), 3 : All (dev)  ) : ");
    scanf("%d", &temp);
    while((temp < 0) || (temp > 4)){
        printf("Wrong value. Which type of display do you want (0 : Unresolved, 1 : Resolved, 2 : Binary (dev), 3 : All (dev)  ) : ");
        scanf("%d", &temp);
    }
    inst->maze_solving = temp;
}


void init_maze(struct t_maze *m){
    
    int i,j;
    m->cells = (enum cell**)malloc(sizeof(int*) * (m->height));
    for(i = 0; i < m->height; i++){
        m->cells[i] = (enum cell*)malloc(sizeof(int) * (m->width));
        for(j=0;j<m->width;j++){
            m->cells[i][j]=WALL;
        }
    }
}
int main(int argc, char* argv[]){
    //Main for the generation only
    /*srand(time(NULL));
    struct t_instance inst;
    ask_user(&inst);
    init_maze(&(inst.m));
    generate_maze(&inst);
    display_maze(&inst);
    free_maze(&(inst.m));*/

    clock_t start, end;
    double cpu_time_used, timee;
    srand(time(NULL));
    struct t_instance inst;
    //ask_user(&inst);
    
    //printf("%.10f \n", clock());
    
    int i;
    for(i=10;i<3350;i=i+5){
        inst.m.height=i;
        inst.m.width=i;
        inst.m.maze_type=0;
        init_maze(&(inst.m));
        start = clock();
        generate_maze(&inst);
        end = clock();
        timee = ((double)(end - start))/CLOCKS_PER_SEC;
        printf("%d x %d; %.6f \n", inst.m.width,inst.m.width, timee);
    }
    
    
    inst.maze_solving=3;
    //display_maze(&inst);
    //display_binary(&(inst.m));

    return 0;
}