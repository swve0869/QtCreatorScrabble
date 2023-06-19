#include "mainwindow.h"
#include "enddialog.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QDir>
#include<QRandomGenerator>
#include <string>
#include <algorithm>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    openDialog * start =  new openDialog;
    connect(start,&openDialog::numPlayers,this,&MainWindow::numPlayersSlot);
    start->setModal(true);
    start->exec();

    playerInfoDialog * pInfo = new playerInfoDialog(numPlayers_);
    connect(pInfo,&playerInfoDialog::createPlayers,this,&MainWindow::createPlayersSlot);
    pInfo->setModal(true);
    pInfo->exec();

    ui->setupUi(this);
    QGraphicsView * view = ui->graphicsView;
        scene  = new QGraphicsScene;
        view->setScene(scene);
        view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setBackgroundBrush(QBrush(backGroundColor_, Qt::SolidPattern));


        //get words from words list
        QFile inputFile(":/imgs/wordList.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              words_.append(line);
           }
           inputFile.close();
        }

        // alphabet/letter tile list
        std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234";
          for( char c : alphabet) {
            alpha_.push_back(c);
          }

        // letter values initialization
       valueMap_= {{'A',1},{'B',3},{'C',3},{'D',2},{'E',1},{'F',4},{'G',2},{'H',4},{'I',1},{'J',8},{'K',5},{'L',1},{'M',3},{'N',1},{'O',1},
                   {'P',3},{'Q',10},{'R',1},{'S',1},{'T',1},{'U',1},{'V',4},{'W',4},{'X',8},{'Y',4},{'Z',10},{'1',0},{'2',0},{'3',0},{'4',0}};


       ///CHANGE BLANK COUNT LAter
        // Bag initialization
        bag_ = {{'A',9},{'B',2},{'C',2},{'D',4},{'E',12},{'F',2},{'G',3},{'H',2},{'I',9},{'J',1},{'K',1},{'L',4},{'M',2},{'N',6},{'O',8},
                {'P',2},{'Q',1},{'R',6},{'S',4},{'T',6},{'U',4},{'V',2},{'W',2},{'X',1},{'Y',2},{'Z',1},{'1',4},{'2',2},{'3',2},{'4',2}};

        //bag_ = {{'A',1},{'B',1},{'C',1},{'D',1},{'E',1},{'F',1},{'G',1},{'H',1},{'I',1},{'J',1},{'K',1},{'L',1},{'M',1},{'N',1},{'O',1},
        //        {'P',1},{'Q',1},{'R',1},{'S',1},{'T',1},{'U',1},{'V',1},{'W',1},{'X',1},{'Y',1},{'Z',1},{'1',1},{'2',1},{'3',1},{'4',1}};


        // Initialize pix maps for letter Tiles
        spriteMap_['A'] = QPixmap(":/imgs/PNG/Blue/letter_A.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['B'] = QPixmap(":/imgs/PNG/Blue/letter_B.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['C'] = QPixmap(":/imgs/PNG/Blue/letter_C.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['D'] = QPixmap(":/imgs/PNG/Blue/letter_D.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['E'] = QPixmap(":/imgs/PNG/Blue/letter_E.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['F'] = QPixmap(":/imgs/PNG/Blue/letter_F.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['G'] = QPixmap(":/imgs/PNG/Blue/letter_G.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['H'] = QPixmap(":/imgs/PNG/Blue/letter_H.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['I'] = QPixmap(":/imgs/PNG/Blue/letter_I.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['J'] = QPixmap(":/imgs/PNG/Blue/letter_J.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['K'] = QPixmap(":/imgs/PNG/Blue/letter_K.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['L'] = QPixmap(":/imgs/PNG/Blue/letter_L.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['M'] = QPixmap(":/imgs/PNG/Blue/letter_M.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['N'] = QPixmap(":/imgs/PNG/Blue/letter_N.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['O'] = QPixmap(":/imgs/PNG/Blue/letter_O.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['P'] = QPixmap(":/imgs/PNG/Blue/letter_P.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['Q'] = QPixmap(":/imgs/PNG/Blue/letter_Q.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['R'] = QPixmap(":/imgs/PNG/Blue/letter_R.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['S'] = QPixmap(":/imgs/PNG/Blue/letter_S.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['T'] = QPixmap(":/imgs/PNG/Blue/letter_T.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['U'] = QPixmap(":/imgs/PNG/Blue/letter_U.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['V'] = QPixmap(":/imgs/PNG/Blue/letter_V.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['W'] = QPixmap(":/imgs/PNG/Blue/letter_W.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['X'] = QPixmap(":/imgs/PNG/Blue/letter_X.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['Y'] = QPixmap(":/imgs/PNG/Blue/letter_Y.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['Z'] = QPixmap(":/imgs/PNG/Blue/letter_Z.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['1'] = QPixmap(":/imgs/PNG/Blue/letter.png").scaled(wi,wi,Qt::IgnoreAspectRatio);
        spriteMap_['2'] = QPixmap(":/imgs/PNG/Blue/bomb.png").scaled(wi,wi,Qt::IgnoreAspectRatio);


        // Board Initialization :/imgs/PNG/special/double_letter.png
        QPixmap blank(":/assets/assets/PNG/special/blank.png");   blank = blank.scaled(wi,wi,Qt::IgnoreAspectRatio);
        QPixmap tripWord(":/imgs/PNG/special/triple_word.png");   tripWord = tripWord.scaled(wi,wi,Qt::IgnoreAspectRatio);
        QPixmap tripLet(":/imgs/PNG/special/tripple_letter.png"); tripLet  = tripLet.scaled(wi,wi,Qt::IgnoreAspectRatio);
        QPixmap doubWord(":/imgs/PNG/special/double_word.png");   doubWord = doubWord.scaled(wi,wi,Qt::IgnoreAspectRatio);
        QPixmap doubLet(":/imgs/PNG/special/double_letter.png");  doubLet = doubLet.scaled(wi,wi,Qt::IgnoreAspectRatio);
        // 0 =  blank  1 = doubleLetter 2 = tripL  3 = doubWord  4 = trippleWord
        init   =     {{4,0,0,1,0,0,0,4,0,0,0,1,0,0,4},  //1
                      {0,3,0,0,0,2,0,0,0,2,0,0,0,3,0},  //2
                      {0,0,3,0,0,0,1,0,1,0,0,0,3,0,0},  //3
                      {1,0,0,3,0,0,0,1,0,0,0,3,0,0,1},  //4
                      {0,0,0,0,3,0,0,0,0,0,3,0,0,0,0},  //5
                      {0,2,0,0,0,2,0,0,0,2,0,0,0,2,0},  //6
                      {0,0,1,0,0,0,1,0,1,0,0,0,1,0,0},  //7
                      {4,0,0,1,0,0,0,3,0,0,0,1,0,0,4},  //8
                      {0,0,1,0,0,0,1,0,1,0,0,0,1,0,0},  //9
                      {0,2,0,0,0,2,0,0,0,2,0,0,0,2,0},  //10
                      {0,0,0,0,3,0,0,0,0,0,3,0,0,0,0},  //11
                      {1,0,0,3,0,0,0,1,0,0,0,3,0,0,1},  //12
                      {0,0,3,0,0,0,1,0,1,0,0,0,3,0,0},  //13
                      {0,3,0,0,0,2,0,0,0,2,0,0,0,3,0},  //14
                      {4,0,0,1,0,0,0,4,0,0,0,1,0,0,4},  //15
                    };

        int pad = 3; int x = pad; int y = pad;
        QColor co = QColor(255,255,255);
        for(int r = 0; r < 15; r ++){
            std::vector <Space*> tmp;
            for(int c = 0; c < 15; c++){
                Space * nspace;
                switch(init[r][c]){
                case 0: nspace = new Space(x,y,r,c,wi,0,blankColor_,blank, sType::blank   , 1); break;
                case 1: nspace = new Space(x,y,r,c,wi,1,co,doubLet,  sType::letterM , 2); break;
                case 2: nspace = new Space(x,y,r,c,wi,1,co,tripLet,  sType::letterM , 3); break;
                case 3: nspace = new Space(x,y,r,c,wi,1,co,doubWord, sType::wordM   , 2); break;
                case 4: nspace = new Space(x,y,r,c,wi,1,co,tripWord, sType::wordM   , 3); break;
                }
                connect(nspace,&Space::spaceSelected,this,&MainWindow::spaceSelectedSlot);
                scene -> addItem(nspace);
                tmp.push_back(nspace);
                x += wi + pad;

                boardTiles_[r][c] = nullptr;
            }
            boardSpaces_.push_back(tmp);
            y += wi + pad;
            x = pad;
        }
        //Display blank Player tile spaces
        x = pTileX_; y = pTileY_;
        for(int i = 0; i < 7; i++){
            Space* nspace = new Space(x,y,0,0,wi,-1,pTileBlankColor_,blank, sType::pTileBlank,1);
            connect(nspace,&Space::spaceSelected,this,&MainWindow::spaceSelectedSlot);
            scene -> addItem(nspace);
            x += wi + pad;
        }

        // initialize non list vars ----------------------------------
        selectedTile_ = nullptr;
        daBlank_ = nullptr;
        turnCount_ = 0;
        firstPlay_ = false;
        drawNew_ = false;
        blankLetterSelected_ = false;

        //----------------------------------
        pop = new QMediaPlayer;
        audioOutput1 = new QAudioOutput;
        pop->setAudioOutput(audioOutput1);
        pop->setSource(QUrl("qrc:/imgs/sounds/mp3/place.mp3"));

        fail = new QMediaPlayer;
        audioOutput2 = new QAudioOutput;
        fail->setAudioOutput(audioOutput2);
        fail->setSource(QUrl("qrc:/imgs/sounds/mp3/bink.mp3"));

        win = new QMediaPlayer;
        audioOutput3 = new QAudioOutput;
        win->setAudioOutput(audioOutput3);
        win->setSource(QUrl("qrc:/imgs/sounds/mp3/win.mp3"));

        wow = new QMediaPlayer;
        audioOutput4 = new QAudioOutput;
        wow->setAudioOutput(audioOutput4);
        wow->setSource(QUrl("qrc:/imgs/sounds/mp3/wow.mp3"));

        bomb = new QMediaPlayer;
        audioOutput5 = new QAudioOutput;
        bomb->setAudioOutput(audioOutput5);
        bomb->setSource(QUrl("qrc:/imgs/sounds/mp3/bomb.mp3"));


        displayScores();
        nextTurn();
    }

void MainWindow::displayPlayerTiles(Player* p){

        int x = pTileX_;
        int y = pTileY_;
        for(unsigned long i = 0; i < p->pTiles_.size(); i++){
            //qDebug() <<  p ->pTiles_[i]->get_letter();
            p ->pTiles_[i]->setXY(x,y);
            scene -> removeItem(p->pTiles_[i]);
            scene -> addItem(p->pTiles_[i]);
            x += wi + 3;
        }

        // display player name
        std::string s = p -> name_ + "'s turn";
        QString qs(s.c_str());
        ui->nameLabel->setText(qs);
        ui->nameLabel->setStyleSheet("QLabel {color : white; }");

    }

void MainWindow::displayScores(){
    static int a = 0;

    int x = 780;
    int y = 10;
    if(a == 0){
        for(unsigned long i = 0; i < players_.size(); i++){
            QLabel * score = new QLabel();
            score -> setGeometry(x,y,150,30);
            score -> setParent(this);
            std::string s = players_[i]->name_ + " : 0 Points";
            QString q(s.c_str());
            score -> setText(q);
            score ->setStyleSheet("QLabel {color : white; }");
            score -> update();
            pointLabels_.push_back(score);
            y += 30;
        }
    }

    // populate other player Scores
    for(unsigned long i = 0; i < pointLabels_.size(); i++){
        std::string pts = std::to_string(players_[i]->points_);
       // qDebug() << "si";
       // qDebug() << QString(pts.c_str());
       // qDebug() <<  players_[i]->points_;
        std::string s = players_[i]->name_ + " : " + std::to_string(players_[i]->points_) + " Points";
        QString q(s.c_str());
        qDebug() << q;
        pointLabels_[i] -> setText(q);
        pointLabels_[i] -> update();
        y += 30;
    }

    a++;

}


void MainWindow::removePlayerTiles(Player*p){
    for(unsigned long i = 0; i < p->pTiles_.size(); i++){
        scene -> removeItem(p->pTiles_[i]);
    }
}

void MainWindow::sort(std::vector<Tile*>& word){
    std::vector<Tile*> tmp;
    for(unsigned long i = 0; i < word.size(); i ++){
        tmp.push_back(word[i]);
    }
    word.clear();

    for(int r = 0; r < 15; r++){
        for(int c = 0; c < 15; c++){
            for(unsigned long i = 0; i < tmp.size(); i ++){
                if(tmp[i] -> get_row() == r &&  tmp[i] -> get_col() == c){
                     word.push_back(tmp[i]);
                }
            }
        }
    }
}

void MainWindow::pullTiles(Player * p){
    QRandomGenerator gen;
    int amt = 7 - p->pTiles_.size();

        if(amt > tilesLeft()){ // check for not enough tiles left
            return;
        }
        for(int i =0; i < amt; i++){
            char ch;
            bool found = false;
            while(!found){
                int r = QRandomGenerator::global()->bounded(0, tileTypeCount_);
                ch = alpha_[r];
                if(bag_[ch] != 0){
                   found = true;
                }
            }

            Tile* newT = letterTileGen(ch);
            connect(newT,&Tile::tileSelected,this,&MainWindow::tileSelectedSlot);
            bag_[ch] --;

            if(newT){
                p -> pTiles_.push_back(newT);
            }
        }

    }

Tile* MainWindow::letterTileGen(char let){

    if(let =='1' || let =='2'  || let =='3' || let =='4' ){
        if(let =='1'){
            return new Tile(0,0,0,0,wi,0,spriteMap_[let],tType::blankLetter, let,valueMap_[let]);
        }
        if(let =='2'){
            return new Tile(0,0,0,0,wi,0,spriteMap_[let],tType::bomb, let,valueMap_[let]);
        }

    }
    else{
        return new Tile(0,0,0,0,wi,0,spriteMap_[let],tType::letter, let,valueMap_[let]);
    }
}

void MainWindow::swapTiles(Tile* t1, Tile* t2){
    scene ->removeItem(t1);
    scene ->removeItem(t2);
    int tempx = t1->get_x(); int tempy = t1->get_y(); int temprow = t1->get_row(); int tempcol = t1->get_col(); int tempstate = t1 -> get_state();
    t1 -> setXY(t2->get_x()  , t2->get_y());
    t1 -> setRC(t2->get_row(), t2->get_col());
    t1 -> setState(t2-> get_state());
    t2 -> setXY(tempx,tempy);
    t2 -> setRC(temprow,tempcol);
    t2 -> setState(tempstate);
    scene ->addItem(t1);
    scene ->addItem(t2);
}

void MainWindow::drawNewTile(){

    char ch;
    bool found = false;
    while(!found){
        int r = QRandomGenerator::global()->bounded(0,tileTypeCount_); // MAKE SURE TO CHANGE BACK TO 30 after adding other tiles types!!
        ch = alpha_[r];
        if(bag_[ch] != 0){
           found = true;
        }
    }

    Tile* newT = letterTileGen(ch);
    newT -> setXY(selectedTile_ -> get_x(), selectedTile_ -> get_y());
    newT ->setState(2);
    connect(newT,&Tile::tileSelected,this,&MainWindow::tileSelectedSlot);
    bag_[ch] --;

    for(unsigned long i = 0; i < 7; i++){
        if(curPlayer->pTiles_[i] == selectedTile_){
            curPlayer->pTiles_[i] = newT;
        }
    }

    scene -> removeItem(selectedTile_);
    scene -> addItem(newT);

    for(unsigned long i = 0; i < 7; i++){
        curPlayer->pTiles_[i]->print();
      }


}

void MainWindow::placeTile(Tile* tile,Space* space){

    scene ->removeItem(tile);
    scene ->removeItem(space);
    if(space -> get_state() == -1){   // set state back to 0 of returned to tray
        tile -> setState(0);
    }else{
        tile -> setState(1);
    }
    tile -> setXY(space->get_x(),space->get_y());
    tile -> setRC(space->get_row(),space->get_col());
    scene ->addItem(space);
    scene ->addItem(tile);
}

void MainWindow::gameOver(){
    qDebug() << "in game over";

    this -> close();
    endDialog * end =  new endDialog(players_);
    //connect(start,&openDialog::numPlayers,this,&MainWindow::numPlayersSlot);
    end->setModal(true);
    end->exec();

}

void MainWindow::nextTurn(){

    qDebug() << tilesLeft() << "tiles left";

    if(turnCount_ == 0){
        curPlayer = players_[0];
        pullTiles(curPlayer);
        displayPlayerTiles(curPlayer);
        turnCount_ ++;
        return;
    }

   // if(noTilesOnBoard()){
    //    firstPlay_ = true;
   // }

    removePlayerTiles(curPlayer);
    selectedTile_ = nullptr;

    curPlayer = players_[turnCount_ % numPlayers_];
    pullTiles(curPlayer);
    displayPlayerTiles(curPlayer);
    turnCount_ ++;
    if(curPlayer->resigned_){
        if(checkAllResigned()){ // check if everyone has resigned
            gameOver();
        }else{
            curPlayer = players_[turnCount_ % numPlayers_];
            pullTiles(curPlayer);
            displayPlayerTiles(curPlayer);
            turnCount_ ++;
        }
    }
}

bool MainWindow::checkAllResigned(){
    for(unsigned long i = 0; i < players_.size(); i++){
        if(!players_[i] -> resigned_){
            return false;
        }
    }
    qDebug() << "everyone resigned";
    return true;
}

int MainWindow::checkVert(std::vector<Tile*>v){  // returns 0 if neither     1 for vertical 2 for horizontal


    bool vert = true;
    bool hori = true;
    for(unsigned long i = 0; i < v.size() -1; i ++){
        if(v[i] -> get_row() != v[i+1] -> get_row()){
            hori = false;
        }
        if(v[i] -> get_col() != v[i+1] -> get_col()){
            vert = false;
        }
    }
    if(!vert && !hori){ return 0;}  // return failure not a straight line
    if(vert) {return 1;}
    if(hori) {return 2;}
    return 0;
}

bool MainWindow::checkConnect(std::vector<Tile*>v){

    if(!firstPlay_){   //check for first turn plays on the center square
        for(unsigned long i = 0; i < v.size(); i ++){
            if(v[i]->get_row() == 7 && v[i]->get_col() == 7){
                return true;
            }
        }
    }
    for(unsigned long i = 0; i < v.size(); i ++){   // check for adjacencies
        int r = v[i] -> get_row();
        int c = v[i] -> get_col();
        if(boardTiles_[r+1][c] || boardTiles_[r-1][c] || boardTiles_[r][c+1] || boardTiles_[r][c-1] ){
                return true;
        }

    }
    return false;
}

bool MainWindow::checkCont(std::vector<Tile*>v,int o){

    if(o == 1){
        for(unsigned long i = 0; i < v.size()-1; i++){
            if(v[i]->get_row() != v[i+1]->get_row() -1){
                return false;
            }
        }
    }
    if(o == 2){
        for(unsigned long i = 0; i < v.size()-1; i++){
            if(v[i]->get_col() != v[i+1] ->get_col()-1){
                return false;
            }
        }
    }
    return true;
}

std::vector<Tile*> MainWindow::findUpDown(Tile* t){
    std::vector<Tile*> word;
    word.push_back(t);
    int row = t -> get_row();
    int col = t -> get_col();
    for(int r = row-1; r > 0; r --){
        if(boardTiles_[r][col]){
            word.push_back(boardTiles_[r][col]);
        }else{break;}
    }

    for(int r = row+1; r <15; r ++){
        if(boardTiles_[r][col]){
            word.push_back(boardTiles_[r][col]);
        }else{break;}
    }
    sort(word);
    return word;

}

std::vector<Tile*> MainWindow::findLeftRight(Tile* t){
    std::vector<Tile*> word;
    word.push_back(t);
    int row = t -> get_row();
    int col = t -> get_col();
    for(int c = col-1; c > 0; c --){
        if(boardTiles_[row][c]){
            word.push_back(boardTiles_[row][c]);
        }else{break;}
    }

    for(int c = col+1; c <15; c ++){
        qDebug() << c <<" " << col;
        if(boardTiles_[row][c]){
            word.push_back(boardTiles_[row][c]);
        }else{break;}
    }
    sort(word);
    return word;
}

bool MainWindow::validateWord(QString q){

    //return true; // DONT FORGET TO REMOVE THIS JUST FOR TESTING

    if(words_.contains(q,Qt::CaseInsensitive )){
        qDebug() << "word: " <<q << "valid";
        return true;
    }else{
        qDebug() << "word: " <<q << "INvalid";
        return false;
    }
}

bool MainWindow::validatePlay(Player* p){

    std::string wrd = "";
    std::vector<Tile*> wordVec;
    bool validWord = false;
    bool connected = false;
    for(int r = 0; r < 15; r++){    // collect played tiles
        for(int c = 0; c < 15; c++){
            for(unsigned long i = 0; i < 7; i ++){
                if(p ->pTiles_[i] -> get_row() == r && p ->pTiles_[i] -> get_col() == c && p->pTiles_[i] -> get_state() == 1){
                    wordVec.push_back(p->pTiles_[i]);
                }
            }
        }
    }

    for(unsigned long i = 0; i < wordVec.size(); i++ ){
        if(wordVec[i]->get_type() == tType::blankLetter){
            qDebug("need a blank?");
            daBlank_ = wordVec[i];
            blankCreater * start =  new blankCreater();
            connect(start,&blankCreater::blankSubmit,this,&MainWindow::blankSubmitSlot);
            start->setModal(true);
            start->exec();
            daBlank_ = nullptr;
        }
    }

    if(checkConnect(wordVec)){      //check that at least a letter is touching the main spread
        qDebug()<< "connected";
    }else{return false;}
   int orient = checkVert(wordVec); // check if vertical horizontal or invalid (diagonal)

   // Depending on vertical or horizontal check for tiles that need to be added to the word
   std::vector<Tile*> missingTiles;
   switch(orient){
   case 0: { qDebug() << "invalid play"; return false; break; }
        case 1: { qDebug("vertical");
                 // ADD Missing tiles to wordVec veritcal words
                int ftr = wordVec[0] ->get_row();
                int ltr = wordVec[wordVec.size()-1] -> get_row();
                int c = wordVec[0] ->get_col();
                for(int i = 0; i<15; i++){       //find middle tiles
                    if(i > ftr && i < ltr && boardTiles_[i][c]){
                        missingTiles.push_back(boardTiles_[i][c]);
                    }
                }
                for(int i = ftr-1; i > 0; i --){ // find beginning tiles
                    if(boardTiles_[i][c]){
                        missingTiles.push_back(boardTiles_[i][c]);
                    }else{break;}}
                for(int i = ltr+1; i < 15; i ++){// find trailing tiles
                    if(boardTiles_[i][c]){
                        missingTiles.push_back(boardTiles_[i][c]);   // add trailing tiles
                    }else{break;}}
                break; }
        case 2: { qDebug("horizontal");
                // ADD Missing tiles to wordVec veritcal words
                int ftc = wordVec[0] ->get_col();
                int ltc = wordVec[wordVec.size()-1] -> get_col();
                int r = wordVec[0] ->get_row();
                for(int i = 0; i<15; i++){       //find middle tiles
                      if(i > ftc && i < ltc && boardTiles_[r][i]){
                          missingTiles.push_back(boardTiles_[r][i]);
                      }
                  }
                for(int i = ftc-1; i > 0; i --){ // find beginning tiles
                      if(boardTiles_[r][i]){
                          missingTiles.push_back(boardTiles_[r][i]);
                      }else{break;}}
                for(int i = ltc+1; i < 15; i ++){// find trailing tiles
                      if(boardTiles_[r][i]){
                          missingTiles.push_back(boardTiles_[r][i]);   // add trailing tiles
                      }else{break;}
                  }
                break; }
   }

   for(unsigned long i = 0; i < missingTiles.size(); i ++){ //add found tiles to wordVec
       wordVec.push_back(missingTiles[i]);
   }
    // resort wordVec afeter adding any missing tile
    sort(wordVec);

    if(!checkCont(wordVec,orient)){   // if the processed word isn't continuous fail
        return false;
    }

    // construct word and validate
    QString qwrd = constructWord(wordVec);
    validWord = validateWord(qwrd);

    // check for connections
    std::vector<std::vector<Tile*>> connectedWords;
    for(unsigned long i = 0; i < wordVec.size(); i++){
          bool flag = true;
          for(unsigned long a = 0; a < missingTiles.size(); a++){  // check that connected word is truly new word not support word
              if(wordVec[i] == missingTiles[a]){ flag = false;}
          }

          if(flag){
              std::vector<Tile*> word;
              if(orient == 1){
                 word = findLeftRight(wordVec[i]);
              }else {
                 word = findUpDown(wordVec[i]);
              }
              if(word.size() > 1){
                  connectedWords.push_back(word);
              }
          }
    }

    // Debug statement for connected words
    qDebug()<<"connected words";
    for(unsigned long i = 0; i < connectedWords.size(); i++){
       printWord(connectedWords[i]);
    }

    // validate all connected words
    bool allValid = true;
    for(unsigned long i = 0; i < connectedWords.size(); i++){
       QString word = constructWord(connectedWords[i]);
       if(!validateWord(word)){
           allValid = false;
           break;
       }
    }

    // calculate scores

    if(allValid && validWord){
        qDebug() << "time to calculat!";
        std::string wrd = "";
        bool noMult = false;
        connectedWords.push_back(wordVec);  // add the main word vector to connected words for score calculation
        int totalpoints = 0;
        for(unsigned long a = 0; a < connectedWords.size(); a ++){        // for each word

            int points = 0;
            int wordm = 1;
            for(unsigned long b = 0; b < connectedWords[a].size(); b ++){ // for each letter of word
                int r = connectedWords[a][b] -> get_row();
                int c = connectedWords[a][b] -> get_col();
                if(boardSpaces_[r][c] -> get_type() == sType::blank){   // blank tile just add letter points
                    points += connectedWords[a][b]->get_value();
                }
                if(boardSpaces_[r][c] -> get_type() == sType::letterM ){   // blank tile just add letter points
                    points += connectedWords[a][b]->get_value() * boardSpaces_[r][c] -> get_multiplier();
                }
                if(boardSpaces_[r][c] -> get_type() == sType::wordM){   // blank tile just add letter points
                    points += connectedWords[a][b]->get_value();
                    wordm = boardSpaces_[r][c] -> get_multiplier();
                }
                wrd += connectedWords[a][b] -> get_letter();
            }
            points = points * wordm;
            totalpoints += points;
            wrd += "  " + std::to_string(points) + " points \n";
        }
        wow -> play();
        QMessageBox* mes = new QMessageBox();
        std::string str = curPlayer ->name_ + " Scored " + std::to_string(totalpoints) + " Points";
        QString q(str.c_str());
        QString q2(wrd.c_str());
        mes -> setModal(true);
        mes -> setText(q);
        mes -> setDetailedText(q2);
        mes -> exec();

        p -> points_ += totalpoints;

        if(!firstPlay_){firstPlay_=true;}
        return true;
    }
    return false;

}

bool MainWindow::noTilesOnBoard(){
    for(int a = 0; a < 15; a++){
        for(int b = 0; b < 15; b++){
            if(boardTiles_[a][b]){
                return true;
            }
        }
    }
    return false;
}

void MainWindow::playBomb(Tile* bTile){
    bomb ->play();
    int r = bTile -> get_row();
    int c = bTile -> get_col();
    for(int row = r-1; row <= r+1; row++){
        for(int col = c-1; col <= c+1; col++ ){
            if(row >= 0 && col >= 0 && row < 15 && col < 15 && boardTiles_[row][col]){
                scene -> removeItem(boardTiles_[row][col]);
                boardTiles_[row][col] = nullptr;
            }
        }

    }
}
//helpers ----------------------------------------------------------
void MainWindow::printBag(){
    std::string s ="";
    for(unsigned long i = 0; i < alpha_.size(); i ++){
        int a = bag_[alpha_[i]];
        s += std::to_string(alpha_[i]) + ":" + std::to_string(a) + "  ";
    }
    QString q(s.c_str());
    qDebug() << q;

}

void MainWindow::printWord(std::vector<Tile*> word){
    std::string s = "";
    for(unsigned long i = 0; i < word.size(); i++){
        s += word[i] -> get_letter();
    }
    QString qs(s.c_str());
    qDebug() << qs;
}

QString MainWindow::constructWord(std::vector<Tile*> word){
    std::string s = "";
    for(long unsigned i = 0; i<word.size(); i ++){
        s += word[i]-> get_letter();
    }
    QString q(s.c_str());
    return q;
}

int MainWindow::tilesLeft(){
    int sum = 0;
    for(unsigned long i = 0; i < alpha_.size(); i ++){
        sum += bag_[alpha_[i]];
    }
    return sum;
}


//Slots ----------------------------------------------------------
void MainWindow::tileSelectedSlot(Tile* tile){

    pop -> play();

    if(tile  == selectedTile_){       // same tile selected do nothing
        selectedTile_ -> setState(0);
        selectedTile_ -> update();
        selectedTile_ = nullptr;
        return;
    }
    if(tile-> get_state() == 5){selectedTile_ = nullptr; return;} // if the tile is locked in do nothing
    if(drawNew_ && tile -> get_state() != 2){
        selectedTile_ = tile;
        drawNewTile();
        selectedTile_ = nullptr;
        return;
    }

    if(!selectedTile_){                  // first tile select
        selectedTile_ = tile;
        selectedTile_ -> setState(3);
        selectedTile_ -> update();

    }else{                               // second TILE selected means swap
        selectedTile_ -> setState(0);
        selectedTile_ -> update();
        swapTiles(tile,selectedTile_);
        selectedTile_ = nullptr;
    }
}

void MainWindow::spaceSelectedSlot(Space* space){
    if(drawNew_){
        return;
    }
    if(selectedTile_){                  // tile has already been selected put tile on space
        pop -> play();
        selectedTile_ -> setState(1);
        selectedTile_ -> update();
        placeTile(selectedTile_,space);
        selectedTile_ = nullptr;
    }
}

void MainWindow::blankSubmitSlot(char let){
    daBlank_ -> setLetter(let);
}

void MainWindow::numPlayersSlot(int n){
    numPlayers_ = n;
}

void MainWindow::createPlayersSlot(std::vector<Player*> p){
    for (unsigned long i=0; i<p.size(); i++)
           players_.push_back(p[i]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Buttin Slots -------------------------------------------------
void MainWindow::on_submitButton_clicked()
{
    bool bombPlayed = false;
    if(drawNew_){return;}
    selectedTile_ = nullptr;
    std::vector<Tile*> tilesOnBoard;     // get all played tiles
    for(unsigned long i = 0; i < 7; i++){
        if(curPlayer->pTiles_[i]->get_state() == 1 || curPlayer->pTiles_[i]->get_state() == 3){
            curPlayer->pTiles_[i]->setState(1);
            tilesOnBoard.push_back(curPlayer->pTiles_[i]);
        }
    }

    for(unsigned long i = 0; i < tilesOnBoard.size(); i++){
        if(tilesOnBoard[i]->get_type() == tType::bomb){
            playBomb(tilesOnBoard[i]);
            bombPlayed = true;
        }
    }


    if(tilesOnBoard.size() == 0){return;}

    if(!bombPlayed){     // NO bomb played validate word etc.
        if(!validatePlay(curPlayer)){
            fail -> play();
            QMessageBox* mes = new QMessageBox();
            QString q("Invalid Play Try Again");
            mes ->setModal(true);
            mes -> setText(q);
            mes->exec();
            return;
        }else{
            displayScores();
            for(unsigned long i = 0; i < tilesOnBoard.size(); i++){
                int r = tilesOnBoard[i]->get_row(); int c = tilesOnBoard[i]->get_col();
                boardTiles_[r][c] = tilesOnBoard[i];
                tilesOnBoard[i] -> setState(5);   // lock in validated word tiles   and remove tiles from player hand
                curPlayer -> pTiles_.erase(std::remove(curPlayer -> pTiles_.begin(), curPlayer -> pTiles_.end(), tilesOnBoard[i]), curPlayer -> pTiles_.end());  // remove  played letters from pTiles
            }
            nextTurn();
        }
    }else{    // bomb played so return any current tiles to the players set
        for(unsigned long i = 0; i < tilesOnBoard.size(); i++){
            if(tilesOnBoard[i] -> get_type() == tType::bomb){
                scene -> removeItem(tilesOnBoard[i]);
                curPlayer -> pTiles_.erase(std::remove(curPlayer -> pTiles_.begin(), curPlayer -> pTiles_.end(), tilesOnBoard[i]), curPlayer -> pTiles_.end());  // remove  played letters from pTiles
            }
            tilesOnBoard[i] -> setState(0);
        }
        nextTurn();
    }

}

void MainWindow::on_passButton_clicked()
{
    if(drawNew_){return;}

    for(unsigned long i = 0; i < curPlayer -> pTiles_.size(); i++){   // clear out unplayed tiles from board return them to player pTiles
        if(curPlayer->pTiles_[i]-> get_state() == 1){
            curPlayer->pTiles_[i]-> setState(0);
            scene -> removeItem(curPlayer->pTiles_[i]);
        }
    }

    nextTurn();

}

void MainWindow::on_drawButton_clicked()
{
    selectedTile_ = nullptr;
    if(drawNew_ == false){
        drawNew_ = true;
        selectedTile_ = nullptr;
        ui -> centralwidget -> setCursor(Qt::WhatsThisCursor);
    }
    else{
        drawNew_ = false;
        for(unsigned long i = 0; i < curPlayer->pTiles_.size(); i ++){
            curPlayer->pTiles_[i]->setState(0);
        }
        nextTurn();
        ui -> centralwidget -> setCursor(Qt::ArrowCursor);
    }


}

void MainWindow::on_resignButton_clicked()
{
    curPlayer -> resigned_ = true;
    nextTurn();
}

