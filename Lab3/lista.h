typedef struct node{
    void* data;
    struct node* next;
}node;

typedef struct TList{
    node* head;
    int len;
}TList;

//Problema 1.
void init(TList **list); //aloca memorie pentru lista si initializeaza campurile
int add(TList *list, int n, void* data);//adauga un nod pe pozitia n, intoarce 1 pt reusita, -1 pt esec
int length(TList *list);//intoarce lungimea listei
void print_int_list(TList *list);//afiseaza o lista de intregi
void print_string_list(TList *list);//afiseaza o lista cu string-uri
node* remove_node(TList *list, int n);//sterge nodul de pe pozitia n si il intoarce
void free_list(TList **list);//sterge toate elementele din lista si elibereaza memoria

//Problema 2.
node* mid_list(TList *list);