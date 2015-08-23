

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Oct 10 11:18:24 2013
 */
/* Compiler settings for .\SlmServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SlmServer_h__
#define __SlmServer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Islmcomm_FWD_DEFINED__
#define __Islmcomm_FWD_DEFINED__
typedef interface Islmcomm Islmcomm;
#endif 	/* __Islmcomm_FWD_DEFINED__ */


#ifndef __slmcomm_FWD_DEFINED__
#define __slmcomm_FWD_DEFINED__

#ifdef __cplusplus
typedef class slmcomm slmcomm;
#else
typedef struct slmcomm slmcomm;
#endif /* __cplusplus */

#endif 	/* __slmcomm_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __Islmcomm_INTERFACE_DEFINED__
#define __Islmcomm_INTERFACE_DEFINED__

/* interface Islmcomm */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_Islmcomm;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D775C513-D0C3-4910-A022-44A696E9C95E")
    Islmcomm : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetControl( 
            /* [in] */ LONG CtrlID,
            /* [in] */ VARIANT CtrlVal,
            /* [in] */ LONG GroupId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetControl( 
            /* [in] */ LONG CtrlID,
            /* [in] */ LONG GroupId,
            /* [out][in] */ VARIANT *CtrlVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOperation( 
            /* [in] */ LONG OperID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOperationVal( 
            /* [in] */ LONG OperID,
            /* [in] */ VARIANT OperVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSystemInfo( 
            /* [in] */ LONG InfoID,
            /* [in] */ LONG Channel,
            /* [out][in] */ VARIANT *InfoVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [in] */ LONG GroupID,
            /* [in] */ LONG ChannelID,
            /* [out][in] */ VARIANT *DataVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RawWrite( 
            /* [in] */ BYTE *p_pbCmd,
            /* [in] */ LONG p_lCmdLen,
            /* [out] */ LONG *p_plAck) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RawRead( 
            /* [in] */ BYTE *p_pbData,
            /* [in] */ LONG p_lMaxLen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastErrorText( 
            /* [out][in] */ VARIANT *p_ErrorMessage,
            /* [in] */ LONG p_lErrorCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadControlTEDS( 
            /* [in] */ BYTE p_byGroup,
            /* [in] */ BYTE p_byTag,
            /* [out][in] */ VARIANT *pv) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadBinaryData( 
            /* [in] */ BSTR bstrOutputFilename,
            /* [in] */ VARIANT *pvFileIndices,
            /* [in] */ VARIANT *pvFileSizes,
            /* [in] */ int nIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadDataZModem( 
            /* [in] */ BSTR bstrOutputFilename,
            /* [in] */ VARIANT *pvFileIndices,
            /* [in] */ VARIANT *pvFileSizes,
            /* [in] */ int nIndex,
            /* [in] */ DWORD dwMask) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFilenames( 
            /* [in] */ LONG nGroupID,
            /* [in] */ LONG nChannelID,
            VARIANT *pvarDataVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IslmcommVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Islmcomm * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Islmcomm * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Islmcomm * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Islmcomm * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Islmcomm * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Islmcomm * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Islmcomm * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetControl )( 
            Islmcomm * This,
            /* [in] */ LONG CtrlID,
            /* [in] */ VARIANT CtrlVal,
            /* [in] */ LONG GroupId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetControl )( 
            Islmcomm * This,
            /* [in] */ LONG CtrlID,
            /* [in] */ LONG GroupId,
            /* [out][in] */ VARIANT *CtrlVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOperation )( 
            Islmcomm * This,
            /* [in] */ LONG OperID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOperationVal )( 
            Islmcomm * This,
            /* [in] */ LONG OperID,
            /* [in] */ VARIANT OperVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSystemInfo )( 
            Islmcomm * This,
            /* [in] */ LONG InfoID,
            /* [in] */ LONG Channel,
            /* [out][in] */ VARIANT *InfoVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetData )( 
            Islmcomm * This,
            /* [in] */ LONG GroupID,
            /* [in] */ LONG ChannelID,
            /* [out][in] */ VARIANT *DataVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RawWrite )( 
            Islmcomm * This,
            /* [in] */ BYTE *p_pbCmd,
            /* [in] */ LONG p_lCmdLen,
            /* [out] */ LONG *p_plAck);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RawRead )( 
            Islmcomm * This,
            /* [in] */ BYTE *p_pbData,
            /* [in] */ LONG p_lMaxLen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastErrorText )( 
            Islmcomm * This,
            /* [out][in] */ VARIANT *p_ErrorMessage,
            /* [in] */ LONG p_lErrorCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadControlTEDS )( 
            Islmcomm * This,
            /* [in] */ BYTE p_byGroup,
            /* [in] */ BYTE p_byTag,
            /* [out][in] */ VARIANT *pv);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadBinaryData )( 
            Islmcomm * This,
            /* [in] */ BSTR bstrOutputFilename,
            /* [in] */ VARIANT *pvFileIndices,
            /* [in] */ VARIANT *pvFileSizes,
            /* [in] */ int nIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadDataZModem )( 
            Islmcomm * This,
            /* [in] */ BSTR bstrOutputFilename,
            /* [in] */ VARIANT *pvFileIndices,
            /* [in] */ VARIANT *pvFileSizes,
            /* [in] */ int nIndex,
            /* [in] */ DWORD dwMask);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginTransaction )( 
            Islmcomm * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndTransaction )( 
            Islmcomm * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFilenames )( 
            Islmcomm * This,
            /* [in] */ LONG nGroupID,
            /* [in] */ LONG nChannelID,
            VARIANT *pvarDataVal);
        
        END_INTERFACE
    } IslmcommVtbl;

    interface Islmcomm
    {
        CONST_VTBL struct IslmcommVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Islmcomm_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Islmcomm_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Islmcomm_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Islmcomm_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Islmcomm_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Islmcomm_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Islmcomm_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define Islmcomm_SetControl(This,CtrlID,CtrlVal,GroupId)	\
    ( (This)->lpVtbl -> SetControl(This,CtrlID,CtrlVal,GroupId) ) 

#define Islmcomm_GetControl(This,CtrlID,GroupId,CtrlVal)	\
    ( (This)->lpVtbl -> GetControl(This,CtrlID,GroupId,CtrlVal) ) 

#define Islmcomm_SetOperation(This,OperID)	\
    ( (This)->lpVtbl -> SetOperation(This,OperID) ) 

#define Islmcomm_SetOperationVal(This,OperID,OperVal)	\
    ( (This)->lpVtbl -> SetOperationVal(This,OperID,OperVal) ) 

#define Islmcomm_GetSystemInfo(This,InfoID,Channel,InfoVal)	\
    ( (This)->lpVtbl -> GetSystemInfo(This,InfoID,Channel,InfoVal) ) 

#define Islmcomm_GetData(This,GroupID,ChannelID,DataVal)	\
    ( (This)->lpVtbl -> GetData(This,GroupID,ChannelID,DataVal) ) 

#define Islmcomm_RawWrite(This,p_pbCmd,p_lCmdLen,p_plAck)	\
    ( (This)->lpVtbl -> RawWrite(This,p_pbCmd,p_lCmdLen,p_plAck) ) 

#define Islmcomm_RawRead(This,p_pbData,p_lMaxLen)	\
    ( (This)->lpVtbl -> RawRead(This,p_pbData,p_lMaxLen) ) 

#define Islmcomm_GetLastErrorText(This,p_ErrorMessage,p_lErrorCode)	\
    ( (This)->lpVtbl -> GetLastErrorText(This,p_ErrorMessage,p_lErrorCode) ) 

#define Islmcomm_ReadControlTEDS(This,p_byGroup,p_byTag,pv)	\
    ( (This)->lpVtbl -> ReadControlTEDS(This,p_byGroup,p_byTag,pv) ) 

#define Islmcomm_DownloadBinaryData(This,bstrOutputFilename,pvFileIndices,pvFileSizes,nIndex)	\
    ( (This)->lpVtbl -> DownloadBinaryData(This,bstrOutputFilename,pvFileIndices,pvFileSizes,nIndex) ) 

#define Islmcomm_DownloadDataZModem(This,bstrOutputFilename,pvFileIndices,pvFileSizes,nIndex,dwMask)	\
    ( (This)->lpVtbl -> DownloadDataZModem(This,bstrOutputFilename,pvFileIndices,pvFileSizes,nIndex,dwMask) ) 

#define Islmcomm_BeginTransaction(This)	\
    ( (This)->lpVtbl -> BeginTransaction(This) ) 

#define Islmcomm_EndTransaction(This)	\
    ( (This)->lpVtbl -> EndTransaction(This) ) 

#define Islmcomm_GetFilenames(This,nGroupID,nChannelID,pvarDataVal)	\
    ( (This)->lpVtbl -> GetFilenames(This,nGroupID,nChannelID,pvarDataVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Islmcomm_INTERFACE_DEFINED__ */



#ifndef __SlmServerLib_LIBRARY_DEFINED__
#define __SlmServerLib_LIBRARY_DEFINED__

/* library SlmServerLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SlmServerLib;

EXTERN_C const CLSID CLSID_slmcomm;

#ifdef __cplusplus

class DECLSPEC_UUID("FB2454F0-B63E-4C3D-9E1A-DC52F1D2ADC1")
slmcomm;
#endif
#endif /* __SlmServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


