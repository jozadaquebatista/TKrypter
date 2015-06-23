#include "../includes/Window.hpp"
#include "../includes/Window_Context.hpp"
#include "../includes/Encrypt.hpp"
#include "../includes/Decrypt.hpp"
#include "../includes/Libraries.hpp"

int main(int argc, char **argv)
{
    Widget::Window win, window;
    
    if(((win.createWindow("primeira janela", 600, 300))!=0) && ((window.createWindow("segunda janela", 800, 400))!=0))
    {
        std::cerr << "\n\t   ============> ERRO AO INICIAR WIDGET JANELA. <============\n";
        exit();
    } else sucess();
}
