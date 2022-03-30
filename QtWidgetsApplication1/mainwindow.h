#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include <QModbusServer>

QT_BEGIN_NAMESPACE

class QLineEdit;

namespace Ui {
class MainWindow;
class SettingsDialog;
}

QT_END_NAMESPACE

class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void on_connectButton_clicked();
    void onStateChanged(int state);

    void coilChanged(int id);
    void discreteInputChanged(int id);
    void bitChanged(int id, QModbusDataUnit::RegisterType table, bool value);

    void setRegister(const QString &value);
    void updateWidgets(QModbusDataUnit::RegisterType table, int address, int size);

    void on_connectType_currentIndexChanged(int);

    void handleDeviceError(QModbusDevice::Error newError);

private:
    void initActions();
    void setupDeviceData();
    void setupWidgetContainers();

    Ui::MainWindow *ui;
    QModbusServer *modbusDevice;

    QButtonGroup coilButtons;
    QButtonGroup discreteButtons;
    QHash<QString, QLineEdit *> registers;
    SettingsDialog *m_settingsDialog;
};

#endif // MAINWINDOW_H
