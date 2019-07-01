#include "dcmtk/dcmnet/dfindscu.h"
#include "dcmtk/dcmtls/tlsopt.h"

using namespace std;

int main(int argc, char const *argv[])
{

    const char            *peer;
    unsigned int          port;
    const char            *ourTitle;
    const char            *peerTitle;
    const char            *abstractSyntax;
    E_TransferSyntax      preferredTransferSyntax;
    T_DIMSE_BlockingMode  blockmode;
    int                   dime_timeout;
    Uint32                maxReceivePDULength;
    OFBool                secureConnection;
    OFBool                abortAssociation;
    unsigned int          repeatCount;
    DcmFindSCUExtractMode extractResponses;
    int                   cancelAfterNResponses;
    OFList<OFString>      *overrideKeys;
    DcmFindSCUCallback    *callback = NULL;
    OFList<OFString>      *fileNameList = NULL;
    const char            *outputDirectory = NULL;
    const char            *extractFilename = NULL;
    DcmTLSOptions         tlsOptions(NET_REQUESTOR);
    Dicom

    string input = "";
    cout << "peer : "; 
    cin >> input;
    peer = input.c_str();
    cout << endl;

    cout << "port : ";
    cin >> port;
    cout << endl;

    cout << "our Title (0 to default) : ";
    cin >> input;
    if (input == "0") ourTitle = "FINDSCU";
        else ourTitle = input.c_str();
    cout << endl;

    cout << "peer Title (0 to default (ANY-SCP)): ";
    cin >> input;
    if (input == "0") peerTitle = "ANY-SCP";
        else peerTitle = input.c_str();

    abstractSyntax = UID_FINDModalityWorklistInformationModel;
    preferredTransferSyntax = EXS_Unknown;
    blockmode = DIMSE_BLOCKING;
    
    cout << "dime time out (defaul is 30) : ";
    cin >> dime_timeout;
    cout << endl;
    maxReceivePDULength = ASC_DEFAULTMAXPDU;

    OFCondition cond = findscu.initializeNetwork(opt_acse_timeout);
    if (cond.bad()) {
      OFLOG_ERROR(findscuLogger, DimseCondition::dump(temp_str, cond));
      return 1;
    }

    secureConnection = tlsOptions.secureConnectionRequested();
    abortAssociation = OFFalse;
    repeatCount = 1;
    extractResponses = FEM_none;
    cancelAfterNResponses = -1;
    
    cout << "file name query : ";
    cin >> input;
    fileNameList.push_back(input.c_str());

    cond = findscu.performQuery();
    return 0;
}
