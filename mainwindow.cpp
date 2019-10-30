#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img;
    img.load("Basler.png");
    ui->label_display->setPixmap(QPixmap::fromImage(img));

    //check the status of dockwidget
    connect(ui->menu_view, &QMenu::aboutToShow, this, &MainWindow::updateViewMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mymsg()
{
    qDebug("trigged");
}

void MainWindow::updateViewMenu()
{
    ui->action_Feature->setChecked(ui->dockWidget_Feature->isVisible());
    ui->action_Para->setChecked(ui->dockWidget_Para->isVisible());
    ui->action_Msg->setChecked(ui->dockWidget_Msg->isVisible());
}
