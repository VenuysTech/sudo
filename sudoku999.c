/***************************************************************************
 *   sudoku999.c                           Version 20201018.020303         *
 *                                                                         *
 *   Sudoku Solver                                                         *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 *                                                                         *
 *                                 Leandro Dantas Lima                     *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *                                                                         *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 *                                                                         *
 *   Leandro Dantas Lima                                                   *
 *   Email: leandroautocontrole@gmail.com                                  *
 *   Webpage: http://beco.poli.br/ldls3                                    *
 *   Phone: +55 (81) 98861-9469                                            *
 *                                                                         *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file sudoku999.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc sudoku999.c -o sudoku999.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv sudoku999.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include "sudoku999.h" /* To be created for this template if needed */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./sudoku999 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
int main(void)
{
    int z; /* flag indicativa de deducao com sucesso */
    int sudoku[9][9][9]={{{0}}}; /* todas as 729 possibilidades */

    IFDEBUG("Starting optarg loop...");

    sudoku999_init(sudoku); /* initialization function: set all candidates to true */
    do
    {
        z=0;
        z+=d1(sudoku); /* naked single */
        z+=d2(sudoku); /* hidden single */
        z+=d3(sudoku); /* naked pair */
        z+=d4(sudoku); /* hidden pair */
        z+=d5(sudoku); /* pointing candidate */
        z+=d6(sudoku); /* claiming candidate */
        z+=d7(sudoku); /* x-wing */
    }while(z);

    /* backtracking */ 
    if(!check(sudoku)) 
        z=d8(sudoku);

    printsudoku(sudoku);

    return check(sudoku);
}

/* Write your functions here... */

/* ---------------------------------------------------------------------- */
/* funcoes de apoio */

/* ---------------------------------------------------------------------- */
/* imprime o tabuleiro de sudoku */
void printsudoku(int w[9][9][9])
{
    printf("\n     +-----------+-----------+-----------+\n");
    printf("       a   b   c   d   e   f   g   h   i \n");
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "sudoku999", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "sudoku999");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "sudoku999", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void sudoku999_init(int w[9][9][9])
{
    IFDEBUG("sudoku999_init()");
    /* initialization */
    return;
}


/* ---------------------------------------------------------------------- */
/* acha coordenada superior esquerda do bloco que contem uma celula l,c dada */
/* retorna o numero do bloco e seta as coordenadas em *ql, *qc
 * +---+---+---+
 * | 0 | 1 | 2 | 0,0 0,3 0,6
 * +---+---+---+
 * | 3 | 4 | 5 | 3,0 3,3 3,6
 * +---+---+---+
 * | 6 | 7 | 8 | 6,0 6,3 6,6
 * +---+---+---+
 */
int cbloco(int l, int c, int *ql, int *qc)
{
    int b; /* numero do bloco */
    return b;
}

/* ---------------------------------------------------------------------- */
/* acha coordenada superior esquerda do bloco n dado */
/* retorna void
 * +---+---+---+
 * | 0 | 1 | 2 | 0,0 0,3 0,6
 * +---+---+---+
 * | 3 | 4 | 5 | 3,0 3,3 3,6
 * +---+---+---+
 * | 6 | 7 | 8 | 6,0 6,3 6,6
 * +---+---+---+
 */
void bloco(int n, int *ql, int *qc)
{
    return;
}

/* ---------------------------------------------------------------------- */
/* retorna verdadeiro se a celula tem candidato unico */
int unico(int y[9])
{
    ;
}

/* ---------------------------------------------------------------------- */
/* check if sudoku is solved, incomplete or invalid */
int check(int w[9][9][9])
{
    ;
}

/* ---------------------------------------------------------------------- */
/* funcoes de deducao de d1 a d8 */


/* ---------------------------------------------------------------------- */
/* naked single : peladao */
/* d1 : naked sigle
 * limpa linha: confronta cada valor ja deduzido com sua linha (horizontal) limpando falsas possibilidades
 *
 * Explicacao:
 *      percorre todas as 9x9 celulas da grade (cada celula contem 9 possibilidades)
 *      Para cada celula que achar que tiver o valor ja determinado (unica possibilidade), 
 *      percorre a horizontal que ela pertence e remove nas outras celulas dessa horizontal 
 *      a possibilidade deste valor que nao pode ser repetido
 */

/* 1- naked single : peladao : 
--> quando as possibilidades de uma celula se reduzem a um unico numero, ele e o valor correto.

   se um numero foi deduzido, remove-se o mesmo como candidato nas outras celulas da mesma linha, coluna ou bloco

algoritmo: fixa celula e gira digito, comparando-o com os grupos (linha, coluna, bloco), ate reduzir suas possibilidades a apenas uma.

 */
int d1(int w[9][9][9])
{
    int z=0;
    z+=d1l(w); /* naked single : line */
    z+=d1c(w); /* naked single : column */
    z+=d1b(w); /* naked single : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden single : peladao escondido */
/* d2: procura um numero que aparece apenas uma vez na linha */
/* Explicacao:
 *      Procura, para cada celula, uma que nao tem valor definido e chame-a de celula com n candidatos.
 *      Percorre a horizontal da celula com n candidatos e remove candidatos que se repetem
 *      Ao final, se restar apenas um candidato na celula fixada inicialmente, este eh o valor
 *      correto da celula.
 * 
 *      Exemplo, o valor 7 para a celula a7. Inicialmente os candidatos sao 1, 3, 6 e 7
 *      Percorrendo a horizontal e removendo os repetidos sobra apenas o 7 como possibilidade
 
       a   b   c   d   e   f   g   h   i
     +===========+===========+===========+
     |1 3:1 3:   |1  :  3:   |   :   : 2 |
  7  |  6:  6:   |   :  6:4 6| 5 :   :   |
     |7  :   :  9|   :   :   |   : 8 :   |
     +-----------+-----------+-----------+
 */

/* 2- hidden single : peladao escondido :
--> mesmo que tenham mais candidatos, se em uma celula tem um valor que nao aparece nas outras da mesma linha, coluna ou bloco, ele eh o solteirao escondido.

 * uma celula com multiplos candidatos eh chamada de solteirao se um dos candidatos so
 * aparece em um local na linha, coluna ou bloco. Ele e a solucao e os outros candidatos podem ser eliminados
 
algoritmo: 
 
 */
int d2(int w[9][9][9])
{
    int z=0;
    z+=d2l(w); /* hidden single : line */
    z+=d2c(w); /* hidden single : column */
    z+=d2b(w); /* hidden single : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* naked pair : dupla pelada */
/* naked pair:
 *
 * para cada conjunto de 2 celulas
 * quando tiverem os mesmo 2 candidatos e apenas eles
 * retira das outras celulas do grupo esses candidatos
 *
 * naked tuple: (todos grupos: linha, coluna e bloco)
 * N>1 celulas exatamente iguais com N candidatos cada
 *
 * >> retira das outras celulas do grupo esses numeros
 *
 * Upgrade: N>1 celulas com APENAS N candidatos em comum
 *
 */

/* 3- naked pair : dupla pelada : 

 * duas celulas com o mesmo par de candidatos e apenas ele, chama-se dupla pelada.
 * os valores do par sao removidos do grupo (bloco, linha ou coluna) em que se encontram
 * sobrando somente a duvida do par
 */

/* Opcional: 3.b- naked triple : tripla pelada : ocorre quando 3 celulas em uma mesma linha, coluna ou bloco contem os
 * apenas os mesmos tres candidatos; ou um subconjunto deles. Todas as aparencias dos 3 candidatos podem ser
 * eliminadas do resto do bloco, linha ou coluna
 */


/* Opcional: 3.c- naked quad : quatro pelados : quatro celulas com os mesmos quatro candidatos ou subconjuntos, em uma mesma
 * linha, coluna ou bloco, implicam que os mesmos candidatos em outras celulas no bloco ou seguindo a linha ou
 * coluna respectiva podem ser eliminados.
 */
int d3(int w[9][9][9])
{
    int z=0;
    z+=d3l(w); /* naked pair : line */
    z+=d3c(w); /* naked pair : column */
    z+=d3b(w); /* naked pair : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : dupla escondida */
/*
 * Se X candidatos em um grupo estao apenas em X celulas compartilhadas, pode-se limpar
 * os outros candidatos dessas X celulas, sobrando apenas os candidatos repetidos.
 * Afeta: apenas as celulas da tupla.
 *
 * O par escondido quando limpo se transforma em par pelado
 *
 */

/* 4- hidden pair : dupla escondida
 *
 * quando dois candidatos aparecem em apenas duas celulas, em um grupo (linha, coluna ou bloco)
 * mesmo que estas celulas estejam com mais candidatos
 * os demais podem ser eliminados dessas duas celulas, restando assim uma dupla pelada.
 */
int d4(int w[9][9][9])
{
    int z=0;
    z+=d4l(w); /* hidden pair : line */
    z+=d4c(w); /* hidden pair : column */
    z+=d4b(w); /* hidden pair : block */
    return z;
}

/* ---------------------------------------------------------------------- */
/* pointing candidate : candidato dedo-duro */
/* pointing pair : dedo-duro
 * quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 5- pointing pair : dedo-duro : quando um candidato esta dentro de um bloco em apenas duas ou tres celulas
 * alinhadas em linha ou coluna, chama-se dedo-duro. O numero do candidato pode ser removido
 * da linha ou coluna que se estende para fora do bloco. Parecido com o 5, mas aqui remove de linha ou coluna,
 * enquanto la remove de bloco.
 */
int d5(int w[9][9][9])
{
    int z=0;
    z+=d5l(w); /* pointing candidate : line */
    z+=d5c(w); /* pointing candidate : column */
    return z;
}

/* ---------------------------------------------------------------------- */
/* claiming candidate : candidato exigente */
/* claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 * 
 * Pointing: um certo candidato de um bloco so aparece numa reta: limpa o restante da reta
 * Claiming: um certo candidato de uma reta so aparece em um bloco: limpa o restante do bloco
 * 
 */

/* 6- claiming pair : exigente : quando um certo candidato precisa estar numa certa linha ou coluna, a linha ou coluna o requisita. Se as possibilidades para essa linha ou coluna estao apenas em um bloco, mantem-se os candidatos na linha ou coluna que intersecciona o bloco, mas remove-se o mesmo do restante do bloco.
 * A linha ou coluna o requisita,
 * logo todas outras celulas deste bloco fora da linha ou coluna, podem ter este numero canditado removido. Parecido com 4, mas aqui remove do bloco, la da linha ou coluna.
 */
int d6(int w[9][9][9])
{
    int z=0;
    z+=d6l(w); /* claiming candidate : line */
    z+=d6c(w); /* claiming candidate : column */
    return z;
}

/* ---------------------------------------------------------------------- */
/* x-wing : cruzamento em x */

/* 7- x-wing : cruzamento : quando um candidato aparece em quatro celulas que formam os cantos de um retangulo ou quadrado,
 * e aparece somente em duas celulas para cada uma das linhas, o candidato pode ser removido das colunas.
 * Idem para o inverso entre colunas e linhas.
 */
int d7(int w[9][9][9])
{
    int z=0;
    z+=d7l(w); /* x-wing : line */
    z+=d7c(w); /* x-wing : column */
    return z;
}

/* ---------------------------------------------------------------------- */
/* backtracking - retroanalise */
/* 8- Backtraking: algoritmo recursivo que tenta todas possibilidades */
int d8(int w[9][9][9])
{
    int z=0;
    tenta8(w); /* backtracking recursive */
    return z;
}



/* ---------------------------------------------------------------------- */
/* deducoes divididas por grupo: linha, coluna e bloco */


/* ---------------------------------------------------------------------- */
/* naked single : line */
/* naked single: confronta cada valor ja deduzido com sua linha (horizontal) */
int d1l(int w[9][9][9])
{
    int l, c, /* indices para rodar o mapa inteiro */
        j, /* as colunas a percorrer na linha l a limpar */
        n, /* o numero unico na linha l */
        z=0, /* retorna verdadeiro se alterou w */
        z1; /* flag para imprimir */
    char *hd="d1l: naked single (line)";
    
    for(l=0; l<9; l++)
        for(c=0; c<9; c++)
            if((n=unico(w[l][c])))
                for(j=0; j<9; j++) /* todas colunas da linha l */

                    /* ... */

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked single : column */
/* naked single: confronta cada valor ja deduzido com sua coluna (vertical) */
int d1c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d1c: naked single (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked single : block */
/* naked single: confronta cada valor ja deduzido com seu quadrado (bloco) */
int d1b(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d1b: naked single (block)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden single : linha */
/* hidden single: procura numa horizontal um numero com apenas uma celula possivel de estar */
int d2l(int w[9][9][9])
{
    int l, c, j, z=0, z1, n;
    int candy[9];
    char *hd="d2l: hidden single (line)";
    
    for(l=0; l<9; l++)
        for(c=0; c<9; c++)
            if(!unico(w[l][c]))
                ;

                    /* ... */

    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden single : column */
/* hidden single: procura numa vertical um numero com apenas uma celula possivel de estar */
int d2c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d2c: hidden single (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden single : block */
/* hidden single: procura num bloco um numero com apenas uma celula possivel de estar */
int d2b(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d2b: hidden single (block)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : line */
/* naked tuple (pair/triple/quad): remove candidatos fora do par, no grupo */
int d3l(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d3l: naked pair (line)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : column */
int d3c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d3c: naked pair (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* naked pair : block */
int d3b(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d3b: naked pair (block)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : line */
/* hidden pair: remove candidatos na celula do par, limpando-o, tornando-o naked pair */
int d4l(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d4l: hidden pair (line)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : column */
int d4c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d4c: hidden pair (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* hidden pair : block */
int d4b(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d4b: hidden pair (block)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : linha */
int d5l(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d5l: pointing pair (line)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* pointing candidates : dedo-duro : coluna */
int d5c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d5c: pointing pair (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : line */
int d6l(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d6l: claiming candidate (line)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* claiming candidate : exigente : column */
int d6c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d6c: claiming candidate (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* x-wing */
int d7l(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d7l: x-wing (line)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* x-wing */
int d7c(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="d7c: x-wing (column)";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* backtracking */
int tenta8(int w[9][9][9])
{
    int z; /* flag que indica se ocorreu deducao */
    char *hd="tenta8: backtracking";
    return z>0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
