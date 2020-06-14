#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);//BACKGROUND HITAM
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);//MEMBUAT KOTAK TEMPAT OBJEK YANG SEDANG DIGAMBAR
    glLineWidth(1.0);//UKURAN GARIS
    glMatrixMode(GL_PROJECTION);//MENGATUR PROYEKSI
    glLoadIdentity();//MEMANGGIL MATRIKS IDENTITAS
}
void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle = rotAngle*3.14159265/180;//MENGATUR ROTASI
    angleInc = 2*3.14159265/n;//MENGATUR BENTUK

    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        for(k=0; k<n; k++){
            angle += angleInc;
            glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        }
}
void display(void)
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);//MENGHAPUS LAYAR
    glBegin(GL_LINE_STRIP);
        for(i=0; i<60; i++){//BESAR KECILNYA BIDANG
                glColor3f(1.0-(i*0.02), 1.0-(i*0.02), 0.5);//Mengatur Gradasi warna
                    ngon(6, 0, 0, 1+i, 180-i);//Sudut, x & y, Radius, rotAngel
                }
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//SET MODUS DISPLAY
    glutInitWindowSize(600,600);//UKURAN WINDOW
    glutInitWindowPosition(50, 50);//SET POSISI WINDOW
    glutCreateWindow("Yohan's Banjarnahor - 672018356");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




