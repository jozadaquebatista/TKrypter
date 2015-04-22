#include "Libraries.hpp"

namespace Widget{

class Window{

private:
    const char*window_title;
    uint32_t size_x,
             size_y;

public:
    Window();
    ~Window();
    bool createWindow(const char*wt, uint32_t x, uint32_t y);
};

class SubWindow : Window
{
private:
    
public:
    SubWindow();
    ~SubWindow();
    bool createSubWindow(const char*wt, uint32_t x, uint32_t y);
};

} // Fim namespace Widget
