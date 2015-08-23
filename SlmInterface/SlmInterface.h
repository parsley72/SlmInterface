#ifndef SLMINTERFACE_H
#define SLMINTERFACE_H

#include "SlmInterfaceData.h"

void Init();

//#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

extern "C" DllImport bool SI_StartSlmTranslation(const wchar_t *pwstrFilename, int nIndex=1);
extern "C" DllImport void SI_EndSlmTranslation(void);
extern "C" DllImport int SI_GetLDFileType(const wchar_t *pwstrFilename, int *pnVersion);
/*
extern "C" DllImport void SI_SetNotifyWnd(long hWnd, int nMsg);
extern "C" DllImport bool SI_ConvertUSBFileToBinFile(char **pszIn, int nFiles, char *pszOut);
*/

extern "C" DllImport bool SI_GetSlmHeaderEx(slmSFileHeader_t *pfh);
extern "C" DllImport bool SI_GetNextSlmRecordEx_Settings(slmSSettings_t *pSettings);
extern "C" DllImport bool SI_GetNextSlmRecordEx(slmSRecord_t *pRec, int nIndex = -1);
extern "C" DllImport void SI_GetBulkCountsEx(slmSDataCnts_t *pDataCnts);
extern "C" DllImport bool SI_GetBulkDataEx(const int nSamplePeriodInMSecs, slmSBulkRecord_t *pSlmBulkRec);

extern "C" DllImport void SI_ReleaseSlmHeaderEx(slmSFileHeader_t *pfh);
extern "C" DllImport void SI_ReleaseNextSlmRecordEx(slmSRecord_t *pRec);
extern "C" DllImport void SI_ReleaseBulkCountsEx(slmSDataCnts_t *pDataCnts);
extern "C" DllImport void SI_ReleaseBulkDataEx(slmSBulkRecord_t *pSlmBulkRec);

extern "C" DllImport int SI_GetInstrumentMode(void); // -1=N/A, 0=SLM, 1=RA, 2=FFT

#endif // SLMINTERFACE_H
