#include <ncurses.h>
#include <stdbool.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void on_start();
void intalise_screens();
void generate_set();

typedef enum {
    GRID = 0,
    CONSOLE = 1,
    OPTIONS = 2
} Screens;

WINDOW * all_screens[3];

typedef struct{
    int x;
    int y;
} Vec2;

typedef struct 
{
    Vec2 centre;
    Vec2 pan;
    int zoom;
}Camera;

typedef struct main
{
};

int grid_height, grid_width;



Vec2 centre = {0,0};
Vec2 origin = {0,0};
int max_x = 2;
int max_y = 1;

int row, col;

int main(){
    initscr();
    cbreak();
    raw();
    keypad(stdscr,true);
    noecho();
    

    refresh();
    on_start();
    
    generate_set();

    
    getch();
    endwin();
    return 0;
};

void generate_set(){

};

void on_start(){
    getmaxyx(stdscr, row, col);
    intalise_screens();

};

void intalise_screens() {
    int row_height = row / 10;
    int col_width = col / 5;

    all_screens[GRID] = create_newwin(row_height*9, col_width*4, 0, 0);
    all_screens[CONSOLE] = create_newwin(row_height*2,col_width*4,row_height*9,0);
    all_screens[GRID] = create_newwin(row_height * 11, col_width, 0, col_width * 4);
};

WINDOW *create_newwin(int height, int width, int starty, int startx){
    WINDOW *local_win;

    local_win = newwin(height,width,starty,startx);
    box(local_win,0,0);

    wrefresh(local_win);

    return local_win;
}