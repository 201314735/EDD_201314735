#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ColaAviones.h"
#include "ColaPasajeros.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QScrollBar>
#include <QDebug>


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

bool ok = true;

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
    fprintf(fp,"\tnode [fontcolor=\"blue\", height=0.5, color=\"red\"]\n");
    fprintf(fp,"\tedge [color=\"blue\", dir=fordware]\n");
    fprintf(fp,"\trankdir=LR\n");
    fprintf(fp,"\tcompound=true;\n");

    if(hayCola()==true){
        fprintf(fp,"\n\tsubgraph ColaAviones{\nnode[shape=box]\nedge[dir=both]\n");

        colaAviones* temp = primerAvion;

        while(temp!=NULL){
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


           // fprintf(fp,"\t\"Aviones\" ->\"Avion Nombre: %i\\n %s\"",temp->tipo,"Avion");


        }
        fprintf(fp,"\n\t}");
    }else{
        fprintf(fp,"\t\"Cola Aviones Vacia\"");
    }




fprintf(fp,"\n}");
fclose(fp);
}

void agregarAA()
{

    colaAviones* colaAvion = (colaAviones*)malloc(sizeof(colaAviones));

    int tamanio = (rand() %(3-1+1))+1;
    int pas;                     //variable numero pasajeros
    int desab;                   //variable numero turnos desabordaje
    int mant;                    //variable numero turnos mantenimiento
    //char nombre [7];
    std::string nombre;

    if (cAviones != 0)
        { //tamaño del avion

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



void MainWindow::on_pushButton_clicked()
{    srand (time(0));
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




//qDebug()<<"**************# Aviones"<<cAviones<<"******************"<<endl;

imprimir();
system("dot -Tpng Graphiz.dot -o Graphiz.png");
graficar(ui->scrollArea);
}

void MainWindow::on_pushButton_2_clicked()
{
agregarAA();

imprimir();
system("dot -Tpng Graphiz.dot -o Graphiz.png");
graficar(ui->scrollArea);


//int a = (rand() %(3-1+1))+1;
//qDebug()<<"**************#"<<a<<"******************"<<endl;

}

