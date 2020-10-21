#ifndef _EXN_H
#define _EXN_H

/* ---------------------------------------------------------------------- */
/* includes */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160908.182854" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

/* ---------------------------------------------------------------------- */
/* funcoes de apoio : sugestoes apenas. Apagar se nao utilizar */
void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void sudoku999_init(int w[9][9][9]);  /**< Initializes some operations before start */

/* dada uma coordenada e um num, faz deducao positiva e elimina possibilidades em w */
int dyes(int l, int c, int n, int w[9][9][9]);
/* dada uma coordenada e um num (de 1 a 9) que nao eh, faz deducao negativa e elimina uma unica possibilidade em w */
int dnot(int l, int c, int n, int w[9][9][9]);
/* retorna verdadeiro (com n de 1 a 9) se a celula ja tem valor unico certo */
int unico(int y[9]);
/* copia os candidatos a serem unica opcao de uma celula */
void copycandy(int w[9][9][9], int l, int c, int y[9]);
/* apaga em candidatos os repetidos em w */
void clearcandy(int w[9][9][9], int l, int c, int y[9]);
/* conta o total de valores verdadeiros em vetor de 9 posicoes */
int totalcandy(int y[9]);
/* acha coordenada superior esquerda do setor que contem a celula l,c */
int cbloco(int l, int c, int *ql, int *qc);
/* dado o numero do bloco (0 a 8), retorna a coordenada da primeira celula */
void bloco(int n, int *ql, int *qc);

/* valida sudoku (candidatos) */
/* dada matriz de candidatos:
 * -1: se todos tem exatamente um candidato: solucao encontrada
 * 1-81: se todos tem pelo menos um candidato: ok, num de celulas em duvida
 * 0: se algum nao tem candidato: erro
 */
int check(int w[9][9][9]); /* check if sudoku is solved, incomplete or invalid */


/* ---------------------------------------------------------------------- */
/* estas funcoes de deducao chamam as suas partes para o grupo */
/* atencao: obrigatorio usar essas funcoes como estao na funcao main() */

int d1(int w[9][9][9]); /* naked single */
int d2(int w[9][9][9]); /* hidden single */
int d3(int w[9][9][9]); /* naked pair */
int d4(int w[9][9][9]); /* hidden pair */
int d5(int w[9][9][9]); /* pointing candidate */
int d6(int w[9][9][9]); /* claiming candidate */
int d7(int w[9][9][9]); /* x-wing */
int d8(int w[9][9][9]); /* backtracking */

/* ---------------------------------------------------------------------- */
/* sub-funcoes de deducao por grupo */
/* d1 : naked single: confronta cada valor ja deduzido com sua linha (horizontal) */
int d1l(int w[9][9][9]);
/* d1 : naked single: confronta cada valor ja deduzido com sua coluna (vertical) */
int d1c(int w[9][9][9]);
/* d1 : naked single: confronta cada valor ja deduzido com seu quadrado (setor) */
int d1b(int w[9][9][9]);

/* d2: hidden single: procura numa horizontal um numero com apenas uma celula possivel de estar */
int d2l(int w[9][9][9]);
/* d2: hidden single: procura numa vertical um numero com apenas uma celula possivel de estar */
int d2c(int w[9][9][9]);
/* d2: hidden single: procura num setor um numero com apenas uma celula possivel de estar */
int d2b(int w[9][9][9]);

/* naked tuple (pair/triple/quad): remove candidatos fora do par, no grupo */
/* d3: naked tuple : line */
int d3l(int w[9][9][9]);
/* d3: naked tuple : column */
int d3c(int w[9][9][9]);
/* d3: naked tuple : block */
int d3b(int w[9][9][9]);

/* hidden pair: remove candidatos na celula do par, limpando-o, tornando-o naked pair */
/* d4: hidden pair na linha */
int d4l(int w[9][9][9]);
/* d4: hidden pairs em colunas */
int d4c(int w[9][9][9]);
/* d4: hidden pairs em bloco */
int d4b(int w[9][9][9]);

/* d5: pointing candidates : dedo-duro : linha */
int d5l( int w[9][9][9]);
/* d5: pointing candidates : dedo-duro : coluna */
int d5c(int w[9][9][9]);

/* d6: claiming line */
int d6l(int w[9][9][9]);
/* d6: claiming column */
int d6c(int w[9][9][9]);

/* d7: x-wing line */
int d7l(int w[9][9][9]);
/* d7: x-wing : column */
int d7c(int w[9][9][9]);

/* d8: backtracking */
int tenta8(int w[9][9][9]);


#endif /* NOT def _EXN_H */
