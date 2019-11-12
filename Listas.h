typedef struct Cliente { int cpf; //identificação da pessoa
						int senha; //senha não sequencial	 
						int tipo; // 1- expresso, 2- normal, 3- complexo
						int prioridade; //0- normal, 1- prioridade
                 	struct Cliente* prox;
                  } tCliente;

typedef struct Guiche{ tCliente* inicio;
                 int numElem;
                 int tempo; //tempo de atendimento em sequencia
                 int tempocorrido; //tempo entre descansos para ser adicionado um prox
                 int sequencia; //no de clientes atendidos em sequencia
               } tGuiche;


 #define X 3 //número de atendimentos máximo para descanso	
 #define Y 10 //ou tempo limite para descanso


tCliente* alocaCLiente(int valor);

void initGuiche(tGuiche* G); //inicializa Guiches

void imprimeGuiche(tGuiche G); //imprime tudo que há nos Guiches

int tempoGuiche(tGuiche G); //retorna tempo do guiche

bool insereNoGuiche(tGuiche* um, tGuiche* dois, tGuiche* tres, tGuiche* pri, int tipo, int prioridade, int cpf, int senha);
//insere novos clientes

bool botaoPanico(tGuiche* G);



