#include "../includes/Libraries.hpp"
#include "../includes/Window_Context.hpp"

#ifdef _WIN32
namespace Widget_WIN32
{
    
bool createWindow(const char*wt)
{    
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
        
        /* if all goes ok, return true */
        return true;
    }
    std::clog << "Sistema Windows!" << std::endl;
}

}
#elif __linux__
namespace Widget_Linux
{

bool createWindow(const char*wt, uint32_t x, uint32_t y)
{    
    Fl_Window *win = new Fl_Window(x, y, wt);
    Fl_Input *input = new Fl_Input(105, 40, 600, 30, "Frase: ");
    Fl_Button* but = new Fl_Button( 90, 160, 90, 40, "Encriptar" );

    
    
    ((Fl_Widget*)input)->when((uchar)FL_WHEN_ENTER_KEY);

    win->show();
    return(Fl::run());
    std::clog << "Sistema Linux!" << std::endl;
    
    /* if all goes ok, return true */
    //return true;
}

}
#endif
