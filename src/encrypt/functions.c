
#include "functions.h"

// FLAG of 1bit to true or false
typedef struct flag { Integer8 value: 1; } flag;

static _Bool krypto_encrypt   ( unsigned const char *phrase,
                                Integer8            key_x  ,
                                Integer8            key_y  ,
                                ... )
{

    unsigned char en_tag[ strlen(phrase) ];
    register unsigned int verStr, i;

    verStr = verifyStr(phrase); // VerStr()

    // Exception handling
    if( verStr == 1 )
    {
        fprintf(stderr, "Encryption error, maybe value passed has been invalid.\n");
        return 1;
    }

    puts(_(\n[HASH CRIPTOGRAFICO));
    
    // Encryption functions                // 00001010
    for(i=0; i < strlen(phrase); i++ )     // 00000001
    {                                      // 00001011
        en_tag[i] = *(phrase+i)^key_x; // Function to encrypt
        
        if(en_tag[i]=='%')
            en_tag[i] = ':';
        
        else if(en_tag[i]=='`')
            en_tag[i] = 'A';
                       
        else if(en_tag[i]=='d')
            en_tag[i] = '+';
                                                           
                              
        // Insert Signature()
        /*else if(((strlen(phrase)/2)-1) == i)
            en_tag[i] += 1;
                       
        else if((((strlen(phrase)/2)/2)-1) == i)
            en_tag[i] += 2;                      */
                                     
        else if(((strlen(phrase)/2)-1) == i)
            en_tag[i] = '@';
                       
        else if((((strlen(phrase)/2)/2)-1) == i)
            en_tag[i] = 'y';
                                              
        printf("%c", en_tag[i]);
        
    }puts("");

    return 0;

}

static _Bool krypto_decrypt   ( unsigned const char *phrase , 
                                Integer8            key_x   ,
                                Integer8            key_y   ,
                                ... )
{

    unsigned char en_tag[ strlen(phrase) ];
    register unsigned int i;
    

    // Valida o HASH
    char content = *(phrase+((strlen(phrase)/2)-1));

    if( content != '@')
    {
        puts("Invalid hash");
        return 1;
    }
    
    for( i=0; i < strlen(phrase); i++ )
    {            
            
        en_tag[i] = /*(String)*/(*(phrase+i)^key_x);

        if(en_tag[i]==':')
            en_tag[i] = '%';
        
        if(en_tag[i]=='+')
            en_tag[i] = 'd';
        
        if(en_tag[i]=='A')
            en_tag[i] = '`';
            
        if(en_tag[i]=='?')
            en_tag[i] = ' ';
        
        else if(en_tag[i]=='D')
            en_tag[i] = 'e';
            
        else if(en_tag[i]=='.')
            en_tag[i] = 'a';
            
        else if(en_tag[i+1]=='a')
            en_tag[i] = '.';
                
        /*else if(((strlen(phrase)/2)-1) == i)
            en_tag[i] -= 1;
                       
        else if((((strlen(phrase)/2)/2)-1) == i)
            en_tag[i] -= 1;    */

        else if(((strlen(phrase)/2)-1) == '@')
            en_tag[i] = '-';
                       
        else if((((strlen(phrase)/2)/2)-1) == 'y')
            en_tag[i] = '-';
            
        //signature(&en_tag[i],phrase, 2, i); // Insert signature in hash
            
        printf("%c", en_tag[i]);
    }
    puts("");
    return 0;

}

static _Bool verifyStr( const unsigned char *msg, ... )
{
    return (msg == nullptr) ? 1 : 0;
}

Integer8 verifyArgs( int argc, char arg[], ... )
{
    if(argc > 1 && (strcmp(arg, "--help") == 1) )
    {
        puts("*Are you looking for some [help?]");
        puts("[usage]: program --help");
        puts("[note]: this program does not accept aditional parameters yet.");
        
        return 1;
    }
    
    else if(argc > 1 && (strcmp(arg, "--help") == 0) )
    {
        puts("[HELP]");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        puts("._ ...");
        
        return 0;
    } else { return 2; }
}

static void signature  ( unsigned char       en_tag[], 
                         unsigned const char *phrase , 
                         Integer8            pos_x   , 
                         int                 i       ,
                         ... )
{
    /*if(((strlen(phrase)/pos_x)-1) == i)
        en_tag[i] = 'y';
                       
    if((((strlen(phrase)/pos_x)/pos_x)-1) == i)
        en_tag[i] = 'b';*/
}
