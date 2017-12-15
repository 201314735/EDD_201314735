#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ColaAviones.h"
#include "ColaPasajeros.h"
#include "ListaEquipaje.h"
#include "ListaEscritorios.h"
#include "ListaMantenimiento.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QScrollBar>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int cTurnos;
int cAviones;
int cEscritorios;
int cMantenimiento;
int idPasajero=1;
int letra=65;
int nMantenimiento=1;

bool ok = true;

void agregarPP(colaAviones* colaAvion)
{
    colaPasajerosDesabordaje* colaPD = (colaPasajerosDesabordaje*)malloc(sizeof(colaPasajerosDesabordaje));
    if (colaAvion==NULL)
    {

    }
    else{

    for(int i=0;i<colaAvion->pasajeros;i++)
    {
        colaPD = (colaPasajerosDesabordaje*)malloc(sizeof(colaPasajerosDesabordaje));

        int mlts = (rand() %(4-1+1))+1;         //# maletas
        int docs = (rand() %(10-1+1))+1;        //# documentos
        int registro = (rand() %(3-1+1))+1;     //# turnos registro

        colaPD -> id = idPasajero;
        colaPD -> maletas = mlts;
        colaPD -> documentos = docs;
        colaPD -> tRegistro = registro;
        agregarPasajeros(colaPD);
        idPasajero++;

        qDebug()<<"Pasajero "<<   colaPD -> id <<" entra a cola de pasajeros"<<endl;
        qDebug()<<"Maletas "<< colaPD -> maletas<<endl;
        qDebug()<<"Documentos "<< colaPD -> documentos<<endl;
        qDebug()<<"Turnos registro "<< colaPD -> tRegistro<<endl;
    }
    }
}



void graficar(QScrollArea* s){

    QImage *img = new QImage();
    img->load("/home/alejandro/EDD_201314735/build-EDD_Practica1-Desktop-Debug/Graphiz.png");
   QPixmap
    imagen=QPixmap::fromImage(*img);
    QLabel *lbl = new QLabel();
    lbl->setBackgroundRole(QPalette::Base);
    lbl->setPixmap(imagen);
    lbl->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    lbl->setScaledContents(true);
    s->setBackgroundRole(QPalette::Dark);
    s->setWidget(lbl);
    s->horizontalScrollBar()->setValue(0);
    s->verticalScrollBar()->setValue(0);
}

void imprimir(){
    FILE *fp;
    fp = fopen("Graphiz.dot","w");

    fprintf(fp,"digraph Programa {\n");
    fprintf(fp,"\tnode [fontcolor=\"blue\", height=0.5, shape=box, color=\"red\"]\n");
    fprintf(fp,"\tedge [color=\"blue\", dir=fordware]\n");
    fprintf(fp,"\trankdir=LR\n");
    fprintf(fp,"\tcompound=true;\n");



    if(hayCola()==true){
        fprintf(fp,"\n\tsubgraph ColaAviones{\nnode[shape=box]\nedge[dir=both]\n");

        colaAviones* temp = primerAvion;

        while(temp!=NULL){

            if (temp->desabordaje != 0)
            {

                if(temp==primerAvion)
                 {
                  fprintf(fp,"\t\"Aviones\" ->\"Tipo: %i, Pasajeros: %i\\nTurnos Desabordaje: %i, Turnos Mantenimiento: %i\"",temp->tipo,temp->pasajeros,temp->desabordaje, temp->mantenimiento);
                  temp=temp->siguiente;
                 }
                 else
                 {
                  fprintf(fp,"->\"Tipo: %i, Pasajeros: %i\\nTurnos Desabordaje: %i, Turnos Mantenimiento: %i\"",temp->tipo,temp->pasajeros,temp->desabordaje, temp->mantenimiento);
                  temp=temp->siguiente;
                 }
            }

            else
            {

            colaAviones* avionFuera= (colaAviones*)malloc(sizeof(colaAviones));
            avionFuera=sacarAvion();
            qDebug()<<"Cliente "<<avionFuera->tipo<<endl;

            if(avionFuera==NULL)
            {

            }

            else
            {
                agregarPP(avionFuera);
            }


           if(primerAvion==NULL)
            {
                temp=NULL;
                fprintf(fp,"\t\"Cola Aviones Vacia\"");

            }
            else
            {
                temp=primerAvion;
            }
            }


        }
        fprintf(fp,"\n\t}");
    }
    else
    {
        fprintf(fp,"\t\"Cola Aviones Vacia\"");
    }


   if(hayColaPasajeros()==true)
    {
       fprintf(fp,"\n\tsubgraph ColaPasajeros{\nnode[shape=box]\nedge[dir=fordware]\n");
       // ptemp = (colaPasajerosDesabordaje*)malloc(sizeof(colaPasajerosDesabordaje));
      colaPasajerosDesabordaje* ptemp = cabeza;

        while(ptemp!=NULL)
        {
            if(ptemp==cabeza)
             {
              fprintf(fp,"\t\"Pasajeros\" ->\"ID: %i, Maletas: %i\\nDocumentos: %i, Turnos Registro: %i\"",ptemp->id,ptemp->maletas,ptemp->documentos, ptemp->tRegistro);


              ptemp=ptemp->siguiente;

              qDebug()<<"aaaa "<<ptemp->siguiente->id<<endl;
             }
             else
             {
              fprintf(fp,"->\"ID: %i, Maletas: %i\\nDocumentos: %i, Turnos Registro: %i\"",ptemp->id,ptemp->maletas,ptemp->documentos, ptemp->tRegistro);
              ptemp=ptemp->siguiente;
             }
       }

        fprintf(fp,"\n\t}");
    }

    else
    {
        fprintf(fp,"\t\"Cola Pasajeros Vacia\"");
    }

   if(hayListaEscritorios()==true)
    {
       fprintf(fp,"\n\tsubgraph ListaEscritorios{\nnode[shape=box]\nedge[dir=fordware]\n");
      listaEscritorios* etemp = primerEscritorio;

        while(etemp!=NULL)
        {
            if(etemp==primerEscritorio)
             {
              fprintf(fp,"\t\"Escritorios\" ->\"ID: %c\"",etemp->nombre);


              etemp=etemp->siguiente;

              qDebug()<<"bbbbb "<<etemp->nombre<<endl;
             }
             else
             {
              fprintf(fp,"->\"ID: %c\"",etemp->nombre);
              etemp=etemp->siguiente;
             }
       }

        fprintf(fp,"\n\t}");
    }

    else
    {
        fprintf(fp,"\t\"Lista Escritorios Vacia\"");
    }

   if(hayListaMantenimiento()==true)
    {
       fprintf(fp,"\n\tsubgraph ListaMantenimiento{\nnode[shape=box]\nedge[dir=fordware]\n");
      listaMantenimiento* mtemp = primerMantenimiento;

        while(mtemp!=NULL)
        {
            if(mtemp==primerMantenimiento)
             {
              fprintf(fp,"\t\"Mantenimiento\" ->\"Estación: %i\"",mtemp->numero);


              mtemp=mtemp->siguiente;

              qDebug()<<"cccc "<<mtemp->numero<<endl;
             }
             else
             {
              fprintf(fp,"->\"Estación: %i\"",mtemp->numero);
              mtemp=mtemp->siguiente;
             }
       }

        fprintf(fp,"\n\t}");
    }

    else
    {
        fprintf(fp,"\t\"Lista Mantenimiento Vacia\"");
    }

fprintf(fp,"\n}");
fclose(fp);
}

void agregarAA()
{

    colaAviones* colaAvion = (colaAviones*)malloc(sizeof(colaAviones));

    int tamanio = (rand() %(3-1+1))+1;//tamaño del avion
    int pas;                     //variable numero pasajeros
    int desab;                   //variable numero turnos desabordaje
    int mant;                    //variable numero turnos mantenimiento
    //char nombre [7];
    std::string nombre;

    if (cAviones != 0)
        {

        if(tamanio == 1)
        {
            colaAvion = (colaAviones*)malloc(sizeof(colaAviones));
            pas = (rand() %(10-5+1))+5;
            desab = 1;
            mant = (rand() %(3-1+1))+1;
           // nombre [7] = {'P', 'e', 'q', 'u', 'e','ñ','o'};
            nombre="Pequeño";

            colaAvion -> tipo = 1;
            colaAvion -> pasajeros = pas;
            colaAvion -> desabordaje = desab;
            colaAvion -> mantenimiento = mant;

            agregarAvion(colaAvion);
            qDebug()<<"Avión "<< QString::fromStdString(nombre)<<" entra a cola de aviones"<<endl;
            qDebug()<<"Pasajeros "<< colaAvion->pasajeros<<endl;
            qDebug()<<"Turnos desabordaje "<< colaAvion->desabordaje<<endl;
            qDebug()<<"Turnos mantenimiento "<< colaAvion->mantenimiento<<endl;
            tamanio = (rand() %(3-1+1))+1;
            cAviones = cAviones -1;

        }
        else if (tamanio == 2)
        {
            pas = (rand() %(25-15+1))+15;
            desab = 2;
            mant = (rand() %(4-2+1))+2;
            //nombre [7] = {'M', 'e', 'd', 'i', 'a','n','o'};

            nombre="Mediano";

            colaAvion -> tipo = 2;
            colaAvion -> pasajeros = pas;
            colaAvion -> desabordaje = desab;
            colaAvion -> mantenimiento = mant;

            agregarAvion(colaAvion);
            qDebug()<<"Avión "<< QString::fromStdString(nombre)<<" entra a cola de aviones"<<endl;
            qDebug()<<"Pasajeros "<< colaAvion->pasajeros<<endl;
            qDebug()<<"Turnos desabordaje "<< colaAvion->desabordaje<<endl;
            qDebug()<<"Turnos mantenimiento "<< colaAvion->mantenimiento<<endl;
            tamanio = (rand() %(3-1+1))+1;
            cAviones = cAviones -1;
        }
        else if (tamanio ==3)
        {
            pas = (rand() %(40-30+1))+30;
            desab = 3;
            mant = (rand() %(6-3+1))+3;
           // nombre [7] = {'G', 'r', 'a', 'n', 'd','e',' '};

            nombre="Grande";

            colaAvion -> tipo = 3;
            colaAvion -> pasajeros = pas;
            colaAvion -> desabordaje = desab;
            colaAvion -> mantenimiento = mant;

            agregarAvion(colaAvion);
            qDebug()<<"Avión "<< QString::fromStdString(nombre)<<" entra a cola de aviones"<<endl;
            qDebug()<<"Pasajeros "<< colaAvion->pasajeros<<endl;
            qDebug()<<"Turnos desabordaje "<< colaAvion->desabordaje<<endl;
            qDebug()<<"Turnos mantenimiento "<< colaAvion->mantenimiento<<endl;
            tamanio = (rand() %(3-1+1))+1;
            cAviones = cAviones -1;
        }
        }
    else {}
}


void agregarEE()
{

    listaEscritorios* lEscritorios= (listaEscritorios*)malloc(sizeof(listaEscritorios));

    while (cEscritorios != 0)
        {
            char nEscritorio = letra;
            lEscritorios = (listaEscritorios*)malloc(sizeof(listaEscritorios));

            lEscritorios -> nombre = nEscritorio;
            agregarEscritorio(lEscritorios);

           qDebug()<<"Escritorio "<< lEscritorios->nombre<<" entra a cola de aviones"<<endl;
       //     qDebug()<<"Pasajeros "<< colaAvion->pasajeros<<endl;
       //     qDebug()<<"Turnos desabordaje "<< colaAvion->desabordaje<<endl;
       //     qDebug()<<"Turnos mantenimiento "<< colaAvion->mantenimiento<<endl;
            letra++;
            cEscritorios = cEscritorios -1;

        }
}

void agregarMM()
{

    listaMantenimiento* lMantenimiento= (listaMantenimiento*)malloc(sizeof(listaMantenimiento));

    while (cMantenimiento != 0)
        {
            lMantenimiento = (listaMantenimiento*)malloc(sizeof(listaMantenimiento));

            lMantenimiento -> numero = nMantenimiento;
            agregarMantenimiento(lMantenimiento);

           qDebug()<<"Mantenimiento "<< lMantenimiento->numero<<endl;
       //     qDebug()<<"Pasajeros "<< colaAvion->pasajeros<<endl;
       //     qDebug()<<"Turnos desabordaje "<< colaAvion->desabordaje<<endl;
       //     qDebug()<<"Turnos mantenimiento "<< colaAvion->mantenimiento<<endl;
            nMantenimiento++;
            cMantenimiento = cMantenimiento -1;

        }
}


void MainWindow::on_pushButton_clicked()
{
    srand (time(0));
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->pushButton->setEnabled(false);

    cTurnos = ui->lineEdit->text().toInt(&ok,10);
    cAviones = ui->lineEdit_2->text().toInt(&ok,10);
    cEscritorios = ui->lineEdit_3->text().toInt(&ok,10);
    cMantenimiento = ui->lineEdit_4->text().toInt(&ok,10);

    agregarAA();
    agregarEE();
    agregarMM();


//qDebug()<<"**************# Aviones"<<cAviones<<"******************"<<endl;

imprimir();
system("dot -Tpng Graphiz.dot -o Graphiz.png");
graficar(ui->scrollArea);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(cTurnos==0)
    {
        QMessageBox::information(
            this,
            tr("Práctica1"),
            tr("Fin de la Simulación.") );

    }

    else{
        if(primerAvion!=NULL){
            primerAvion->desabordaje--;
            agregarAA();

            imprimir();
            system("dot -Tpng Graphiz.dot -o Graphiz.png");
            graficar(ui->scrollArea);
            cTurnos--;
        }
        else
        {
            qDebug()<<"**************# Hola"<<"******************"<<endl;

            imprimir();
            system("dot -Tpng Graphiz.dot -o Graphiz.png");
            graficar(ui->scrollArea);
            cTurnos--;
        }

//int a = (rand() %(3-1+1))+1;
//qDebug()<<"**************#"<<a<<"******************"<<endl;
    }
}

