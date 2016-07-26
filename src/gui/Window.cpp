#include "../includes/Window.hpp"
#include "../includes/Window_Context.hpp"

Widget::Window::Window()
{
    window_title = "<none>";
    size_x = 300;
    size_y = 90;
    
    puts("Procedimentos de inicializacao.");
}

Widget::Window::~Window()
{
    puts("Finalizacao do objeto janela.");
    std::clog<<"JANELA:"
    <<"-> titulo: "
    <<window_title<<std::endl
    <<"-> dimensao: "
    <<size_x
    <<" x "
    <<size_y<<std::endl;
}

bool Widget::Window::createWindow(const char*wt, uint32_t x, uint32_t y)
{
    window_title = (const char*)wt;
    size_x = x;
    size_y = y;
    
    /* ************************************* *
     * IF Windows, compile for that platform.*
     * ************************************* */
    #ifdef _WIN32
        Widget_WIN32::createWindow(wt);
    
    /* ************************************ *
     * IF Linux, compile for that platform. *
     * ************************************ */
    #elif __linux__
        Widget_Linux::createWindow(wt,x,y);
    #endif
    
    std::clog << "Procedimentos para criacao da janela." << std::endl;
    return true;
}

// SUBWINDOW
Widget::SubWindow::SubWindow()
{
    //pass ...
}

Widget::SubWindow::~SubWindow()
{
    //pass ...
}

bool Widget::SubWindow::createSubWindow(const char*wt, uint32_t x, uint32_t y)
{
    puts("criada subjanela");
    return true;
}
