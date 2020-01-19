#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initChart(){
    m_typeChart = new QChart();
        m_typeChart->setAnimationOptions(QChart::SeriesAnimations);//动画效果
        m_barSet = new QBarSet("eg");//创建条，可以创建多个
        m_barSet->setLabelColor(QColor(0,0,0));
        m_barSeries = new QBarSeries(m_typeChart);
        m_barSeries->setLabelsVisible(true);//判断是否在图柱上显示数值
        m_barSeries->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);//在柱上显示数值方式
        m_typeChart->addSeries(m_barSeries);
        m_typeChart->setTitle("XXXX");
        m_typeAxis = new QBarCategoryAxis();//创建X轴
        m_typeChart->createDefaultAxes();
        m_typeChart->setAcceptTouchEvents(true);
        m_typeChart->setAxisX(m_typeAxis, m_barSeries);
        m_typeAxisY = new QValueAxis;//创建Y轴
        m_typeAxisY->setRange(0, 10);//显示数值范围
        m_typeAxisY->setTickCount(10);     //设置多少格
    //        m_typeAxisY->setLabelFormat("%u"); //设置刻度的格式
    //        m_typeAxisY->setTitleText("AxisY"); //设置Y轴标题
    //        m_typeAxisY->setGridLineVisible(true); //设置是否显示网格线
        m_typeAxisY->setMinorTickCount(5); //设置每格小刻度数目
        m_typeChart->setAxisY(m_typeAxisY, m_barSeries);
        m_typeChart->legend()->setVisible(true);
        m_typeChart->legend()->setAlignment(Qt::AlignBottom);
        m_typeChart->legend()->hide();
        m_typeView = new QChartView();
        m_typeView->setChart(m_typeChart);
        m_typeView->setRubberBand(QChartView::RectangleRubberBand);//拉伸效果
        m_typeView->setRenderHint(QPainter::Antialiasing);
        m_typeView->chart()->setTheme(QChart::ChartThemeBrownSand);
        QPalette pal = window()->palette();
        pal.setColor(QPalette::Window, QRgb(0x9e8965));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));
        window()->setPalette(pal);
        ui->widget->layout()->addWidget(m_typeView);
        sltpushButton();
        connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(sltpushButton_2()));
        connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(sltpushButton_3()));
        connect(m_typeAxis, SIGNAL(categoriesChanged()), this, SLOT(sltCategoriesChanged()));//QValueAxis改变是会触发信号

}

void MainWindow::sltpushButton()
{
    *m_barSet << 1 << 2 << 3 << 4 << 5 << 6;
    m_barSeries->append(m_barSet);
    QStringList categories;
    categories  << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jan";
    m_typeAxis->append(categories);//
}

void MainWindow::sltpushButton_2()
{
    m_typeAxis->clear();
}

void MainWindow::sltCategoriesChanged()
{
    m_barSeries->clear();//因为下边会重新添加新的X轴所以会触发两次因此需要清空QBarSeries
    m_barSet = new QBarSet("eg");//需要重新创建一个柱
    m_barSet->setLabelColor(QColor(0,0,0));
    *m_barSet<< 2 << 3 << 4 << 5 << 6<<1;
    m_barSeries->append(m_barSet);
    QStringList categories;
    categories  << "1" << "2" << "3" << "4"<< "5"<< "6" ;
    m_typeAxis->append(categories);
}

