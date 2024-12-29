#include <stdlib.h>
#include <stdio.h>

#include "../include/generate.h"
#include "../include/util.h"
#include "../include/display.h"

int is_diggable(struct t_maze *m, int y, int x, enum direction dir){
    int i, j;
    /*switch(dir){
        case NORTH:
            for(j=-2;j<=-1;j++){
                for(i=-1;i<=1;i++){
                    if(m->cells[y+j][x+i]!=(WALL || GENERATED_CORRIDOR)){
                        return 0;
                    }
                }
            }
            return 1;

            if((m->cells[y-2][x-1]==(WALL || GENERATED_CORRIDOR)) && (m->cells[y-2][x+1]==(WALL || GENERATED_CORRIDOR)) && (m->cells[y-1][x-1]==(WALL || GENERATED_CORRIDOR)) && (m->cells[y-1][x+1]==(WALL || GENERATED_CORRIDOR)) && (m->cells[y-2][x]==(WALL || GENERATED_CORRIDOR))){
                return 1;
            } else {
                return 0;
            }
        case SOUTH:
            if((m->cells[y+2][x-1]==WALL || m->cells[y+2][x-1]==GENERATED_CORRIDOR) && (m->cells[y+2][x+1]==WALL || m->cells[y+2][x+1]==GENERATED_CORRIDOR) && (m->cells[y+1][x-1]==WALL || m->cells[y+1][x-1]==GENERATED_CORRIDOR) && (m->cells[y+1][x+1]==WALL || m->cells[y+1][x+1]==GENERATED_CORRIDOR) && (m->cells[y+2][x]==WALL || m->cells[y+2][x]==GENERATED_CORRIDOR)){
                return 1;
            } else {
                return 0;
            }
        case EAST:
            if((m->cells[y-1][x+2]==WALL || m->cells[y-1][x+2]==GENERATED_CORRIDOR) && (m->cells[y+1][x+2]==WALL || m->cells[y+1][x+2]==GENERATED_CORRIDOR) && (m->cells[y-1][x+1]==WALL || m->cells[y-1][x+1]==GENERATED_CORRIDOR) && (m->cells[y+1][x+1]==WALL || m->cells[y+1][x+1]==GENERATED_CORRIDOR) && (m->cells[y][x+2]==WALL || m->cells[y][x+2]==GENERATED_CORRIDOR)){
                return 1;
            } else {
                return 0;
            }
        case WEST:
            if((m->cells[y-1][x-2]==WALL || m->cells[y-1][x-2]==GENERATED_CORRIDOR) && (m->cells[y+1][x-2]==WALL || m->cells[y+1][x-2]==GENERATED_CORRIDOR) && (m->cells[y-1][x-1]==WALL || m->cells[y-1][x-1]==GENERATED_CORRIDOR) && (m->cells[y+1][x-1]==WALL || m->cells[y+1][x-1]==GENERATED_CORRIDOR) && (m->cells[y][x-2]==WALL || m->cells[y][x-2]==GENERATED_CORRIDOR)){
                return 1;
            } else {
                return 0;
            }
    }*/

    switch(dir){
        case NORTH:
            for(j=-2;j<=-1;j++){
                for(i=-1;i<=1;i++){
                    if(m->cells[y+j][x+i]!=WALL && m->cells[y+j][x+i]!=GENERATED_CORRIDOR){
                        return 0;
                    }
                }
            }
            return 1;
        case SOUTH:
            for(j=1;j<=2;j++){
                for(i=-1;i<=1;i++){
                    if(m->cells[y+j][x+i]!=WALL && m->cells[y+j][x+i]!=GENERATED_CORRIDOR){
                        return 0;
                    }
                }
            }
            return 1;
        case EAST:
            for(j=-1;j<=1;j++){
                for(i=1;i<=2;i++){
                    if(m->cells[y+j][x+i]!=WALL && m->cells[y+j][x+i]!=GENERATED_CORRIDOR){
                        return 0;
                    }
                }
            }
            return 1;
        case WEST:
            for(j=-1;j<=1;j++){
                for(i=-2;i<=-1;i++){
                    if(m->cells[y+j][x+i]!=WALL && m->cells[y+j][x+i]!=GENERATED_CORRIDOR){
                        return 0;
                    }
                }
            }
            return 1;
    }
}

int dig(struct t_maze *m, int y, int x, struct t_stack_top *top){
    enum direction random_direc_to_dig;
    int digBool=0, n=1,s=1,e=1,w=1;
    while((digBool==0)&&(n+s+e+w!=0)){
        random_direc_to_dig = random_number(NORTH, WEST);
        switch(random_direc_to_dig){
            case NORTH:
                /*if(m->cells[y-1][x]!=WALL && m->cells[y-1][x]!=GENERATED_CORRIDOR){
                    n=0;
                    break;
                } else {*/
                    if(is_diggable(m,y,x,random_direc_to_dig)){
                        digBool=1;
                        break;
                    } else {
                        n=0;
                        break;
                    }
                //}
            case SOUTH:
                /*if(m->cells[y+1][x]!=WALL && m->cells[y+1][x]!=GENERATED_CORRIDOR){
                    s=0;
                    break;
                } else {*/
                    if(is_diggable(m,y,x,random_direc_to_dig)){
                        digBool=1;
                        break;
                    } else {
                        s=0;
                        break;
                    }
                //}
            case EAST:
                /*if(m->cells[y][x+1]!=WALL && m->cells[y][x+1]!=GENERATED_CORRIDOR){
                    e=0;
                    break;
                } else {*/
                    if(is_diggable(m,y,x,random_direc_to_dig)){
                        digBool=1;
                        break;
                    } else {
                        e=0;
                        break;
                    }
                //}
            case WEST:
                /*if(m->cells[y][x-1]!=WALL && m->cells[y][x-1]!=GENERATED_CORRIDOR){
                    w=0;
                    break;
                } else {*/
                    if(is_diggable(m,y,x,random_direc_to_dig)){
                        digBool=1;
                        break;
                    } else {
                        w=0;
                        break;
                    }
                //}
        }
    }
    if(digBool){
        switch(random_direc_to_dig){
            case NORTH:
                m->cells[y-1][x]=DOWN;
                stack(top,y-1,x);
                dig(m, y-1, x, top);
                break;
            case SOUTH:
                m->cells[y+1][x]=UP;
                stack(top,y+1, x);
                dig(m, y+1, x, top);
                break;
            case EAST:
                m->cells[y][x+1]=LEFT;
                stack(top,y,x+1);
                dig(m, y, x+1, top);
                break;
            case WEST:
                m->cells[y][x-1]=RIGHT;
                stack(top,y,x-1);
                dig(m, y, x-1, top);
                break;
        }
    } else {
        if(m->cells[top->stack->y][top->stack->x]==ENTRY){
            return 0;
        } else {
            int tempX = top->stack->next->x;
            int tempY = top->stack->next->y;
            unstack(top);
            dig(m, tempY, tempX, top);
        }
    }
}

void generate_maze(struct t_instance *inst){
    struct t_stack_top top;
    int i,j;
    for(i=0; i<inst->m.height;i++){
        inst->m.cells[i][0] = BORDER;
        inst->m.cells[i][1] = BORDER;
        inst->m.cells[i][inst->m.width-1] = BORDER;
        inst->m.cells[i][inst->m.width-2] = BORDER;
    }
    
    for(i=0; i<inst->m.width;i++){
        inst->m.cells[0][i] = BORDER;
        inst->m.cells[1][i] = BORDER;
        inst->m.cells[inst->m.height-1][i] = BORDER;
        inst->m.cells[inst->m.height-2][i] = BORDER;
    }
    // Ilot
    if(inst->m.maze_type==0){
        //case impaires-impaires en couloir
        for(i=2;i<inst->m.height-3;i++){
            if(i%2!=0){
                for(j=2;j<inst->m.width-3;j++){
                    if(j%2!=0){
                        inst->m.cells[i][j]=GENERATED_CORRIDOR;
                    }
                }
            }
        }
    } else {
    }
    
    int randX, randY;
    int randomTab[2] = {2, inst->m.width-3};

    // Random placement of entry (Y must be odd)
    randY = random_number(2,(inst->m.height-3));
    if((randY%2)==0){
        if(randY==inst->m.height-3){
            randY--;
        } else {
            randY++;
        }
    }
    
    // If Y placed on the upside or bottom of the maze
    if((randY == 2) || (randY == inst->m.height-3)){
        randX = random_number(3,(inst->m.width-4));
        if((randX%2)==0){
            if(randX==inst->m.width-4){
                randX--;
            } else {
                randX++;
            }
        }
    } else {
        randX = randomTab[random_number(0,1)];
    }

    inst->m.cells[randY][randX] = ENTRY;
    stack(&top, randY, randX);
    dig(&(inst->m), randY, randX, &top);
    unstack(&top);
}