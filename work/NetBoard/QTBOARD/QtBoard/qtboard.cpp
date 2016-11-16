#include "qtboard.h"
#include<QtGui>

QtBoard::QtBoard( )
{
    w=5;
    m_bDrawing = false;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("drawing board"));
    setFixedSize(1024,600);
    image = QImage(this->width(),this->height(),QImage::Format_RGB32);
    tempimage = QImage(this->width(),this->height(),QImage::Format_RGB32);
    image.fill(~0x0);
    createActions();
    createMenus();
    createToolBar();

    this->setCursor(QCursor(Qt::CrossCursor));
    p_WBSocket = new QUdpSocket(this);
        p_WBSocket->bind(QHostAddress::LocalHost,15201);
    connect(p_WBSocket,SIGNAL(readyRead()),this,SLOT(readPendingDatagrams()));
    this->drawpen();
    BrushStyle = Qt::NoBrush;
    MovedFlag = false;
}
QtBoard::~QtBoard()
{

//    delete aboutAction;
//    delete rectAction;
//    delete lineAction;
//    delete ellipseAction;
//    delete penAction;
//    delete eraserAction;

//    delete widthLabel;
//    delete fillLabel;
//    delete lineLabel;
//    delete lineButton;
//    delete fillButton;
//    delete spinbox;

//    image.detach();;
//    tempimage.detach();;
}

void QtBoard::createActions()
{
    OpenAction = new QAction(QIcon(":QtBoardImages/Images/open.png"),tr("Open"),this); //打开动作
    OpenAction->setShortcut(tr("Ctrl+O"));
    OpenAction->setStatusTip(tr("open a file"));
    connect(OpenAction,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

    NewAction = new QAction(QIcon(":QtBoardImages/Images/new.png"),tr("New"),this);//新建动作
    NewAction->setShortcut(tr("Ctrl+N"));
    NewAction->setStatusTip(tr("new file"));
    connect(NewAction,SIGNAL(triggered()),this,SLOT(slotNewFile()));

    SaveAction = new QAction(QPixmap(":QtBoardImages/Images/save.png"),tr("Save"),this); //保存动作
    SaveAction->setShortcut(tr("Ctrl+S"));
    SaveAction->setStatusTip(tr("save file"));
    connect(SaveAction,SIGNAL(activated()),this,SLOT(slotSaveFile()));

    exitAction = new QAction(tr("Exit"), this);//退出动作
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("exit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));


    aboutAction = new QAction(tr("About"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(slotAbout()));

    penAction = new QAction(QIcon(":QtBoardImages/Images/huabi.png"),tr("pen"),this);//画笔
    penAction->setStatusTip(tr("draw anything"));
    connect(penAction,SIGNAL(triggered()),this,SLOT(drawpen()));


    lineAction = new QAction(QIcon(":QtBoardImages/Images/zhixian.png"),tr("line"),this);//画线
    lineAction->setStatusTip(tr("draw a line"));
    connect(lineAction,SIGNAL(triggered()),this,SLOT(drawlines()));

    rectAction = new QAction(QIcon(":QtBoardImages/Images/juxing.png"),tr("rect"),this); //画方框
    rectAction->setStatusTip(tr("draw a rect"));
    connect(rectAction,SIGNAL(triggered()),this,SLOT(drawrects()));

    ellipseAction = new QAction(QIcon(":QtBoardImages/Images/yuan.png"),tr("circle"),this);//画圆
    ellipseAction->setStatusTip(tr("draw a ellipse"));
    connect(ellipseAction,SIGNAL(triggered()),this,SLOT(drawellipses()));

    eraserAction = new QAction(QIcon(":QtBoardImages/Images/xiangpica.png"),tr("eraser"),this);//橡皮擦
    eraserAction->setStatusTip(tr("clean image"));
    connect(eraserAction,SIGNAL(triggered()),this,SLOT(draweraser()));

}

void QtBoard::createMenus()//创建菜单
{
    fileMenu = menuBar()->addMenu(tr("File"));
    aboutMenu = menuBar()->addMenu(tr("Help"));

    fileMenu->addAction(NewAction);
    fileMenu->addAction(OpenAction);
    fileMenu->addAction(SaveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);



    aboutMenu->addAction(aboutAction);
}

void QtBoard::createToolBar()//创建工具栏
{
    fileTool = addToolBar(tr("file"));
    fileTool->addAction(NewAction);
    fileTool->addAction(OpenAction);
    fileTool->addAction(SaveAction);
    fileTool->addSeparator();

    paintTool = addToolBar(tr("Paint"));
    paintTool->addAction(penAction);
    paintTool->addAction(eraserAction);
    paintTool->addAction(lineAction);
    paintTool->addAction(rectAction);
    paintTool->addAction(ellipseAction);

    lineLabel = new QLabel(tr(" line color"));
    linecolor.setRgb(0,170,255);
    paintTool->addWidget(lineLabel);
    lineButton = new QToolButton();
    QIcon lineButtonIcon ;
    lineButtonIcon.addFile(":QtBoardImages/Images/lineButtonIcon.png");
    lineButton->setIcon( lineButtonIcon );
    paintTool->addWidget(lineButton);
    //lineButton->setPalette(QPalette(linecolor));
    lineButton->setAutoFillBackground(true);
    connect(lineButton,SIGNAL(clicked()),this,SLOT(drawPaletteline()));


    fillLabel = new QLabel(tr(" fill color"));
    fillcolor.setRgb(0,170,255);
    QIcon fillButtonIcon ;
    fillButtonIcon.addFile(":QtBoardImages/Images/fillButtonIcon.png");
    paintTool->addWidget(fillLabel);
    fillButton = new QToolButton();
    paintTool->addWidget(fillButton);
    fillButton->setIcon( fillButtonIcon );
    //fillButton->setPalette(QPalette(fillcolor));
    fillButton->setAutoFillBackground(true);
    connect(fillButton,SIGNAL(clicked()),this,SLOT(drawPalettefill()));

 //   widthLabel = new QLabel();
  //  widthLabel->setPicture();
    spinbox = new QSpinBox();
    spinbox->setValue(3);
    spinbox->setRange(0,50);
    paintTool->addWidget(spinbox);
    connect(spinbox,SIGNAL(valueChanged(int)),this,SLOT(drawwidth()));

    brushLabel = new QLabel(tr(" IsShapeFill"));
    brushcheck = new QCheckBox();
    brushcheck->setCheckState( Qt::Unchecked );
    paintTool->addWidget(brushLabel);
    paintTool->addWidget( brushcheck );
    connect(brushcheck, SIGNAL(stateChanged(int)),this,SLOT(BrushChange()));


}

void QtBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(m_bDrawing==true)
    {
        painter.drawImage(0,53,tempimage);
    }
    else
    {
        painter.drawImage(0,53,image);
    }
}

void QtBoard::mouseMoveEvent(QMouseEvent *event)
{

//    this->setCursor(QCursor(Qt::BitmapCursor));
    if(event->buttons()&Qt::LeftButton)
    {
  //     QPainter painter(&image);
        endPoint = event->pos();
        endPoint.setY(endPoint.y()-50);
        tempimage = image;
        if(m_Tool==pen||m_Tool==eraser)
        {
            paint(image);
        }
        else
        {
            paint(tempimage);
        }
    }
    MovedFlag = true;
}

void QtBoard::mouseReleaseEvent(QMouseEvent *event)
{
    if( m_Tool == eraser ){paint(image);return;}
    if( !MovedFlag )return;
    m_bDrawing = false;
//    if(m_Tool==line||m_Tool==rect||m_Tool==ellipse){
    paint(image);
//    }
    MovedFlag = false;
}

void QtBoard::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        m_bDrawing = true;

        startPoint=event->pos();
        startPoint.setY(startPoint.y()-50);
    }
}

void QtBoard::paint(QImage &image)//画图函数
{
    if(this->m_bOwnerDraw)
    {
        if(!this->m_bDrawing || pen == m_Tool || eraser == m_Tool)
        {
            SendDrawInfoToYate(startPoint,endPoint);
        }
    }
    QPainter painter(&image);
    QPen apen;
    apen.setStyle(Qt::SolidLine);
    apen.setColor(linecolor);
    apen.setWidth(w);
    painter.setPen(apen);
    painter.setBrush(QBrush(fillcolor,BrushStyle));
    switch(m_Tool)
    {
    case line:
        painter.drawLine(startPoint,endPoint);
        break;
    case rect:
        painter.drawRect(startPoint.x(),startPoint.y(),
                         (endPoint.x()-startPoint.x()),
                         (endPoint.y()-startPoint.y()));
         break;
    case ellipse:
         painter.drawEllipse(startPoint.x(),startPoint.y(),
                            (endPoint.x()-startPoint.x()),
                            (endPoint.y()-startPoint.y()));

         break;
    case pen:
         painter.drawLine(startPoint,endPoint);

         startPoint = endPoint;
         break;
    case eraser:
//         painter.eraseRect(startPoint.x(),startPoint.y(),w,w);
         QPen EraserPen;
         EraserPen.setColor(Qt::white);
         EraserPen.setWidth(w);
         painter.setPen( EraserPen );
         painter.drawLine(startPoint,endPoint);
         startPoint = endPoint;
         break;
    }
    update();
    this->repaint();
}

void QtBoard::paint(DRAWINFO drawInfo)//由画图信息画图的函数
{
    QPainter painter(&image);
    QPen apen;
    apen.setStyle(Qt::SolidLine);
    apen.setColor(drawInfo.lineColor);
    apen.setWidth(drawInfo.width);
    painter.setPen(apen);
    painter.setBrush(QBrush(drawInfo.fillColor, drawInfo.brushStyle));
    switch(drawInfo.m_Tool)
    {
    case line:
        painter.drawLine(drawInfo.StartPoint,drawInfo.EndPoint);
        break;
    case rect:
        painter.drawRect(drawInfo.StartPoint.x(),drawInfo.StartPoint.y(),
                         (drawInfo.EndPoint.x() - drawInfo.StartPoint.x()),
                         (drawInfo.EndPoint.y() - drawInfo.StartPoint.y()));
         break;
    case ellipse:
         painter.drawEllipse(drawInfo.StartPoint.x(),drawInfo.StartPoint.y(),
                             (drawInfo.EndPoint.x() - drawInfo.StartPoint.x()),
                             (drawInfo.EndPoint.y() - drawInfo.StartPoint.y()));

         break;
    case pen:
         painter.drawLine(drawInfo.StartPoint, drawInfo.EndPoint);
         break;
    case eraser:
         QPen EraserPen;
         EraserPen.setColor(Qt::white);
         EraserPen.setWidth(drawInfo.width);
         painter.setPen( EraserPen );
         painter.drawLine(drawInfo.StartPoint, drawInfo.EndPoint);
         break;
    }
    update();
    this->repaint();
}

void QtBoard::slotNewFile()
{
    QtBoard *newWin = new QtBoard();
    newWin->show();
}

void QtBoard::slotOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName
                                    (this,tr("Open File"),
                                     "/",
                                     tr("Images (*.png *.xpm *.jpg)"));

    image.load(fileName);
    update();
}

void QtBoard::slotSaveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),
                                                    "/",tr("Images(*.png *.xpm *.jpg"));
    image.save(fileName);
    update();

}



void QtBoard::slotAbout()
{
    QMessageBox::StandardButton help;
    help = QMessageBox::information(this,"YATEWHITEBOARD","This is a Qt drawing board program",
                                    QMessageBox::Yes);

}

void QtBoard::drawlines()
{
    m_Tool = line;
}

void QtBoard::drawrects()
{
    m_Tool = rect;
}

void QtBoard::drawellipses()
{
    m_Tool = ellipse;
}

void QtBoard::drawpen()
{
    m_Tool = pen;
}

void QtBoard::draweraser()
{
    m_Tool = eraser;
}

void QtBoard::drawPaletteline() //线颜色
{
    linecolor = QColorDialog::getColor(Qt::black,this);
    if(linecolor.isValid())
    {
//        lineButton->setPalette(QPalette(linecolor));
        lineButton->setAutoFillBackground(true);
    }
}

void QtBoard::drawPalettefill()//填充色
{
    fillcolor = QColorDialog::getColor(Qt::white,this);
    if(fillcolor.isValid())
    {
        fillButton->setPalette(QPalette(fillcolor));
        fillButton->setAutoFillBackground(true);
    }
}

void QtBoard::drawwidth()//设置橡皮擦，线条宽度
{
    w = spinbox->value();
}

void QtBoard::BrushChange()//设置画刷，
{
    BrushStyle = brushcheck->isChecked() ?
            Qt::SolidPattern
            : Qt::NoBrush;
}
void QtBoard::SendDrawInfoToYate(QPoint StartPoint,QPoint EndPoint)          //发送画图消息给Yate
{
    DRAWINFO drawInfo;
    drawInfo.brushStyle = BrushStyle;
    drawInfo.EndPoint = EndPoint;
    drawInfo.fillColor = fillcolor;
    drawInfo.lineColor = linecolor;
    drawInfo.m_Tool = m_Tool;
    drawInfo.StartPoint = StartPoint;
    drawInfo.width = w;
	uint len = sizeof(DRAWINFO);
    char *pSendData = new char[sizeof(DRAWINFO)];
	memset(pSendData,0,sizeof(DRAWINFO));
    memcpy(pSendData,&drawInfo,sizeof(DRAWINFO));
	char Send[60];
 //   QByteArray dataSend = drawInfo;
	//dataSend.resize(sizeof(DRAWINFO));
	//dataSend.q
	QUdpSocket *Sender = new QUdpSocket(this);
    Sender->bind(QHostAddress("127.0.0.1"),15200);
    Sender->writeDatagram(pSendData,sizeof(DRAWINFO),QHostAddress("127.0.0.1"),15201);

}
void QtBoard::readPendingDatagrams()
{
    char *p_dataGram;
    p_dataGram = new char[p_WBSocket->pendingDatagramSize()];
	memset(p_dataGram,0,p_WBSocket->pendingDatagramSize());

    while(p_WBSocket->hasPendingDatagrams())
    {
		
        p_WBSocket->readDatagram(p_dataGram,sizeof(m_drawInfo));
    }
	//CharArrayToDrawInfo(&m_drawInfo,p_dataGram,sizeof(m_drawInfo.m_Tool));
    memcpy(&m_drawInfo,p_dataGram,sizeof(m_drawInfo));
	paint(m_drawInfo);
}
void QtBoard::CharArrayToDrawInfo( DRAWINFO * Dst,const char* Src, int size)
{
	/*    typedef struct DrawInfo
    {
        TOOLS   m_Tool;
        int     width;
        QColor  lineColor;
        QColor  fillColor;
        Qt::
                BrushStyle
                brushStyle;
        QPoint  StartPoint;
        QPoint  EndPoint;
    }DRAWINFO;
*/
	Dst->m_Tool = (TOOLS)(*Src);
	Dst->width = (int)(*(Src+(sizeof(int))));
	Dst->lineColor = (QColor)(*(Src+(sizeof(int)*2)));
	Dst->fillColor = (QColor)(*(Src+(sizeof(int)*2+sizeof(QColor))));
	Dst->brushStyle = (Qt::BrushStyle)(*(Src+(sizeof(int)*2+sizeof(QColor)*2)));
	//Dst->StartPoint = (QPoint)(*(Src+(sizeof(int)*2+sizeof(QColor)*2+sizeof(BrushStyle))));
	//Dst->EndPoint =  (QPoint)(*(Src+(sizeof(int)*2+sizeof(QColor)*2+sizeof(BrushStyle)+sizeof(QPoint))));
	
}
