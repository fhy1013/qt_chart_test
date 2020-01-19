#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QBarSeries>
#include <QBarSet>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void initChart();

private slots:
    void sltpushButton();
    void sltpushButton_2();
    void sltpushButton_3();
    void sltCategoriesChanged();
private:
    Ui::MainWindow *ui;
    QChart*                         m_typeChart;
    QChartView*                     m_typeView;
    QBarCategoryAxis*               m_typeAxis;
    QValueAxis*                     m_typeAxisY;
    QBarSeries*                     m_barSeries;
    QBarSet*                        m_barSet;
};


#endif // MAINWINDOW_H
