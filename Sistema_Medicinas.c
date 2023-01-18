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

//Funciones para Menu Principal
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


//Subemnu de Medicinas
void medi_sale();
void stock();
void medi_entry();
void medi_search();
void Remain();

//Subemnu de proovedores
void supp_entry();
void supp_list();
void sup_update();
void search();

//Submenu Clientes
void cust_search();
void cust_entry();
void cust_list();
void cust_update();

//Submenu de Reporte
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();

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

//=================================== BASES DE DATOS =========================
struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

char a[10];
struct Proveedor
{
	int supp_id;
	char supp_name[25];
	char city[20];
	char mob_no[11];
	char email[30];

};
struct Proveedor temp1;

struct Clientes
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};
struct Clientes temp_cli;
FILE *ptr1;

struct Factura
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct Factura temp_Fac;
FILE *ptrbill;

struct Reporte_Ventas
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct Reporte_Ventas Temp_ReportV;
FILE *ptrs_r;

struct Rporte_Compras
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct Rporte_Compras Temp_ReportC;
FILE *ptrp_r;

struct Reporte_Usuario
{
	char medi_id[6];
	char medir_name[20];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct Reporte_Usuario Temp_ReportUser;
FILE *ptrpr_r;

void linkfloat()
{
	float f,*p;
	p=&f;
	f=*p;
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
   for(i=3;i<=79;i++)
	{
		gotoxy(i,3);
		printf("%c",219);
		gotoxy(78,45);
		printf("%c",219);
		gotoxy(i,45);
		printf("%c",219);
	}

	for(i=3;i<=45;i++)      
	{                       
		gotoxy(3,i);
		printf("%c",219);
		gotoxy(79,i);
		printf("%c",219);
	}
}
void Wbox()
{
	for(i=5;i<=75;i++) 	
	{
		gotoxy(i,5);    
		printf("%c",219);
		gotoxy(74,40);
		printf("%c",219);
		gotoxy(i,40);
		printf("%c",219);
	}

	for(i=5;i<=40;i++)      
	{
		gotoxy(5,i);
		printf("%c",219);
		gotoxy(75,i);
		printf("%c",219);
	}
}

//=========================== Main ===================

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

		Remain();
		gotoxy(10,40);
		printf("Selecciona");
		gotoxy(10,42);
		printf("Presione uno de los numeros [N] para acceder al submenu:   ");

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

	int Index;
	do
	{
	  system("cls");

	  gotoxy(34,3);
	  printf("----------------");
	  gotoxy(35,4);
	  printf("MENU Provedores");
	  gotoxy(34,5);
	  printf("----------------");

	  gotoxy(26,11);
	  printf("[1] Agregar nuevo Proveedor");

	  gotoxy(26,15);
	  printf("[2] Actualizar Proveedor");

	  gotoxy(26,19);
	  printf("[3] Buscar Proveedor");

	  gotoxy(26,23);
	  printf("[4] Lista de Proveedores");

	  gotoxy(26,27);
	  printf("[5] Regresar al Menu Principal");
	  Main_box();

	  gotoxy(10,40);
	  printf("Presione la tecla numero para inicar la operacion:    ");


	  Index= toupper(getche());
	  switch(Index)
	  {
		case '1': 
			supp_entry();
			break;
		case '2':
			sup_update();
			break;
		case '3':
			supp_list();
			break;
		case '4':
			search();
			break;
		case '5':
			Main_Menu();
			break;
		default:
			gotoxy(11,34);
			printf("Por favor solo ingresar los siguientes numeros (1,2,3,4,5).");
			getch();
	  }
	}while(Index!='6');

}

//========================= Obtener ID Proveedor =======================
int getsupp_id()
{

 FILE *fp;
	 fp= fopen("Proveedor.dat","r");
	 if(fp==NULL)
	 {
		gotoxy(22,15);
		printf("No existen Datos.....");
		getch();
	 }
	 else
	 {
		temp1.supp_id= 1000;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.city, temp1.mob_no,temp1.email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp1.supp_id+1;
}
//======================== Submenu =============================
void supp_entry() { 	// Agregar nuevos proovedores
	
	char ch;
 	FILE *fp;
 		
		system("cls");

	   	fp=fopen("Proveedor.dat","a");
	   	if(fp==NULL)
	   	{
			printf("\n No es posible abrir el archivo!!");
			exit(0);
	   	}

		system("cls");
		t();
		box();
		gotoxy(30,8);
		printf(" Entrada Proveedores ");

		gotoxy(8,13);
		temp1.supp_id= getsupp_id();
		printf("ID PROVEEDOR : %d ",temp1.supp_id);

		gotoxy(39,13);
		printf("NOMBRE PROV: ");

		gotoxy(8,18);
		printf("CIUDAD: ");

		gotoxy(39,18);
		printf("CONTACTO NO. : ");

		gotoxy(8,23);
		printf("CORREO ELECTRONICO: ");

		gotoxy(52,13);
		gets(temp1.supp_name);

		gotoxy(16,18);
		gets(temp1.city);

		gotoxy(54,18);
		gets(temp1.mob_no);

		gotoxy(28,23);
		gets(temp1.email);

		gotoxy(21,30);
		printf("[S] GUARDAR");

		gotoxy(38,30);
		printf("[C] CANCELAR");

		gotoxy(18,36);
		printf("Presiona un tecla para ejecutar la operacion [S/C] : ");

		ch= getch();

		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);
			fprintf(fp,"\n");

			system("cls");
			gotoxy(20,20);
			printf("Proveedor agregado con exito!!!!!");
			Sleep(2000);
			ch=getche();
		}

	   fclose(fp);
}

void sup_update() {

}

void supp_list() {

}

void search() {

}

//======================== Submenu Clientes =============================
void Clientes() {

	int Index;
	do
	{
	  system("cls");

	  gotoxy(34,3);
	  printf("---------------");
	  gotoxy(35,4);
	  printf("MENU Clientes");
	  gotoxy(34,5);
	  printf("---------------");

	  gotoxy(26,11);
	  printf("[1] Agregar nuevo Cliente");

	  gotoxy(26,15);
	  printf("[2] Actualizar Cliente");

	  gotoxy(26,19);
	  printf("[3] Buscar CLientes");

	  gotoxy(26,23);
	  printf("[4] Lista de clientes");

	  gotoxy(26,27);
	  printf("[5] Regresar al Menu Principal");
	  Main_box();

	  gotoxy(10,40);
	  printf("Presione la tecla numero para inicar la operacion:    ");


	  Index= toupper(getche());
	  switch(Index)
	  {
		case '1':
			cust_entry();
			break;
		case '2':
			cust_update();
			break;
		case '3':
			cust_list();
			break;
		case '4':
			cust_search();
			break;
		case '5':
			Main_Menu();
			break;
		default:
			gotoxy(11,34);
			printf("Por favor solo ingresar los siguientes numeros (1,2,3,4,5).");
			getch();
	  }
	}while(Index!='6');

}

//======================== Submenu =============================
void cust_entry() {

}

void cust_update() {

}

void cust_list() {

}

void cust_search() {

}

//======================== Submenu Medicinas =============================
void Medicinas() {

	int Index;
	do
	{
	  system("cls");

	  gotoxy(34,3);
	  printf("---------------");
	  gotoxy(35,4);
	  printf("MENU Medicinas.");
	  gotoxy(34,5);
	  printf("---------------");

	  gotoxy(26,15);
	  printf("[1] Agregar nuevas medicinas");

	  gotoxy(26,19);
	  printf("[2] Venta Medicinas");

	  gotoxy(26,23);
	  printf("[3] Stock de medicinas");

	  gotoxy(26,27);
	  printf("[4] Buscar Medicinas");

	  gotoxy(26,31);
	  printf("[5] Regresar al Menu Principal.");
	  Main_box();

	  gotoxy(10,40);
	  printf("Presione la tecla numero para inicar la operacion:    ");


	  Index= toupper(getche());
	  switch(Index)
	  {
		case '1':
			 medi_entry();
			 break;
		case '2':
			 medi_sale();
			 break;
		case '3':
			stock();
			 break;
		case '4':
			medi_search();
			break;
		case '5':
			Main_Menu();
			break;
		default:
			gotoxy(11,34);
			printf("Por favor solo ingresar los siguientes numeros (1,2,3,4,5).");
			getch();
	  }
	} while(Index!= 6);

}
//======================== Submenus =============================

void medi_entry() {

}

void medi_sale() {

}

void stock() {

}

void medi_search(){

}

//======================Recordatorio Stock de medicinas ===============
void Remain()
{
	ptr1=fopen("Medical.dat","r");

	while((fread(&temp,sizeof(temp),1,ptr1))==1)
	{
		if(temp.quantity<10)
		{
			gotoxy(10,45);
			printf("%s : ",temp.medi_name);
			printf("Recordatorio importante: Quedan en stock 10");
		}
	}
}

//======================== Submenu Reporte =============================
void Reporte_Menu() {
	int Index;
	do
	{
	  system("cls");

	  gotoxy(34,3);
	  printf("---------------");
	  gotoxy(35,4);
	  printf("MENU Reporte");
	  gotoxy(34,5);
	  printf("---------------");

	  gotoxy(26,12);
	  printf("[1] Agregar nuevo Reporte");

	  gotoxy(26,16);
	  printf("[2] Reporte de ventas");

	  gotoxy(26,20);
	  printf("[3] Reporte del usuario");

	  gotoxy(26,24);
	  printf("[4] Reporte de ventas diarias");

	  gotoxy(26,28);
	  printf("[5] Reporte de compras diarias");

	  gotoxy(26,32);
	  printf("[6] Regresar el Menu Principal");
	  Main_box();

	  gotoxy(10,40);
	  printf("Presione la tecla numero para inicar la operacion:    ");


	  Index= toupper(getche());
	  switch(Index)
	  {
		case '1':
			pur_rpt();
			break;
		case '2':
			sale_rpt();
			break;
		case '3':
			sale_rpt_daily();
			break;
		case '4':
			profit_rpt();
			break;
		case '5':
			pur_rpt_daily();
			break;
		case '6':
			Main_Menu();
			break;
		default:
			gotoxy(11,34);
			printf("Por favor solo ingresar los siguientes numeros (1,2,3,4,5,6).");
			getch();
	  }
	}while(Index!='7');
}

//======================== Submenu =============================
void pur_rpt() {

}

void sale_rpt() {

}

void sale_rpt_daily() {

}

void profit_rpt() {

}

void pur_rpt_daily() {

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
	printf("=> Integrantes: David Rueda, Sebastian Ramirez, Michael, Joel Ibarra");
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
			Main_Menu();
			gotoxy(26,24);
			puts("<<--PRESIONA SOLAMENTE LA TECLA 1 PARA REGRESAR-->>");
			getch();
		}

}   while(c != '1');

}