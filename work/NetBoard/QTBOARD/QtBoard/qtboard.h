#ifndef QTBOARD_H
#define QTBOARD_H

#include <QMainWindow>
#include <QtNetwork>

//namespace UiSuanec {
//    class QtBoard;
//}

class QAction;
class QMenu;
class QToolBar;
class QImage;
class QPoint;
class QColor;
class QBrush;
class QPen;
class QLabel;
class QToolButton;
class QSpinBox;
class QCheckBox;
class QBitmap;


class QtBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtBoard();
    ~QtBoard();
    void createMenus();
    void createActions();
    void createToolBar();
    enum TOOLS
    {
        line=1,                             /// ֱ��
        rect,                               /// ����
        ellipse,                            /// ��Բ
        pen,                                /// ����
        eraser,                             /// ��Ƥ��
        CLEARGRAPHICS,                      /// ���ͼ��
    };
    typedef struct DrawInfo
    {
        Qt::
                BrushStyle
                brushStyle;
        QPoint  EndPoint;
        QColor  fillColor;
        QColor  lineColor;
        TOOLS   m_Tool;
        QPoint  StartPoint;
        int     width;
    }DRAWINFO;

public slots:
    void slotNewFile();
    void slotOpenFile();
    void slotSaveFile();

    void slotAbout();
    void drawrects();
    void drawlines();
    void drawellipses();
    void drawpen();
    void draweraser();
    void drawPaletteline();
    void drawPalettefill();
    void drawwidth();
    void BrushChange();
    void readPendingDatagrams();


protected:
    bool        MovedFlag;
    void        mousePressEvent(QMouseEvent *);
    void        mouseMoveEvent(QMouseEvent *);
    void        mouseReleaseEvent(QMouseEvent *);
    void        mouseLeaveEvent(QMouseEvent *);
    void        paintEvent(QPaintEvent *);
    void        paint(QImage &image);
    void        paint(DRAWINFO drawInfo);   /// �ɻ�ͼ��Ϣ��ͼ�ĺ���
    void        SendDrawInfoToYate
                (QPoint StartPoint,
                 QPoint EndPoint);          /// ���ͻ�ͼ��Ϣ��Yate
    bool        m_bDrawing;         /// �Ƿ��ڻ�ͼ��
    bool        m_bOwnerDraw;       /// �Ƿ����Լ���ͼ���Ǳ��˻�ͼ
private:
    QMenu       *fileMenu;
    QMenu       *editMenu;
    QMenu       *aboutMenu;
    QToolBar    *fileTool;
    QToolBar    *paintTool;
    QAction     *OpenAction;
    QAction     *NewAction;
    QAction     *SaveAction;
    QAction     *exitAction;

    QAction     *aboutAction;
    QAction     *rectAction;
    QAction     *lineAction;
    QAction     *ellipseAction;
    QAction     *penAction;
    QAction     *eraserAction;

    QLabel      *widthLabel;
    QLabel      *fillLabel;
    QLabel      *lineLabel;
    QLabel      *brushLabel;
    QToolButton *lineButton;
    QToolButton *fillButton;
    QSpinBox    *spinbox;
    QCheckBox   *brushcheck;

    QImage      image;
    QImage      tempimage;
    QPoint      startPoint;
    QPoint      endPoint;
    TOOLS       m_Tool ;
    QColor      fillcolor;
    QColor      linecolor;
    QBrush      brush;
    Qt::\
    BrushStyle  BrushStyle;

    QUdpSocket  *p_WBSocket;        /// �����߳�
    DRAWINFO    m_drawInfo;
    int         w;
    void        CharArrayToDrawInfo( DRAWINFO * Dst,const char*, int size);

};

#endif // QTBOARD_H
