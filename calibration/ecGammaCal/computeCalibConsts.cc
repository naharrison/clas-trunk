#include <iostream>
#include <fstream>
#include <cstdio>

extern "C" {

#include <ntypes.h>
#include <bostypes.h>
#include <utility.h>
#include <itape.h>

}

#include <clasEvent.h>
#include "TCalibECCalib.h"

using namespace std;

// ------------------------------------------------
// ------------------  Prototypes  ----------------
// ------------------------------------------------
int StartRun(int nRunNo);
void PrintUsage(const char *szProcessName);
// extern "C" {
//   void bnames_(const int *);
// }

int StartRun(int nRunNo)
{
  int static nCurrentRun = -1;
  if (nCurrentRun != nRunNo) {
    vertex_brun(nRunNo);
    nCurrentRun = nRunNo;
  }
  return (0);
}


// ------------------------------------------------
// ------------------  Utilities   ----------------
// ------------------------------------------------
void PrintUsage(const char *szProcessName)
{
  cerr << "\nUsage: " << szProcessName << " <options>\n";
  cerr << "\tComputes EC calibration constants\n";
  cerr << "\toptions are:\n";

  cerr << "\t-f<filename>\tname of stub file containing list of files to process.\n";
  cerr << "\t-c<filename>\tcalibration constants output file (default is calibconsts.dat).\n";
  cerr << "\t-n#\tminimum number of hits in a tube for calibration (default is 50).\n";
  cerr << "\t-e#\tphoton minimum energy (in GeV) for calibration (default is 0.1).\n";
  cerr << "\t-a#\tMinimum ADC value in a tube for calibration (default is 100.).\n";
  cerr << "\t-g#\tPART bank group number (default is 1).\n";
  cerr << "\t-M#\tmaximum # of events to process in a file (default is 0, process all events)\n";
  cerr << "\t-i\tquiet mode (no counter).\n";
  cerr << "\t-h\tprint the above" << endl;

  exit(0);
}



// ------------------------------------------------
// ------------------ Main program ----------------
// ------------------------------------------------
int main(int argc, char **argv)
{

  int nDispatch = 0;

  //
  char* szStubFilename = NULL;
  char* szCalibConstsFilename = (char*)&"calibconsts.dat"; // calibration constants output.
  int nMinHitsForCalib = 50;    // minimum number of hits in a tube in order to calibrate it.
  double dMinGammaEnergy = 0.1; // 100 MeV minimum to get ride of the background.
  double dMinAdcValue = 100.;
  int nPartGroupIndex = 1;
  int nMaxEventsToRead = 0;   // if set to 0, process all events in the file
  bool bBatchMode = false;    // events counter is on by default

  if (argc == 1){
    PrintUsage(argv[0]);
  }
  for (int i = 1; i < argc; i++) {
    char* argptr = argv[i];
    if (*argptr == '-') {
      argptr++;
      switch (*argptr) {

      case 'f':
    if (*(++argptr)) {
      szStubFilename =  argptr;
    }
    break;

      case 'c':
    if (*(++argptr)) {
      szCalibConstsFilename = argptr;
    }
    break;

      case 'n':
    if (*(++argptr)) {
      nMinHitsForCalib = atoi(argptr);
    }
    break;

      case 'e':
    if (*(++argptr)) {
      dMinGammaEnergy = atof(argptr);
    }
    break;

      case 'a':
    if (*(++argptr)) {
      dMinAdcValue = atof(argptr);
    }
    break;

      case 'g':
    if (*(++argptr)) {
      nPartGroupIndex = atoi(argptr);
    }
    break;

      case 'M':
    if (*(++argptr)) {
      nMaxEventsToRead = atoi(argptr);
    }
    break;

      case 'i':
        bBatchMode = true;
        break;

      case 'h':
    PrintUsage(argv[0]);
    break;

      default:
    cerr << "Unrecognized argument: " << argptr << endl;
    exit(0);
    break;
      }
    }
  }

  // Initialize BOS
  int c_nMaxBosBanks = 1000;
  bnames_(&c_nMaxBosBanks);
  initbos();
  configure_banks(stderr, 0);

  // try to open stub file
  ifstream fsStubFile(szStubFilename);
  if (!fsStubFile) {
    cerr << "Couldn't read stub file " << szStubFilename << "!\n";
    exit(8);
  }

  TCalibECCalib calibEC(nMinHitsForCalib, dMinAdcValue); // initializes object
  // iniializes different counters
  int nTotalEventsRead = 0, nTotalEventsProcessed = 0, nTotalGammasFound = 0;

  string stBosFilename; // filename read from the stub file
  while (fsStubFile >> stBosFilename) {
    // we have a file to process
    char *filein = (char *) stBosFilename.c_str();
    clasEvent event(filein, &bcs_, nPartGroupIndex, 0);
    cerr << "\nInitialize:\t" << stBosFilename << endl;
    nDispatch = isDispatcher(filein);

    if (event.status()) {
      int nEventsRead = 0, nEventsProcessed = 0, nGammasFound = 0, nStillEvents = 1; // initializes variables for new file
      while ((nMaxEventsToRead ? nEventsRead < nMaxEventsToRead : 1) && nStillEvents) {
    // process every event in the file
    nStillEvents = event.read(nPartGroupIndex);
    if (nStillEvents == DISIO_DATA) {
      nEventsRead++;
      if (!bBatchMode && ((nEventsRead % 100) == 0)){
        cerr << nEventsRead << "\r";
      }

      if (event.status()) {
        int nRunNo = event.run();
        ConfigEvent(nRunNo, 0);
        // Initialize the TOF geometry.  This is needed regardless of whether you remake the SC reconstruction banks or not.  However, for the regeneration case, this is done in ConfigEvent.
        StartRun(nRunNo);

        nGammasFound += calibEC.FindGammas(&bcs_, dMinGammaEnergy, nPartGroupIndex);
        dropAllBanks(&bcs_, (char*)&"E");
        cleanBanks(&bcs_);
        nEventsProcessed++;
      }
    }
    else if (nStillEvents == DISIO_COMMAND) {
      cerr << "\nMessage from Giant Head: " << getBuffer() << endl;
    }
      }

      // sum over all files
      nTotalEventsRead += nEventsRead;
      nTotalEventsProcessed  += nEventsProcessed;
      nTotalGammasFound += nGammasFound;

      cerr << "\nnumber of events read in " << stBosFilename << ":\t" << nEventsRead << endl;
      cerr << "number of events processed in " << stBosFilename << ":\t" << nEventsProcessed << endl;
      cerr << "number of good gammas found in " << stBosFilename << ":\t" << nGammasFound;

    }
    else {
      cerr << "\nUnable to open " << stBosFilename << endl;
    }
  }

  // after processing all files, computes and writes down calibration constants
  calibEC.ComputeCalibConstants(szCalibConstsFilename);

  if (nDispatch) {
    disIO_command("FINISHED");
  }

  cerr << "\nTotal number of events read:\t" << nTotalEventsRead << endl;
  cerr << "Total number of events processed:\t" << nTotalEventsProcessed << endl;
  cerr << "Total number of gammas found for calibration:\t" << nTotalGammasFound << endl;


  return (0);
}






