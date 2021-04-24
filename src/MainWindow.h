//
// Created by haknk on 24.04.2021.
//

#ifndef STREAMDECK_MAINWINDOW_H
#define STREAMDECK_MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QMainWindow{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void guiInitialSettings();
    void mainContent();
    void createStatusBar();
};


#endif //STREAMDECK_MAINWINDOW_H
