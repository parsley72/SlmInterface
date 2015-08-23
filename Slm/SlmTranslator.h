#ifndef SLMTRANSLATOR_H
#define SLMTRANSLATOR_H

#include "LxT831.h"
#include "SlmStructs.h"

DllImport BOOL StartSlmTranslation(char *pszFileName, int nIndex=1);
DllImport void EndSlmTranslation(void);
DllImport int GetLDFileType(char *pszFilename, int *pnVersion);
DllImport void SetNotifyWnd(long hWnd, int nMsg);
DllImport BOOL ConvertUSBFileToBinFile(char **pszIn, int nFiles, char *pszOut);

DllImport BOOL GetSlmHeaderEx(stFileHeader_t &fh);
DllImport BOOL GetNextSlmRecordEx(stSlmRecord_t *pRec, int nIndex = -1);
DllImport void GetBulkCountsEx(stDataCnts_t * pDataCnts);
DllImport BOOL GetBulkDataEx(stSlmBulkRecord_t *pSlmBulkRec);

DllImport int GetInstrumentMode(void); // -1=N/A, 0=SLM, 1=RA, 2=FFT

#endif // SLMTRANSLATOR_H
