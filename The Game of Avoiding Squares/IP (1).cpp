#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>
#include <stdio.h>
#include <mmsystem.h>
using namespace std;



int stanga,sus,width,height,latura, numar,limba_1,prioritate,ult_mutare_linie,ult_mutare_coloana, piesa_pers,istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;
int ult_linie_calc,ult_coloana_calc,sunet_1;
bool gata;
int piesa1=1,piesa2=2;
struct patrat1
{
    int lin,col;
}v1[300];
struct patrat2
{
    int lin,col;
}v2[300];
int TablaDeJoc[22][22],Mutari[22][22];
//_______cazul de remiza____
int verif_remiza(int numar)
{
    int i,j;
    for(i=1;i<=numar;++i)
        for(j=1;j<=numar;++j)
    {
        if(TablaDeJoc[i][j]==0) return 0; //tabla nu este completata total, deci nu este remiza
    }
    return 1; //nu avem nicio valoare de zero, deci tabla este completata total, deci avem remiza
}
int verif_pierd(int numar)
{
    int i,j,k=0,t=0,a,b;
    v1[300]={0};
    v2[300]={0};
    for(i=1;i<=numar;++i)
        for(j=1;j<=numar;++j)
        if(TablaDeJoc[i][j]==1)
    {
        v1[++t].lin=i;
        v1[t].col=j;
    }
    else
        if(TablaDeJoc[i][j]==2)
    {
        v2[++k].lin=i;
        v2[k].col=j;
    }

    int numarator1,numarator2,numitor1,numitor2;
    for(i=1;i<=t-3;++i)
    for(j=i+1;j<=t-2;++j)
    for(a=j+1;a<=t-1;++a)
    for(b=a+1;b<=t;++b)
 {
numarator1=v1[b].col-v1[j].col;
numarator2=v1[a].col-v1[i].col;
numitor1=v1[b].lin-v1[j].lin;
numitor2=v1[a].lin-v1[i].lin;

if((numitor1==numitor2 && numarator1==numarator2) && ((v1[j].lin-v1[i].lin)*(v1[j].lin-v1[i].lin)+(v1[j].col-v1[i].col)*(v1[j].col-v1[i].col)==(v1[j].lin-v1[b].lin)*(v1[j].lin-v1[b].lin)+(v1[j].col-v1[b].col)*(v1[j].col-v1[b].col)))
    {cout<<v1[i].lin<<" "<<v1[i].col<<"\n";
    cout<<v1[j].lin<<" "<<v1[j].col<<"\n";
    cout<<v1[a].lin<<" "<<v1[a].col<<"\n";
    cout<<v1[b].lin<<" "<<v1[b].col<<"\n";
        return 1;}
 }

 for(i=1;i<=k-3;++i)
    for(j=i+1;j<=k-2;++j)
    for(a=j+1;a<=k-1;++a)
    for(b=a+1;b<=k;++b)
 {
numarator1=v2[b].col-v2[j].col;
numarator2=v2[a].col-v2[i].col;
numitor1=v2[b].lin-v2[j].lin;
numitor2=v2[a].lin-v2[i].lin;

if((numitor1==numitor2 && numarator1==numarator2) &&
   ((v2[j].lin-v2[i].lin)*(v2[j].lin-v2[i].lin)+(v2[j].col-v2[i].col)*(v2[j].col-v2[i].col)==(v2[j].lin-v2[b].lin)*(v2[j].lin-v2[b].lin)+(v2[j].col-v2[b].col)*(v2[j].col-v2[b].col)))
    {cout<<v2[i].lin<<" "<<v2[i].col<<"\n";
    cout<<v2[j].lin<<" "<<v2[j].col<<"\n";
    cout<<v2[a].lin<<" "<<v2[a].col<<"\n";
    cout<<v2[b].lin<<" "<<v2[b].col<<"\n";
        return 2;}
 }
    return 0;
}
//______________________Verificare conditie de pierdere sau de remiza__________________________//
int verif_pierd_castig_remiza(int numar)
{
    int i,j;



      if(verif_pierd(numar)==1)
      {istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70; //valorile pentru scrierea pe tabla a istoricului mutarilor trebuie actualizate
          //a pierdut primul jucator
          return 1;
      }
      else
      if(verif_pierd(numar)==2)
      {istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;
          //a pierdut al doilea jucator
          return 2;
      }
      else
        if(verif_remiza(numar)==1)
      {istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;
          //este remiza
          return -1;
      }
      else
      if(verif_pierd(numar)==0)
      {
          //jocul se mai poate juca
          return 0;
      }
    }
///______Functie care opreste/porneste sunetele______
int sunet()
{
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
settextstyle(BOLD_FONT,HORIZ_DIR,6);
if(limba_1==1)
outtextxy(440,10,"Setari sunet");
if(limba_1==2)
outtextxy(440,10,"Impostazioni audio");
if(limba_1==3)
outtextxy(440,10,"Sound settings");
if(limba_1==4)
outtextxy(440,10,"Réglages sonores");
if(limba_1==5)
outtextxy(440,10,"Ajustes de sonido");
floodfill(2,2,WHITE);
settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
setcolor(BLUE);
rectangle(440, 150, 770, 200);
setcolor(WHITE);
if (limba_1==1)
{
outtextxy(450, 160, "Set sunete 1");
outtextxy(400, 230, "Jucator 1");
outtextxy(850, 230, "Jucator 2");}
if (limba_1==2) {
outtextxy(450, 160, "Imposta suoni 1");
outtextxy(400, 230, "Giocatore 1");
outtextxy(850, 230, "Giocatore 2");}
if (limba_1==3) {
outtextxy(450, 160, "Sounds set 1");
outtextxy(400, 230, "Player 1");
outtextxy(850, 230, "Player 2");}
if (limba_1==4) {
outtextxy(450, 160, "Regler les sons 1");
outtextxy(400, 230, "Joueur 1");
outtextxy(850, 230, "Joueur 2");}
if (limba_1==5) {
outtextxy(450, 160, "Establecer sonidos 1");
outtextxy(400, 230, "Jugador 1");
outtextxy(850, 230, "Jugador 2");}
floodfill(2,2, WHITE);
//desen butoane set 1 de sunete
//jucator 1
rectangle(270, 230, 310, 270);
line(312, 230, 335, 190);
line(312, 230, 312, 270);
line(312, 270,335, 310 );
line(335,190, 335, 310);
arc(340, 250, 270, 90, 5);
arc(340, 250, 270, 90, 25);
arc(340, 250, 270, 90, 45);
// jucator 2
rectangle(710, 230, 750,270 );
line(752, 230, 785, 190);
line(752, 230, 752, 270);
line(752, 270,785, 310 );
line(785,190, 785, 310);
arc(790, 250, 270, 90, 5);
arc(790, 250, 270, 90, 25);
arc(790, 250, 270, 90, 45);
//buton set sunete 2
setcolor(BLUE);
rectangle(440, 350, 770, 400);
setcolor(WHITE);
if (limba_1==1)
{
outtextxy(450, 350, "Set sunete 2");
outtextxy(400, 430, "Jucator 1");
outtextxy(850, 430, "Jucator 2");}
if (limba_1==2) {
outtextxy(450, 350, "Imposta suoni 2");
outtextxy(400, 430, "Giocatore 1");
outtextxy(850, 430, "Giocatore 2");}
if (limba_1==3) {
outtextxy(450, 350, "Sounds set 2");
outtextxy(400, 430, "Player 1");
outtextxy(850, 430, "Player 2");}
if (limba_1==4) {
outtextxy(450, 350, "Regler les sons 2");
outtextxy(400, 430, "Joueur 1");
outtextxy(850, 430, "Joueur 2");}
if (limba_1==5) {
outtextxy(450, 350, "Establecer sonidos 2");
outtextxy(400, 430, "Jugador 1");
outtextxy(850, 430, "Jugador 2");}
floodfill(2,2, WHITE);
//desen butoane set 2 de sunete
//jucator 1
rectangle(270, 430, 310, 470);
line(312, 430, 312, 470);
line(312, 430, 335, 390 );
line(312, 470, 335, 510);
line(335, 390, 335, 510);
arc(340, 450, 270, 90, 5);
arc(340, 450, 270, 90, 25);
arc(340, 450, 270, 90, 45);
// jucator 2
rectangle(710, 430, 750,470 );
line(752, 430, 785, 390);
line(752, 430, 752, 470);
line(752, 470, 785, 510 );
line(785,390, 785, 510);
arc(790, 450, 270, 90, 5);
arc(790, 450, 270, 90, 25);
arc(790, 450, 270, 90, 45);
// buton Mute
setcolor(BLUE);
rectangle(440, 620, 770, 650);
setcolor(WHITE);
if (limba_1==1)
outtextxy(450, 620, "Mut");
if (limba_1==2)
outtextxy(450, 620, "Muto");
if (limba_1==3)
outtextxy(450, 620, "Mute");
if (limba_1==4)
outtextxy(450, 620, "Muet");
if (limba_1==5)
outtextxy(450, 620, "Mudo");
floodfill(2,2,WHITE);
//desen buton 3
rectangle(270, 630, 310, 670);
line(312, 630, 312, 670);
line(312, 630, 335, 590 );
line(312, 670, 335, 710);
line(335, 590, 335, 710);
arc(340, 650, 270, 90, 5);
arc(340, 650, 270, 90, 25);
arc(340, 650, 270, 90, 45);
line(400, 580, 250, 710);
settextstyle(SIMPLEX_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,650,800);
setcolor(WHITE);
if(limba_1==1)
outtextxy(60,710,"SETARI");
if(limba_1==2)
outtextxy(60,710,"IMPOSTAZIONI");
if(limba_1==3)
outtextxy(60,710,"SETTINGS");
if(limba_1==4)
outtextxy(60,710,"PARAMETRES");
if(limba_1==5)
outtextxy(60,710,"AJUSTES");
floodfill(50,710,WHITE);
while (1)
{
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int xs=mousex();
        int ys=mousey();
        if (xs<=650 && xs>=50 && ys<=800 &&ys>=700)
        {
            cleardevice();
            return 1;
        }
        else if (xs>=440 && xs<=770 && ys>=150 && ys<=200)
        {
            Beep(300, 400);
            delay (300);
            Beep( 450, 400);
            return 2;
        }
        else if (xs>=440 && xs<= 770 && ys>=350 && ys<=400)
        {
            Beep(230, 400);
            delay(300);
            Beep(520, 400);
            return 3;
        }
        else if (xs>= 440 && xs<=770 && ys<=650 && ys>=620)
        {
            Beep(0, 0);
            delay (300);
            return 4;
        }
    }
}
}
//Functie care da posibilitatea jucatorului de a alege dintr-un set de piese
int pers_piese()
{
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
settextstyle(BOLD_FONT,HORIZ_DIR,6);
      if (limba_1==1)
outtextxy(500, 10, "ALEGETI PIESELE");
      if (limba_1==2)
outtextxy(500, 10, "SCEGLI I PEZZI");
      if (limba_1==3)
outtextxy(500, 10, "CHOOSE PIECES");
      if(limba_1==4)
outtextxy(500,10,"CHOISISSEZ DES TARTES");
      if(limba_1==5)
outtextxy(500,10,"ELEGIR LOS PASTELES");
floodfill(2,2,WHITE);
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,650,800);
setcolor(WHITE);
      if(limba_1==1)
outtextxy(60,710,"SETARI");
      if(limba_1==2)
outtextxy(60,710,"IMPOSTAZIONI");
      if(limba_1==3)
outtextxy(60,710,"SETTINGS");
      if(limba_1==4)
outtextxy(60,710,"PARAMETRES");
      if(limba_1==5)
outtextxy(60,710,"AJUSTES");
floodfill(50,710,WHITE);
//primul set de piese
setcolor(WHITE);
rectangle(550, 180, 1000, 340);
setcolor(RED);
setfillstyle(SOLID_FILL, RED);
fillellipse(630,260, 70, 70);
setcolor(LIGHTMAGENTA);
setfillstyle(SOLID_FILL,LIGHTMAGENTA);
fillellipse(900,260,70,70);
// al doilea set de piese
setcolor(WHITE);
rectangle(550,360,1000,520);
setfillstyle(LTSLASH_FILL, 	LIGHTGREEN);
bar(560, 370, 710, 510);
setfillstyle(SLASH_FILL,YELLOW);
bar(820,370,990,510);
// al treilea rand de piese
setcolor(WHITE);
rectangle(550, 540, 1000, 700);
setcolor(WHITE);
setfillstyle(WIDE_DOT_FILL, WHITE);
fillellipse(630,620, 70, 70);
setcolor(CYAN);
setfillstyle(CLOSE_DOT_FILL,MAGENTA);
fillellipse(900,620,70,70);
while (1)
{
  if (ismouseclick(WM_LBUTTONDOWN))
  {   clearmouseclick(WM_LBUTTONDOWN);
      int xp=mousex();
      int yp=mousey();
      if(xp>=50 && xp<=650 && yp>=700 && yp<=800)
      {cleardevice();
          return 1;
      }
    if (xp>=550 && xp<=1000 && yp>=180 && yp<=340 )
    {
        cleardevice();
             return 2;
    }
    else
    if (xp>=550 && xp<=1000 && yp>=360 && yp<=520 )
    {
        cleardevice();

        return 3;
    }
    if (xp>=550 && xp<=1000 && yp>=540 && yp<=700 )
    {
        cleardevice();

        return 4;
    }

  }
}
}
//_____Functie pentru setarile jocului(sunet, personalizare piese)_______
int setari()
{
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(limba_1==1)
outtextxy(500,10,"SETARI");
    if(limba_1==2)
outtextxy(500,10,"IMPOSTAZIONI");
    if(limba_1==3)
outtextxy(500,10,"SETTINGS");
    if(limba_1==4)
outtextxy(500,10,"PARAMETRES");
    if(limba_1==5)
outtextxy(500,10,"AJUSTES");
settextstyle(BOLD_FONT,HORIZ_DIR,6);
//setari pentru sunet
setcolor(BLUE);
rectangle(500,200,650,300);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(510,210,"SUNET");
    if(limba_1==2)
outtextxy(510,210,"SOUND");
    if(limba_1==3)
outtextxy(510,210,"SOUND");
    if(limba_1==4)
outtextxy(510,210,"SOUND");
    if(limba_1==5)
outtextxy(510,210,"SONIDO");
floodfill(510,210,WHITE);
//personalizare piese
setcolor(BLUE);
rectangle(500,400,900,500);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(510,410,"ALEGE PIESELE");
    if(limba_1==2)
outtextxy(510,410,"SCEGLI LE PIZZE");
    if(limba_1==3)
outtextxy(510,410,"CHOOSE PIECES");
    if(limba_1==4)
outtextxy(510,410,"CHOISISSEZ DES TARTES");
    if(limba_1==5)
outtextxy(510,410,"ELEGIR LOS PASTELES");
floodfill(510,410,WHITE);
//buton de intoarcere la meniu
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,650,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(60,710,"Inapoi la meniu");
    if(limba_1==2)
outtextxy(60,710,"Torna al menu");
    if(limba_1==3)
outtextxy(60,710,"Back to menu");
    if(limba_1==4)
outtextxy(60,710,"Revenir au menu");
    if(limba_1==5)
outtextxy(60,710,"Volver al menu");
floodfill(50,710,WHITE);


while(1)
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x=mousex();
        int y=mousey();
        if(x>=500 && x<=650 && y>=200 && y<=300)
        {
            cleardevice();
            sunet_1=sunet();
            setari();
            return 1;
        }

      if(x>=500 && x<=900 && y>=400 && y<=500)
        {   if (sunet_1==2)
              {

                  Beep(300,400);
                  Beep(450,400);
              }
              else if (sunet_1==3)
              {

                  Beep(230,400);
                  Beep(520,400);
              }
              else if (sunet_1==4)
                Beep(0,0);
              else
              {   // daca jucatorul nu a ales nici un set de sunete se va juca cu cel prestabilit

                  Beep(200,400);
                  Beep(300,350);
              }
            cleardevice();
           piesa_pers= pers_piese();
            setari();
            return 1;
        }

    if(x>=50 && x<=650 && y>=700 && y<=800)
    {    if (sunet_1==2)
              {

                  Beep(300,400);
                  Beep(450,400);
              }
              else if (sunet_1==3)
              {

                  Beep(230,400);
                  Beep(520,400);
              }
              else if (sunet_1==4)
                Beep(0,0);
              else
              {   // daca jucatorul nu a ales nici un set de sunete se va juca cu cel prestabilit

                  Beep(200,400);
                  Beep(300,350);
              }
        cleardevice();

        return 1;
    }}}}

//_______Mutare(desenare) piese_______
void deseneazaPiesa(int linia, int coloana, int codPiesa,int marime)
{/*In tabla de joc vor aparea piesele conform alegerii jucatorului, iar daca acesta nu a ales nimic din setari,
se vor genera pisele alese de cel care a programat jocul*/
   if (piesa_pers==2)
   {
   int x1,y1,x2,y2,xmijloc,ymijloc;
   x1=stanga+latura*(coloana-1);
   y1=sus+latura*(linia-1);
   x2=x1+latura; y2=y1+latura;
   xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;

   if(codPiesa==1)
   {
       //Se va desena in tabla piesa corespunzatoare primului jucator
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    if(marime==3)
        fillellipse(xmijloc,ymijloc,100,100);
    else
    if(marime>=4 && marime<=6)
        fillellipse(xmijloc,ymijloc,30,30);
    else
        fillellipse(xmijloc,ymijloc,18,15);


   }
   else
   { //Se va desena in tabla piesa corespunzatoare celuilalt jucator
setcolor(LIGHTMAGENTA);
setfillstyle(SOLID_FILL,LIGHTMAGENTA);
        if(marime==3)
            fillellipse(xmijloc,ymijloc,100,100);
        else
            if(marime>=4 && marime<=6)
                fillellipse(xmijloc,ymijloc,30,30);
   else
                fillellipse(xmijloc,ymijloc,18,15);
   }
   }
   else
    if (piesa_pers==3)
   {
      int x1, y1, x2, y2;
       x1=stanga+latura*(coloana-1);
       y1=sus+latura*(linia-1);
       x2=x1+latura; y2=y1+latura;
    int xmijloc=(x1+x2)/2;
    int ymijloc=(y1+y2)/2;
       if (codPiesa==1)
       {
        setcolor(LIGHTGREEN);
        setfillstyle(LTSLASH_FILL, LIGHTGREEN);
        if(marime==3)
        bar(x1+20, y1+20, x2-20, y2-20);
        else
        if(marime>=4 && marime<=6)
        bar(x1+20,y1+20,x2-10,y2-10);
        else
            bar(x1+10,y1+10,x2-10,y2-10);
       }
       else
       {
           setcolor(YELLOW);
           setfillstyle(SLASH_FILL, YELLOW);
           if(marime==3)
           bar(x1+20, y1+20, x2-20, y2-20);
           else
           if(marime>=4 && marime<=6)
           bar(x1+20,y1+20,x2-10,y2-10);
           else
            bar(x1+10,y1+10,x2-10,y2-10);

       }
   }
   else
    if (piesa_pers==4)
   {
   int x1,y1,x2,y2,xmijloc,ymijloc;
   x1=stanga+latura*(coloana-1);
   y1=sus+latura*(linia-1);
   x2=x1+latura; y2=y1+latura;
   xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;

   if(codPiesa==1)
   {
       //muta orimul jucator
       setcolor(WHITE);
   setfillstyle(WIDE_DOT_FILL,WHITE);
   if(marime==3)
   fillellipse(xmijloc,ymijloc,100,100);
   else
   if(marime>=4 && marime<=6)
    fillellipse(xmijloc,ymijloc,30,30);
   else
    fillellipse(xmijloc,ymijloc,18,15);
    }
   else
   {
       setcolor(WHITE);
   setfillstyle(CLOSE_DOT_FILL,MAGENTA);
    if(marime==3)
   fillellipse(xmijloc,ymijloc,100,100);
   else
   if(marime>=4 && marime<=6)
    fillellipse(xmijloc,ymijloc,30,30);
   else
    fillellipse(xmijloc,ymijloc,18,15);
   }
   }
   else
   {
    {
   int x1,y1,x2,y2,xmijloc,ymijloc;
   x1=stanga+latura*(coloana-1);
   y1=sus+latura*(linia-1);
   x2=x1+latura; y2=y1+latura;
   xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;

   if(codPiesa==1)
   {
       //muta orimul jucator
       setcolor(RED);
   setfillstyle(INTERLEAVE_FILL,RED);
   if(marime==3)
   fillellipse(xmijloc,ymijloc,100,100);
   else
   if(marime>=4 && marime<=6)
    fillellipse(xmijloc,ymijloc,30,30);
   else
    fillellipse(xmijloc,ymijloc,18,15);


   }
   else
   {
       setcolor(GREEN);
   setfillstyle(LINE_FILL,GREEN);
    if(marime==3)
   fillellipse(xmijloc,ymijloc,100,100);
   else
   if(marime>=4 && marime<=6)
    fillellipse(xmijloc,ymijloc,30,30);
   else
    fillellipse(xmijloc,ymijloc,18,15);
   }}}}
//___Functie care identifica unde vrea jucatorul sa isi plaseze pionul si modifica in matrice campul corespunzator coordonatelor mouseu-lui
int mutarePiesa(int jucator,int marime_tabla)
{

   int linia,coloana,x,y;
   int x1, y1, x2, y2;
   int xmijloc, ymijloc;
while(1)
{if(ismouseclick(WM_LBUTTONDOWN))
{
    clearmouseclick(WM_LBUTTONDOWN);
    int x=mousex();
    int y=mousey();
    linia=(y-sus)/latura+1; coloana=(x-stanga)/latura+1;

    if(TablaDeJoc[linia][coloana]==0 && (x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height))
    {TablaDeJoc[linia][coloana]=jucator;
    //trebuie sa retim ultima mutare a jucatorului de fiecare data pentru strategia hard calculatorului
    ult_mutare_coloana=coloana; ult_mutare_linie=linia;
   deseneazaPiesa(linia,coloana,jucator,marime_tabla);
    if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);
     else if (sunet_1==3)
      Beep(230, 400);
    else if (sunet_1==4)
        Beep(0,0);
    else
        Beep(610,400);
    }
    if (jucator==2)
    {
        if (sunet_1==2)
            Beep(450, 400);
      else  if (sunet_1==3)
            Beep(520, 400);
        else if (sunet_1==4)
            Beep(0,0);
        else
            Beep(500, 400);
    }
 }
 else
 {//daca se apasa in afara tablei sau pe o casuta deja ocupata de un pion se iese din joc
      clearmouseclick(WM_LBUTTONDOWN);
      gata=false;
      //mutarePiesa(jucator,marime_tabla);
 }


    return 1;

}}
}
//MODUL EASY
int mutare_piesa_easy(int jucator,int marime_tabla)
{//Modul easy al calculatorului consta in mutarea unor piese pe tabla random(cu ajutorul functiei rand())
    int linia, coloana,linia2,coloana2;
    linia=rand()%marime_tabla+1;
    coloana=rand()%marime_tabla+1;

    if(TablaDeJoc[linia][coloana]==0) {TablaDeJoc[linia][coloana]=jucator;ult_linie_calc=linia;ult_coloana_calc=coloana;}
    else
   {
       while(TablaDeJoc[linia][coloana]==1 || TablaDeJoc[linia][coloana]==2)
    {linia2=rand()%marime_tabla+1;
    coloana2=rand()%marime_tabla+1;
    while(linia2==linia) linia2=rand()%marime_tabla+1;
    while(coloana2==coloana) coloana2=rand()%marime_tabla+1;
        //schimb linia
        if(TablaDeJoc[linia2][coloana2]==0)
        {
            TablaDeJoc[linia2][coloana2]=jucator;
            ult_linie_calc=linia2;
            ult_coloana_calc=coloana2;
            deseneazaPiesa(linia2,coloana2,jucator,marime_tabla);
            return 1;
        }
        else
        if(TablaDeJoc[linia2][coloana]==0 ) {linia=linia2;TablaDeJoc[linia][coloana]=jucator;
        ult_linie_calc=linia2;
        ult_coloana_calc=coloana2;
        deseneazaPiesa(linia,coloana,jucator,marime_tabla);
    return 1;}
        else
        if(TablaDeJoc[linia][coloana2]==0) {coloana=coloana2;TablaDeJoc[linia][coloana]=jucator;
        ult_linie_calc=linia;
        ult_coloana_calc=coloana;
        deseneazaPiesa(linia,coloana,jucator,marime_tabla);
    return 1;}
    }
   }
    deseneazaPiesa(linia,coloana,jucator,marime_tabla);
       if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);
     else if (sunet_1==3)
      Beep(230, 400);
    else if (sunet_1==4)
        Beep(0,0);
    else
        Beep(610,400);
    }
    if (jucator==2)
    {
        if (sunet_1==2)
            Beep(450, 400);
      else  if (sunet_1==3)
            Beep(520, 400);
        else if (sunet_1==4)
            Beep(0,0);
        else
            Beep(500, 400);
    }
    return 1;
}
int mutare_piesa_hard(int jucator,int marime_tabla)
{
    int linia, coloana,mij_tabla,diferenta,linia2,coloana2;
    if(marime_tabla%2==0)
    {
        //simetrie fata de dreapta care desparte tabla in doua(paralela cu baza)
        mij_tabla=marime_tabla/2;
        //coloana corespunde cu cea a mutarii jucatorului
        coloana=ult_mutare_coloana;
        if(ult_mutare_linie<=mij_tabla)
        {//daca se afla deasupra liniei care desparte tabla in doua
            diferenta=mij_tabla-ult_mutare_linie;
        linia=mij_tabla+diferenta+1;}
        else
        {
            //daca se afla sub linia care desparte tabla in doua
            diferenta=ult_mutare_linie-mij_tabla;
            linia=mij_tabla-(diferenta-1);
        }

        if(TablaDeJoc[linia][coloana]==0)
        {//putem folosi prima strategie de joc-simetrie fata de dreapta care desparte tabla in doua(paralela cu baza)
            TablaDeJoc[linia][coloana]=jucator;
            //pastram valoarea liniei si coloanei in care s-au pus pioni pentru istoricul mutarilor
            ult_coloana_calc=coloana; ult_linie_calc=linia;
        deseneazaPiesa(linia,coloana,jucator,marime_tabla);
                if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);
        else
            if (sunet_1==3)
      Beep(230, 400);
      else
        if (sunet_1==4)
Beep(0,0);
else
        Beep(610,400);
    }if (jucator==2)
    {if (sunet_1==2)
            Beep(450, 400);else  if (sunet_1==3)
            Beep(520, 400);else if (sunet_1==4)
            Beep(0,0);else
            Beep(500, 400);
    }
        return 1;}



    }
    else
    {int gasit=1;
        //aceasta strategie se aseamana tot cu cea de la tabla de ordin par(doar ca neglijam linia din mijloc a tablei)
        //pe linia din mijloc piesele se vor pune random
        //la tabla de ordin impar, mijlocul se afla la (marime_tabla/2+1)
        mij_tabla=marime_tabla/2+1;
        //coloana corespunde cu cea a mutarii jucatorului
        coloana=ult_mutare_coloana;

        if(ult_mutare_linie<mij_tabla)
        {//daca se afla deasupra liniei care desparte tabla in doua
            diferenta=mij_tabla-ult_mutare_linie;
        linia=mij_tabla+diferenta;
        if(TablaDeJoc[linia][coloana]==0)
        {TablaDeJoc[linia][coloana]=jucator;
        ult_coloana_calc=coloana;
        ult_linie_calc=linia;
            deseneazaPiesa(linia,coloana,jucator,marime_tabla);
                            if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);else if (sunet_1==3)
      Beep(230, 400);else if (sunet_1==4)
Beep(0,0);else
        Beep(610,400);
    }if (jucator==2)
    {if (sunet_1==2)
            Beep(450, 400);else  if (sunet_1==3)
            Beep(520, 400);else if (sunet_1==4)
            Beep(0,0);else
            Beep(500, 400);
    }return 1;
        }
        gasit=0;
        }

        if(ult_mutare_linie>mij_tabla)

        {
            //daca se afla sub linia care desparte tabla in doua
            diferenta=ult_mutare_linie-mij_tabla;
            linia=mij_tabla-diferenta;
            if(TablaDeJoc[linia][coloana]==0)
            {TablaDeJoc[linia][coloana]=jucator;
            ult_coloana_calc=coloana;
            ult_linie_calc=linia;
                deseneazaPiesa(linia,coloana,jucator,marime_tabla);
                                if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);else if (sunet_1==3)
      Beep(230, 400);else if (sunet_1==4)
Beep(0,0);else
        Beep(610,400);
    }if (jucator==2)
    {if (sunet_1==2)
            Beep(450, 400);else  if (sunet_1==3)
            Beep(520, 400);else if (sunet_1==4)
            Beep(0,0);else
            Beep(500, 400);
    }
                return 1;
            }
            else
            gasit=0;
        }

        if(ult_mutare_linie==mij_tabla || gasit==0)
        {
            if(TablaDeJoc[1][coloana]==0 && gasit==1)
            {
                TablaDeJoc[1][coloana]=jucator;
                ult_coloana_calc=coloana;
                ult_linie_calc=linia;
                        if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);
     else if (sunet_1==3)
      Beep(230, 400);
    else if (sunet_1==4)
        Beep(0,0);
    else
        Beep(610,400);
    }
    if (jucator==2)
    {
        if (sunet_1==2)
            Beep(450, 400);
      else  if (sunet_1==3)
            Beep(520, 400);
        else if (sunet_1==4)
            Beep(0,0);
        else
            Beep(500, 400);
    }
                deseneazaPiesa(1,coloana,jucator,marime_tabla);
                return 1;
            }
            else
            if(TablaDeJoc[marime_tabla][coloana]==0 && gasit==1)
            {
                TablaDeJoc[marime_tabla][coloana]=jucator;
                ult_coloana_calc=coloana;
                ult_linie_calc=linia;
                deseneazaPiesa(marime_tabla,coloana,jucator,marime_tabla);
                                if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);else if (sunet_1==3)
      Beep(230, 400);else if (sunet_1==4)
Beep(0,0);else
        Beep(610,400);
    }if (jucator==2)
    {if (sunet_1==2)
            Beep(450, 400);else  if (sunet_1==3)
            Beep(520, 400);else if (sunet_1==4)
            Beep(0,0);else
            Beep(500, 400);
    }
                return 1;
            }
            else
            {
                //daca nu este niciun spatiu gol prin simetrie, se alege un spatiu random in care calculatorul sa mute pionul
               linia=rand()%marime_tabla+1;
               coloana=rand()%marime_tabla+1;
    if(TablaDeJoc[linia][coloana]==0 || gasit==0) {TablaDeJoc[linia][coloana]=jucator;ult_linie_calc=linia;ult_coloana_calc=coloana;
    deseneazaPiesa(linia,coloana,jucator,marime_tabla);
                    if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);else if (sunet_1==3)
      Beep(230, 400);else if (sunet_1==4)
Beep(0,0);else
        Beep(610,400);
    }if (jucator==2)
    {if (sunet_1==2)
            Beep(450, 400);else  if (sunet_1==3)
            Beep(520, 400);else if (sunet_1==4)
            Beep(0,0);else
            Beep(500, 400);
    }return 1;}
    else
   {
       while(TablaDeJoc[linia][coloana]==1 || TablaDeJoc[linia][coloana]==2)
    {linia2=rand()%marime_tabla+1;
    coloana2=rand()%marime_tabla+1;
    while(linia2==linia) linia2=rand()%marime_tabla+1;
    while(coloana2==coloana) coloana2=rand()%marime_tabla+1;
        //schimb linia
        if(TablaDeJoc[linia2][coloana2]==0)
        {
            TablaDeJoc[linia2][coloana2]=jucator;
            ult_linie_calc=linia2;
            ult_coloana_calc=coloana2;
            deseneazaPiesa(linia2,coloana2,jucator,marime_tabla);
                    if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);else if (sunet_1==3)
      Beep(230, 400);else if (sunet_1==4)
Beep(0,0);else
        Beep(610,400);
    }if (jucator==2)
    {if (sunet_1==2)
            Beep(450, 400);else  if (sunet_1==3)
            Beep(520, 400);else if (sunet_1==4)
            Beep(0,0);else
            Beep(500, 400);
    }
            return 1;
        }
        else
        if(TablaDeJoc[linia2][coloana]==0 ) {linia=linia2;TablaDeJoc[linia][coloana]=jucator;
        ult_linie_calc=linia2;
        ult_coloana_calc=coloana2;
        deseneazaPiesa(linia,coloana,jucator,marime_tabla);
    return 1;}
        else
        if(TablaDeJoc[linia][coloana2]==0) {coloana=coloana2;TablaDeJoc[linia][coloana]=jucator;
        ult_linie_calc=linia;
        ult_coloana_calc=coloana;
        deseneazaPiesa(linia,coloana,jucator,marime_tabla);
                if (jucator==1)
    {
    if (sunet_1==2)
        Beep(300, 400);
     else if (sunet_1==3)
      Beep(230, 400);
    else if (sunet_1==4)
        Beep(0,0);
    else
        Beep(610,400);
    }
    if (jucator==2)
    {
        if (sunet_1==2)
            Beep(450, 400);
      else  if (sunet_1==3)
            Beep(520, 400);
        else if (sunet_1==4)
            Beep(0,0);
        else
            Beep(500, 400);
    }
    return 1;}
           }}}}}
}
int fereastra_pierzator(int jucator)

{
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
settextstyle(BOLD_FONT,HORIZ_DIR,7);
PlaySound(TEXT("pierd.wav"),NULL,SND_ASYNC);

if(limba_1==1)
    if(jucator==1)
        outtextxy(100,300,"Primul jucator a pierdut");
    else
    if(jucator==2)
        outtextxy(100,300,"Al doilea jucator a pierdut");
if(limba_1==2)
    if(jucator==1)
        outtextxy(100,300,"Il primo giocatore ha perso...");
    else
        outtextxy(100,300,"Il secondo giocatora ha perso...");
if(limba_1==3)
    if(jucator==1)
        outtextxy(100,300,"The first player lost...");
    else
        outtextxy(100,300,"The second player lost...");
if(limba_1==4)
    if(jucator==1)
        outtextxy(100,300,"Le premier joueur a perdu...");
    else
        outtextxy(100,300,"Le deuxieme joueur a perdu...");
if(limba_1==5)
    if(jucator==1)
        outtextxy(100,300,"El primer jugador perdido...");
    else
        outtextxy(100,300,"El segundo jugador perdido...");

settextstyle(BOLD_FONT,HORIZ_DIR,5);
outtextxy(700,500,":(");
floodfill(2,2,WHITE);
//buton de intoarcere la meniu
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(200,700,650,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(210,710,"Inapoi la meniu");
    if(limba_1==2)
outtextxy(210,710,"Torna al menu");
    if(limba_1==3)
outtextxy(210,710,"Back to menu");
    if(limba_1==4)
outtextxy(210,710,"Revenir au menu");
    if(limba_1==5)
outtextxy(210,710,"Volver al menu");
floodfill(210,710,WHITE);
//BEEP
while(1)
{if(ismouseclick(WM_LBUTTONDOWN))
{clearmouseclick(WM_LBUTTONDOWN);
    int x=mousex();
    int y=mousey();
    if(x>=200 && x<=650 && y>=700 && y<=800)
    {PlaySound(NULL,NULL,SND_ASYNC);
        cleardevice();
        return 1;
    }



}}}

int fereastra_REMIZA()
{
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
PlaySound(TEXT("remiza.wav"),NULL,SND_ASYNC);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
settextstyle(BOLD_FONT,HORIZ_DIR,7);
    if(limba_1==1)
outtextxy(500,200,"REMIZA");
    if(limba_1==2)
outtextxy(500,200,"DISEGNARE");
    if(limba_1==3)
outtextxy(500,200,"DRAW");
    if(limba_1==4)
outtextxy(500,200,"DESSINER");
    if(limba_1==5)
outtextxy(500,200,"DIBUJAR");
floodfill(500,500,WHITE);
Beep(800,100);
Beep(900,100);
Beep(1000,100);
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(200,700,650,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(210,710,"Inapoi la meniu");
    if(limba_1==2)
outtextxy(210,710,"Torna al menu");
    if(limba_1==3)
outtextxy(210,710,"Back to menu");
    if(limba_1==4)
outtextxy(210,710,"Revenir au menu");
    if(limba_1==5)
outtextxy(210,710,"Volver al menu");
floodfill(210,710,WHITE);
//BEEP
while(1)
{if(ismouseclick(WM_LBUTTONDOWN))
{clearmouseclick(WM_LBUTTONDOWN);
    int x=mousex();
    int y=mousey();
    if(x>=200 && x<=650 && y>=700 && y<=800)
    {PlaySound(NULL,NULL,SND_ASYNC);
        cleardevice();
        return 1;
    }

}


}}
//____Desen tabla pentru 1v1
int desen(int numar)
{
   int i,j;gata=true;
   for(i=1;i<=numar;++i)
    for(j=1;j<=numar;++j)
    {TablaDeJoc[i][j]=0;Mutari[i][j]=0;}
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);

initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
width=800; height=800; latura=width/numar;
   sus=(getmaxy()-width)/2; stanga=(getmaxx()-height)/2;

//coloanele pentru istoricul mutarilor
settextstyle(BOLD_FONT,HORIZ_DIR,5);
if (limba_1==1)
{
outtextxy(20,30,"Jucator 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Jucator 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==2)
{
outtextxy(20,30,"Giocatore 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Giocatore 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==3)
{
outtextxy(20,30,"Player 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Player 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==4)
{
outtextxy(20,30,"Joueur 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Joueur 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==5)
{
outtextxy(20,30,"Jugador 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Jugador 2:");
floodfill(1200,30,WHITE);
}


char arr1[50];

   //clearviewport();
   for (i=1; i<=numar; i++)
       for (j=1; j<=numar; j++)
           rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
int ok;
//inceprea jocului
do {

       mutarePiesa(piesa1,numar);
if(gata==false)
    return 0;

       settextstyle(BOLD_FONT,HORIZ_DIR,5);
    if(istoric_y1>=760)
    {
        //nu mai este loc unde sa afisez istocul mutarilor
        setcolor(WHITE);
        setfillstyle(INTERLEAVE_FILL ,MAGENTA);
        bar(20,70,150,863);
        floodfill(20,70,WHITE);
        bar(1250,70,1380,863);
        floodfill(1250,70,WHITE);
        istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;


    }
    if(Mutari[ult_mutare_linie][ult_mutare_coloana]==0 && ult_mutare_linie && ult_mutare_coloana)
{arr1[0]=NULL;
sprintf(arr1,"%d",ult_mutare_linie);
//itoa(ult_mutare_linie,arr1,10);
setcolor(WHITE);
outtextxy(istoric_x1,istoric_y1,arr1); setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x1,istoric_y1,WHITE);
arr1[0]=NULL;
istoric_x1=istoric_x1+80;
sprintf(arr1,"%d",ult_mutare_coloana);
//itoa(ult_mutare_coloana,arr1,10);
setcolor(WHITE);
outtextxy(istoric_x1,istoric_y1,arr1); setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x1,istoric_y1,WHITE);
istoric_x1=istoric_x1-80;
istoric_y1=istoric_y1+40;

//fundal
 setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
Mutari[ult_mutare_linie][ult_mutare_coloana]=1;
}

       delay(600);
       if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
} //pagina care afiseaza castigatoul si pierzatorul dau daca este remiza

gata=true;
if(gata==false)
    return 0;
       mutarePiesa(piesa2,numar);
if(Mutari[ult_mutare_linie][ult_mutare_coloana]==0 && ult_mutare_linie && ult_mutare_coloana)
    {arr1[0]=NULL;
    sprintf(arr1,"%d",ult_mutare_linie);
    //itoa(ult_mutare_linie,arr1,10);
    setcolor(WHITE);
    outtextxy(istoric_x2,istoric_y2,arr1); setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
    floodfill(istoric_x2,istoric_y2,WHITE);
    arr1[0]=NULL;
    istoric_x2=istoric_x2+80;
    sprintf(arr1,"%d",ult_mutare_coloana);
    //itoa(ult_mutare_coloana,arr1,10);
    outtextxy(istoric_x2,istoric_y2,arr1); setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
    floodfill(istoric_x2,istoric_y2,WHITE);
    istoric_x2=istoric_x2-80;
    istoric_y2=istoric_y2+40;
    Mutari[ult_mutare_linie][ult_mutare_coloana]=1;
    }

       delay(600);
       if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
} //pagina care afiseaza castigatoul si pierzatorul dau daca este remiza

  } while (verif_pierd_castig_remiza(numar)==0);
if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
}


}
//_____Desen tabla pentru jucator vs calculator_modul easy
int desen_jucator_calculator_easy(int numar)
{
   int i,j;
   istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;
   //Initializam de fiecare data matricea corespunzatoare tablei de joc cu 0
for(i=1;i<=numar;++i)
for(j=1;j<=numar;++j)
    {TablaDeJoc[i][j]=0;Mutari[i][j]=0;}
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
width=800; height=800; latura=width/numar;
sus=(getmaxy()-width)/2; stanga=(getmaxx()-height)/2;

//coloanele pentru istoricul mutarilor
settextstyle(BOLD_FONT,HORIZ_DIR,5);
if (limba_1==1)
{
outtextxy(20,30,"Jucator 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Jucator 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==2)
{
outtextxy(20,30,"Giocatore 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Giocatore 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==3)
{
outtextxy(20,30,"Player 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Player 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==4)
{
outtextxy(20,30,"Joueur 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Joueur 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==5)
{
outtextxy(20,30,"Jugador 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Jugador 2:");
floodfill(1200,30,WHITE);
}
char arr1[50];


   //clearviewport();
   for (i=1; i<=numar; i++)
       for (j=1; j<=numar; j++)
           rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
//inceprea jocului
do {

gata=true;
mutarePiesa(piesa1,numar);
if(gata==false)
    return 0;
    if(istoric_y1>=830)
    {
        //nu mai este loc unde sa afisez istocul mutarilor
        setcolor(WHITE);
        setfillstyle(INTERLEAVE_FILL ,MAGENTA);
        bar(20,70,150,863);
        floodfill(20,70,WHITE);
        bar(1250,70,1380,863);
        floodfill(1250,70,WHITE);
        istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;


    }
    if(Mutari[ult_mutare_linie][ult_mutare_coloana]==0 && ult_mutare_coloana && ult_mutare_coloana)
{arr1[0]=NULL;
sprintf(arr1,"%d",ult_mutare_linie);
setcolor(WHITE);
outtextxy(istoric_x1,istoric_y1,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x1,istoric_y1,WHITE);
arr1[0]=NULL;
istoric_x1=istoric_x1+80;
sprintf(arr1,"%d",ult_mutare_coloana);
setcolor(WHITE);
outtextxy(istoric_x1,istoric_y1,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x1,istoric_y1,WHITE);
istoric_x1=istoric_x1-80;
istoric_y1=istoric_y1+40;
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
Mutari[ult_mutare_linie][ult_mutare_coloana]=1;
}
       delay(1600);
       if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
} //pagina care afiseaza castigatoul si pierzatorul sau daca este remiza
    //jucatorul 2 este calculatorul(modul easy)

mutare_piesa_easy(piesa2,numar);
if(Mutari[ult_linie_calc][ult_coloana_calc]==0 && ult_linie_calc && ult_coloana_calc)
{arr1[0]=NULL;
sprintf(arr1,"%d",ult_linie_calc);
setcolor(WHITE);
outtextxy(istoric_x2,istoric_y2,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x2,istoric_y2,WHITE);
arr1[0]=NULL;
istoric_x2=istoric_x2+80;
sprintf(arr1,"%d",ult_coloana_calc);
outtextxy(istoric_x2,istoric_y2,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x2,istoric_y2,WHITE);
istoric_x2=istoric_x2-80;
istoric_y2=istoric_y2+40;
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
Mutari[ult_linie_calc][ult_coloana_calc]=1;
}
       delay(1600);

       if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
} //pagina care afiseaza castigatoul si pierzatorul dau daca este remiza

  } while (verif_pierd_castig_remiza(numar)==0);

if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
}

return 0;
}
//___Desen jucator calculator(modul hard)
int desen_jucator_calculator_hard(int numar)
{
   int i,j;
   istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;
   for(i=1;i<=numar;++i)
    for(j=1;j<=numar;++j)
    {TablaDeJoc[i][j]=0;Mutari[i][j]=0;}
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
 setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
width=800; height=800; latura=width/numar;
   sus=(getmaxy()-width)/2; stanga=(getmaxx()-height)/2;
//coloanele pentru istoricul mutarilor
settextstyle(BOLD_FONT,HORIZ_DIR,5);
if (limba_1==1)
{
outtextxy(20,30,"Jucator 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Jucator 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==2)
{
outtextxy(20,30,"Giocatore 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Giocatore 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==3)
{
outtextxy(20,30,"Player 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Player 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==4)
{
outtextxy(20,30,"Joueur 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Joueur 2:");
floodfill(1200,30,WHITE);
}
if (limba_1==5)
{
outtextxy(20,30,"Jugador 1:");
floodfill(20,30,WHITE);
outtextxy(1200,30,"Jugador 2:");
floodfill(1200,30,WHITE);
}
char arr1[50];




   for (i=1; i<=numar; i++)
       for (j=1; j<=numar; j++)
           rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
//inceprea jocului

do {


//muta primul jucator
gata=true;
mutarePiesa(piesa1,numar);
if(gata==false)
    return 0;
    if(istoric_y1>=830)
    {
        //nu mai este loc unde sa afisez istocul mutarilor
        setcolor(WHITE);
        setfillstyle(INTERLEAVE_FILL ,MAGENTA);
        bar(20,70,150,863);
        floodfill(20,70,WHITE);
        bar(1250,70,1380,863);
        floodfill(1250,70,WHITE);
        istoric_x1=20,istoric_y1=70,istoric_x2=1250,istoric_y2=70;


    }
    if(Mutari[ult_mutare_linie][ult_mutare_coloana]==0 && ult_mutare_coloana && ult_mutare_linie)
{arr1[0]=NULL;
sprintf(arr1,"%d",ult_mutare_linie);
setcolor(WHITE);
outtextxy(istoric_x1,istoric_y1,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x1,istoric_y1,WHITE);
arr1[0]=NULL;
istoric_x1=istoric_x1+80;
sprintf(arr1,"%d",ult_mutare_coloana);
setcolor(WHITE);
outtextxy(istoric_x1,istoric_y1,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x1,istoric_y1,WHITE);
istoric_x1=istoric_x1-80;
istoric_y1=istoric_y1+40;
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
Mutari[ult_mutare_linie][ult_mutare_coloana]=1;
}
       delay(1600);
       if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
} //pagina care afiseaza castigatoul si pierzatorul sau daca este remiza
    //jucatorul 2 este calculatorul(modul hard-cu strategie)

mutare_piesa_hard(piesa2,numar);
if(Mutari[ult_linie_calc][ult_coloana_calc]==0 && ult_linie_calc && ult_coloana_calc)
{arr1[0]=NULL;
sprintf(arr1,"%d",ult_linie_calc);
setcolor(WHITE);
outtextxy(istoric_x2,istoric_y2,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x2,istoric_y2,WHITE);
arr1[0]=NULL;
istoric_x2=istoric_x2+80;
sprintf(arr1,"%d",ult_coloana_calc);
outtextxy(istoric_x2,istoric_y2,arr1);
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
floodfill(istoric_x2,istoric_y2,WHITE);
istoric_x2=istoric_x2-80;
istoric_y2=istoric_y2+40;
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2,2,WHITE);
Mutari[ult_linie_calc][ult_coloana_calc]=1;
}
       delay(1600);

      if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
} //pagina care afiseaza castigatoul si pierzatorul dau daca este remiza


  } while (verif_pierd_castig_remiza(numar)==0);


if(verif_pierd_castig_remiza(numar)==1)
    {cleardevice();
        fereastra_pierzator(1);
        return 1;}
if(verif_pierd_castig_remiza(numar)==2)
    {cleardevice();
        fereastra_pierzator(2);
        return 1;}
if(verif_pierd_castig_remiza(numar)==-1)
{
    cleardevice();
    fereastra_REMIZA();
    return 1;
}


}
//____________________Alege tabla pentru jucator contra jucator___________
int alege_tabla()
{   DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    if(limba_1==1)
    outtextxy(440,10,"Alegeti dimensiunea tablei de joc");
    else
    if(limba_1==2)
    outtextxy(200,10,"Selezione la dimensione del tabello del gioco");
    else
    if(limba_1==3)
    outtextxy(440,10,"Choose the size of the board");
    else
    if(limba_1==4)
    outtextxy(440,10,"Choisissez la taille du table de jeu");
    if(limba_1==5)
    outtextxy(200,10,"Elegid las dimensiones de la tabla de juego");
     setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2, 2,WHITE);
    int x=screenHeight; int y=screenWidth;
     settextstyle(BOLD_FONT,HORIZ_DIR,6);
//primul rand de butoane
    //tabla 3x3
    setcolor(BLUE);
    rectangle(x/3-50,100,y/3,165);
    setcolor(WHITE);
    outtextxy(x/3+30,110,"3x3");
    floodfill(x/3+30,110,WHITE);
    //tabla 4x4
    setcolor(BLUE);
    rectangle(x/3+400,100,y/3+400,165);
    setcolor(WHITE);
    outtextxy(x/3+410,110,"4x4");
    floodfill(x/3+410,110,WHITE);
    //tabla 5x5
    setcolor(BLUE);
    rectangle(x/3+800,100,y/3+800,165);
    setcolor(WHITE);
    outtextxy(x/3+810,110,"5x5");
    floodfill(x/3+810,110,WHITE);
//al doilea rand de butoane
    //tabla 6x6
    setcolor(BLUE);
    rectangle(x/3-50,210,y/3,280);
    setcolor(WHITE);
    outtextxy(x/3+30,220,"6x6");
    floodfill(x/3+30,220,WHITE);
    //tabla 7x7
    setcolor(BLUE);
    rectangle(x/3+400,210,y/3+400,280);
    setcolor(WHITE);
    outtextxy(x/3+410,220,"7x7");
    floodfill(x/3+410,220,WHITE);
    //tabla 8x8
    setcolor(BLUE);
    rectangle(x/3+800,210,y/3+800,280);
    setcolor(WHITE);
    outtextxy(x/3+810,220,"8x8");
    floodfill(x/3+810,220,WHITE);
//al treilea rand de butoane
    //tabla 9x9
    setcolor(BLUE);
    rectangle(x/3-50,325,y/3,395);
    setcolor(WHITE);
    outtextxy(x/3+30,330,"9x9");
    floodfill(x/3+30,330,WHITE);
    //tabla 10x10
    setcolor(BLUE);
    rectangle(x/3+400,325,y/3+400,395);
    setcolor(WHITE);
    outtextxy(x/3+410,330,"10x10");
    floodfill(x/3+410,330,WHITE);
    //tabla 11x11
    setcolor(BLUE);
    rectangle(x/3+800,325,y/3+800,395);
    setcolor(WHITE);
    outtextxy(x/3+810,330,"11x11");
    floodfill(x/3+810,330,WHITE);
//al patrulea rand de butoane
    //12x12
    setcolor(BLUE);
    rectangle(x/3-50,435,y/3,505);
    setcolor(WHITE);
    outtextxy(x/3+30,440,"12x12");
    floodfill(x/3+30,440,WHITE);
    //13x13
    setcolor(BLUE);
    rectangle(x/3+400,435,y/3+400,505);
    setcolor(WHITE);
    outtextxy(x/3+410,440,"13x13");
    floodfill(x/3+410,440,WHITE);
    //14x14
    setcolor(BLUE);
    rectangle(x/3+800,435,y/3+800,505);
    setcolor(WHITE);
    outtextxy(x/3+810,440,"14x14");
    floodfill(x/3+810,440,WHITE);
//al cincilea rand de butoane
    //15x15
    setcolor(BLUE);
    rectangle(x/3-50,550,y/3,620);
    setcolor(WHITE);
    outtextxy(x/3+30,560,"15x15");
    floodfill(x/3+30,560,WHITE);
    //16x16
    setcolor(BLUE);
    rectangle(x/3+400,550,y/3+400,620);
    setcolor(WHITE);
    outtextxy(x/3+410,560,"16x16");
    floodfill(x/3+410,560,WHITE);
    //17x17
    setcolor(BLUE);
    rectangle(x/3+800,550,y/3+800,620);
    setcolor(WHITE);
    outtextxy(x/3+810,560,"17x17");
    floodfill(x/3+810,560,WHITE);
//al saselea rand de butoane
    //18x18
    setcolor(BLUE);
    rectangle(x/3-50,665,y/3,735);
    setcolor(WHITE);
    outtextxy(x/3+30,670,"18x18");
    floodfill(x/3+30,670,WHITE);
    //19x19
    setcolor(BLUE);
    rectangle(x/3+400,665,y/3+400,735);
    setcolor(WHITE);
    outtextxy(x/3+410,670,"19x19");
    floodfill(x/3+410,670,WHITE);
    //20x20
    setcolor(BLUE);
    rectangle(x/3+800,665,y/3+800,735);
    setcolor(WHITE);
    outtextxy(x/3+810,670,"20x20");
    floodfill(x/3+810,670,WHITE);
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,200,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(60,710,"Meniu");
    if(limba_1==2)
outtextxy(60,710,"Menu");
    if(limba_1==3)
outtextxy(60,710,"Menu");
    if(limba_1==4)
outtextxy(60,710,"Menu");
    if(limba_1==5)
outtextxy(60,710,"Menu");
floodfill(50,710,WHITE);

      while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int xx=mousex();
            int yy=mousey();
            if(xx>=x/3-50 && xx<=y/3 && yy>=100 && yy<=165)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(3);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=100 && yy<=165)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(4);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=100 && yy<=165 )
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(5);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=210 && yy<=280)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(6);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>= 210 && yy<=280)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(7);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=210 && yy<=280)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(8);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=325 && yy<=395)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(9);
               return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=325 && yy<=395)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(10);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3 +800 && yy>=325 && yy<=395)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(11);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=435 && yy<=505)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(12);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=435 && yy<=505)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(13);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=435 && yy<=505)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(14);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=550 && yy<=620)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(15);
                return 1;
            }
            else
            if(xx>= x/3+400 && xx<=y/3+400 && yy>=550 && yy<=620)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(16);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=550 && yy<=620)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(17);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=665 && yy<=735)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(18);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=665 && yy<=735)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(19);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=665 && yy<=735)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen(20);
                return 1;
            }
            else
                if (xx>=50 && xx<=200 && yy>=700 && yy<=800)
            {
                cleardevice();
                return 1;
            }
        }
    }
}
//___________________Alege tabla pentru jucator contra calculator(modul easy)____
int alege_tabla_calculator_easy()
{   DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(limba_1==1)
    outtextxy(440,10,"Alegeti dimensiunea tablei de joc");
    else
    if(limba_1==2)
    outtextxy(200,10,"Selezione la dimensione del tabello del gioco");
    else
    if(limba_1==3)
    outtextxy(440,10,"Choose the size of the board");
    else
    if(limba_1==4)
    outtextxy(440,10,"Choisissez la taille du table de jeu");
    if(limba_1==5)
    outtextxy(200,10,"Elegid las dimensiones de la tabla de juego");
     setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2, 2,WHITE);
        settextstyle(BOLD_FONT,HORIZ_DIR,6);
    int x=screenHeight; int y=screenWidth;
//primul rand de butoane
    //tabla 3x3
    setcolor(BLUE);
    rectangle(x/3-50,100,y/3,165);
    setcolor(WHITE);
    outtextxy(x/3+30,110,"3x3");
    floodfill(x/3+30,110,WHITE);
    //tabla 4x4
    setcolor(BLUE);
    rectangle(x/3+400,100,y/3+400,165);
    setcolor(WHITE);
    outtextxy(x/3+410,110,"4x4");
    floodfill(x/3+410,110,WHITE);
    //tabla 5x5
    setcolor(BLUE);
    rectangle(x/3+800,100,y/3+800,165);
    setcolor(WHITE);
    outtextxy(x/3+810,110,"5x5");
    floodfill(x/3+810,110,WHITE);
//al doilea rand de butoane
    //tabla 6x6
    setcolor(BLUE);
    rectangle(x/3-50,210,y/3,280);
    setcolor(WHITE);
    outtextxy(x/3+30,220,"6x6");
    floodfill(x/3+30,220,WHITE);
    //tabla 7x7
    setcolor(BLUE);
    rectangle(x/3+400,210,y/3+400,280);
    setcolor(WHITE);
    outtextxy(x/3+410,220,"7x7");
    floodfill(x/3+410,220,WHITE);
    //tabla 8x8
    setcolor(BLUE);
    rectangle(x/3+800,210,y/3+800,280);
    setcolor(WHITE);
    outtextxy(x/3+810,220,"8x8");
    floodfill(x/3+810,220,WHITE);
//al treilea rand de butoane
    //tabla 9x9
    setcolor(BLUE);
    rectangle(x/3-50,325,y/3,395);
    setcolor(WHITE);
    outtextxy(x/3+30,330,"9x9");
    floodfill(x/3+30,330,WHITE);
    //tabla 10x10
    setcolor(BLUE);
    rectangle(x/3+400,325,y/3+400,395);
    setcolor(WHITE);
    outtextxy(x/3+410,330,"10x10");
    floodfill(x/3+410,330,WHITE);
    //tabla 11x11
    setcolor(BLUE);
    rectangle(x/3+800,325,y/3+800,395);
    setcolor(WHITE);
    outtextxy(x/3+810,330,"11x11");
    floodfill(x/3+810,330,WHITE);
//al patrulea rand de butoane
    //12x12
    setcolor(BLUE);
    rectangle(x/3-50,435,y/3,505);
    setcolor(WHITE);
    outtextxy(x/3+30,440,"12x12");
    floodfill(x/3+30,440,WHITE);
    //13x13
    setcolor(BLUE);
    rectangle(x/3+400,435,y/3+400,505);
    setcolor(WHITE);
    outtextxy(x/3+410,440,"13x13");
    floodfill(x/3+410,440,WHITE);
    //14x14
    setcolor(BLUE);
    rectangle(x/3+800,435,y/3+800,505);
    setcolor(WHITE);
    outtextxy(x/3+810,440,"14x14");
    floodfill(x/3+810,440,WHITE);
//al cincilea rand de butoane
    //15x15
    setcolor(BLUE);
    rectangle(x/3-50,550,y/3,620);
    setcolor(WHITE);
    outtextxy(x/3+30,560,"15x15");
    floodfill(x/3+30,560,WHITE);
    //16x16
    setcolor(BLUE);
    rectangle(x/3+400,550,y/3+400,620);
    setcolor(WHITE);
    outtextxy(x/3+410,560,"16x16");
    floodfill(x/3+410,560,WHITE);
    //17x17
    setcolor(BLUE);
    rectangle(x/3+800,550,y/3+800,620);
    setcolor(WHITE);
    outtextxy(x/3+810,560,"17x17");
    floodfill(x/3+810,560,WHITE);
//al saselea rand de butoane
    //18x18
    setcolor(BLUE);
    rectangle(x/3-50,665,y/3,735);
    setcolor(WHITE);
    outtextxy(x/3+30,670,"18x18");
    floodfill(x/3+30,670,WHITE);
    //19x19
    setcolor(BLUE);
    rectangle(x/3+400,665,y/3+400,735);
    setcolor(WHITE);
    outtextxy(x/3+410,670,"19x19");
    floodfill(x/3+410,670,WHITE);
    //20x20
    setcolor(BLUE);
    rectangle(x/3+800,665,y/3+800,735);
    setcolor(WHITE);
    outtextxy(x/3+810,670,"20x20");
    floodfill(x/3+810,670,WHITE);
     settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,200,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(60,710,"Meniu");
    if(limba_1==2)
outtextxy(60,710,"Menu");
    if(limba_1==3)
outtextxy(60,710,"Menu");
    if(limba_1==4)
outtextxy(60,710,"Menu");
    if(limba_1==5)
outtextxy(60,710,"Menu");
floodfill(50,710,WHITE);



      while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int xx=mousex();
            int yy=mousey();
            if (sunet_1==2)
             {
                 Beep(300,400);
                 Beep(450,400);
             }
         else if (sunet_1==3)
             {
                 Beep(230,400);
                 Beep(520,400);
             }
        else if (sunet_1==4)
           Beep(0,0);
         else
             {
                 Beep(200,400);
                 Beep(300,350);
             }
            if(xx>=x/3-50 && xx<=y/3 && yy>=100 && yy<=165)
            {
                cleardevice();
                desen_jucator_calculator_easy(3);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=100 && yy<=165)
            {
                cleardevice();
                desen_jucator_calculator_easy(4);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=100 && yy<=165 )
            {
                cleardevice();
                desen_jucator_calculator_easy(5);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=210 && yy<=280)
            {
                cleardevice();
                desen_jucator_calculator_easy(6);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>= 210 && yy<=280)
            {
                cleardevice();
                desen_jucator_calculator_easy(7);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=210 && yy<=280)
            {
                cleardevice();
                desen_jucator_calculator_easy(8);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=325 && yy<=395)
            {
                cleardevice();
                desen_jucator_calculator_easy(9);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=325 && yy<=395)
            {
                cleardevice();
                desen_jucator_calculator_easy(10);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3 +800 && yy>=325 && yy<=395)
            {
                cleardevice();
                desen_jucator_calculator_easy(11);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=435 && yy<=505)
            {
                cleardevice();
                desen_jucator_calculator_easy(12);
                return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=435 && yy<=505)
            {
                cleardevice();
                desen_jucator_calculator_easy(13);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=435 && yy<=505)
            {
                cleardevice();
                desen_jucator_calculator_easy(14);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=550 && yy<=620)
            {
                cleardevice();
                desen_jucator_calculator_easy(15);
                return 1;
            }
            else
            if(xx>= x/3+400 && xx<=y/3+400 && yy>=550 && yy<=620)
            {
                cleardevice();
                desen_jucator_calculator_easy(16);
                return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=550 && yy<=620)
            {
                cleardevice();
                desen_jucator_calculator_easy(17);
                return 1;
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=665 && yy<=735)
            {
                cleardevice();
                desen_jucator_calculator_easy(18);
               return 1;
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=665 && yy<=735)
            {
                cleardevice();
                desen_jucator_calculator_easy(19);
               return 1;
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=665 && yy<=735)
            {
                cleardevice();
                desen_jucator_calculator_easy(20);
                return 1;
            }
           else
            if (xx>=50 && xx<=200 && yy>=700 && yy<=800)
           {
               cleardevice();
               return 1;
           }

        }
    }

}
int alege_tabla_calculator_hard()
{   DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(limba_1==1)
    outtextxy(440,10,"Alegeti dimensiunea tablei de joc");
    else
    if(limba_1==2)
    outtextxy(200,10,"Selezione la dimensione del tabello del gioco");
    else
    if(limba_1==3)
    outtextxy(440,10,"Choose the size of the board");
    else
    if(limba_1==4)
    outtextxy(440,10,"Choisissez la taille du table de jeu");
    if(limba_1==5)
    outtextxy(200,10,"Elegid las dimensiones de la tabla de juego");
     setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2, 2,WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    int x=screenHeight; int y=screenWidth;
//primul rand de butoane
    //tabla 3x3
    setcolor(BLUE);
    rectangle(x/3-50,100,y/3,165);
    setcolor(WHITE);
    outtextxy(x/3+30,110,"3x3");
    floodfill(x/3+30,110,WHITE);
    //tabla 4x4
    setcolor(BLUE);
    rectangle(x/3+400,100,y/3+400,165);
    setcolor(WHITE);
    outtextxy(x/3+410,110,"4x4");
    floodfill(x/3+410,110,WHITE);
    //tabla 5x5
    setcolor(BLUE);
    rectangle(x/3+800,100,y/3+800,165);
    setcolor(WHITE);
    outtextxy(x/3+810,110,"5x5");
    floodfill(x/3+810,110,WHITE);
//al doilea rand de butoane
    //tabla 6x6
    setcolor(BLUE);
    rectangle(x/3-50,210,y/3,280);
    setcolor(WHITE);
    outtextxy(x/3+30,220,"6x6");
    floodfill(x/3+30,220,WHITE);
    //tabla 7x7
    setcolor(BLUE);
    rectangle(x/3+400,210,y/3+400,280);
    setcolor(WHITE);
    outtextxy(x/3+410,220,"7x7");
    floodfill(x/3+410,220,WHITE);
    //tabla 8x8
    setcolor(BLUE);
    rectangle(x/3+800,210,y/3+800,280);
    setcolor(WHITE);
    outtextxy(x/3+810,220,"8x8");
    floodfill(x/3+810,220,WHITE);
//al treilea rand de butoane
    //tabla 9x9
    setcolor(BLUE);
    rectangle(x/3-50,325,y/3,395);
    setcolor(WHITE);
    outtextxy(x/3+30,330,"9x9");
    floodfill(x/3+30,330,WHITE);
    //tabla 10x10
    setcolor(BLUE);
    rectangle(x/3+400,325,y/3+400,395);
    setcolor(WHITE);
    outtextxy(x/3+410,330,"10x10");
    floodfill(x/3+410,330,WHITE);
    //tabla 11x11
    setcolor(BLUE);
    rectangle(x/3+800,325,y/3+800,395);
    setcolor(WHITE);
    outtextxy(x/3+810,330,"11x11");
    floodfill(x/3+810,330,WHITE);
//al patrulea rand de butoane
    //12x12
    setcolor(BLUE);
    rectangle(x/3-50,435,y/3,505);
    setcolor(WHITE);
    outtextxy(x/3+30,440,"12x12");
    floodfill(x/3+30,440,WHITE);
    //13x13
    setcolor(BLUE);
    rectangle(x/3+400,435,y/3+400,505);
    setcolor(WHITE);
    outtextxy(x/3+410,440,"13x13");
    floodfill(x/3+410,440,WHITE);
    //14x14
    setcolor(BLUE);
    rectangle(x/3+800,435,y/3+800,505);
    setcolor(WHITE);
    outtextxy(x/3+810,440,"14x14");
    floodfill(x/3+810,440,WHITE);
//al cincilea rand de butoane
    //15x15
    setcolor(BLUE);
    rectangle(x/3-50,550,y/3,620);
    setcolor(WHITE);
    outtextxy(x/3+30,560,"15x15");
    floodfill(x/3+30,560,WHITE);
    //16x16
    setcolor(BLUE);
    rectangle(x/3+400,550,y/3+400,620);
    setcolor(WHITE);
    outtextxy(x/3+410,560,"16x16");
    floodfill(x/3+410,560,WHITE);
    //17x17
    setcolor(BLUE);
    rectangle(x/3+800,550,y/3+800,620);
    setcolor(WHITE);
    outtextxy(x/3+810,560,"17x17");
    floodfill(x/3+810,560,WHITE);
//al saselea rand de butoane
    //18x18
    setcolor(BLUE);
    rectangle(x/3-50,665,y/3,735);
    setcolor(WHITE);
    outtextxy(x/3+30,670,"18x18");
    floodfill(x/3+30,670,WHITE);
    //19x19
    setcolor(BLUE);
    rectangle(x/3+400,665,y/3+400,735);
    setcolor(WHITE);
    outtextxy(x/3+410,670,"19x19");
    floodfill(x/3+410,670,WHITE);
    //20x20
    setcolor(BLUE);
    rectangle(x/3+800,665,y/3+800,735);
    setcolor(WHITE);
    outtextxy(x/3+810,670,"20x20");
    floodfill(x/3+810,670,WHITE);
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,200,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(60,710,"Meniu");
    if(limba_1==2)
outtextxy(60,710,"Menu");
    if(limba_1==3)
outtextxy(60,710,"Menu");
    if(limba_1==4)
outtextxy(60,710,"Menu");
    if(limba_1==5)
outtextxy(60,710,"Menu");
floodfill(50,710,WHITE);



      while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int xx=mousex();
            int yy=mousey();
            if (sunet_1==2)
             Beep(350, 700);
         else if (sunet_1==3)
             Beep(290, 750);
        else if (sunet_1==4)
           Beep(0,0);
         else
             Beep(300, 700);
            if(xx>=x/3-50 && xx<=y/3 && yy>=100 && yy<=165)
            {
                cleardevice();
                desen_jucator_calculator_hard(3);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=100 && yy<=165)
            {
                cleardevice();
                desen_jucator_calculator_hard(4);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=100 && yy<=165 )
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(5);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=210 && yy<=280)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(6);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>= 210 && yy<=280)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(7);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=210 && yy<=280)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(8);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=325 && yy<=395)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(9);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=325 && yy<=395)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(10);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+800 && xx<=y/3 +800 && yy>=325 && yy<=395)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(11);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=435 && yy<=505)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(12);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=435 && yy<=505)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(13);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=435 && yy<=505)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(14);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=550 && yy<=620)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(15);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>= x/3+400 && xx<=y/3+400 && yy>=550 && yy<=620)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(16);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=550 && yy<=620)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(17);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3-50 && xx<=y/3 && yy>=665 && yy<=735)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(18);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+400 && xx<=y/3+400 && yy>=665 && yy<=735)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(19);
                alege_tabla_calculator_hard();
            }
            else
            if(xx>=x/3+800 && xx<=y/3+800 && yy>=665 && yy<=735)
            {//clearmouseclick(WM_LBUTTONDOWN);
                cleardevice();
                desen_jucator_calculator_hard(20);
                alege_tabla_calculator_hard();
            }
       else
        if (xx>=50 && xx<=200 && yy>=700 && yy<=800)
       {
        cleardevice();
        return 1;
       }
        }
    }

}
int tutorial_1()
{
    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor",-2,-3);
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2,2,WHITE);
    int i,j;
    //desenez tabla
    /*for(i=1;i<=6;++i)
    for(j=1;j<=6;++j)
    TablaDeJoc[i][j]=0;*/
    width=800; height=800; latura=width/6;
   sus=(getmaxy()-width)/2; stanga=(getmaxx()-height)/2;

 for (i=1; i<=6; i++)
       for (j=1; j<=6; j++)
           rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
           delay(1000);
           deseneazaPiesa(1,4,1,4);
           delay(900);
           deseneazaPiesa(6,6,2,6);
           delay(900);
           deseneazaPiesa(2,3,1,6);
           delay(900);
           deseneazaPiesa(6,1,2,6);
           delay(900);
           deseneazaPiesa(2,5,1,6);
           delay(900);
           deseneazaPiesa(1,1,2,6);
           delay(900);
           deseneazaPiesa(3,4,1,6);
           delay(1700);
          fereastra_pierzator(1);


}
int tutorial_2()
{
    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor",-2,-3);
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2,2,WHITE);
    int i,j;
    //desenez tabla
    /*for(i=1;i<=6;++i)
    for(j=1;j<=6;++j)
    TablaDeJoc[i][j]=0;*/
    width=800; height=800; latura=width/8;
   sus=(getmaxy()-width)/2; stanga=(getmaxx()-height)/2;

 for (i=1; i<=8; i++)
       for (j=1; j<=8; j++)
           rectangle(stanga+latura*(i-1),sus+latura*(j-1),stanga+latura*i,sus+latura*j);
           delay(1000);
           deseneazaPiesa(1,3,1,8);
           delay(900);
           deseneazaPiesa(6,6,2,8);
           delay(900);
           deseneazaPiesa(2,6,1,8);
           delay(900);
           deseneazaPiesa(6,1,2,8);
           delay(900);
           deseneazaPiesa(4,2,1,8);
           delay(900);
           deseneazaPiesa(1,1,2,8);
           delay(900);
           deseneazaPiesa(5,5,1,8);
           delay(1700);
           fereastra_pierzator(1);


}
int instructiuni()
{


    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor",-2,-3);
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2, 2,WHITE);
    if (limba_1==1)
    {
        outtextxy(440, 100, "INSTRUCTIUNI");
        setcolor(WHITE);
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(65, 250,"Fiind un joc de strategie,fiecare jucator pune pe rand,un pion propriu intr-o" );
        outtextxy(10, 300,"casuta libera a tablei, cautand sa evite formarea unui patrat. Patratul format");
        outtextxy(10, 350,"de unul dintre jucatori poate fi de orice marime si in orice pozitie (paralele");
        outtextxy(10, 400,"sau nu cu axele Ox, Oy). Este clar ca jocul se poate termina intotdeauna.");
        outtextxy(10, 450, "Insa remiza se poate realiza doar pe table mai mici de 7x7.");
        outtextxy(10,500,"Succes");
        setcolor(BLUE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        rectangle(90,600, 300,650);
        setcolor(WHITE);
        outtextxy(90, 610, "Inapoi");
        floodfill(90,610, WHITE);
    }
    if (limba_1==3)
    {
        outtextxy(440, 100, "INSTRUCTIONS");
        setcolor(WHITE);
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(70, 250, " Each player inserts in turn his own mark in a free space of the grid," );
        outtextxy(10, 300,"avoiding making a square. The square made by one of the players can be ");
        outtextxy(10, 350,"of any size and in any position (parallel or not with Ox and Oy axis).");
        outtextxy(10, 400,"It is clear that game could be finished always. But the draw is");
        outtextxy(10, 450, "possible only on grids less than 7x7.");
        outtextxy(10,500,"Success");
        setcolor(BLUE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        rectangle(90,600, 300,650);
        setcolor(WHITE);
        outtextxy(90, 610, "Back");
        floodfill(90,610, WHITE);
    }
    if (limba_1==2)
    {
        outtextxy(440, 100, "INSTRUZIONE");
        setcolor(WHITE);
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(50, 250, "Qualsiasi giocatore mette un pedone proprio in una casella libera della" );
        outtextxy(10, 300,"libera della scacchiera, cercando di evitare la formazione di un quadrato.");
        outtextxy(10, 350,"Il quadrato formato da un giocatore, puo essere di qualsiasi dimensione(parallelismi");
        outtextxy(10, 400,"o no senza Ox, Oy). E chiaro che il gioco finisce sempre. Ma il pareggio si puo");
        outtextxy(10, 450,"fare solo sui tabelli piu piccoli da 7x7.");
        outtextxy(10,500,"Successo.");
        setcolor(BLUE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        rectangle(90,600, 300,650);
        setcolor(WHITE);
        outtextxy(90, 610, "Indietro");
        floodfill(90,610, WHITE);
    }
    if (limba_1==4)
    {
        outtextxy(440, 100, "INSTRUCTIONS");
        setcolor(WHITE);
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(70, 250, " Chaque joeur place son propre pion dans une case libre du tableau, en" );
        outtextxy(10, 300,"cherchant eviter la formation d'un carre. Le carre formee par l'un des joeurs ");
        outtextxy(10, 350,"peut etre de n'importe quelle position(en parallele ou non avec les axes Ox,Oy)");
        outtextxy(10, 400,"Il est clair que le jeu peut tojours terminer. L'egalite ne peut etre faite que sur");
        outtextxy(10, 450, "des tables que avec moindre 7x7.");
        outtextxy(10,500,"Succes");
        setcolor(BLUE);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        rectangle(90,600, 300,650);
        setcolor(WHITE);
        outtextxy(90, 610, "Revenir");
        floodfill(90,610, WHITE);
    }
    if (limba_1==5)
    {
        outtextxy(440, 100, "INSTRUCCIONES");
        setcolor(WHITE);
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(50, 250, "Cada jugador pone uno a la vez, un peon proprio en una casilla libre de" );
        outtextxy(10, 300,"la tabla, libre de la tabla, buscando evitar creacion de un cuadrado.");
        outtextxy(10, 350,"El cuadrado formado por no de los jugadores puede tener cualquier tamano");
        outtextxy(10, 400,"y posicion(paralelos o formado por no con los ejes Ox,Oy). Esta claro que el");
        outtextxy(10, 450,"juego puede termina siempre. Pero el empate se puede realizar solo en tablas");
        outtextxy(10,500,"mas pequenas que 7x7.");
        outtextxy(10,500,"Suerte");
        setcolor(BLUE);
        rectangle(90,600, 300,650);
        settextstyle(BOLD_FONT, HORIZ_DIR, 4);
        setcolor(WHITE);
        outtextxy(90, 610, "Volver");
        floodfill(90,610, WHITE);
    }
    setcolor(MAGENTA);
    rectangle(850,600,1000,650);
    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(860,610,"TUTORIAL");
    floodfill(860,610,WHITE);
    setcolor(WHITE);
    rectangle(1020,600,1045,650);
    setcolor(WHITE);
    outtextxy(1025,610,"1");
    floodfill(1025,610,WHITE);
    setcolor(WHITE);
    rectangle(1060,600,1085,650);
    setcolor(WHITE);
    outtextxy(1065,610,"2");
    floodfill(1065,610,WHITE);

    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int xx=mousex();
            int yy=mousey();
            if(xx>=90 && xx<=300 && yy>=600 && yy<=650 )
            {
                return 1;
            }
            else
            if(xx>=1020 && xx<=1045 && yy>=600 && yy<=650)
            {
                tutorial_1();
                return 1;
            }
            else
            if(xx>=1060 && xx<=1085 && yy>=600 && yy<=650)
            {tutorial_2();
                return 1;
            }
        }
    }


}


int alege_dificultate()
{
    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
    settextstyle(BOLD_FONT,HORIZ_DIR, 6);
if(limba_1==1)
    outtextxy(440,10,"Alege dificultatea jocului");
if(limba_1==2)
    outtextxy(440,10,"Scegli la difficolta del gioco");
if(limba_1==3)
    outtextxy(440,10,"Choose the level of difficulty");
if(limba_1==4)
    outtextxy(440,10,"Choisissez le niveau de difficulte");
if(limba_1==5)
    outtextxy(440,10,"Elige el nivel de dificultad");

settextstyle(EUROPEAN_FONT, HORIZ_DIR,7 );
setfillstyle(INTERLEAVE_FILL ,MAGENTA);
floodfill(2, 2,WHITE);
    //butonul de easy
setcolor(BLUE);
rectangle(440,200,800,350);
setcolor(WHITE);
if(limba_1==1)
    outtextxy(450,210,"USOR");
if(limba_1==2)
    outtextxy(450,210,"FACILE");
if(limba_1==3)
    outtextxy(450,210,"EASY");
if(limba_1==4)
    outtextxy(450,210,"FACILE");
if(limba_1==5)
    outtextxy(450,210,"FACIL");
    floodfill(450,210,WHITE);
    //butonul de hard
    setcolor( BLUE);
    rectangle(440,400,800,550);
    setcolor( WHITE);
if(limba_1==1)
    outtextxy(450,410,"GREU");
if(limba_1==2)
    outtextxy(450,410,"DIFFICILE");
if(limba_1==3)
    outtextxy(450,410,"HARD");
if(limba_1==4)
    outtextxy(450,410,"DUR");
if(limba_1==5)
    outtextxy(450,410,"DIFICIL");
    floodfill(450,410,WHITE);
settextstyle(BOLD_FONT,HORIZ_DIR,5);
setcolor(BLUE);
rectangle(50,700,650,800);
setcolor(WHITE);
    if(limba_1==1)
outtextxy(60,710,"Inapoi la meniu");
    if(limba_1==2)
outtextxy(60,710,"Torna al menu");
    if(limba_1==3)
outtextxy(60,710,"Back to menu");
    if(limba_1==4)
outtextxy(60,710,"Revenir au menu");
    if(limba_1==5)
outtextxy(60,710,"Volver al menu");
floodfill(50,710,WHITE);
    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int x=mousex(); int y=mousey();
            if (sunet_1==2)
         {

             Beep(300,400);
             Beep(450,400);
         }
         else if (sunet_1==3)
         {

             Beep(230,400);
             Beep(520,400);

         }
        else if (sunet_1==4)
           Beep(0,0);
         else
         {

             Beep(200,400);
             Beep(300,350);
         }
            if(x>=440 && x<=800 && y>=200 && y<=350)
            {
                cleardevice();

                alege_tabla_calculator_easy();
                return 1;
            }
            if(x>=440 && x<=800 && y>=400 && y<=550)
            {
                cleardevice();
                //prioritate=alege_ordine_jucatori();
                alege_tabla_calculator_hard();
                return 1;
            }
            if (x>=50 && x<=650 && y>=700 && y<=800)
            {
                cleardevice();
                return 1;
            }
        }
    }


}
//pagina cu setarile pentru limba
int limba()
{
    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor",-2,-3);
    settextstyle(BOLD_FONT,HORIZ_DIR, 6);
    setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2, 2,WHITE);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR, 5);
    setcolor(BLUE);
    rectangle(440, 200, 750, 260);
    setcolor(WHITE);
    outtextxy(445, 210, "ROMANA");
    floodfill(445,210, WHITE);
    setcolor(BLUE);
    rectangle(440, 280, 750, 340);
    setcolor(WHITE);
    outtextxy(445, 290, "ITALIANO");
    floodfill(445,290, WHITE);
    setcolor(BLUE);
    rectangle(440, 360, 750, 420);
    setcolor(WHITE);
    outtextxy(445, 370, "ENGLISH");
    floodfill(445,370, WHITE);
    setcolor(BLUE);
    rectangle(440, 450, 750, 510);
    setcolor(WHITE);
    outtextxy(445, 460, "FRANCAIS");
    floodfill(445,460, WHITE);
    setcolor(BLUE);
    rectangle(440,540,750,600);
    setcolor(WHITE);
    outtextxy(445,550,"ESPANOL");
    floodfill(445,550,WHITE);
    while (1)
{        if (ismouseclick(WM_MOUSEMOVE))
{
    clearmouseclick(WM_MOUSEMOVE);
    int x=mousex();
    int y= mousey();
    if (x<=750 && x>=440 && y>=200 && y<=260)
               {
                bar(790, 200, 880, 250);
                setfillstyle(SOLID_FILL,BLUE);
                bar(790,200,820,250);
                setfillstyle(SOLID_FILL,YELLOW);
                bar(820,200,850,250);
                setfillstyle(SOLID_FILL,RED);
                bar(850,200,880,250);
                }
            else if (x<=750 && x>= 440 && y<=340 && y>=280)
            {
                bar(790, 280, 880, 330);
                setfillstyle(SOLID_FILL,GREEN);
                bar(790,280,820,330);
                setfillstyle(SOLID_FILL,WHITE);
                bar(820,280,850,330);
                setfillstyle(SOLID_FILL,RED);
                bar(850,280,880,330);
            }
            else if (x<=750 && x>=440 && y<=420 && y>=360)
            {
               setfillstyle(SOLID_FILL,BLUE);
               bar(790, 360, 870, 410);
              //diagonale de la stanga la dreapta
              setcolor(WHITE);
               line(800,360, 870, 400 );
               line(799, 360,870, 401);
               line(798, 360,870, 402);
               line(797, 360,870, 403);
               line(796, 360,870, 404);
               line(795, 360,870, 405);
               line(790,370, 860, 410 );
               line(790,369, 860, 409 );
               line(790,368, 860, 408 );
               setcolor(RED);
               line(794, 360, 870, 405);
               line(793, 360, 870, 406);
               line(792, 360, 870, 407);
               line(791, 360, 870, 408);
               line(790, 360, 870, 409);
               line(790, 360, 870, 410);
               line(790,367, 860, 407 );
               line(790,366, 860, 406 );
               line(790,365, 860, 405 );
               line(790,364, 860, 404 );
               line(790,363, 860, 403 );
               line(790,362, 860, 402 );
               line(790,361, 860, 401 );
               line(790,360, 860, 400 );
               line(866, 360, 790, 406);
               line(867, 360, 790, 407);
                line(868, 360, 790, 408);
                line(869, 360, 790, 409);
                line(870, 360, 790, 410);
                line(870, 367, 800, 407);
                line(870, 366, 800, 406);
                line(870, 365, 800, 405);
                line(870, 364, 800, 404);
                line(870, 363, 800, 403);
                line(870, 362, 800, 402);
                line(870, 361, 800, 401);
                line(870, 360, 800, 410);
               setcolor(WHITE);
               line (860, 360, 790, 400);
               line (861,360, 790, 401);
               line (862,360, 790, 402);
               line (863,360, 790, 403);
               line (864,360, 790, 404);
               line (865,360, 790, 405);
               line(870,370, 800, 410);
               line(870, 369, 800, 409);
               line(870, 368, 800, 408);
               setfillstyle(SOLID_FILL,WHITE);
               bar(820,360, 840, 410);
               bar(790, 375, 870, 395);
               setfillstyle(SOLID_FILL,RED);
               bar(825, 360, 835, 410);
               bar(790, 380, 870, 390);
            }
            else if (x<=750 && x>=440 && y<=510 && y>=450)
            {
                bar(790, 450, 880, 500);
                setfillstyle(SOLID_FILL, BLUE);
                bar (790,450, 820, 500 );
                setfillstyle(SOLID_FILL, WHITE);
                bar(820, 450, 850, 500);
                setfillstyle(SOLID_FILL, RED);
                bar(850, 450, 880, 500);
            }
            else if(x>=440 && x<=750 && y>=540 && y<=600)
            {
                setfillstyle(SOLID_FILL, RED);
                bar(790, 540, 870, 555);
                bar(790, 575, 870, 590);
                setfillstyle(SOLID_FILL, YELLOW);
                bar(790, 550,870, 580 );
            }
}
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int x= mousex();
            int y= mousey();
            Beep(300, 700);
            Beep(400, 500);
            if (x<=750 && x>=440 && y>=200 && y<=260)
            {
                cleardevice();
                return 1;
            }
            else if (x<=750 && x>= 440 && y<=340 && y>=280)
            {
                cleardevice();
                return 2;
            }
            else if (x<=750 && x>=440 && y<=420 && y>=360)
            {
                cleardevice();
                return 3;
            }
            else if (x<=750 && x>=440 && y<=510 && y>=450)
            {
                cleardevice();
                return 4;
            }
            else if(x>=440 && x<=750 && y>=540 && y<=600)
            {
                cleardevice();
                return 5;
            }
        }
    }
}
void pagina_start()
{
    DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);
    PlaySound(TEXT("musica.wav"),NULL,SND_ASYNC);
    initwindow(screenWidth, screenHeight, "Jocul evitarii patratelor", -2, -3);
    settextstyle(BOLD_FONT,HORIZ_DIR, 6);
    if(limba_1==1)
    outtextxy(440,10,"JOCUL EVITARII PATRATELOR");
    else
    if(limba_1==2)
    outtextxy(440,10,"IL GIOCO DI EVITARE I QUADRATI");
    else
    if(limba_1==3)
    outtextxy(440,10,"THE GAME OF AVOIDING SQUARES");
    else
    if(limba_1==4)
    outtextxy(440,10,"LE JEU D'EVITER LES CARRES");
     else   if(limba_1==5)
    outtextxy(440,10,"EL JUEGO DE LA EVITACION DE LOS CUADRADOS");
    setfillstyle(INTERLEAVE_FILL ,MAGENTA);
    floodfill(2, 2,WHITE);
    //primul buton
    setcolor(BLUE);
    rectangle(500,200,1205,300);
    setcolor(WHITE);
    if(limba_1==1)
    outtextxy(510,210,"2 JUCATORI");
    else
    if(limba_1==2)
    outtextxy(510,210,"2 GIUCATORI");
    else
    if(limba_1==3)
     outtextxy(510,210,"2 PLAYERS");
    else
    if(limba_1==4)
    outtextxy(510,210,"2 JOUEURS");
   else
    if(limba_1==5)
    outtextxy(510,210,"2 JUGADORES");
    floodfill(510,210,WHITE);
    //al doilea buton
    setcolor(BLUE);
    rectangle(500,350,1330,450);
    setcolor(WHITE);
    if(limba_1==1)
    outtextxy(510,360,"JUCATOR vs CALCULATOR");
    else
    if(limba_1==2)
    outtextxy(510,360,"GIOCATORE vs COMPUTER");
    else
    if(limba_1==3)
    outtextxy(510,360,"PLAYER vs COMPUTER");
    else
    if (limba_1==4)
    outtextxy(510,360,"JOUER vs ORDINATEUR");
    else
    if (limba_1==5)
    outtextxy(510,360,"JUGADOR vs ORDENADOR");
    floodfill(510,360,WHITE);

    //al treilea buton-prezinta strategia jocului
    setcolor(BLUE);
    rectangle(500,500,1205,600);
    setcolor(WHITE);
    if(limba_1==1)
    outtextxy(510,510,"INSTRUCTIUNI");
    else
    if(limba_1==2)
    outtextxy(510,510,"INSTRUZIONE");
    else
    if(limba_1==3)
    outtextxy(510,510,"INSTRUCTIONS");
    else if (limba_1==4)
    outtextxy(510,510,"INSTRUCTIONS");
    else
    outtextxy(510,510,"INSTRUCCIONES");
    floodfill(510,510,WHITE);

    //al patrulea buton-setari pentru sunet piese
    setcolor(BLUE);
    rectangle(500,650,1205,750);
    setcolor(WHITE);
    if (limba_1==1)
    outtextxy(510,660,"SETARI");
    else if (limba_1==3)
    outtextxy(510,660,"SETTINGS");
    else if (limba_1==2)
    outtextxy(510,660,"IMPOSTAZIONI");
    else if (limba_1==4)
    outtextxy(510,660,"PARAMETRES");
    else
    outtextxy(510,660,"AJUSTES");
    floodfill(510,660,WHITE);

    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            int x=mousex(); int y=mousey();
             if (sunet_1==2)
         {

             Beep(300,400);
             Beep(450,400);
         }
         else if (sunet_1==3)
         {

             Beep(230,400);
             Beep(520,400);
         }
        else if (sunet_1==4)
           Beep(0,0);
         else
         {

             Beep(200,400);
             Beep(300,350);
         }
             if(x<=1205 && x>=500 && y<=300 && y>=200)
 {//se opreste muzica
PlaySound(NULL,NULL,SND_ASYNC);


     cleardevice();
     alege_tabla();
     pagina_start();

 }
      else
         if(x<=1330 && x>=500 && y<=450 && y>=350)
         {PlaySound(NULL,NULL,SND_ASYNC);

             cleardevice();
             alege_dificultate();
             pagina_start();

         }
         else
             if(x<=1205 && x>=500 && y<=600 && y>=500)
         {

             cleardevice();
             instructiuni();

             pagina_start();

         }
         else
            if(x>=500 && x<=1205 && y>=650 && y<=750)
         {

             cleardevice();
             setari();
             pagina_start();
         }


    }
    }
}


int main()
{


limba_1=limba(); //1-romana, 2-italiana, 3-engleza, 4-franceza, 5-spaniola
pagina_start();


   getch();
   closegraph();
   return 0;
}
