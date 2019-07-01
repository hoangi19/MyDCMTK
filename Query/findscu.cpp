#include "dcmtk/dcmnet/dfindscu.h"
#include "dcmtk/dcmtls/tlsopt.h"

using namespace std;

static OFLogger findscuLogger = OFLog::getLogger("dcmtk.apps.findscu");
OFString temp_str;

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
    OFList<OFString>      overrideKeys;
    DcmFindSCUCallback    *callback = NULL;
    OFList<OFString>      fileNameList;
    const char            *outputDirectory = NULL;
    const char            *extractFilename = NULL;
    DcmTLSOptions         tlsOptions(NET_REQUESTOR);

    string inpeer = "";
    cout << "peer : "; 
    cin >> inpeer;
    peer = inpeer.c_str();
    cout << endl;
    
    cout << "port : ";
    cin >> port;
    cout << endl;
    
    string inAET;
    cout << "our Title (0 to default) : ";
    cin >> inAET;
    if (inAET == "0") ourTitle = "FINDSCU";
        else ourTitle = inAET.c_str();
    cout << endl;

    string inAEC;
    cout << "peer Title (0 to default (ANY-SCP)): ";
    cin >> inAEC;
    if (inAEC == "0") peerTitle = "ANY-SCP";
        else peerTitle = inAEC.c_str();
    
    string queryInfomationModel;
    cout << "query information model : --worklist --patient --study --psonly ";
    cin >> queryInfomationModel;
    if (queryInfomationModel ==  ("--worklist")) abstractSyntax = UID_FINDModalityWorklistInformationModel;
    if (queryInfomationModel ==  ("--patient"))  abstractSyntax = UID_FINDPatientRootQueryRetrieveInformationModel;
    if (queryInfomationModel ==  ("--study"))    abstractSyntax = UID_FINDStudyRootQueryRetrieveInformationModel;
    if (queryInfomationModel ==  ("--psonly"))   abstractSyntax = UID_RETIRED_FINDPatientStudyOnlyQueryRetrieveInformationModel;
    //abstractSyntax = UID_FINDPatientRootQueryRetrieveInformationModel;
    preferredTransferSyntax = EXS_Unknown;
    blockmode = DIMSE_BLOCKING;
    
    cout << "dime time out (defaul is 30) : ";
    cin >> dime_timeout;
    cout << endl;
    maxReceivePDULength = ASC_DEFAULTMAXPDU;
    DcmFindSCU findscu;
    OFCondition cond = findscu.initializeNetwork(30);

    // enabled or disable removal of trailing padding
    dcmEnableAutomaticInputDataCorrection.set(OFFalse);
    
    if (cond.bad()) {
        OFLOG_ERROR(findscuLogger, DimseCondition::dump(temp_str, cond));
        cout << "Can't connect";
        return 1;
    }

    secureConnection = tlsOptions.secureConnectionRequested();
    abortAssociation = OFFalse;
    repeatCount = 1;
    extractResponses = FEM_none;
    cancelAfterNResponses = -1;
    
    string inFileName;
    cout << "file name query : ";
    cin >> inFileName;
    fileNameList.push_back(inFileName.c_str());
    int nKey;
    cout << "Number of Key : ";
    cin >> nKey;
    for (int i = 1; i <= nKey; i++){
        string inKey;
        cout << "Key : ";
        cin >> inKey;
        overrideKeys.push_back(inKey.c_str());
        // cout << "\n";
    }
    
    // cout << "peer : " << peer;
    cond = findscu.performQuery(peer, port, ourTitle, peerTitle, abstractSyntax, preferredTransferSyntax, blockmode, dime_timeout, maxReceivePDULength, secureConnection, abortAssociation, repeatCount, extractResponses, cancelAfterNResponses, &overrideKeys, callback, &fileNameList, outputDirectory, extractFilename);
    cond = findscu.dropNetwork();
    if (cond.bad()) OFLOG_ERROR(findscuLogger, DimseCondition::dump(temp_str, cond));

    OFStandard::shutdownNetwork();

    cond = tlsOptions.writeRandomSeed();
    if (cond.bad()) {
        // failure to write back the random seed is a warning, not an error
        OFLOG_WARN(findscuLogger, DimseCondition::dump(temp_str, cond));
    }
    return 0;
}
