#include <graphics.h> // ����EasyXͼ�ο�
#include <conio.h> // ����getch()����

#define WIDTH 640 // ���崰�ڿ��
#define HEIGHT 480 // ���崰�ڸ߶�
#define SIZE 10 // �������ص��С

// ��������С�˵Ľṹ��
struct PixelMan {
    int x; // x����
    int y; // y����
    COLORREF color; // ��ɫ
};

// ��������С�˵ĳ�ʼ������
void initPixelMan(struct PixelMan* pm, int x, int y, COLORREF color) {
    pm->x = x;
    pm->y = y;
    pm->color = color;
}

// ��������С�˵Ļ��ƺ���
void drawPixelMan(struct PixelMan* pm) {
    setfillcolor(pm->color); // ���������ɫΪ����С�˵���ɫ
    // ��������С�˵�ͷ����һ��SIZE*SIZE��������
    fillrectangle(pm->x, pm->y, pm->x + SIZE - 1, pm->y + SIZE - 1);
    // ��������С�˵����壬һ��SIZE*2*SIZE��������
    fillrectangle(pm->x, pm->y + SIZE, pm->x + SIZE - 1, pm->y + SIZE * 3 - 1);
    // ��������С�˵����֣�һ��SIZE*SIZE��������
    fillrectangle(pm->x - SIZE, pm->y + SIZE, pm->x - 1, pm->y + SIZE * 2 - 1);
    // ��������С�˵����֣�һ��SIZE*SIZE��������
    fillrectangle(pm->x + SIZE, pm->y + SIZE, pm->x + SIZE * 2 - 1, pm->y + SIZE * 2 - 1);
    // ��������С�˵���ţ�һ��SIZE*SIZE��������
    fillrectangle(pm->x - SIZE, pm->y + SIZE * 3, pm->x - 1, pm->y + SIZE * 4 - 1);
    // ��������С�˵��ҽţ�һ��SIZE*SIZE��������
    fillrectangle(pm->x + SIZE, pm->y + SIZE * 3, pm->x + SIZE * 2 - 1, pm->y + SIZE * 4 - 1);
}

// ��������С�˵��ƶ�����
void movePixelMan(struct PixelMan* pm, int dx, int dy) {
    pm->x += dx; // ����x����
    pm->y += dy; // ����y����
    // �ж��Ƿ񳬳��߽磬�������ص���һ��
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
    initgraph(WIDTH, HEIGHT); // ��ʼ��ͼ�δ���
    struct PixelMan pm; // ����һ������С�˱���
    initPixelMan(&pm, WIDTH / 2, HEIGHT / 2, RGB(255, 0, 0)); // ��ʼ������С�ˣ�λ���ڴ������룬��ɫΪ��ɫ
    drawPixelMan(&pm); // ��������С��
    while (1) { // ����ѭ��
        if (_kbhit()) { // ����а�������
            char ch = _getch(); // ��ȡ����ֵ
            cleardevice(); // ��մ���
            switch (ch) { // ���ݰ���ֵ�жϷ���
            case 'w': // �����w���������ƶ�һ��SIZE
                movePixelMan(&pm, 0, -SIZE);
                break;
            case 's': // �����s���������ƶ�һ��SIZE
                movePixelMan(&pm, 0, SIZE);
                break;
            case 'a': // �����a���������ƶ�һ��SIZE
                movePixelMan(&pm, -SIZE, 0);
                break;
            case 'd': // �����d���������ƶ�һ��SIZE
                movePixelMan(&pm, SIZE, 0);
                break;
            }
            drawPixelMan(&pm); // ��������С��
        }
    }
    closegraph(); // �ر�ͼ�δ���
    return 0;
}
