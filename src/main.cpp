#include "../includes/Window.hpp"
#include "../includes/Encrypt.hpp"
#include "../includes/Decrypt.hpp"
#include "../includes/Libraries.hpp"

int main(int argc, char **argv)
{
    Widget::Window win, window;
    
    if(((win.createWindow("my window", 500, 500))!=0) && ((window.createWindow("my window", 500, 500))!=0))
    {
        puts("\n\t   ============> ERRO AO INICIAR WIDGET JANELA. <============\n");
        exit();
    }
    sucess(); 
}
