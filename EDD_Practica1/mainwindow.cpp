#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ColaAviones.h"
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

fprintf(fp,"\n}");
fclose(fp);
}

void MainWindow::on_pushButton_clicked()
{
imprimir();
system("dot -Tpng Graphiz.dot -o Graphiz.png");
graficar(ui->scrollArea);
}

void MainWindow::on_pushButton_2_clicked()
{
imprimir();
system("dot -Tpng Graphiz.dot -o Graphiz.png");
graficar(ui->scrollArea);
}
