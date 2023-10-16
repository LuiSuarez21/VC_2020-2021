
#define VC_DEBUG

/* GRUPO 15
* Alunos: Luis Esteves - 16960
*         João Morais  - 17214  
*         Sergio Ribeiro - 18858  
* IPCA
* Disciplina: Visão de computadores, LESI-PL, 2º Ano;
* Trabalho Prático nº1 | Problema 1 (P1);
* Neste problema é pretendido calcular o centro de massa o perimetro e a area de um cerebro. Para alem disso, realizar processos morfologicos de maneira a
* extrair do cranio (imagem original) apenas a parte que nós queremos, que é o cerebro.
*/

//Vc.h -> onde é guardado as etiquetas de todas as funcoes e as structs utilizadas no trabalho;



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct
{
	unsigned char *data;
	int width, height;
	int channels;	  // Binario/Cinzentos=1; RGB=3
	int levels;		  // Binario=1; Cinzentos [1,255]; RGB [1,255]
	int bytesperline; // width * channels
} IVC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UM BLOB (OBJECTO)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

typedef struct {
	int x, y, width, height;	// Caixa Delimitadora (Bounding Box)
	int area;					// Area
	int xc, yc;					// Centro-de-massa
	int perimeter;				// Perimetro
	int label;					// Etiqueta
} OVC;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                    PROTOTIPOS DE FUNCOES
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUNCOES: ALOCAR E LIBERTAR UMA IMAGEM
IVC *vc_image_new(int width, int height, int channels, int levels);
IVC *vc_image_free(IVC *image);

// FUNCOES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename);
int vc_write_image(char *filename, IVC *image);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    FUNCOES: FUNCOES DESENVOLVIDAS EM AULA OU FORA DA AULA UTILIZADAS NESTE PROJECTO
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int vc_gray_to_bin(IVC *src, IVC *dst);
int vc_bin_dilate(IVC *src, IVC *dst, int kernel);
int vc_bin_erode(IVC *src, IVC *dst, int kernel);
int vc_bin_open(IVC *src, IVC *dst, int kernel);
int vc_bin_close(IVC *src, IVC *dst, int kernel);
OVC* vc_bin_blob_label(IVC *src, IVC *dst, int *nlabels);
int vc_bin_blob_calc(IVC *src, OVC *blobs, int *nblobs);
int vc_convert(IVC *src, IVC *src2, IVC *dst);