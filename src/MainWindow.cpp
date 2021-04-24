//
// Created by haknk on 24.04.2021.
//

#include "MainWindow.h"

/// Constructor func.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    guiInitialSettings();
    mainContent();
}

/// Initial settings for GUI
void MainWindow::guiInitialSettings(){
    qDebug()  << "Starting...";

    setWindowTitle("STREAM DECK v0.1");
    //resize(400, 200);
}

/// Central widget
void MainWindow::mainContent() {

    QHBoxLayout *deviceLayout = new QHBoxLayout();

    QComboBox *deviceComPort = new QComboBox(this);
    deviceLayout->addWidget(deviceComPort);

    QComboBox *deviceBaudRate = new QComboBox(this);
    deviceLayout->addWidget(deviceBaudRate);

    QPushButton *connect = new QPushButton("Connect", this);
    deviceLayout->addWidget(connect);

    QWidget *placeholderWidget = new QWidget;
    placeholderWidget->setLayout(deviceLayout);
    setCentralWidget(placeholderWidget);

}

/// Status bar create
void MainWindow::createStatusBar() {

}
