
#include "functions.c"
#include "functions.h"


int MyShuffle(int x, int y)
{
    int i = rand()%10;
    int r_number = i ^ 1;
    
    while(r_number > y)
    {
        if(r_number > y || r_number < y)
        {
            r_number = i^=i;
        } else { return r_number; } 
    }
    return r_number;
}


int main( int argc, char **argv )
{

    //String phrase;
    Integer8 exec_code;
    time_t seconds;
    
    time(&seconds);
    
  /*
   *
   * Verify if the program has some arguments, and look for what argument 
   * has been passed to program.
   * 
   */
   
    Integer8 code = verifyArgs( argc, *argv);
    printf("CODE>%d\n", code);
    if( (code == 1 || code == 0 ) ) return 1;

    /*char *msg_enc = calloc(1, sizeof(strlen("Mensagem a ser criptografada.")));
    char *msg_enc = calloc(1, sizeof(strlen("H`kvdb`h%d%v`w%fwluqjbwdcdad+")));

    msg_enc = (char*)"Mensagem a ser criptografada.";*/

    //krypto_phrase(&phrase);

    
    // Executes an encryption on phrase passed as parameter,
    // then returns your execution code, where 0(zero) means
    // sucess and 1 fault.

    char *msg[] = { "O rato roeu a roupa do Rei de Roma.",
                    "Agua mole em pedra dura",
                    "O marcos robou pao na casa do joao.",
                    "blablabla" }; // NOTE: take off keys around sentences {"sentence"}... #

    srand((unsigned int) seconds);
    
    printf("%s\n", msg[rand()%3]);

    char *message_to_encrypt = msg[rand()%3];

    exec_code = (krypto_encrypt(message_to_encrypt, 0x05, 0x04)); // Fix letter accentuation AFTER!!!
    
    if(exec_code == 0)
    {
        puts("\ndecrypted phrase:");
        krypto_decrypt("J:w+qj:yjAp:+:wj@u+:aj:WAl:aA:Wjh++", 0x05, 0x04);
        exec_result(exec_code);
    }
    else
    {
        exec_result(1);
        puts("Fail to encrypt phrase or file.");
    }

    return exec_code;

}
