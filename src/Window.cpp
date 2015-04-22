#include "../includes/Window.hpp"

Widget::Window::Window()
{
    window_title = "<none>";
    size_x = 600;
    size_y = 400;
    
    puts("Procedimentos de inicializacao.");
}

Widget::Window::~Window()
{
    puts("Finalizacao do objeto janela.");
    fprintf(stdout, "JANELA:\n-titulo:%s\n-dimensao:%dx%d\n", window_title, size_x, size_y);
}

bool Widget::Window::createWindow(const char*wt, uint32_t x, uint32_t y)
{
    window_title = (const char*)wt;
    size_x = x;
    size_y = y;
    
    #ifdef _WIN32
        
        const char*WndClassName = (const char*)wt;
    
        LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
        int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, uint8 cmdShow)
        {
            HWND hWnd;
            WNDCLASSEX wc;

            wc.cbSize         = sizeof(WNDCLASSEX);
            wc.style          = CS_HREDRAW | CS_VREDRAW;
            wc.lpfnWndProc    = WndProc;
            wc.cbClsExtra     = 0;
            wc.cbWndExtra     = 0;
            wc.hInstance      = hInstance;
            wc.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
            wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
            wc.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
            wc.lpszMenuName   = NULL;
            wc.lpszClassName  = WndClassName;
            wc.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
        }
        puts("Sistema Windows!");
    #elif __linux__
        
        Fl_Window win(x, y);
        win.show();
        return(Fl::run());
        
        puts("Sistema Linux!");
    #endif
    
    puts("Procedimentos para criacao da janela.");
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
