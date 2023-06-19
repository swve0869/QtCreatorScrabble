#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tile.h"
#include "space.h"
#include "opendialog.h"
#include "playerinfodialog.h"
#include "blankcreater.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QtMultimedia/QMediaPlayer>
//#include <QSound>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayPlayerTiles(Player* p);
    void displayScores();
    void removePlayerTiles(Player*p);
    void pullTiles(Player* p);
    Tile* letterTileGen(char let);
    void swapTiles(Tile* t1, Tile* t2);
    void placeTile(Tile* tile,Space* space);
    void drawNewTile();
    void playBomb(Tile* bTile);
    void blankLetterCreate();
    void sort(std::vector<Tile*>& word);
    void gameOver();
    std::vector<Tile*> findUpDown(Tile* t);
    std::vector<Tile*> findLeftRight(Tile* t);
    bool validatePlay(Player* p);
    bool checkConnect(std::vector<Tile*>v);
    bool checkCont(std::vector<Tile*>v,int o);
    bool validateWord(QString q);
    bool checkAllResigned();
    bool noTilesOnBoard();
    int checkVert(std::vector<Tile*> wordVec);    // returns 0 if neither 1 for vertical 2 for horizontal

    void nextTurn();



    //helpers
    int tilesLeft();
    void printBag();
    void printWord(std::vector<Tile*> word);
    QString constructWord(std::vector<Tile*> word);


private slots:
    void tileSelectedSlot(Tile* tile);
    void spaceSelectedSlot(Space* space);
    void on_submitButton_clicked();
    void on_passButton_clicked();
    void on_drawButton_clicked();
    void numPlayersSlot(int n);
    void blankSubmitSlot(char let);
    void createPlayersSlot(std::vector<Player*> p);


    void on_resignButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    std::vector<char> alpha_;
    std::vector<std::vector<int>>  init;
    std::vector<std::vector<sType>>  locations_;
    std::map<char,int> valueMap_;
    std::map<char,QPixmap> spriteMap_;

    std::vector<Player*> players_;

    std::map<char,int> bag_;
    std::vector<std::vector<Space*>> boardSpaces_;
    Tile*  boardTiles_[15][15];
    QStringList words_;

    Tile* selectedTile_;
    Tile* daBlank_;
    Player* curPlayer;
    int numPlayers_;
    int turnCount_;
    bool firstPlay_;
    bool drawNew_;
    bool blankLetterSelected_;

    std::vector<QLabel*> pointLabels_;

    const static int wi = 47;  // 40      graphics 650 711
    // 3 + 15 * (60 +3)
    const static int pTileX_ = 3+(4*(wi+3));  //170;
    const static int pTileY_ = 3+(15*(wi+3)) + 10; // 655
    const static int tileTypeCount_ = 28;    // increase to 30 after adding special tiles

    QColor blankColor_ = QColor(255,255,255);
    QColor pTileBlankColor_ = QColor(105,105,105);
    QColor backGroundColor_ = QColor(220,220,220);

    QMediaPlayer* pop;
    QMediaPlayer* fail;
    QMediaPlayer* wow;
    QMediaPlayer* win;
    QMediaPlayer* bomb;
    QAudioOutput* audioOutput1;
    QAudioOutput* audioOutput2;
    QAudioOutput* audioOutput3;
    QAudioOutput* audioOutput4;
    QAudioOutput* audioOutput5;





};
#endif // MAINWINDOW_H
