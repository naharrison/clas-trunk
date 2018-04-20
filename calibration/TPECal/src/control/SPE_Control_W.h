#ifndef SPE_Control_WIDGET_H
#define SPE_Control_WIDGET_H

// %%%%%%%%%%
// Qt headers
// %%%%%%%%%%
#include <QApplication>
#include <QSplashScreen>
#include <QListWidget>
#include <QTableWidget>
#include <QProgressDialog>
#include <QLCDNumber>

// %%%%%%%%%%%%%
// ROOT headers
// %%%%%%%%%%%%%
#include "TCanvas.h"
#include "TLatex.h"


// %%%%%%%%%%%%%%%%
// Cerenkov headers
// %%%%%%%%%%%%%%%%
#include "tpecal_calib.h"
#include "usage.h"

class SPE_Control_W : public QWidget
{
 // metaobject required for non-qt slots
 Q_OBJECT

 public:
   SPE_Control_W(QWidget*, QSplashScreen*, QApplication*, tpecal_opts*, tpecal_calib*, TCanvas*, QLabel*);
  ~SPE_Control_W(){;}

   QSplashScreen *splash;
   QApplication  *tpecal_gui;
   tpecal_opts   *tpecalOpt;
   tpecal_calib  *TPECal_calib;
   TCanvas       *Spe;
   TLatex        me;
   QLabel        *wlog;

   QLCDNumber  *minRun;      ///< Database min Run Number
   QLCDNumber  *maxRun;      ///< Database max Run Number
   QLabel      *runIndex;    ///< Run Index name

 private:
   QString WLOG;
   int     PRINT;

 public slots:
   void show_spes();                                      ///< Show MIPs Graphs
   void print_spes() { PRINT=1; show_spes(); PRINT=0; }   ///< Print MIPs Graphs
   void write_pars();                                     ///< Write Parameters to file

};

#endif
