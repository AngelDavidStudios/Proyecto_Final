#include<stdio.h>
#include<conio.h>
//#include<string.h>
#include<math.h>
//#include<dos.h>
#include<time.h>
//#include<ctype.h>
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

int getcust_id();
int getsupp_id();
int getmedic_id();

//Tiempo Local
void t();

//Funciones para Menu Principal
void Welcome();
void Main_Menu();

void Proveedores();
void Clientes();
void Medicinas();
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
//void update_stock();
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
void cust_entry();
void cust_list();
void cust_update();
void search_cid();
void search_cname();

//========================= Hora & Fecha ====================
void t()
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
}

//=================================== BASES DE DATOS =========================
struct medical
{
	int id;
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
//struct medical x[20];
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
	int billno;
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;

};
struct Factura temp_Fac;
FILE *ptrbill;

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
void lbox()
{
	gotoxy(25,6);
	printf("%c",201);
	for(i=26;i<55;i++)
	{
		gotoxy(i,6);
		printf("%c",205);
	}
	gotoxy(55,6);
	printf("%c",187);
	gotoxy(25,6);
	for(i=6;i<8;i++)
	{
		gotoxy(25,i+1);
		printf("%c",186);
	}
	gotoxy(25,9);
	printf("%c",200);
	for(i=26;i<55;i++)
	{
		gotoxy(i,9);
		printf("%c",205);
	}
	gotoxy(55,9);
	printf("%c",188);
	gotoxy(55,6);
	for(i=6;i<8;i++)
	{
		gotoxy(55,i+1);
		printf("%c",186);
	}
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

//=========================== MAIN ===================
int main()
{
	system("cls");

    Welcome();
    Main_Menu();
}

void Main_Menu() {
    int Indice;
    char ch;

	do
	{
		system("cls");

		gotoxy(4,5);
		printf("[1] Proveed.");

		gotoxy(17,5);
		printf("[2] Clientes");

		gotoxy(31,5);
		printf("[3] Medicinas");

		gotoxy(46,5);
		printf("[4] Factura");

		gotoxy(59,5);
		printf("[5] About");

		gotoxy(70,5);
		printf("[6] Salir");

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
                Bill();
				break;
			case '5': 
                About();
				break;
			case '6': 
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
			printf("Por favor solo ingresar los siguientes numeros (1,2,3,4,5,6).");
			getch();
		}
	}   while(Indice!='6');
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
	  printf("[3] Lista de Proveedores");

	  gotoxy(26,23);
	  printf("[4] Buscar Proveedores");

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
		lbox();
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

			system("cls");
			gotoxy(20,20);
			printf("Proveedor agregado con exito!!!!!");
			Sleep(2000);
			ch=getche();
		}

	   fclose(fp);
}

void sup_update() {

  	char Index;
  	int sid;
  	FILE *Temporal;
	FILE *Original;

  	system("cls");
  	box();

	   Original= fopen("Proveedor.dat","r+");
	   if(Original==NULL )
	   {
		printf("\n\t Error, no se puede abrir este archivo!! ");
		exit(0);
	   }

	   lbox();
	   gotoxy(30,8);
	   printf(" Modificando Proveeedor ");

	   gotoxy(12,13);
	   printf("Introduzcca el ID del Proveedor:  ");
	   scanf("%d",&sid);

	    gotoxy(12,15);
		Temporal= fopen("Temp.dat","w");
		if(Temporal==NULL)
		{
			printf("Este archivo no se puede abrir");
			exit(1);
		}
		else
		{
			while(fscanf(Original,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city,temp1.email)!=EOF)
			{
				if(temp1.supp_id==sid)
				{
					gotoxy(18,17);
					printf(" Registro existente  ");

					gotoxy(10,19);
					printf("%d\t %s \t%s \t%s \t%s",temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city,temp1.email);

					gotoxy(12,22);
					printf("Introduzca un nuevo nombre       : ");
					gets(temp1.supp_name);

					gotoxy(12,24);
					printf("Introduzca el numero de telefono  : ");
					gets(temp1.mob_no);

					gotoxy(12,26);
					printf("Introduzca la ciudad       : ");
					gets(temp1.city);

					gotoxy(12,28);
					printf("Introduzca el correo electronico      : ");
					gets(temp1.email);

					gotoxy(20,32);
					printf("[S] Actualizar");

					gotoxy(40,32);
					printf("[C] Cancelar");

					gotoxy(18,36);
					printf("Presione una letra para ejecutar la operacion: ");
					Index= getch();

					if(Index=='s' || Index == 'S')
					{
					    fprintf(Temporal,"%d %s %s %s %s\n\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);

						system("cls");
					    gotoxy(20,25);
					    printf("Proveedor actualizado con exito...");
						fclose(Temporal);
	   					fclose(Original);
						remove("Proveedor.dat");
						rename("Temp.dat","Proveedor.dat");
						Index= getche();

					}			
				}
			else
			{
				fprintf(Temporal,"%d %s %s %s %s\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);
				fflush(stdin);
			}
		}

	   fclose(Temporal);
	   fclose(Original);
	   }

}

void supp_list() {

char ch;
system("cls");
	   ptr1=fopen("Proveedor.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Error, no se puede abrir el archivo! ");
		exit(0);
	   }

	   system("cls");
	   box();

	   gotoxy(8,48);
	   printf(" Presione una tecla para regresar al MENU de PROVEEDORES !!!");
	   lbox();

	   gotoxy(30,8);
	   printf(" LISTA DE PROVEEDORES ");

	   gotoxy(5,10);
	   printf("ID.  NOMBRE PROVEED.   CIUDAD.     TEL.NO.       EMAIL");

	   gotoxy(4,12);
	   i=14;
	   printf("=================================================================");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.city,temp1.mob_no,temp1.email)!=EOF)
	   {
		gotoxy(4,i);
		printf(" %d",temp1.supp_id);
		gotoxy(9,i);
		printf(" %s",temp1.supp_name);
		gotoxy(29,i);
		printf(" %s",temp1.city);
		gotoxy(41,i);
		printf(" %s",temp1.mob_no);
		gotoxy(54,i);
		printf(" %s",temp1.email);
		i=i+2;
	   }
	   fclose(ptr1);
	   getche();
	   
}

void search() {
	int Index;

	do
	 {
	   system("cls");

	   gotoxy(17,10);
	   printf(" Filtros disponibles para la busqueda ");

	   gotoxy(15,15);
	   printf("[1] Buscar por [Numero ID]");

	   gotoxy(15,18);
	   printf("[2] Buscar por [Nombre]");

	   gotoxy(15,21);
	   printf("[3] Regresar");

	   Main_box();
	   gotoxy(17,24);
	   printf("Presione un numero para ejecutar la operacion: ");

	   Index= toupper(getche());
	   switch(Index)
	   {
		case '1':
			search_id();
			break;
		case '2':
			search_name();
			break;
		case '3':
			Proveedores();
			break;
		default:
			gotoxy(22,29);
			printf("Seleccionastes una tecla incorrecta!!!!!");
			getch();
	   }
	   }while(Index!='9');

}

//======================== Busqueda por ID =============================
void search_id() {

	int id;
  	FILE *fp;

	   fp=fopen("Proveedor.dat","r");
	   if(fp==NULL)
	   {
	     printf("Error, el archivo no puede abrirse!!!!");

	   }
	   system("cls");

	   box();
	   gotoxy(13,8);
	   printf("Introduzca el codigo ID para buscar:");
	   scanf("%d",&id);

	   gotoxy(20,35);
	   printf("Presione alguna tecla para regresar al MENU....");

	   gotoxy(12,14);
	   printf("ID.  NOMBRE PROVEED.   CIUDAD.     TEL.NO.       EMAIL");
	   gotoxy(12,16);
	   i=18;
	   printf("==============================================================");
	   while(fscanf(fp,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email)!=EOF)
	   {
		if(temp1.supp_id==id)
		{
			gotoxy(10,i);
			printf(" %d",temp1.supp_id);

			gotoxy(15,i);
			printf(" %s",temp1.supp_name);

			gotoxy(30,i);
			printf(" %s",temp1.city);

			gotoxy(40,i);
			printf(" %s",temp1.mob_no);

			gotoxy(53,i);
			printf(" %s",temp1.email);
			i++;
			break;
		}
	   }
	   if(temp1.supp_id!=id)
	   {
		gotoxy(20,30);
		printf("Registro no encontrado!");
	   }
	   fclose(fp);
	   getche();
}

//======================== Busqueda por nombre =============================
void search_name() {

	char name[20];
  	FILE *fp;

	   fp=fopen("Proveedor.dat","r");
	   if(fp==NULL)
	   {
	     printf("Error, el archivo no puede abrirse!!!!");

	   }
	   system("cls");

	   box();
	   gotoxy(13,8);
	   printf(" Introduzca el nombre para la busqueda : ");
	   scanf("%s",&name);

	   gotoxy(20,35);
	   printf("Presione alguna tecla para regresar al MENU ....");

	   gotoxy(12,14);
	   printf("ID. SUPPLIER NAME.   CITY.     PH.NO.       EMAIL");

	   gotoxy(12,16);
	   i=18;
	   printf("==============================================================");

	   while(fscanf(fp,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city,temp1.email)!=EOF)
	   {
		if(strcmp(temp1.supp_name,name)==0)
		{
			gotoxy(11,i);
			printf(" %d",temp1.supp_id);
			gotoxy(15,i);
			printf(" %s",temp1.supp_name);
			gotoxy(30,i);
			printf(" %s",temp1.city);
			gotoxy(40,i);
			printf(" %s",temp1.mob_no);
			gotoxy(53,i);
			printf(" %s",temp1.email);
			i++;
			break;
		}
	   }
	   if(strcmp(temp1.supp_name,name)!=0)
	   {
		gotoxy(20,30);
		printf("Registro no encontrado!");
	   }
	   fclose(fp);
	   getche();

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
	  printf("Presione la tecla numero para iniciar la operacion:    ");


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
			cust_search();			
			break;
		case '4':
			cust_list();			
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

//========================= Obtener ID Cliente =======================
int getcust_id()
{
 FILE *fp;
	 fp= fopen("Clientes.dat","r");
	 if(fp==NULL)
	 {
		gotoxy(22,15);
		printf("No existen Datos.....");
		getch();
	 }
	 else
	 {
		temp_cli.cust_id=1000;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no,temp_cli.city,temp_cli.email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp_cli.cust_id+1;
}
//======================== Submenu =============================
void cust_entry() {

	char ch;
 	int id;
 	FILE *fp;
 	system("cls");

	   fp=fopen("Clientes.dat","a");

	   if(fp==NULL)
	   {
		printf("\n No se puede abrir el archivo!!");
		exit(0);
	   }

	   system("cls");

	   ch='y';
	   while(ch=='y')
	   {
		system("cls");

		t();
		box();
		lbox();
		gotoxy(30,8);
		printf(" ENTRADA CLIENTES ");

		gotoxy(8,13);
		temp_cli.cust_id=getcust_id();
		printf("ID CLIENTE :%d",temp_cli.cust_id);

		gotoxy(39,13);
		printf("NOMBRE CLIENTE: ");

		gotoxy(8,18);
		printf("CIUDAD: ");

		gotoxy(39,18);
		printf("CONTACTO NO. : ");

		gotoxy(8,23);
		printf("CORREO ELECTRONICO: ");

		gotoxy(55,13);
		gets(temp_cli.cust_name);

		gotoxy(16,18);
		gets(temp_cli.city);

		gotoxy(54,18);
		gets(temp_cli.mob_no);

		gotoxy(28,23);
		gets(temp_cli.email);

		gotoxy(21,30);
		printf("[S] GUARDAR");

		gotoxy(38,30);
		printf("[C] CANCELAR");

		gotoxy(18,36);
		printf("Presiona un tecla para ejecutar la operacion [S/C] : ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n",temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no,temp_cli.city,temp_cli.email);

			system("cls");
			gotoxy(20,20);
			printf("Proveedor agregado con exito!!!!!");
			Sleep(2000);
			ch= getche();

		}
	   }
	   fclose(fp);

}

void cust_update() {
	int i;
  	char ch;
  	int cid;
  	FILE *ft;
  
  	system("cls");
  	box();
	   ptr1=fopen("Clientes.dat","r+");

	   if(ptr1==NULL)
	   {
		printf("\n\t Este archivo no se puede abrir!! ");
		exit(0);
	   }

	   lbox();
	   gotoxy(30,8);
	   printf(" Modificando cliente ");

	   gotoxy(12,13);
	   printf("Introduzca el ID del cliente : ");
	   scanf("%d",&cid);
	   gotoxy(12,15);

		ft=fopen("TempCli.dat","w");
		if(ft==NULL)
		{
			printf("\n Este archivo no se puede abrir");
			exit(0);
		}
		else
		{

			while(fscanf(ptr1,"%d %s %s %s %s",&temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email)!=EOF)
			{
				if(temp_cli.cust_id==cid)
				{
					gotoxy(25,17);
					printf("*** Existing Record ***");
					gotoxy(10,19);
					printf("%d\t %s \t%s \t%s \t%s",temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email);
					
					gotoxy(12,22);
					printf("Introduzca el nuevo nombre         : ");
					gets(temp_cli.cust_name);

					gotoxy(12,24);
					printf("Introduzca el numero de celular    : ");
					gets(temp_cli.mob_no);

					gotoxy(12,26);
					printf("Introduzca la ciudad         : ");
					gets(temp_cli.city);

					gotoxy(12,28);
					printf("Introduzca el correo electronico        : ");
					scanf("%s",temp_cli.email);

					gotoxy(20,32);
					printf("[S] Actualizar");

					gotoxy(40,32);
					printf("[C] Cancelar");

					gotoxy(18,35);
					printf("Presione una letra para ejecutar la operacion: ");
					ch=getche();

					if(ch=='s' || ch=='S')
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email);

					gotoxy(20,36);
					printf("Customer updated successfully...");
					fclose(ft);
	   				fclose(ptr1);
					remove("Clientes.dat");
					rename("TempCli.dat","Clientes.dat");
					}					
					}
					else
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email);
					fflush(stdin);
					}
				  }

	   fclose(ft);
	   fclose(ptr1);
      }
}

void cust_list() {
	char ch;
 	system("cls");
	   ptr1=fopen("Clientes.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Error, no se puede abrir el archivo! ");
		exit(0);
	   }

	   system("cls");
	   box();

	   gotoxy(8,48);
	   printf(" Presione una tecla para regresar al MENU de CLIENTES !!!");
	   lbox();

	   gotoxy(30,8);
	   printf(" LISTA CLIENTES ");
	   i=14;
	   gotoxy(5,10);
	   printf(" ID. NOMBRE CLIENTE.    CIUDAD.     TELF.NO.      EMAIL");
	   gotoxy(4,12);
	   printf("==============================================================");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email)!=EOF)
	   {
		gotoxy(4,i);
		printf(" %d",temp_cli.cust_id);
		gotoxy(11,i);
		printf(" %s",temp_cli.cust_name);
		gotoxy(28,i);
		printf(" %s",temp_cli.city);
		gotoxy(40,i);
		printf(" %s",temp_cli.mob_no);
		gotoxy(53,i);
		printf(" %s",temp_cli.email);
		i=i+2;
	   }
	   getche();
	   fclose(ptr1);

}

void cust_search() {
	int Index;

	do
	 {
	   system("cls");

	   gotoxy(17,10);
	   printf(" Filtros disponibles para la busqueda ");

	   gotoxy(15,15);
	   printf("[1] Buscar por [Numero ID]");

	   gotoxy(15,18);
	   printf("[2] Buscar por [Nombre]");

	   gotoxy(16,21);
	   printf("[3] Regresar");

	   Main_box();
	   gotoxy(17,24);
	   printf("Presione un numero para ejecutar la operacion: ");

	   Index= toupper(getche());
	   switch(Index)
	   {
		case '1':
			search_cid();
			break;
		case '2':
			search_cname();
			break;
		case '3':
			Clientes();
			break;
		default:
			gotoxy(22,18);
			printf("Seleccionastes una tecla incorrecta!!!!!");
			getch();
	   }
	   }while(Index!='R');
       getche();
}

//======================== Busqueda por ID =============================
void search_cid() {
	int id;
	FILE *fp;

  	system("cls");
  	box();
	   fp=fopen("Clientes.dat","r");
	   	if(fp==NULL)
	   {
	     printf("Error, el archivo no puede abrirse!!!!");
	   }

	   gotoxy(13,8);
	   printf("Introduzca el codigo ID para buscar:");
	   scanf("%d",&id);

		gotoxy(20,35);
		printf("Presione alguna tecla para regresar al MENU....");

	   gotoxy(9,15);
	   printf(" ID. NOMBRE CLIENTE.    CIUDAD.     TELF.NO.      EMAIL");
	   gotoxy(8,16);
	   i= 18;
	   printf("==============================================================");
	   while(fscanf(fp,"%d %s %s %s %s",&temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email)!=EOF)
	   {
		if(temp_cli.cust_id==id)
		{
			gotoxy(8,i);
			printf(" %d",temp_cli.cust_id);
			gotoxy(15,i);
			printf(" %s",temp_cli.cust_name);
			gotoxy(28,i);
			printf(" %s",temp_cli.city);
			gotoxy(40,i);
			printf(" %s",temp_cli.mob_no);
			gotoxy(54,i);
			printf(" %s",temp_cli.email);
			break;
		}
	   }
	   if(temp_cli.cust_id!=id)
	   {
		gotoxy(20,30);
		printf("Registro no encontrado!");
	   }
	   fclose(fp);
       getche();

}
//======================== Busqueda por Nombre =============================
void search_cname() {

	char name[20];

  	system("cls");
  	box();
	   ptr1=fopen("Clientes.dat","r");
	   
	   gotoxy(12,8);
	   printf("Introduzca el nombre del cliente para buscar:");
	   scanf("%s",&name);
	   i=18;

	   gotoxy(9,15);
	   printf("ID. NOMBRE CLIENTE.    CIUDAD.     TELF.NO.      EMAIL");

	   gotoxy(8,16);
	   printf("==============================================================");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email)!=EOF)
	   {
		if(strcmp(temp_cli.cust_name,name)==0)
		{
			gotoxy(8,i);
			printf(" %d",temp_cli.cust_id);
			gotoxy(15,i);
			printf(" %s",temp_cli.cust_name);
			gotoxy(28,i);
			printf(" %s",temp_cli.city);
			gotoxy(40,i);
			printf(" %s",temp_cli.mob_no);
			gotoxy(54,i);
			printf(" %s",temp_cli.email);

			gotoxy(20,35);
			printf("Presione alguna tecla para regresar al MENU....");
			break;
		}
	   }
	   if(strcmp(temp_cli.cust_name,name)!=0)
	   {
		gotoxy(5,10);
		printf("Registro no encontrado!");
	   }
	fclose(ptr1);
	getche();
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

//========================= Obtener ID Medicinas =======================
int getmedic_id() {

	FILE *fp;
	 fp= fopen("Medical.dat","r");
	 if(fp==NULL)
	 {
		gotoxy(22,15);
		printf("No existen Datos.....");
		getch();
	 }
	 else
	 {
		temp.id=100;
		rewind(fp);
		while(fscanf(fp,"%d %s %d %s %s %s %f %f %d %s %s",&temp.id,temp.medi_name,&temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, &temp.unit, &temp.sale, &temp.quantity, temp.manu_date, temp.exp_date)!=EOF)
		{
		
		}
	 }
	 fclose(fp);
	 return temp.id+1;

}
//======================== Submenus =============================
void medi_entry() {
	char ch;
 	FILE *fp;
 	system("cls");

	   fp=fopen("Medical.dat","a");

		if(fp==NULL)
		{
			printf("\n No se puede abrir el archivo!!");
			exit(0);
		}

	   system("cls");

	   ch='y';
	   while(ch=='y')
	   {
		system("cls");

		box();
		lbox();
		gotoxy(30,8);
		printf(" COMPRA MEDICINA  ");

			gotoxy(7,11);
			temp.id= getmedic_id();
			printf("ID MEDICINA    : %d", temp.id);

			gotoxy(40,11);
			printf("NOMBRE MEDICINA  : ");

			gotoxy(7,14);
			printf("NO. ESTANTERIA  : ");

			gotoxy(40,14);
			printf("NO. GABINETE      : ");

			gotoxy(7,18);
			printf("NOMBRE COMPANIA  : ");

			gotoxy(40,18);
			printf("NOMBRE PROVEEDOR : ");

			gotoxy(7,21);
			printf("COSTO/UNIDAD   Rs.:  ");

			gotoxy(40,21);
			printf("COSTO VENTA   Rs.: ");

			gotoxy(7,24);
			printf("CANTIDAD       :  ");

			gotoxy(7,27);
			printf("MFG.DATE(dd-mm-yyyy): ");

			gotoxy(7,29);
			printf("EXP.DATE(dd-mm-yyyy): ");

			gotoxy(59,11);
			gets(temp.medi_name);

			gotoxy(25,14);
			gets(a);
			temp.rack= atoi(a);

			gotoxy(60,14);
			gets(temp.cabnit);

			gotoxy(26,18);
			gets(temp.comp_name);

			gotoxy(59,18);
			gets(temp.supp_name);

			gotoxy(27,21);
			gets(a);
			temp.unit= atof(a);

			gotoxy(59,21);
			gets(a);
			temp.sale= atof(a);

			gotoxy(25,24);
			gets(a);
			temp.quantity= atoi(a);

			gotoxy(29,27);
			gets(temp.manu_date);

			gotoxy(29,29);
			gets(temp.exp_date);

			gotoxy(7,31);
			printf("==========================================================");
			temp.total= temp.quantity * temp.sale;

			gotoxy(10,33);
			printf("COSTO DE VENTA TOTAL = %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);

			gotoxy(40,33);
			printf("COSTE TOTAL POR UNIDAD =  %.2f",temp.cost);

		 	gotoxy(21,35);
			printf("[S] Guardar");

			gotoxy(35,35);
			printf("[C] Cancelar");

			gotoxy(18,38);
			printf("Presiona alguna tecla para la operacion : ");

			ch= toupper(getche());


		if(ch=='s' || ch=='S')
		{
			fprintf(fp, "%d %s %d %s %s %s %f %f %d %s %s\n",temp.id,temp.medi_name,temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, temp.unit, temp.sale, temp.quantity, temp.manu_date, temp.exp_date);

			system("cls");

			gotoxy(20,20);
			printf("Medicina agregada con exito!!!!!!");
			ch= toupper(getche());
		}
	   }
	fclose(fp);
}

void medi_sale() {

	int i,a;
  	float b,total,rate;
	char Index;
	int EnterID;
	int IDFact;
	char NameCli[30];


  	FILE *Facture;
  
	   Index='y';
	   while(Index=='y')
	   {
		Facture = fopen("Factura.dat","a");
		ptr1 = fopen("Clientes.dat","r");
		ptr = fopen("Medical.dat","r+");

		system("cls");

		box();
		for(i=3;i<=45;i++)  
		{                     
		gotoxy(50,i);
		printf("%c",219);
		}
	
		i=9;
		gotoxy(52,7);
		printf("Cli_ID    Cli_Name");
		while(fscanf(ptr1,"%d %s %s %s %s",&temp_cli.cust_id,temp_cli.cust_name,temp_cli.mob_no, temp_cli.city,temp_cli.email)!=EOF)
		{
			gotoxy(53,i);
			printf("%d",temp_cli.cust_id);
			gotoxy(64,i);
			printf("%s",temp_cli.cust_name);
			i+=2;
		}

		gotoxy(9,7);
		printf("INTRODUZCA EL ID  : ");
		scanf("%d",&EnterID);

			while (fscanf(ptr,"%d %s %d %s %s %s %f %f %d %s %s",&temp.id,temp.medi_name,&temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, &temp.unit, &temp.sale, &temp.quantity, temp.manu_date, temp.exp_date)!= EOF)
			{
					if (temp.id==EnterID)
			{
					gotoxy(8,10);
					printf(" Nombre Medicina        : %s",temp.medi_name);
					gotoxy(8,12);
					printf(" Cantidad en Stock    : %d",temp.quantity);
					gotoxy(8,14);
					printf(" Precio Venta          : %.2f",temp.sale);

					gotoxy(8,16);
					printf("Introduzca # de factrura     : ");
					scanf("%d", &IDFact);
					
					gotoxy(8,18);
					printf("Introduzca nombre del cliente   : ");
					scanf("%s", NameCli);

					gotoxy(8,20);
					printf("Cantidad para vender: ");
					scanf("%d",&a);
					
					gotoxy(10,32);
					printf("[Y] Aceptar");

					gotoxy(20,32);
					printf("[C] Cancelar");

					gotoxy(10,35);
					printf("Presione una letra para ejecutar la operacion: ");
					Index=getche();

					if (Index=='y' || Index=='Y')
					{
					temp_Fac.billno = IDFact;
					strcpy(temp_Fac.cname,NameCli);
					strcpy(temp_Fac.mediname, temp.medi_name);
					temp_Fac.medi_qty= a;
					temp_Fac.medi_rate= temp.sale;
					temp_Fac.total= temp.sale * a;
					temp.quantity = temp.quantity - a;

					fprintf(Facture,"%d %s %s %d %f %f\n",temp_Fac.billno, temp_Fac.cname, temp_Fac.mediname, temp_Fac.medi_qty, temp_Fac.medi_rate, temp_Fac.total);


					fclose(Facture);
	   				fclose(ptr1);
					} else
					{
					fprintf(Facture,"%d %s %s %d %f %f\n",temp_Fac.billno, temp_Fac.cname, temp_Fac.mediname, temp_Fac.medi_qty, temp_Fac.medi_rate, temp_Fac.total);
					fflush(stdin);
					}
			}	
			
			}

		system("cls");
		box();

		gotoxy(8,17);
		printf("* Cantidad vendida= %d",a);
		gotoxy(20,25);
		printf("Venta realizada con exito...");
		gotoxy(20,30);
		printf("Medicina [%s] restante: %d", temp.medi_name, temp.quantity);
		
		getche();
		Index=getche();
		
	   }
	   	fclose(Facture);
		fclose(ptr1);
		fclose(ptr);
	}

void stock() {

	char ch;
	int i, Index;

	FILE *MedFp;
	   do
	   {
		system("cls");

		MedFp=fopen("Medical.dat","r");
		if(MedFp==NULL)
		{
			printf("\n\t Error no se puede abrir el archivo! ");
			exit(1);
		}
		system("cls");

		box();
		lbox();
		gotoxy(30,8);
		printf(" STOCK MEDICINA ");
		i=14;

		gotoxy(9,10);
		printf("ID.   NOMBRE MEDICINA.    QTY     NOMBRE PROVE.     Exp.Fecha");
		gotoxy(9,12);
		printf("==================================================================\n");

		while(fscanf(MedFp,"%d %s %d %s %s %s %f %f %d %s %s",&temp.id,temp.medi_name,&temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, &temp.unit, &temp.sale, &temp.quantity, temp.manu_date, temp.exp_date)!=EOF)
		{
			gotoxy(9,i);
			printf(" %d",temp.id);

			gotoxy(15,i);
			printf(" %s",temp.medi_name);

			gotoxy(32,i);
			printf(" %d",temp.quantity);

			gotoxy(43,i);
			printf(" %s",temp.supp_name);

			gotoxy(60,i);
			printf(" %s",temp.exp_date);
			i++;
		}
		gotoxy(10,42);
		printf("Presiona [0] para regresar al Menu ");
		Index = (getche());
		switch (Index)
		{
			case '0':
				Medicinas();
				fclose(MedFp);				
				 break;
			/*case '1':
				fclose(MedFp);
				update_stock();
				 break; */
		}

	   }while(Index != '1');
	   getche();
}

void medi_search(){

	int EnterID;
  	int i;
	FILE *FileMed;

  	system("cls");
	   FileMed=fopen("Medical.dat","r");

	   if(FileMed==NULL)
	   {
		printf("\n\t Error no se puede abrir el archivo! ");
		exit(0);
	   }

	   system("cls");
	   box();

	   gotoxy(10,7);
	   printf("Introduzca el ID de la medicina para buscar : ");
	   scanf("%d",&EnterID);

	   system("cls");
	   box();
	   lbox();

	   gotoxy(30,8);
	   printf(" MEDICINA ");
	   i=14;

	   gotoxy(9,10);
	   printf("ID.   NOMBRE MEDICINA.    QTY     NOMBRE PROVE.     Exp.Fecha");
	   gotoxy(9,12);
	   printf("==================================================================\n");
	   while(fscanf(FileMed,"%d %s %d %s %s %s %f %f %d %s %s",&temp.id,temp.medi_name,&temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, &temp.unit, &temp.sale, &temp.quantity, temp.manu_date, temp.exp_date)!=EOF)
	   {
		if(temp.id==EnterID)
		{
			gotoxy(9,i);
			printf(" %d",temp.id);
			gotoxy(15,i);
			printf(" %s",temp.medi_name);
			gotoxy(32,i);
			printf(" %d",temp.quantity);
			gotoxy(43,i);
			printf(" %s",temp.supp_name);
			gotoxy(60,i);
			printf(" %s",temp.exp_date);
			i++;
			break;
		}

	   }
	   if(temp.id!=EnterID)
	   {
		gotoxy(20,20);
		printf("No esta en Stock.....");
	   }
	   getche();

}
/*
//======================Actualizar Stock de medicinas ===============
//=======================================
void update_stock() {
	
	int EnterID;
	int UpdateQty;
  	char Index;
  	FILE *Original;
	FILE *Temporal;
  
  	system("cls");
  	box();
	   	Original=fopen("Medical.dat","r+");

	   if(Original==NULL)
	   {
		printf("\n\t Este archivo no se puede abrir!! ");
		exit(0);
	   }

	   box();
	   gotoxy(20,45);
	   printf("Presiona Enter para regresar al MENU ...........");

	   gotoxy(27,8);
	   printf(" ACTUALIZAR LA CANTIDAD DE MEDICINA ");
	   gotoxy(9,10);
	   
	   printf("Introduzca ID para actualizar la cantidad: ");
	   scanf("%d",&EnterID);

	   gotoxy(12,15);
	   Temporal=fopen("TempMedi.dat","w");

		if(Temporal==NULL)
		{
			printf("\n Este archivo no se puede abrir");
			exit(0);
		}
		else
		{
			while(fscanf(Original,"%d %s %d %s %s %s %f %f %d %s %s",&temp.id,temp.medi_name,&temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, &temp.unit, &temp.sale, &temp.quantity, temp.manu_date, temp.exp_date)!=EOF)
			{
				if(temp.id==EnterID)
				{
					gotoxy(8,12);
					printf("Nombre Medicina     : %s",temp.medi_name);

					gotoxy(8,14);
					printf("Cantidad en Stock : %d",temp.quantity);

					gotoxy(8,16);
					printf("Cantidad para actualizar : ");
					scanf("%d",&UpdateQty);

					gotoxy(20,32);
					printf("[S] Actualizar");

					gotoxy(40,32);
					printf("[C] Cancelar");

					gotoxy(18,35);
					printf("Presione una letra para ejecutar la operacion: ");
					Index=getche();

					if(Index=='s' || Index=='S')	
					{
						temp.quantity = temp.quantity + UpdateQty;
						temp.total= temp.quantity * temp.sale;
						temp.cost=(temp.unit*temp.quantity);

						fprintf(Temporal,"%d %s %d %s %s %s %f %f %d %s %s\n",temp.id,temp.medi_name,temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, temp.unit, temp.sale, temp.quantity, temp.manu_date, temp.exp_date);

						system("cls");
						gotoxy(25,25);
						printf("Medicina actualizada con exito...");

						fclose(Original);
						fclose(Temporal);

						remove("Medical.dat");
						rename("TempMedi.dat","Medical.dat");
						//Index= getche();
					}					
					else
					{
					fprintf(Temporal,"%d %s %d %s %s %s %f %f %d %s %s\n",temp.id,temp.medi_name,temp.rack,temp.cabnit,temp.comp_name,temp.supp_name, temp.unit, temp.sale, temp.quantity, temp.manu_date, temp.exp_date);
					fflush(stdin);
					}
				}
			}
		fclose(Temporal);
		fclose(Original);
		}	
}
//=========================================
*/
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

//======================== Submenu Facturas =============================
void Bill() {

		time_t t = time(NULL);
    	struct tm tiempoLocal = *localtime(&t);

    	char Fecha[70];
    	char *FormatoFecha = "%Y-%m-%d";
    	int EstructuraFecha = strftime(Fecha, sizeof Fecha, FormatoFecha, &tiempoLocal);

	   FILE *F_Factura;
	   int ID;
	   int j=1,d1,m,y,k;
	   float netamt=0.0;

	   system("cls");
	   F_Factura=fopen("Factura.dat","r");

	   gotoxy(13,4);
	   printf("Introduzca No Factura: ");
	   scanf("%s",&ID);

	   system("cls");
	   gotoxy(25,3);
	   box();

	   gotoxy(7,7);
	   printf("Factura No: ");
	   printf(" %s",ID);

	   gotoxy(7,9);
	   printf("Nombre Cliente: ");

	   gotoxy(50,7);
	   printf("FECHA: %s", Fecha);
	   

	   gotoxy(7,12);
	   printf("Sr.No   Nombre Medicina       Cantidad          Rate         Total ");
	   gotoxy(6,14);
	   printf("---------------------------------------------------------------------");

	   i=15;
	   
		while(fscanf(F_Factura,"%d %s %s %d %f %f",&temp_Fac.billno,temp_Fac.cname,temp_Fac.mediname,&temp_Fac.medi_qty,&temp_Fac.medi_rate,&temp_Fac.total)!=EOF)
	   {
		if(temp_Fac.billno == ID)
		{
			gotoxy(7,i);
				printf(" %d",j);
				gotoxy(14,i);
				printf(" %s",temp_Fac.mediname);
				gotoxy(22,9);
				printf(" %s",temp_Fac.cname);
				gotoxy(35,i);
				printf(" %d",temp_Fac.medi_qty);
				gotoxy(47,i);
				printf(" %.2f",temp_Fac.medi_rate);
				gotoxy(60,i);
				printf(" %.2f",temp_Fac.total);
				netamt= netamt + temp_Fac.total;
				i++;
				j++;
				gotoxy(35,32);
				printf("                                ");
				gotoxy(20,50);
				printf("Presione alguna tecla para regresar al MENU ...........");
		}

	   }
	   gotoxy(6,35);
	   printf("---------------------------------------------------------------------");
	   gotoxy(50,37);
	   printf("Cantidad Neto: ");
	   printf("%.2f",netamt);

	   fclose(F_Factura);
	   getch();

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