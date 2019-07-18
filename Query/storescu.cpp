#include "dcmtk/config/osconfig.h" /* make sure OS specific configuration is included first */

#define INCLUDE_CSTDLIB
#define INCLUDE_CSTDIO
#define INCLUDE_CSTRING
#define INCLUDE_CCTYPE
#include "dcmtk/ofstd/ofstdinc.h"

BEGIN_EXTERN_C
#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif
END_EXTERN_C

#include "dcmtk/ofstd/ofstd.h"
#include "dcmtk/ofstd/ofconapp.h"
#include "dcmtk/ofstd/ofstring.h"
#include "dcmtk/ofstd/ofstream.h"
#include "dcmtk/dcmnet/dicom.h"      /* for DICOM_APPLICATION_REQUESTOR */
#include "dcmtk/dcmnet/dimse.h"
#include "dcmtk/dcmnet/diutil.h"
#include "dcmtk/dcmnet/dcmtrans.h"   /* for dcmSocketSend/ReceiveTimeout */
#include "dcmtk/dcmnet/dcasccfg.h"   /* for class DcmAssociationConfiguration */
#include "dcmtk/dcmnet/dcasccff.h"   /* for class DcmAssociationConfigurationFile */
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcmetinf.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/dcmdata/dcdict.h"
#include "dcmtk/dcmdata/dcdeftag.h"
#include "dcmtk/dcmdata/cmdlnarg.h"
#include "dcmtk/dcmdata/dcuid.h"     /* for dcmtk version name */
#include "dcmtk/dcmdata/dcostrmz.h"  /* for dcmZlibCompressionLevel */
#include "dcmtk/dcmtls/tlsopt.h"      /* for DcmTLSOptions */
#include "dcmtk/dcmnet/dstorscu.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /* 
    OFOStringStream optStream;

    const char *opt_peer = NULL;
    OFCmdUnsignedInt opt_port = 104;
    const char *opt_peerTitle = PEERAPPLICATIONTITLE;
    const char *opt_ourTitle = APPLICATIONTITLE;

    OFList<OFString> fileNameList;       // list of files to transfer to SCP
    OFList<OFString> sopClassUIDList;    // the list of SOP classes
    OFList<OFString> sopInstanceUIDList; // the list of SOP instances

    T_ASC_Network *net;
    T_ASC_Parameters *params;
    DIC_NODENAME peerHost;
    T_ASC_Association *assoc;
    DcmAssociationConfiguration asccfg;  // handler for association configuration profiles
    DcmTLSOptions tlsOptions(NET_REQUESTOR);

    OFStandard::initializeNetwork();
    */
    /* finally, create list of input files */
    //const char *paramString = NULL;
    // const int paramCount = cmd.getParamCount();
    //OFList<OFString> inputFiles;

    /* initialize network, i.e. create an instance of T_ASC_Network*. */
    /* 
    OFCondition cond = ASC_initializeNetwork(NET_REQUESTOR, 0, opt_acse_timeout, &net);
    if (cond.bad()) {
      OFLOG_FATAL(storescuLogger, DimseCondition::dump(temp_str, cond));
      return 1;
    }
    */
    /* sets this application's title and the called application's title in the params */
    /* structure. The default values to be set here are "STORESCU" and "ANY-SCP". */
    //ASC_setAPTitles(params, opt_ourTitle, opt_peerTitle, NULL);

    /* Figure out the presentation addresses and copy the */
    /* corresponding values into the association parameters.*/
    /*
    sprintf(peerHost, "%s:%d", opt_peer, OFstatic_cast(int, opt_port));
    ASC_setPresentationAddresses(params, OFStandard::getHostName().c_str(), peerHost);
    */
    DcmStorageSCU storageSCU;
    
    Uint32 maxRecPDU = 30;
    //cout << "Max Receive PDU Length";
    //cin >> maxRecPDU;
    storageSCU.setMaxReceivePDULength(maxRecPDU);

    storageSCU.setDIMSEBlockingMode(DIMSE_BLOCKING);
    
    OFString aetitle = "ACME1";
    //cout << "AETitle : ";
    //cin >> aetitle;
    storageSCU.setAETitle(aetitle);

    OFString peer = "localhost";
    //cout << "Peer : ";
    //cin >> peer;
    storageSCU.setPeerHostName(peer);

    OFString aec = "ACME_STORE";
    //cout << "AECall : ";
    //cin >> aec;
    storageSCU.setPeerAETitle(aec);

    int port = 5678;
    //cout << "Port : ";
    //cin >> port;
    storageSCU.setPeerPort(port);
    
    storageSCU.setDIMSETimeout(30);

    storageSCU.setACSETimeout(30);
    
    storageSCU.setConnectionTimeout(30);

    // storageSCU.setStorageMode(DCMSCU_STORAGE_DISK);

    storageSCU.setVerbosePCMode(OFTrue);

    
    OFString filename;
    cout << "File name : ";
    cin >> filename;
    storageSCU.addDicomFile(filename);
    
    storageSCU.addPresentationContexts();
    storageSCU.initNetwork();
    cout << "hi xxx";
    OFCondition cond = storageSCU.negotiateAssociation();
    cout << "hi";
    
    if (cond.bad()){
      cout << "dm kiwon";
      return 1;
    } else cout << "done!";
    storageSCU.sendSOPInstances();
    cond = storageSCU.releaseAssociation();
    if (cond.bad()){
      cout << "dm kiwon";
      return 1;
    } else cout << "done!";
    storageSCU.clear();
    return 0;
}
