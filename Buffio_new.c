typedef enum status_buffio {
    STATBUF_SUCCESS = 148,
    STATBUF_ERROR
} status_buffio;

#define INIT_EXCEPTIONS() int error = 0;

#define TRY(fn, err, str_err)      \
    error = (int)fn;                     \
    if (error == (int)err) {         \
        printf(str_err);              \
    }
            
char buffer[];

int Buffio_lib_counted_readln(char* var, int count);
int Buffio_lib_readln(char* var);
char Buffio_lib_gbufchar(char* buffer);
int Buffio_lib_gbufstr(char* buff, char* buffer, char* str, const int maxlen);
int Buffio_lib_cpybufstr(char* buffer, char* str, const int maxlen);

typedef struct {
    int (*print)(char*, ...);

    int (*counted_readln)(char* var, int count);
    int (*readln)(char* var);
    char (*gbufchar)(char* buffer);
    int (*gbufstr)(char* buff, char* buffer, char* str, const int maxlen);
    int (*cpybufstr)(char* buffer, char* str, const int maxlen);
} bufflib;

void init_buffio(bufflib* buff_lib) {
    buff_lib->print = printf;

    buff_lib->counted_readln = Buffio_lib_counted_readln;
    buff_lib->readln         = Buffio_lib_readln;
    buff_lib->gbufchar       = Buffio_lib_gbufchar;
    buff_lib->gbufstr        = Buffio_lib_gbufstr;
    buff_lib->cpybufstr      = Buffio_lib_cpybufstr;
}

#define allocate(T) (T*) malloc(sizeof(T))


int main(void) {
    bufflib buffio;
    init_buffio(&buffio);
    char nick[32];
    buffio.readln(nick);
    buffio.print("%s\n", nick);
    return 0;
}

int Buffio_lib_gbufstr(char* buff, char* buffer, char* str, const int maxlen) {
    char tmpch[32];
    for (int i = 0; buffer[i] != '\0'; i++) {
        tmpch[i] = Buffio_lib_gbufchar(buff);
    }
    /*for (int i = 0; i <= maxlen; i++) {
        
    }*/
    return STATBUF_SUCCESS;
}

int Buffio_lib_cpybufstr(char* buffer, char* str, const int maxlen) {
    char checkStr[32];
    for (int i = 0; buffer[i] != ' '; i++) {
        checkStr[i] = buffer[i];
    }
    for (int i = 0; i < maxlen; i++) {
        if (i < maxlen) {
            str[i] = checkStr[i];
        } else {
            str[i] = '\0';
        }
    }
    return STATBUF_SUCCESS;
}

char Buffio_lib_gbufchar(char* buffer) {
    char firstChar;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 0) {
            firstChar = buffer[i];
            break;
        }
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = buffer[i+1];
    }
    
    return firstChar;
}

int Buffio_lib_readln(char* var) {
    int err = scanf("%[^\n]", var);
    getchar(); // очищение \n
    if (err != EOF) {
        return STATBUF_SUCCESS;
    } else {
        return STATBUF_ERROR;
    }
}

int Buffio_lib_counted_readln(char* var, int count) {
    int count_and_err = scanf("%[^\n]", var);
    getchar(); // очищение \n
    if (count_and_err != EOF || count_and_err <= count) {
        return STATBUF_SUCCESS;
    } else {
        return STATBUF_ERROR;
    }
}
