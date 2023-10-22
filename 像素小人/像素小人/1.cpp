#include <graphics.h> // 引入EasyX图形库
#include <conio.h> // 引入getch()函数

#define WIDTH 640 // 定义窗口宽度
#define HEIGHT 480 // 定义窗口高度
#define SIZE 10 // 定义像素点大小

// 定义像素小人的结构体
struct PixelMan {
    int x; // x坐标
    int y; // y坐标
    COLORREF color; // 颜色
};

// 定义像素小人的初始化函数
void initPixelMan(struct PixelMan* pm, int x, int y, COLORREF color) {
    pm->x = x;
    pm->y = y;
    pm->color = color;
}

// 定义像素小人的绘制函数
void drawPixelMan(struct PixelMan* pm) {
    setfillcolor(pm->color); // 设置填充颜色为像素小人的颜色
    // 绘制像素小人的头部，一个SIZE*SIZE的正方形
    fillrectangle(pm->x, pm->y, pm->x + SIZE - 1, pm->y + SIZE - 1);
    // 绘制像素小人的身体，一个SIZE*2*SIZE的正方形
    fillrectangle(pm->x, pm->y + SIZE, pm->x + SIZE - 1, pm->y + SIZE * 3 - 1);
    // 绘制像素小人的左手，一个SIZE*SIZE的正方形
    fillrectangle(pm->x - SIZE, pm->y + SIZE, pm->x - 1, pm->y + SIZE * 2 - 1);
    // 绘制像素小人的右手，一个SIZE*SIZE的正方形
    fillrectangle(pm->x + SIZE, pm->y + SIZE, pm->x + SIZE * 2 - 1, pm->y + SIZE * 2 - 1);
    // 绘制像素小人的左脚，一个SIZE*SIZE的正方形
    fillrectangle(pm->x - SIZE, pm->y + SIZE * 3, pm->x - 1, pm->y + SIZE * 4 - 1);
    // 绘制像素小人的右脚，一个SIZE*SIZE的正方形
    fillrectangle(pm->x + SIZE, pm->y + SIZE * 3, pm->x + SIZE * 2 - 1, pm->y + SIZE * 4 - 1);
}

// 定义像素小人的移动函数
void movePixelMan(struct PixelMan* pm, int dx, int dy) {
    pm->x += dx; // 更新x坐标
    pm->y += dy; // 更新y坐标
    // 判断是否超出边界，如果是则回到另一边
    if (pm->x < 0) {
        pm->x = WIDTH - SIZE;
    }
    if (pm->x > WIDTH - SIZE) {
        pm->x = 0;
    }
    if (pm->y < 0) {
        pm->y = HEIGHT - SIZE * 4;
    }
    if (pm->y > HEIGHT - SIZE * 4) {
        pm->y = 0;
    }
}

int main() {
    initgraph(WIDTH, HEIGHT); // 初始化图形窗口
    struct PixelMan pm; // 声明一个像素小人变量
    initPixelMan(&pm, WIDTH / 2, HEIGHT / 2, RGB(255, 0, 0)); // 初始化像素小人，位置在窗口中央，颜色为红色
    drawPixelMan(&pm); // 绘制像素小人
    while (1) { // 无限循环
        if (_kbhit()) { // 如果有按键按下
            char ch = _getch(); // 获取按键值
            cleardevice(); // 清空窗口
            switch (ch) { // 根据按键值判断方向
            case 'w': // 如果是w键，向上移动一个SIZE
                movePixelMan(&pm, 0, -SIZE);
                break;
            case 's': // 如果是s键，向下移动一个SIZE
                movePixelMan(&pm, 0, SIZE);
                break;
            case 'a': // 如果是a键，向左移动一个SIZE
                movePixelMan(&pm, -SIZE, 0);
                break;
            case 'd': // 如果是d键，向右移动一个SIZE
                movePixelMan(&pm, SIZE, 0);
                break;
            }
            drawPixelMan(&pm); // 绘制像素小人
        }
    }
    closegraph(); // 关闭图形窗口
    return 0;
}
