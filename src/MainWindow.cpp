//
// Created by haknk on 24.04.2021.
//

#include "MainWindow.h"
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/QSerialPortInfo"

/// Constructor func.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    guiInitialSettings();
    createStatusBar();
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
    deviceBaudRate->addItems({"9600", "115200"});
    deviceLayout->addWidget(deviceBaudRate);

    QPushButton *refreshButton = new QPushButton("Refresh", this);
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(refreshPort()));
    deviceLayout->addWidget(refreshButton);

    QPushButton *connectButton = new QPushButton("Connect", this);
    connect(connectButton, SIGNAL(clicked()), this, SLOT(deviceConnect()));
    deviceLayout->addWidget(connectButton);

    QTableWidget *content = new QTableWidget();

    QWidget *placeholderWidget = new QWidget;
    placeholderWidget->setLayout(deviceLayout);
    setCentralWidget(placeholderWidget);
}

/// Status bar create
void MainWindow::createStatusBar() {
    auto statusBar = new QStatusBar();
    statusBar->showMessage("Not Connected");

    setStatusBar(statusBar);
}

//
void MainWindow::refreshPort() {
    qDebug() << "Refresh Button";

    QList<QSerialPortInfo> list;

    list = QSerialPortInfo::availablePorts();

    for(int i=0; i<list.size(); i++){
        qDebug() << list[i].description() << list[i].portName();
    }

}

void MainWindow::deviceConnect() {
    qDebug() << "Connection test...";
}
