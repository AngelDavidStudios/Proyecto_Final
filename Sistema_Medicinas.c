#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

COORD coord = {0, 0};

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;

//function for auto increment customer & supplier Id.
//int Get_Clientes_Id();
//int Get_Proveedor_Id();

//Procedimiento para Menu Principal
void Welcome();
void Main_Menu();

void Proveedores();
void Clientes();
void Medicinas();
void Reporte_Menu();
void Bill();
void About();

//Diseño de menus y cajas
void Main_box();
void Box1();
void Wbox();

/* 
//Subemnu de Medicinas

void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();
void Remain();

//Subemnu de proovedores

void supp_entry();
void supp_list();
void sup_update();
void search();
void search_id();
void search_name();

//Submenu Clientes

void cust_search();
void search_cid();
void search_cname();
void cust_entry();
void cust_list();
void cust_update();

//Submenu de Reporte

void report();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();
*/


//========================= Hora & Fecha ====================
int t(void)
{

    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);

    char Fecha[70];
    char Hora[70];
    char *FormatoFecha = "%Y-%m-%d";
    char *FormatoHora = "%H:%M:%S";
    int EstructuraFecha = strftime(Fecha, sizeof Fecha, FormatoFecha, &tiempoLocal);
    int EstructuraHora = strftime(Hora, sizeof Fecha, FormatoHora, &tiempoLocal);

	gotoxy(55,46);
	    printf("FECHA: %s", Fecha);
    gotoxy(55,48);
        printf("HORA: %s", Hora);
	return 0;
}

//======================= ANIMACIONES ==========================
void Animation()
{
	for (i=45; i>=1; i--)
	{
		Sleep(30);
		gotoxy(1,i);

	}
	for (i=1; i<=20; i++)
	{

		Sleep(40);
		gotoxy(1,i);
	}
}

//========================= PANTALLA DE BIENVENIDA ==============

void Welcome()
{
 system("cls");

		Wbox();

		gotoxy(35,20);
		printf("BIENVENIDOS");

		gotoxy(38,22);
		printf("A");

		gotoxy(40,22);
		printf("LA");

		gotoxy(30,24);
		printf("COORPORACION");

		gotoxy(43,24);
		printf("UMBRELLA");
        
		gotoxy(52,45);
		printf("Loading......");

    Sleep(4000);
}

//============================ Diseño Box ==============================
void Box1()
{
	gotoxy(1,3);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,3);
		printf("%c",205);
	}

	gotoxy(80,3);
	printf("%c",187);
	gotoxy(1,3);
	for(i=4;i<10;i++)
	{
		gotoxy(1,i);
		printf("%c",186);
	}
	gotoxy(1,9);
	for(i=4;i<8;i++)
	{
		gotoxy(80,i);
		printf("%c",186);
	}
}

//============================================================================
void box()
{
   for(i=3;i<=79;i++) 	//This 'FOR' loop will print a combination of
	{
		gotoxy(i,3);    //the 79th column is reached.
		printf("%c",219);
		gotoxy(78,45);
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=3;i<=45;i++)      //This 'FOR' loop will print asterisks 'I'
	{                       //vertically till the 3th row is reached.
		gotoxy(3,i);
		printf("%c",219);
		gotoxy(79,i);
		printf("%c",219);
	}
}
void Wbox()
{
	for(i=5;i<=75;i++) 	//This 'FOR' loop will print a combination of
	{
		gotoxy(i,5);    //the 75th column is reached.
		printf("%c",219);
		gotoxy(74,40);
		printf("%c",219);
		gotoxy(i,40);
		printf("%c",219);
	}

	for(i=5;i<=40;i++)      //This 'FOR' loop will print asteriks 'I'
	{                       //vertically till the 17th row is reached.
		gotoxy(5,i);
		printf("%c",219);
		gotoxy(75,i);
		printf("%c",219);
	}
}

//===========================main ===================

int main()
{
	system("cls");

    Welcome();
    Main_Menu();
}

void Main_box()
{
	gotoxy(1,6);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,6);
		printf("%c",205);
	}

	gotoxy(80,6);
	printf("%c",187);
	gotoxy(1,6);
	for(i=5;i<35;i++)
	{
		gotoxy(1,2+i);
		printf("%c",186);
	}
	gotoxy(1,37);
	printf("%c",200);
	for(i=1;i<79;i++)
	{
		gotoxy(1+i,37);
		printf("%c",205);
	}
	gotoxy(80,37);
	printf("%c",188);
	gotoxy(80,6);
	for(i=5;i<35;i++)
	{
		gotoxy(80,2+i);
		printf("%c",186);
	}
}

void Main_Menu() {
    int Indice;
    char ch;

	do
	{
		system("cls");

		gotoxy(3,5);
		printf("[1]Proveed.");

		gotoxy(15,5);
		printf("[2]Clientes");

		gotoxy(27,5);
		printf("[3]Medicinas");

		gotoxy(40,5);
		printf("[4]Reporte");

		gotoxy(51,5);
		printf("[5]Factura");

		gotoxy(62,5);
		printf("[6]About");

		gotoxy(71,5);
		printf("[7]Salir");

		t();   //DESPLIEGUE FECHA Y HORA
		Box1();
		Main_box();
		gotoxy(20,10);
		printf("Bienvenidos al sistema de medicinas ");
		gotoxy(2,28);

		//Remain();//this function is active when medicine qty is less then 10.
		gotoxy(10,40);
		printf("Selecciona");
		gotoxy(10,42);
		printf("Uno de los numeros [N] para acceder al submenu");

		Indice=toupper(getche());
		switch(Indice)
		{
			case '1': 
                Proveedores();
			    break;
			case '2': 
                Clientes();
				break;
			case '3': 
                Medicinas();
				break;
			case '4': 
                Reporte_Menu();
				break;
			case '5': 
                Bill();
				break;
			case '6': 
                About();
				break;
			case '7': 
                gotoxy(23,20);
			    printf("Desea Salir del Sistema? Y/N :");
			    Sleep(100);
			    ch=(getche());
			    ch=toupper(ch);
			
                if(ch=='Y')
			    {
				Animation();
				system("cls");
				gotoxy(35,20);
				printf(" Por favor Espere.....");
				Sleep(2000);
				exit(0);
			    }
			    else
			    {
				Main_Menu();
			    }

			default:
			gotoxy(11,34);
			printf("Por favor solo ingresar los siguientes numeros (1,2,3,4,5,6,7).");
			getch();
		}
	}   while(Indice!='7');
}

//======================== Submenu Proveedores =============================
void Proveedores() {

}

//======================== Submenu Clientes =============================
void Clientes() {

}

//======================== Submenu Medicinas =============================
void Medicinas() {

}

//======================== Submenu Reporte =============================
void Reporte_Menu() {

}

//======================== Submenu Facturas =============================
void Bill() {

}

//======================== Submenu About =============================
void About() {
    
   int c;
   system("cls");

   do
   {

	gotoxy(28,4);

	printf("***** PROYECTO FINAL PROGRESO 3 *****");
	gotoxy(10,8);
	printf("=> Proyecto: Sistema de medicinas UMBRELLA CORP. ");
	gotoxy(10,10);
	printf("=> Integrantes: David Rueda, Sebastian Ramirez, Michael");
	gotoxy(10,12);
	printf("=> MATERIA: Programacion 1");
	gotoxy(10,14);
	printf("=> FECHA PRESENTACION: 24-1-2023");
	gotoxy(10,16);
	printf("=> VERSION: Ver 1.0.0 \n\n");
	gotoxy(10,20);
	printf("<<<<-Presiona 1 para regresar al Menu Principal->>>>");

	c = (getche());

	switch (c)
		{
			case '1':
			Animation(); 
			Main_Menu();
			gotoxy(26,24);
			puts("<<--PRESIONA SOLAMENTE LA TECLA 1 PARA REGRESAR-->>");
			getch();
		}

}   while(c != '1');

}