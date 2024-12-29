#include "../include/display.h"
#include "../include/maze.h"
#include "../include/util.h"
#include <stdio.h>
#include <stdint.h>
// most significant digit in 1 byte char
#define TEC_MOST_SIG_BIT 128


uint32_t urslvdcellstyle[SMAX] = {0x3000,0x2B1B,0x2B1B,0x3000,0x2B1B,0x3000,0x3000,0x3000,0x3000};
uint32_t rslvdcellstyle[SMAX] = {0x3000,0x2B1B,0x2B1B,0x3000,0x2B1B,0x2191,0x2193,0x2190,0x2192};
// UTF-16 codes Table
char utf8[16];


void display_maze(struct t_instance *inst){
	int mazesolving = inst->maze_solving;
	switch(mazesolving){
		case 0:
			display_unresolved(&(inst->m));
			break;
		case 1:
			display_resolved(&(inst->m));
			break;
		case 2:
			display_binary(&(inst->m));
			break;
		case 3:
			display_unresolved(&(inst->m));
			display_resolved(&(inst->m));
			display_binary(&(inst->m));
			break;
	}
}

/*tec_string_utf8:
	encodes a unicode codepoint into a utf8 encoded string
	uint32_t codepoint: the codepoint to be encoded into utf8
	char *str: the string where the encoded codepoint will be written to
	you need to ensure that str has at least 5 bytes
	4 bytes is the max length of a utf8 encoding plus NULL character
	returns number of bytes written (excluding NULL character)
*/


int tec_string_utf8(uint32_t n, char *str){

	if(n > 1114112 || ( n >= 0xd800 && n <= 0xdfff ) ){
		//encodes U+fffd; replacement character
		str[0] = 0xef;
		str[1] = 0xbf;
		str[2] = 0xbd;
		str[3] = 0;
		return 3;
	}

	// just like 7-bit ascii
	if(n < 128){
		str[0] = n;
		str[1] = '\0';
		return 1;
	}

	uint32_t len = 0;
	if(n < 2048){
		len = 2;
	}else{
		if( n < 65636){
			len = 3;
		}else{
			len = 4;
		}
	}
	str[len] = '\0';

	// set the bits at the start to indicate number of bytes
	unsigned char m = TEC_MOST_SIG_BIT;
	uint32_t i = 0;
	str[0] = 0;
	while(i < len){
		str[0] |= m;
		i += 1;
		m >>= 1;
	}

	//set the most significant bits in the other bytes
	i = 1;
	while(i < len){
		str[i] = TEC_MOST_SIG_BIT;
		i += 1;
	}

	//fill in the codepoint
	int j = len - 1;
	while(j >= 0){
		m = 1;
		i = 0;
		while(n && i < 6){
			if(n%2){
				str[j] |= m;
			}
			n >>= 1;
			m <<= 1;
			i += 1;
		}
		j -= 1;
	}

	return len;

}//tec_string_utf8*/


void display_binary(struct t_maze *m){
    int i,j;
    for(i=2;i<m->height-2;i++){
        for(j=2;j<m->width-2;j++){
            printf("%d ", m->cells[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void display_unresolved(struct t_maze *m){
    int x,y;
    uint32_t cp;
    for(x=2;x<m->height-2;x++){
        for(y=2;y<m->width-2;y++){
			cp = urslvdcellstyle[m->cells[x][y]];
			tec_string_utf8(cp, utf8);
			printf("%s", utf8); 
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void display_resolved(struct t_maze *m){
    int x,y;
    uint32_t cp;
    for(x=2;x<m->height-2;x++){
        for(y=2;y<m->width-2;y++){
			cp = rslvdcellstyle[m->cells[x][y]];
			tec_string_utf8(cp, utf8);
			if(m->cells[x][y]>=5){
				printf("%4s", utf8);         
			}else{
				printf("%s", utf8);  
			}
		       
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}
