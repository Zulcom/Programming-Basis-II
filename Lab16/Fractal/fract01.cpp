void tria (int xa, int ya, int xb, int yb, int xc, int yc, int n) {
    int xp, yp, yq, xq, xr, yr;
    if ( n>0 ) {
        xp = (xb+xc)/2; yp = (yb+yc)/2;
        xq = (xc+xa)/2; yq = (yc+ya)/2;
        xr = (xa+xb)/2; yr = (ya+yb)/2;
        moveto(xp,yp); //Пеpемещение в точку (xp,yp)
        //Рисование тpеугольника
        lineto (xq, yq);
        lineto (xr, yr);
        lineto (xp, yp);
        //Рисование трех малых треугольников
        tria (xa, ya, xr, yr, xq, yq, n-1);
        tria (xb, yb, xp, yp, xr, yr, n-1);
        tria (xc, yc, xq, yq, xp, yp, n-1);
    }
}   

void main() {
    int n, d, r;
    int xa, ya, xb, yb, xc, yc;
    printf ( "Глубина pекуpсии :" );
    scanf ( "%d", &n );
    d = DETECT;
    initgraph ( &d, &r, "d: \\bc \\bgi" );
    xa = 0; ya = getmaxy();
    xb = getmaxx(); yb = getmaxy();
    xc = 0; yc = 0;
    //Рисование пеpвого тpеугольника
    moveto (xa, ya);
    lineto (xb, yb);
    lineto (xc, yc);
    lineto (xa, ya);
    tria (xa, ya, xb, yb, xc, yc, n); 
    getch ();
    closegraph ();
}
 